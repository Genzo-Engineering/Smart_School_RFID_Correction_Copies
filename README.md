# 📄 Spécifications Métier & Cahier des Charges (01-metier)

Ce dossier et cette branche (`01-metier/cahier-des-charges.md`) regroupent l'ensemble de la documentation fonctionnelle, du cadrage et des objectifs métier du projet **Smart School**.

---

## 🎯 Objet de ce Répertoire

Le document principal présent dans cette section (`Cahier_des_charges_Smart_School (1) (1).pdf`) définit le cadre stratégique, les périmètres d'intervention et les critères d'acceptation du système d'automatisation et de suivi scolaire[cite: 1, 3].

Il sert de référence unique pour valider les besoins fonctionnels des utilisateurs (professeurs, élèves et administration).

---

## 📌 Synthèse du Cahier des Charges

* **Contexte & Problématique :** Automatisation des tâches administratives répétitives (appel, retards, correction de copies, statistiques) pour redonner du temps pédagogique aux enseignants.
* **Méthodologie M1 → M6 :** Structuration du projet autour de 6 grands jalons d'ingénierie (*Cadrer, Organiser, Expérimenter, Sécuriser, Documenter, Livrer & Surveiller*).
* **Périmètre Fonctionnel (9 Modules) :**
  1. Gestion des étudiants & assignation RFID
  2. Suivi automatique de l'assiduité (IoT/MQTT)
  3. Gestion des examens & compétences
  4. Correction assistée par IA (LLM)
  5. Validation humaine obligatoire (si confiance IA < 85%)
  6. Analyse pédagogique des résultats
  7. Analyse croisée (Assiduité × Performances) pour détecter le décrochage
  8. Notifications intelligentes (Email / Slack)
  9. Dashboard synthétique en temps réel
---

## 👥 Roles & Gouvernance (RACI)

Cette branche synthétise également la répartition des responsabilités par module fonctionnel :
* **Professeur :** Définit les examens, valide/ajuste les corrections proposées par l'IA et consulte les alertes pédagogiques.
* **Étudiant :** Utilise son badge RFID pour enregistrer automatiquement son assiduité.
* **Administrateur :** Gère la flotte de badges RFID, les accès et la structure des classes.
* **Fusion AI :** Moteur central orchestrant les flux de données, la communication MQTT, l'interrogation du LLM et PostgreSQL.

---

## 🚀 Équipe Projet

Projet réalisé par l'équipe projet sous la méthodologie M1-M6 :
* **Salaheddine KHALF**
* **Mohamed MANTRACH**
* **Meriem BAHROUD**
* **Ghizlane MISBAHI**
