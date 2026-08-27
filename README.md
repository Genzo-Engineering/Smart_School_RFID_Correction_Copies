# 🧪 Matrice de Tests & Qualité (tests/matrice-tests.md)

Ce dossier et cette branche (`tests/matrice-tests.md`) regroupent la stratégie de recette, la matrice de qualification et les critères de validation Bout-en-Bout (E2E) du projet **Smart School**.

---

## 🎯 Objet de cette Section

Cette documentation permet de valider la conformité des développements par rapport au cahier des charges fonctionnel et technique. Elle définit les scénarios d'essai, les seuils d'acceptation et les tests de non-régression.

---

## 🧪 Matrice de Qualification & Scénarios d'Essai

| ID | Module | Description du Test | Condition de Réussite | Statut |
| :--- | :--- | :--- | :--- | :---: |
| **TEST-01** | **IoT / RFID** | Badging d'un étudiant via le lecteur ESP32. | Réception du message MQTT et enregistrement de l'assiduité en BDD en `< 5s`. | PASS |
| **TEST-02** | **Correction IA** | Soumission d'une copie numérisée lisible. | Génération d'un score, des explications et enregistrement dans PostgreSQL. | PASS |
| **TEST-03** | **Validation Humaine** | Soumission d'une copie avec indice de confiance `< 85%`. | Blocage de la validation auto et routage vers l'interface prof. | PASS |
| **TEST-04** | **Analyse Croisée** | Simulation d'une baisse simultanée d'assiduité et de notes. | Génération automatique d'une alerte de décrochage sur le Dashboard. | PASS |
| **TEST-05** | **Notifications** | Déclenchement d'une alerte critique (absence ou note basse)[cite: 3]. | Envoi effectif d'une notification via Email / Slack. | PASS |

---

## ⚙️ Exécution des Tests Automated

```bash
# Lancer la suite de tests unitaires et d'intégration
npm run test

# Lancer la recette E2E des flux Fusion AI / PostgreSQL
npm run test:e2e
