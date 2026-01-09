# Push_swap

# **📋 TODO List - Push_Swap**

## **🔴 Priorité Haute (Obligatoire pour valider)**

### **1. Mode Benchmark (--bench)**

- [ ]  Créer une structure globale pour compter les opérations
    
    typedef struct s_bench {
    
    int sa, sb, ss;
    
    int pa, pb;
    
    int ra, rb, rr;
    
    int rra, rrb, rrr;
    
    int total;
    
    } t_bench;
    
- [ ]  Modifier chaque instruction pour incrémenter son compteur
- [ ]  Passer le flag bench aux fonctions de tri
- [ ]  Afficher les stats sur stderr à la fin:
- [bench] disorder: XX.XX%
- [bench] strategy: <nom> / O(<complexité>)
- [bench] total Ops: <N>
- [bench] sa: X sb: X ss: X pa: X pb: X
- [bench] ra: X rb: X rr: X rra: X rrb: X rrr: X

---

### **2. Implémenter sort_complex (vrai O(n log n))**

- [ ]  Choisir un algorithme: Radix sort ou Turkish algorithm
- [ ]  Implémenter l'algorithme
- [ ]  Tester les performances avec 500 nombres
- [ ]  Objectif: < 5500 opérations pour 500 nombres

---

### **3. Créer README.md**

- [ ]  Première ligne: *This project has been created as part of the 42 curriculum by <login1>, <login2>*
- [ ]  Section **Description**: expliquer le projet
- [ ]  Section **Instructions**: make, ./push_swap --adaptive 3 2 1
- [ ]  Section **Resources**: liens + utilisation de l'IA
- [ ]  Section **Algorithmes**: expliquer chaque stratégie et justifier les choix

---

## **🟠 Priorité Moyenne (Amélioration des perfs)**

### **4. Optimiser les opérations combinées**

- [ ]  Utiliser rr quand ra et rb sont nécessaires en même temps
- [ ]  Utiliser rrr quand rra et rrb sont nécessaires en même temps
- [ ]  Utiliser ss quand sa et sb sont nécessaires en même temps

---

### **5. Optimiser chunk_sort**

- [ ]  Ajuster dynamiquement la taille des chunks selon n
- [ ]  Optimiser le "push back" (garder une rotation partielle en B)
- [ ]  Tester différentes tailles de chunks pour trouver l'optimal

---

### **6. Améliorer sort_simple pour petits ensembles**

- [ ]  Optimiser le cas n=3 (max 2-3 ops)
- [ ]  Optimiser le cas n=5 (max ~12 ops)
- [ ]  Éviter les rotations inutiles

---

## **🟢 Priorité Basse (Bonus)**

### **7. Programme checker (Bonus)**

- [ ]  Créer les fichiers *_bonus.c et *_bonus.h
- [ ]  Ajouter la règle bonus dans le Makefile
- [ ]  Lire les opérations depuis stdin (get_next_line)
- [ ]  Exécuter les opérations sur la stack
- [ ]  Afficher "OK" si trié et B vide, sinon "KO"
- [ ]  Gérer les erreurs (instruction invalide → "Error")

---

## **🧪 Tests à faire**

- [ ]  Tester avec 100 nombres aléatoires → viser < 700 ops
- [ ]  Tester avec 500 nombres aléatoires → viser < 5500 ops
- [ ]  Tester les edge cases:
- [ ]  Liste déjà triée
- [ ]  Liste inversée
- [ ]  Un seul argument
- [ ]  Arguments avec espaces "1 2 3"
- [ ]  Doublons → "Error"
- [ ]  Overflow INT_MAX+1 → "Error"
- [ ]  Non-nombre → "Error"
- [ ]  Vérifier avec ./checker_linux

---

## **📁 Fichiers à créer/modifier**