# Smart_School_RFID_Correction_Copies
# ⚙️ Documentation d'Exploitation & Maintenance (03-exploitation)

Ce dossier et cette branche (`03-exploitation`) contiennent l'ensemble des procédures opérationnelles, des consignes de sécurité, de la gestion des secrets et du suivi d'exploitation du système **Smart School**.

---

## 🎯 Objet de cette Section

Cette documentation s'adresse aux équipes d'ingénierie, d'administration système et de maintenance. Elle garantit le maintien en condition opérationnelle (MCO) de l'écosystème Smart School : matériel IoT (ESP32), flux MQTT, base PostgreSQL et workflows d'IA (Fusion AI).

---

## 🔒 Configuration & Gestion des Secrets (.env)

Toutes les variables d'environnement critiques doivent être configurées dans le fichier `.env` à la racine de l'application et **ne doivent jamais être committées sur Git**.

### Modèle de Fichier `.env.example`

```env
# Base de Données PostgreSQL
POSTGRES_HOST=localhost
POSTGRES_PORT=5432
POSTGRES_DB=smart_school_db
POSTGRES_USER=admin_user
POSTGRES_PASSWORD=ChAnGeMe_StRoNgPaSsWoRd!

# Broker MQTT (IoT / ESP32)
MQTT_BROKER_URL=mqtt://broker.hivemq.com
MQTT_PORT=1883
MQTT_TOPIC_ATTENDANCE=smartschool/rfid/attendance
MQTT_CLIENT_ID=fusion_ai_orchestrator

# Moteur IA & LLM
LLM_API_KEY=sk-proj-xxxxxxxxxxxxxxxxxxxxxxxx
LLM_MODEL=gpt-4o
CONFIDENCE_THRESHOLD=0.85

# Services de Notification
SMTP_GMAIL_USER=alerts.smartschool@gmail.com
SMTP_GMAIL_PASS=xxxx-xxxx-xxxx-xxxx
SLACK_WEBHOOK_URL=[https://hooks.slack.com/services/XXX/YYY/ZZZ](https://hooks.slack.com/services/XXX/YYY/ZZZ)

