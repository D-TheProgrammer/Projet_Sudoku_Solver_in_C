# Projet_Sudoku_Solver_in_C
[French] Projet de jeu Sudoku en C avec son Solver (D'abord ce sera le README en français, puis en anglais)  
[English] Sudoku Game Project in C with its Solver (First it will be the French README then the English README After)

![C](https://img.shields.io/badge/C-A8B9CC?style=flat&logo=c&logoColor=black)
![AI](https://img.shields.io/badge/AI-Solver-orange)
![Game](https://img.shields.io/badge/Game-Puzzle-blue)
![Terminal](https://img.shields.io/badge/Interface-Terminal-green)
![Status](https://img.shields.io/badge/Status-Complete-success)

<div align="center">
  <img width="323" alt="image" src="https://github.com/D-TheProgrammer/Projet_Sudoku_Solver_in_C/assets/151149998/64a04980-be3a-4ead-aa4d-533a4e9f9d50">
</div>

#### SOMMAIRE / SUMMARY
- [Présentation en francais avec tutoriel / Presentation in French with tutorial](#presentation-en-francais)
- [Présentation en anglais avec tutoriel / Presentation in English with tutorial](#english-presentation)


## [PRESENTATION EN FRANCAIS]
#### 1.  <ins>[Information]</ins>
Le sudoku, est un jeu en forme de grille de 9 par 9 dont le but du jeu est de remplir la grille avec une série de chiffres (ou de lettres ou de symboles) tous différents, qui ne se trouvent jamais plusieurs fois sur une même ligne, dans une même colonne ou dans une même région sous-grille. La plupart du temps, les symboles sont des chiffres allant de 1 à 9, avec des régions carrés de 3 × 3. Quelques symboles sont déjà disposés dans la grille, ce qui autorise une résolution progressive du problème complet.


#### 2.  <ins>[Fonctionnalités]</ins>
Les fonctionnalités de mon Sudoku sont les suivantes :
- Nous pouvons jouer au Sudoku en plaçant des nombres où nous voulons en indiquant les colonnes, les lignes et les numéros.
- Nous pouvons vérifier notre grille et voir si nous avons gagné.
- Nous pouvons sauvegarder notre progression dans un fichier .txt et reprendre la partie plus tard.
- Nous pouvons, comme dit précédemment, commencer la partie avec une sauvegarde.
- Nous pouvons choisir la difficulté via des grilles déjà proposées.
- Nous pouvons générer une grille aléatoire pour y jouer et la sauvegarder si nécessaire.
- Nous pouvons utiliser un résolveur qui va résoudre la grille à notre place.
- Nous pouvons naviguer dans des menus textuels.
- Nous pouvons quitter le jeu à tout moment.

Pour jouer au Sudoku, veuillez lire les indications et les nombres indiqués par le programme affiché sur le terminal.  

#### 3.  <ins>[Ce que contient le dossier du projet]</ins>
Des grilles pour différents niveaux de difficulté sont fournies :
-  grille_facile.txt (grille de jeu avec difficulté "facile")  
-  grille.txt    (grille de jeu avec difficulté "moyenne")  
-  grille_difficile.txt  (grille de jeu avec difficulté "difficile")   
-  grille_victorieuse.txt  (grille de jeu déja résolu pour test le fonctionnement du programme)   
-  grille_vide_pour_test.txt (grille de jeu totalement vide pour test le fonctionnement du programme)
-  grille_generer_alea.txt (grille généré aléatoirement par le programme )   
Concernant la grille aléatoire et sa solution, il faudra d'abord la générer via le programme pour pouvoir accéder au fichier .txt complet et à sa solution en .txt.  

Des fichier _.txt_ nommé "solution" sont fourni cela permet de comparer la résolution du programme avec ces fichier fournis :
-  grille_facile_solution.txt  
-  grille_difficile_solution.txt  
-  grille_generer_alea_solution.txt  
  

Enfin des fichier _.txt_ nommé "sauvegarde" sont donnés afin d'arreter la partie et la reprendre plus tard :
-  sauvegarde_Niveau_Alea.txt
-  sauvegarde_Niveau0.txt (pour la difficulté victorieuse)
-  sauvegarde_Niveau1.txt (pour la difficulté facile)
-  sauvegarde_Niveau2.txt (pour la difficulté moyenne)
-  sauvegarde_Niveau3.txt (pour la difficulté difficile)

> [!TIP]
> Pour compiler le projet utilisez une méthode classique avec gcc a savoir : 
> ```bash
> gcc projet_sudoku_D-TheProgrammer.c -o projet_sudoku_D-TheProgrammer
> ```
> Pour exécuter le projet :
Veuillez utiliser une méthode classique de terminal a savoir : 
> ```bash
> .\projet_sudoku_D-TheProgrammer 
> ```

## [Tutoriel]
#### ÉTAPE 0 : Création de la grille de jeu a partir d'un fichier .txt
Le jeu se base sur les différrent fichier _.txt_ cité ci-dessus pour jouer , pour créer ca grille il suffit de modifier convenablement un fichier .txt notamment `grille_vide_pour_test.txt`  , il faut faire une grille de 9x9 en inscrivant les chiffres que l'on veut et en mettant des __"_"__ pour représenter le chiffre "0"
<div align="center">
  <img width="375" alt="image" src="https://github.com/D-TheProgrammer/Projet_Sudoku_Solver_in_C/assets/151149998/b98ee69f-bfc9-4611-a596-5cbc30d4984b">
</div>


#### ÉTAPE 1 : Après avoir lancer le programme, on accueille du joueur avec l'explication des règles
<div align="center">
	<img width="337" alt="image" src="https://github.com/D-TheProgrammer/Projet_Sudoku_Solver_in_C/assets/151149998/9cb2503f-4b71-4e44-bb6c-5958c4dc3910">
  <img width="296" alt="image" src="https://github.com/D-TheProgrammer/Projet_Sudoku_Solver_in_C/assets/151149998/4184cf72-4af2-49ac-afa5-fd0817cb9485">
</div>

#### ÉTAPE 2 : Menu proposant plusieurs  choix : - Jouer directement - Utiliser une sauvegarde pour reprendre sa partie - Quitter le jeu
<div align="center">
	<img width="614" alt="image" src="https://github.com/D-TheProgrammer/Projet_Sudoku_Solver_in_C/assets/151149998/24bf6dc2-c98b-48e1-9c0f-29dd6dd40111">
</div>

#### ÉTAPE 3 : Si le joueur décide de charger une sauvegarde il peut en choisir une parmis la liste choix 1-5 (ou revenir en arrière Choix-6)
<div align="center">
  <img width="678" alt="image" src="https://github.com/D-TheProgrammer/Projet_Sudoku_Solver_in_C/assets/151149998/d1fbcd5f-0976-43b7-be17-9925e0173ab5">
</div>

#### ÉTAPE 4 : Si le joueur décide de jouer ou de jouer a partir d'une sauveagrde il peut  dire où il veut placer un numéro
<div align="center">
	<img width="411" alt="image" src="https://github.com/D-TheProgrammer/Projet_Sudoku_Solver_in_C/assets/151149998/23a372a1-df45-4e8f-8398-6b378e6ac7d7">
</div>

#### ÉTAPE 5 :  Une fois jouer , un nouveau Menu se déclenche permettant de : - Continuer à jouer SANS Sauvegarder - Sauvegarder et Continuer à jouer - Sauvegarder et Quitter - Quitter sans Sauvegarder - Vérifier si la grille est bonne , pour tester la condition de victoire -  Utiliser le Solver pour Resoudre la Grille 

<div align="center">
  <img width="823" alt="image" src="https://github.com/D-TheProgrammer/Projet_Sudoku_Solver_in_C/assets/151149998/de4c149e-05af-4ef5-88cf-9a18f475d2c4">
</div>

Selon la réponse, différents embranchements se font mais nous allons les regrouper : 
- Lorsque le choix est “Continuer à Jouer” et “Sauvegarder et continuer à jouer” , le programme reboucle au niveau de la proposition de la colonne et des lignes pour inscrire un numéro.  
- Lorsque le choix est “ Sauvegarder et Arrêter de Jouer” et “Quitter Sans Sauvegarder", un choix s’ouvre au joueur le proposant s’il veut rejouer à partir de ce moment le programme peut reprendre du début, ou si le choix est d'arrêter il quitte le programme

<div align="center">
  <img width="460" alt="image" src="https://github.com/D-TheProgrammer/Projet_Sudoku_Solver_in_C/assets/151149998/d30ed41f-7aca-4f28-94f3-3dd45dc76a7e">
</div>

- Le dernier choix est "Vérifié si la grille est bien remplie et voir si tu as gagné “ , ce choix ouvre 2 porte soit le joueur gagne , un message s’affiche et on lui demande s’il veut continuer ou arrêter le programme. Par contre s’il a faux on retourne au proposition de ligne et colonne pour placer un numéro.

- Enfin c'est a partir de ce menu qu'il est possible d'utiliser le solver automatique [Choix 6] qui va résoudre la grille si c'est cela est possible (si la grille qu'utilise le joueur est impossible a résoudre un message s'affichera) , après ça il sera possible de rejouer :

<div align="center">
  <img width="199" alt="image" src="https://github.com/D-TheProgrammer/Projet_Sudoku_Solver_in_C/assets/151149998/5abf9270-d519-407c-82be-f048d80d7f74">
  <img width="440" alt="image" src="https://github.com/D-TheProgrammer/Projet_Sudoku_Solver_in_C/assets/151149998/d1ebe1da-e90f-4734-858d-1b1f439dd654">
</div>

___

## [ENGLISH PRESENTATION]
#### 1. <ins>[Information]</ins>
Sudoku is a grid-based game of 9 by 9 squares, where the goal is to fill the grid with a series of numbers (or letters or symbols), all different, which never appear more than once in the same row, column, or 3x3 sub-grid. Most of the time, the symbols are numbers from 1 to 9, with square regions of 3 × 3. Some symbols are already placed in the grid, allowing for a progressive resolution of the complete problem.

#### 2. <ins>[Features]</ins>
The features of my Sudoku are as follows:
- We can play Sudoku by placing numbers where we want, indicating the columns, rows, and numbers.
- We can check our grid and see if we have won.
- We can save our progress in a .txt file and resume the game later.
- We can start the game with a saved game as mentioned above.
- We can choose the difficulty via already provided grids.
- We can generate a random grid to play and save it if necessary.
- We can use a solver to solve the grid for us.
- We can navigate through text menus.
- We can quit the game at any time.

To play Sudoku, please read the instructions and numbers indicated by the program displayed on the terminal.

#### 3. <ins>[Contents of the project folder]</ins>
Grids for different difficulty levels are provided:
-  grille_facile.txt (game grid with "easy" difficulty)
-  grille.txt (game grid with "medium" difficulty)
-  grille_difficile.txt (game grid with "difficult" difficulty)
-  grille_victorieuse.txt (pre-solved game grid to test the program's functionality)
-  grille_vide_pour_test.txt (completely empty game grid to test the program's functionality)
-  grille_generer_alea.txt (grid randomly generated by the program)
  
Regarding the random grid and its solution, you will need to generate it via the program first to access the complete .txt file and its solution in .txt.

Text files named "solution" are provided to compare the program's resolution with these provided files:
-  grille_facile_solution.txt
-  grille_difficile_solution.txt
-  grille_generer_alea_solution.txt

Finally, "sauvegarde" (.txt) files are provided to stop the game and resume it later:
-  sauvegarde_Niveau_Alea.txt
-  sauvegarde_Niveau0.txt (for victorious difficulty)
-  sauvegarde_Niveau1.txt (for easy difficulty)
-  sauvegarde_Niveau2.txt (for medium difficulty)
-  sauvegarde_Niveau3.txt (for difficult difficulty)


> [!TIP]
> To compile the project, use a classic method with gcc, namely:  
> ```bash
> gcc projet_sudoku_D-TheProgrammer.c -o projet_sudoku_D-TheProgrammer  
> ```
> Pour exécuter le projet :
Please use a classic terminal method, namely:   
> ```bash
> .\projet_sudoku_D-TheProgrammer   
> ```

## [Tutorial]
#### STEP 0: Creating the game grid from a .txt file
The game relies on the various mentioned _.txt_ files to play. To create this grid, simply modify a .txt file, notably `grille_vide_pour_test.txt`, by making a 9x9 grid and writing the desired numbers while using "__" to represent the number "0".

<div align="center">
  <img width="375" alt="image" src="https://github.com/D-TheProgrammer/Projet_Sudoku_Solver_in_C/assets/151149998/b98ee69f-bfc9-4611-a596-5cbc30d4984b">
</div>

#### STEP 1: After launching the program, the player is greeted with an explanation of the rules.
<div align="center">
	<img width="437" alt="image" src="https://github.com/D-TheProgrammer/Projet_Sudoku_Solver_in_C/assets/151149998/9cb2503f-4b71-4e44-bb6c-5958c4dc3910">
  <img width="296" alt="image" src="https://github.com/D-TheProgrammer/Projet_Sudoku_Solver_in_C/assets/151149998/4184cf72-4af2-49ac-afa5-fd0817cb9485">
</div>

#### STEP 2: Menu offering several choices: - Play directly [Choice 1] - Use a saved game to resume [Choice 2] - Quit the game [Choice 3]
<div align="center">
	<img width="614" alt="image" src="https://github.com/D-TheProgrammer/Projet_Sudoku_Solver_in_C/assets/151149998/24bf6dc2-c98b-48e1-9c0f-29dd6dd40111">
</div>

#### STEP 3: If the player decides to load a saved game, they can choose one from the list, options 1-5 (or go back Option-6).
<div align="center">
  <img width="678" alt="image" src="https://github.com/D-TheProgrammer/Projet_Sudoku_Solver_in_C/assets/151149998/d1fbcd5f-0976-43b7-be17-9925e0173ab5">
</div>

#### STEP 4: If the player decides to play or play from a saved game, they can indicate where they want to place a number.
<div align="center">
	<img width="411" alt="image" src="https://github.com/D-TheProgrammer/Projet_Sudoku_Solver_in_C/assets/151149998/23a372a1-df45-4e8f-8398-6b378e6ac7d7">
</div>

#### STEP 5: Once played, a new menu triggers allowing to: - Continue playing WITHOUT Saving [Choice 1] - Save and Continue playing [Choice 2] - Save and Quit [Choice 3] - Quit without Saving [Choice 4]  - Check if the grid is correct, to test the winning condition [Choice 5] - Use 
<div align="center">
  <img width="823" alt="image" src="https://github.com/D-TheProgrammer/Projet_Sudoku_Solver_in_C/assets/151149998/de4c149e-05af-4ef5-88cf-9a18f475d2c4">
</div>

Depending on the response, different branches occur, but we will group them:
- When the choice is "Continuer à Jouer" (Continue Playing [Choice 1]) and “Sauvegarder et continuer à jouer” (Save and Continue Playing [Choice2]), the program loops back to the proposal of the column and rows to enter a number.
- When the choice is “ Sauvegarder et Arrêter de Jouer” (Save and Stop Playing [Choice 3]) and “Quitter Sans Sauvegarder" (Quit Without Saving [Choice 4] ), an option opens to the player asking if they want to replay from this point. The program can restart from the beginning, or if the choice is to stop, it exits the program.

<div align="center">
  <img width="460" alt="image" src="https://github.com/D-TheProgrammer/Projet_Sudoku_Solver_in_C/assets/151149998/d30ed41f-7aca-4f28-94f3-3dd45dc76a7e">
</div>


- The last choice is  "Vérifié si la grille est bien remplie et voir si tu as gagné “ (Check if the grid is filled correctly and see if you have won [Choice 5] ). This choice opens two doors: if the player wins, a message appears and asks if they want to continue or stop the program. However, if they are wrong, we return to the proposal of rows and columns to place a number.


- Finally, it is from this menu that it is possible to use the automatic solver [Choice 6], which will solve the grid if it is possible (if the grid used by the player is impossible to solve, a message will be displayed). After that, it will be possible to play again.
<div align="center">
  <img width="199" alt="image" src="https://github.com/D-TheProgrammer/Projet_Sudoku_Solver_in_C/assets/151149998/5abf9270-d519-407c-82be-f048d80d7f74">
  <img width="440" alt="image" src="https://github.com/D-TheProgrammer/Projet_Sudoku_Solver_in_C/assets/151149998/d1ebe1da-e90f-4734-858d-1b1f439dd654">
</div>
