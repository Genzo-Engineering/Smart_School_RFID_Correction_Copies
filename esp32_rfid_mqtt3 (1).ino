#include <WiFi.h>
#include <PubSubClient.h>
#include <SPI.h>
#include <MFRC522.h>

// =========================
// WiFi
// =========================
const char* WIFI_SSID = "A30";
const char* WIFI_PASSWORD = "salaheddine";

// =========================
// MQTT
// =========================
const char* MQTT_HOST = "broker.hivemq.com";
const int MQTT_PORT = 1883;

const char* MQTT_TOPIC = "smart-hospital-monitor/MakerBoard_01";

const char* MQTT_CLIENT_ID = "fusion-mqtt-subscriber_salahkh";

// =====================================================
// RC522
// =====================================================
#define SS_PIN    5
#define RST_PIN   22
#define SCK_PIN   14
#define MISO_PIN  12
#define MOSI_PIN  13
MFRC522 rfid(SS_PIN, RST_PIN);

// =====================================================
// BUZZER
// =====================================================
#define BUZZER_PIN 26

// =====================================================
// LEDS
// =====================================================
int led1 = 33, led2 = 32;

// =========================
// Objects
// =========================
WiFiClient espClient;
PubSubClient mqttClient(espClient);

// =========================
// Connect WiFi
// =========================
void connectWiFi() {
  Serial.print("Connecting to WiFi");

  WiFi.begin(WIFI_SSID, WIFI_PASSWORD);

  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }

  // Désactiver le power-saving WiFi (cause fréquente de déconnexion
  // avec les hotspots téléphone / certains routeurs)
  WiFi.setSleep(false);

  Serial.println();
  Serial.println("WiFi connected");
  Serial.print("ESP32 IP: ");
  Serial.println(WiFi.localIP());
  Serial.print("RSSI: ");
  Serial.println(WiFi.RSSI());
}

// =========================
// Connect MQTT
// =========================
void connectMQTT() {

  while (!mqttClient.connected()) {

    Serial.println();
    Serial.println("Connecting to MQTT broker...");

    String clientId = "MakerBoard_01_";
    clientId += String((uint32_t)ESP.getEfuseMac(), HEX);

    if (mqttClient.connect(clientId.c_str())) {

      Serial.println("MQTT connected!");

      Serial.print("MQTT Host: ");
      Serial.println(MQTT_HOST);

      Serial.print("MQTT Port: ");
      Serial.println(MQTT_PORT);

      Serial.print("MQTT Topic: ");
      Serial.println(MQTT_TOPIC);

    } else {

      Serial.print("MQTT connection failed. State = ");
      Serial.println(mqttClient.state());

      Serial.println("Retrying in 5 seconds...");

      delay(5000);
    }
  }
}

// =========================
// Read RFID UID as hex string
// =========================
String readRFIDUID() {

  String uidStr = "";

  for (byte i = 0; i < rfid.uid.size; i++) {
    if (rfid.uid.uidByte[i] < 0x10) {
      uidStr += "0";
    }
    uidStr += String(rfid.uid.uidByte[i], HEX);
  }

  uidStr.toUpperCase();
  return uidStr;
}

// =========================
// Buzzer beep
// =========================
void beepBuzzer() {
  digitalWrite(BUZZER_PIN, HIGH);
  delay(150);
  digitalWrite(BUZZER_PIN, LOW);
}

// =========================
// Setup
// =========================
void setup() {

  Serial.begin(115200);

  delay(1000);

  // Init SPI + RC522
  SPI.begin(SCK_PIN, MISO_PIN, MOSI_PIN, SS_PIN);
  rfid.PCD_Init();

  // Init Buzzer
  pinMode(BUZZER_PIN, OUTPUT);
  digitalWrite(BUZZER_PIN, LOW);

  // Init LEDs
  pinMode(led1, OUTPUT);
  pinMode(led2, OUTPUT);
  digitalWrite(led1, LOW);
  digitalWrite(led2, LOW);

  connectWiFi();

  mqttClient.setServer(MQTT_HOST, MQTT_PORT);
  mqttClient.setKeepAlive(60);   // keepalive plus large (défaut 15s)
  mqttClient.setSocketTimeout(10);

  connectMQTT();
}

// =========================
// Loop
// =========================
void loop() {

  if (WiFi.status() != WL_CONNECTED) {
    connectWiFi();
  }

  if (!mqttClient.connected()) {
    Serial.print("MQTT disconnected, state = ");
    Serial.println(mqttClient.state());
    connectMQTT();
  }

  mqttClient.loop();

  // Vérifier si une nouvelle carte est présente
  if (!rfid.PICC_IsNewCardPresent()) {
    delay(50);
    return;
  }

  // Essayer de lire son UID
  if (!rfid.PICC_ReadCardSerial()) {
    return;
  }

  String rfidUID = readRFIDUID();

  String payload = "{\"rfid_uid\":\"";
  payload += rfidUID;
  payload += "\"}";

  Serial.print("Publishing: ");
  Serial.println(payload);

  bool published = mqttClient.publish(
    MQTT_TOPIC,
    payload.c_str()
  );

  if (published) {
    Serial.println("MQTT message published successfully");
    beepBuzzer();
    digitalWrite(led1, HIGH);
    digitalWrite(led2, HIGH);
    delay(150);
    digitalWrite(led1, LOW);
    digitalWrite(led2, LOW);
  } else {
    Serial.println("MQTT publish FAILED");
  }

  // Arrêter la communication avec la carte
  rfid.PICC_HaltA();
  rfid.PCD_StopCrypto1();

  delay(1000);
}
