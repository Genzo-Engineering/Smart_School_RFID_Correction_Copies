# Smart_School_RFID_Correction_Copies

# 🏗️ Spécifications Techniques & Architecture Système (02-technique)

Ce dossier et cette branche (`02-technique/architecture`) regroupent la documentation technique, le schéma de données, l'architecture logicielle/matérielle ainsi que les workflows d'orchestration du projet **Smart School**.

---

## 🎯 Objet de ce Répertoire

Cette section sert de référence technique pour l'équipe de développement et d'ingénierie. Elle détaille le fonctionnement interne de la plateforme, les flux d'intégration IoT/MQTT, l'orchestration via Fusion AI, le modèle relationnel PostgreSQL et l'intégration du moteur IA (LLM).

---

## 📐 Architecture Globale & Flux de Données

Le système repose sur une architecture découplée et événementielle :
### Description des Composants :
1. **IoT / Hardware (ESP32 + RFID)** : Captures en temps réel des passages de badges RFID (UID), émis sous forme de messages JSON via MQTT.
2. **Broker MQTT & Fusion AI** : Moteur central d'orchestration qui intercepte les événements MQTT, applique la logique métier, met à jour la base PostgreSQL et déclenche les workflows d'analyse.
3. **Moteur IA (LLM)** : Service d'analyse et de correction automatique des copies scannées. Calcule la note, le feedback et attribue un indice de confiance.
4. **Base de Données PostgreSQL** : Stockage persistant structuré pour la gestion des utilisateurs, présences, épreuves, copies et journaux d'audit.
5. **Dashboard Enseignant** : Interface web de consultation des indicateurs, de validation des corrections et de gestion des alertes.

---

## 🗄️ Schéma de la Base de Données (PostgreSQL)

La base relationnelle est structurée autour des entités clés suivantes :

* `classes` ➔ `students` : Structuration des élèves par groupe/niveau.
* `students` ➔ `attendance` : Historique des pointages RFID (Statut : *Présent, Retard, Absent*).
* `exams` ➔ `questions` : Examens, barèmes, réponses attendues et compétences évaluées.
* `students` + `exams` ➔ `submissions` ➔ `corrections` : Copies d'élèves téléversées, scores attribués par le LLM, taux de confiance et statut de validation.
* `notifications` & `recommendations` : Alertes automatiques et recommandations pédagogiques générées par l'analyse croisée.

---

## 🛠️ Stack Technique

* **Hardware / IoT** : ESP32, Lecteur RFID (RC522/PN532), C++ (Arduino/PlatformIO).
* **Protocole Réseau** : MQTT (Broker HiveMQ/Mosquitto).
* **Orchestration** : Fusion AI Engine (Workflows basés sur des nœuds événementiels).
* **Intelligence Artificielle** : API LLM pour l'extraction OCR, correction automatique et calcul de confiance.
* **SGBD** : PostgreSQL 15+.

---

## ⚙️ Contraintes Techniques & Sécurité

* **Latence** : Traitement des événements RFID et mise à jour en base de données en moins de 5 secondes.
* **Résilience IoT** : Gestion du buffering local de l'ESP32 et retry automatique en cas de perte de connexion WiFi/MQTT.
* **Confidentialité & Sécurité** : Chiffrement des clés API, accès sécurisés par rôles (Professeur, Admin, Service) et journalisation systématique des validations pour audit.

---

## 🚀 Équipe Technique & Auteurs

Documentation rédigée dans le cadre de la méthode M1-M6:
* **Salaheddine KHALF**
* **Mohamed MANTRACH**
* **Meriem BAHROUD**
* **Ghizlane MISBAHI**
