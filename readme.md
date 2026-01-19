*This project has been created as part of the 42 curriculum by elsahin, fermis.*

# Push_swap

## 📖 Description

Push_swap est un programme écrit en C dont le but est de trier une liste d'entiers sur une pile `a`, en utilisant une pile auxiliaire `b` et un ensemble limité d’opérations. Le défi principal est de trier les nombres avec le **moins d'opérations possible**.

Le programme prend en entrée une liste d'entiers en arguments et affiche sur la sortie standard la suite d'instructions permettant de trier cette liste.

### Opérations Autorisées

-   `sa`, `sb`, `ss` : Échange les deux premiers éléments d'une pile.
-   `pa`, `pb` : Prend le premier élément d'une pile et le met sur l'autre.
-   `ra`, `rb`, `rr` : Décale tous les éléments d'une pile vers le haut.
-   `rra`, `rrb`, `rrr` : Décale tous les éléments d'une pile vers le bas.

## 🛠️ Instructions

### Compilation

Le projet utilise un **Makefile** pour compiler l'exécutable.

```bash
make
```

Cela générera l'exécutable `push_swap`.

### Exécution

Pour exécuter le programme, passez une liste d'entiers à trier en argument :

```bash
./push_swap 2 1 3 6 5 8
```

Vous pouvez vérifier le nombre d'opérations avec `wc -l` :

```bash
./push_swap 2 1 3 6 5 8 | wc -l
```

## 🧠 Algorithmes

Le projet implémente une stratégie **adaptative** (`sort_adaptive`) qui choisit le meilleur algorithme en fonction de la taille de l'entrée et de son désordre.

### 1. Simple Sort (Petits inputs)
Pour les très petites listes (taille ≤ 5) ou les listes presque triées de taille moyenne :
-   Une approche brute ou optimisée au cas par cas est utilisée.
-   Pour **2 éléments**, un simple échange (`sa`) si nécessaire.
-   Pour **3 à 5 éléments**, un tri par insertion ou sélection spécifique est appliqué pour minimiser les coups.

### 2. Chunk Sort (Inputs Moyens ~100)
Utilisé principalement pour les listes de taille moyenne (environ 100 éléments) :
-   L'algorithme divise les nombres triés théoriquement en plusieurs "chunks" (morceaux).
-   Il pousse les éléments du chunk courant de A vers B.
-   Une optimisation intelligente déplace les éléments proches des bornes (haut/bas) pour préparer le retour.
-   Une fois tout dans B, les éléments sont repoussés dans A dans l'ordre (du plus grand au plus petit).

### 3. Quick Sort (Grands Inputs > 100)
Pour les grandes listes (ex: 500 éléments), une adaptation du **Quick Sort** est utilisée pour sa complexité efficace :
-   **Partitionnement** : La pile A est divisée récursivement autour d'un pivot. Les éléments inférieurs au pivot sont poussés vers B (`pb`), les autres subissent une rotation (`ra`).
-   **Récursivité** : Le processus est répété sur les sous-piles jusqu'à ce qu'elles soient triées.
-   Cette approche est très efficace pour réduire le nombre d'opérations sur de grands ensembles de données.

## 📚 Resources & AI Usage

### Ressources
-   Medium
-   Gemini 3 pro
-   Youtube

### Utilisation de l'IA
Dans le cadre de ce projet, l'assistant IA **Gemini 3 Pro** a été utilisé pour :
-  **Génération de structure** : Mise en place rapide des fichiers headers et des squelettes de fonctions.
-  **Implémentation d'Algorithmes** : Conception et adaptation des algorithmes avancés, spécifiquement le **Chunk Sort** pour les tailles moyennes et le **Quick Sort** pour les grands ensembles de données.
-  **Optimisation** : Analyse des cas limites (ex: optimiser le tri pour exactement 2 éléments dans `sort_simple`).
-  **Documentation** : Aide à la rédaction et à la structuration de ce fichier `README.md`.
-  **Debugging** : Vérification de la logique des algorithmes de tri.



