# Smart_School_RFID_Correction_Copies

# Smart School - Fusion AI Academy

## 📖 À propos du projet
**Smart School** est une application développée par **Fusion AI Academy** (une filiale de ABA Technology). 
Ce projet vise à créer une plateforme centralisée pour automatiser le suivi administratif, gérer l'assiduité via un système RFID, et assister les professeurs dans la correction des examens grâce à l'Intelligence Artificielle. 

L'objectif principal est de réduire la charge de travail répétitive des enseignants afin qu'ils puissent se concentrer davantage sur la pédagogie.

## ✨ Fonctionnalités Principales

Le système s'articule autour de 9 modules clés:

* **Gestion des étudiants :** Création des profils, assignation des classes et association des badges RFID.
* **Suivi de l'assiduité (IoT) :** Pointage automatique des présences, retards et absences via lecteur RFID.
* **Gestion des examens :** Création d'épreuves, définition des barèmes, compétences évaluées et téléversement des copies.
* **Correction assistée par IA :** Utilisation d'un LLM pour analyser les copies, proposer un score, identifier les erreurs et générer un feedback.
* **Validation humaine :** Si la confiance de l'IA est insuffisante, la correction est envoyée au professeur pour vérification et validation manuelle.
* **Analyse pédagogique :** Évaluation des performances individuelles et globales de la classe par compétence et par question.
* **Analyse croisée :** Croisement des données (Assiduité + Résultats) pour détecter les étudiants en difficulté ou en risque de décrochage.
* **Notifications :** Envoi d'alertes au professeur pour des absences répétées, des corrections à vérifier ou des baisses de performance.
* **Dashboard :** Interface web centralisée affichant les taux de présence, la moyenne de la classe, les alertes et les recommandations de l'IA.

## 🛠 Architecture & Technologies

Le projet repose sur l'interaction de plusieurs composants :

* **IoT (ESP32 + RFID) :** Matériel chargé de lire les badges étudiants et d'envoyer les événements en temps réel via le protocole **MQTT**.
* **Fusion AI :** Moteur d'orchestration central qui gère les workflows, traite les événements MQTT, communique avec la base de données et interroge le modèle IA (LLM).
* **Base de données :** **PostgreSQL** pour stocker les informations relatives aux étudiants, présences, examens, corrections et notifications.

## 👥 Acteurs du Système

* **Professeur :** Gère les examens, valide les notes de l'IA, consulte les statistiques et reçoit les alertes.
* **Étudiant :** Badge avec sa carte RFID pour enregistrer sa présence lors des séances.
* **Administrateur :** Supervise la plateforme, gère les accès, les classes et le matériel RFID.

## 🗄️ Structure des Données
La base de données relationnelle est structurée autour de tables majeures telles que :
`classes`, `students`, `attendance` (présences), `exams`, `questions`, `submissions` (copies), `answers`, `corrections`, `competencies`, `recommendations`, et `notifications`.

## 👨‍💻 Équipe Projet
Ce document de cadrage (Version 1.0) a été réalisé le 17/08/2026 par :
* Salaheddine Khalf
* Mohamed Mantrach
* Meriem Bahroud
* Ghizlane Misbahi

* ## 📂 Structure du Dépôt

## 📁 Structure de la Documentation

```plaintext
docs/
├── 📁 01-metier/
│   └── 📄 cahier-des-charges.md    # Périmètre fonctionnel, 9 modules (RFID, IA, Dashboard), acteurs et RACI[cite: 3]
├── 📁 02-technique/
│   └── 📄 architecture.md          # Flux IoT (ESP32/MQTT), schéma DB PostgreSQL et orchestration Fusion AI[cite: 3]
├── 📁 03-exploitation/
│   └── 📄 runbook.md               # Variables d'environnement (.env), gestion des erreurs MQTT et rotation des secrets[cite: 3]
├── 📁 tests/
│   └── 📄 matrice-tests.md         # Tests E2E, seuils de confiance LLM (< 85%) et scénarios de validation[cite: 3]
└── 📁 passation/
    └── 📄 checklist-reprise.md     # Procédures de passation, accès repo, exports JSON Fusion AI et plan de rollback[cite: 3]

├── 📄 CHANGELOG.md                 # Historique des versions (v0.1.0 POC à v1.0.0 MVP)[cite: 3]
├── 📄 README.md                    # Présentation générale, installation rapide et guide de démarrage[cite: 3]
└── 📄 VERSION                      # Fichier texte contenant la version actuelle (ex: 1.0.0)[cite: 3]
