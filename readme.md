*This project has been created as part of the 42 curriculum by <login1>, <login2>.*

# Push_swap

## 📖 Description

Push_swap est un programme écrit en C dont le but est de trier une liste d'entiers en utilisant uniquement deux piles (`a` et `b`) et un ensemble limité d’opérations.

Le programme doit générer la **plus petite séquence possible d’instructions** permettant de trier la pile `a` en ordre croissant.

Ce projet met l’accent sur :
- La compréhension de la complexité algorithmique.
- L’optimisation du nombre d’opérations.
- La sélection dynamique d’algorithmes selon la configuration des données.
- La rigueur mémoire et la robustesse du parsing.

---

## ⚙️ Règles du jeu

### Piles
- `a` : pile principale contenant les nombres au départ.
- `b` : pile auxiliaire vide au départ.

### Objectif
Trier la pile `a` en ordre croissant, avec la plus petite valeur en haut.

### Opérations autorisées

- `sa` : swap des deux premiers éléments de `a`
- `sb` : swap des deux premiers éléments de `b`
- `ss` : `sa` et `sb` en même temps

- `pa` : push du sommet de `b` vers `a`
- `pb` : push du sommet de `a` vers `b`

- `ra` : rotation de `a` (le premier devient dernier)
- `rb` : rotation de `b`
- `rr` : `ra` et `rb`

- `rra` : reverse rotation de `a`
- `rrb` : reverse rotation de `b`
- `rrr` : `rra` et `rrb`

Chaque opération est affichée sur une ligne.

---

## 🧠 Disorder Metric

Avant toute opération, on calcule un **indice de désordre** compris entre 0 et 1.

Principe :
- On compte toutes les paires `(i, j)` telles que `i < j`.
- Si `a[i] > a[j]`, c’est une inversion (une erreur).
- Le désordre = `nombre d’erreurs / nombre total de paires`.

- `0` → pile déjà triée.
- `1` → pire ordre possible.

Ce score est utilisé pour choisir dynamiquement la stratégie de tri.

---

## 🚀 Stratégies implémentées

Le programme embarque **4 stratégies** :

### 1️⃣ Simple — O(n²)
Utilisée pour de petites tailles ou faible désordre.
Exemples possibles :
- Sélection du minimum
- Insertion adaptée aux stacks

Objectif : simplicité et prédictibilité.

---

### 2️⃣ Medium — O(n √n)
Approche intermédiaire basée sur :
- Découpage en chunks / blocs
- Répartition progressive dans `b`
- Réinsertion optimisée

Compromis entre simplicité et performance.

---

### 3️⃣ Complex — O(n log n)
Optimisée pour les grands volumes de données.
Exemples possibles :
- Radix sort
- Partitionnement type quicksort adapté aux stacks

Objectif : minimiser drastiquement le nombre d’opérations.

---

### 4️⃣ Adaptive — stratégie dynamique

La stratégie adaptative choisit automatiquement l’algorithme selon le désordre :

- Désordre < 0.2 → stratégie Simple
- 0.2 ≤ Désordre < 0.5 → stratégie Medium
- Désordre ≥ 0.5 → stratégie Complex

Cette approche permet d’adapter le coût en opérations à la réalité du jeu de données.

---

## 📊 Benchmark Mode (`--bench`)

Le programme supporte un **mode benchmark** permettant d’analyser les performances réelles du tri.

Lorsque l’option `--bench` est activée :
- Les opérations continuent d’être affichées sur `stdout`.
- Les métriques sont affichées sur `stderr`.

### Informations affichées

- Désordre initial (en %, deux décimales)
- Nom de la stratégie sélectionnée
- Classe de complexité annoncée
- Nombre total d’opérations
- Détail du nombre d’appels pour chaque instruction :
  - `sa`, `sb`, `ss`
  - `pa`, `pb`
  - `ra`, `rb`, `rr`
  - `rra`, `rrb`, `rrr`

### Exemple

```bash
./push_swap --bench --adaptive 4 67 3 87 23

## 🖥️ Compilation

```bash
make
