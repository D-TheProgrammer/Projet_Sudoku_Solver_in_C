#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <time.h>

#define ROW 8
#define COL 8

//SUDOKU !!! Par D-TheProgrammer
int lire_grille(char *nom_fichier2, int grille[9][9]){
    //printf("%d",nom_fichier2);

    //-----Ouverture du fichier grille------  
    FILE * fichier;
    fichier = fopen(nom_fichier2,"r");
    if (fichier== NULL) {
        printf("Erreuur fopen\n");
        return 1;
    }

    int i = 0;
    char chaine[60];
    char grille_temporaire[9][9];
    
    //----Attribution des Valeur du fichier au array2D ------- 
    while(fgets(grille_temporaire[i], 60, fichier)) {
        //printf("%c", grille_temporaire[i][1]);
        i++;
    }
    
    //printf("grille temporaire indice 0-0 %c\n", grille_temporaire[0][0]);

    //------Conversion des charactere en nombres -------
    for(int y=0; y<9 ; y++){
        for (int i = 0; i < 9; i++)
        {
            if (grille_temporaire[y][i]== '_'){
                grille[y][i]=0;
            }
            else if (grille_temporaire[y][i]== '0')
            {
                grille[y][i]= 0;
            }
            else if (grille_temporaire[y][i]== '1')
            {
                grille[y][i]= 1;
            }
            else if (grille_temporaire[y][i]== '2')
            {
                grille[y][i]= 2;
            }
            else if (grille_temporaire[y][i]== '3')
            {
                grille[y][i]= 3;
            }
            else if (grille_temporaire[y][i]== '4')
            {
                grille[y][i]= 4;
            }
            else if (grille_temporaire[y][i]== '5')
            {
                grille[y][i]= 5;
            }
            else if (grille_temporaire[y][i]== '6')
            {
                grille[y][i]= 6;
            }
            else if (grille_temporaire[y][i]== '7')
            {
                grille[y][i]= 7;
            }
            else if (grille_temporaire[y][i]== '8')
            {
                grille[y][i]= 8;
            }
            else
            {
                grille[y][i]= 9;
            }

        }    
    }
    fclose(fichier);
    return grille[9][9];
    
    
}

int lire_grille_vide(char *nom_fichier2){
    FILE *fichier = fopen(nom_fichier2, "r");

    if(fichier == NULL)
        return 0;

    //----Ici on deplace le curseur de lecture du fichier a la fin avec fseek et ftell renvoie la valeur de la position du curseur----
    //--- si le fichier est vide la position de fin est 0 donc on renvoie 0----
    fseek(fichier, 0, SEEK_END);
    int taille = ftell(fichier);
    
    if(taille == 0){
        printf("Le fichier de sauvegarde est Vide , utilisez un autre sauvegarde \nou sinon creer une sauvegarde en jouant normalement\n ");
        return 0;
    }

    else{   
        printf("Vous pouvez utiliser la sauvegarde.\n");
        printf("\n");
    }

    fclose(fichier);
	return 1;
}

void afficher_grille(int grille[9][9]){
    int decalage=0;

    //---Affichage des marges horitale-----
    printf("    1  2  3   4  5  6   7  8  9");
    printf("\n   ______________________________\n");
    for(int ligne = 0; ligne < 9; ligne++)
  	{
        printf("%d | ",ligne+1); //---Affichage des marges verticale-----

  		for(int colonne = 0; colonne < 9; colonne++)
  		{
            printf("%d  ", grille[ligne][colonne]); //---affichage des valeur des fichier grille-----
            
            if (colonne == 2 || colonne== 5 || colonne==8){
                printf("|");  //---Separation horizontale aspect graphique -----
            }
		}
        if (ligne == 2 || ligne== 5 || ligne==8 ){
            printf("\n  |______________________________|");  //---Separation horizontale aspect graphique -----
            }
        
   		printf("\n");
  	}
}

void ecrire_grille(char *nom_fichier2, int grille[9][9]) {
    FILE * fichier;
    fichier = fopen(nom_fichier2,"w");
    if (fichier== NULL) {
        printf("Erreuur fopen\n");
    }

    //------ On ecrit dans le dossier le nombre du tableau ------
    else{
        for(int ligne = 0; ligne < 9; ligne++)
        {
            for(int colonne = 0; colonne < 9; colonne++)
            {
                fprintf(fichier,"%d", grille[ligne][colonne]);
            }
            fprintf(fichier,"\n");
  	    }
    }


    fclose(fichier);
}


void regles(){

    printf("----------------------------------------------------------------------\n");
    printf("----------------------------   REGLES  -------------------------------\n");
    printf("----------------------------------------------------------------------\n");
    printf("Le jeu Sudoku se joue sur une grille en carre de neuf cases de cote,\n");
    printf("subdivise en autant de sous-grilles carrees identiques, appelees '' regions ''.\n");
    printf("La regle du jeu est simple il suffit simplement que chaque ligne,\n");
    printf("colonne et region ne contiennent qu'une seule fois tous les chiffres de un a neuf (1-9).\n");
    printf("\n");
    printf("--------------------- !!! FIN REGLES !!! -------------------------------\n\n");

}


void comment_jouer(){
    printf("------------------------------------------------------------------------------\n");
    printf("----------------------------   COMMENT JOUER  -------------------------------\n");
    printf("-----------------------------------------------------------------------------\n");
    printf("\n");
    printf("Ce jeu est principalement textuelle afin de pourvoir modifier les cases\n");
    printf("Certains textes seront indiquer a l'ecran afin de pouvoir jouer , sauvegarder, et charger une partie\n" );
    printf("Lorsque ces choix se presentent veuillez inscrire le numero indiquer\n\n" );
    printf("Lors de la partie afin de pouvoir modifier une case du tableau, veuillez indiquer sa colonne et sa ligne via des nombres\n");
    printf("Des aides sont mises a disposition le nombre des colonnes et des lignes sont indiques\n");
    printf("Exemple : \n");

    printf("          1  2  3   4  5  6   7  8  9     \n");
    printf("         ______________________________   \n");
    printf("      1 | A  0  0  |0  0  0  |0  0  0  |  \n");
    printf("      2 | 0  0  0  |0  0  0  |0  0  0  |  \n");
    printf("      3 | 0  0  0  |0  0  0  |0  0  0  |  \n");
    printf("        |______________________________|  \n");
    printf("      4 | 0  0  0  |0  0  0  |0  0  0  |  \n");
    printf("      5 | 0  0  0  |0  0  0  |X  0  0  |  \n");
    printf("      6 | 0  0  0  |0  0  0  |0  0  0  |  \n");
    printf("        |______________________________|  \n");
    printf("      7 | 0  0  0  |0  0  0  |0  0  0  |  \n");
    printf("      8 | 0  0  0  |0  0  0  |0  0  0  |  \n");
    printf("      9 | 0  0  0  |0  0  0  |0  0  0  |  \n");
    printf("        |______________________________|  \n");

    printf("Pour le A : Il faut ecrire '1' pour la colonne\n");
    printf("          : Il faut ecrire '1' pour la ligne\n");
    printf("          : Donc 1-1\n");
    printf("Pour le X : Il faut ecrire '7' pour la colonne\n");
    printf("          : Il faut ecrire '5' pour la ligne\n");
    printf("          : Donc 7-5\n");

    printf("\n--------------------- !!! FIN COMMENT JOUER !!! ---------------------\n");
}


void jouer(int grille[9][9]){
    int colonne_choisi;
    int ligne_choisi; 
    int nombre_choisi;

    // CHOIX DE LA COLONNE DE JEU 
    printf("Dans quel COLONNE voulez vous jouez ? Les colonnes vont de 1 a 9 inclus : ");
    scanf("%d",&colonne_choisi);
    while (! (1 <= colonne_choisi && colonne_choisi <= 9) ){
        printf("C'est un choix entre 1 et 9 inclus !\n");
        printf("Dans quel COLONNE voulez vous jouez ? Les colonnes vont de 1 a 9 inclus : ");
        scanf("%d",&colonne_choisi);
    }

    // CHOIX DE LA LIGNE DE JEU 
    printf("Dans quel LIGNE voulez vous jouez ? Les lignes vont de 1 a 9 inclus : ");
    scanf("%d",&ligne_choisi);
    while (! (1 <= ligne_choisi && ligne_choisi <= 9) ){
        printf("C'est un choix entre 1 et 9 inclus !\n");
        printf("Dans quel LIGNE voulez vous jouez ? Les colonnes vont de 1 a 9 inclus : ");
        scanf("%d",&ligne_choisi);
    }

    // CHOIX DU NOMBRE A INSCRIRE DANS LA CASE CHOISI  
    printf("Quel NOMBRE voulez vous ECRIRE dans le tableau  a la case indiqué ??  : ");
    scanf("%d",&nombre_choisi);
    while (! (1 <= nombre_choisi && nombre_choisi <= 9) ){
        printf("C'est un choix entre 1 et 9 inclus !\n");
        printf("Dans quel NOMBRE voulez vous jouez ? Les colonnes vont de 1 a 9 inclus : ");
        scanf("%d",&nombre_choisi);
    }

    printf("\nDonc LA CASE CHOISI EST : %d-%d \n", colonne_choisi, ligne_choisi );
    printf("la case DEVIENT : %d \n", nombre_choisi);

    grille[ligne_choisi-1][colonne_choisi-1]= nombre_choisi;

    afficher_grille(grille);
}


int sans_conflit(int grille[9][9], int grilleAnalyse){
    //----------------------------COMPARAISON HORIZONTAL--------------------------------
    int aucun_conflitHORI=0;
    int conflitHORI=0;
    int aucun_conflitVERT=0;
    int conflitVERT=0;
    //int grilleAnalyse=0;


    for(int ligne = 0; ligne < 9; ligne++)
    {
        // Copie de chaque LIGNE De la Grille 
        int copy_ligne_tableauHORI[9];
        for(int colonne = 0; colonne < 9; colonne++)
        {
            copy_ligne_tableauHORI[colonne]=grille[ligne][colonne];   
        }    

        // TRIAGE PAR ORDRE 
        for (int i = 0; i < 9-1; i++){       

            for (int j = 0; j < 9-i-1; j++){

                if (copy_ligne_tableauHORI[j] > copy_ligne_tableauHORI[j+1]) 
                {
                    int temp = copy_ligne_tableauHORI[j]; 
                    copy_ligne_tableauHORI[j] = copy_ligne_tableauHORI[j+1]; 
                    copy_ligne_tableauHORI[j+1] = temp; 
                }
            } 
        }

        //GESTION CONFLIT HORIZONTAL 
        for (int j = 0; j < 8; j++) {     
            if(copy_ligne_tableauHORI[j] != copy_ligne_tableauHORI[j+1]) {
                
                aucun_conflitHORI=1;
            }     
            else{
                conflitHORI =1;   
            }
        }   
        
    }

    //COMPARAISON VERTICALE
    //printf("-----------------------VERTICAL---------------------------\n");

    for (int ligne = 0; ligne < 9; ligne++){
        

        // Copie de chaque LIGNE du tableau dans un NOUVEAU Tableau a 2 DIMENSION DONT LES COLONNE DEVIENNENT DES LIGNES ! Le sens change! 
        int copy_ligne_tableauVERT2D[9][9];
        for(int colonne = 0; colonne < 9; colonne++)
        {
            copy_ligne_tableauVERT2D[ligne][colonne]=grille[colonne][ligne];   
        } 

        //CONVERSION DE CETTE COPIE A 2 DIMENSION avec le sens changer EN UN TABLEAU A 1 DIMENSION  
        int copy_ligne_tableauVERT1D[9];
        for(int colonne = 0; colonne < 9; colonne++)
        {
            copy_ligne_tableauVERT1D[colonne]=copy_ligne_tableauVERT2D[ligne][colonne];   
        } 


        // TRIAGE PAR ORDRE CROISSANT     
        for (int i = 0; i < 9-1; i++){       

            for (int j = 0; j < 9-i-1; j++){

                if (copy_ligne_tableauVERT1D[j] > copy_ligne_tableauVERT1D[j+1]) 
                {
                    int temp = copy_ligne_tableauVERT1D[j]; 
                    copy_ligne_tableauVERT1D[j] = copy_ligne_tableauVERT1D[j+1]; 
                    copy_ligne_tableauVERT1D[j+1] = temp; 
                }
            } 
        }


        //GESTION CONFLIT HORIZONTAL 
        for (int j = 0; j < 8; j++) {     
            if(copy_ligne_tableauVERT1D[j] != copy_ligne_tableauVERT1D[j+1]) {
                
                aucun_conflitVERT=1;
            }     
            else{
                conflitVERT =1;
            }
        }   
        
    }

    // -----CONDITION---------
    if( conflitVERT == 0 && conflitHORI == 0 && aucun_conflitVERT==1 && aucun_conflitHORI==1) {
        //printf("\n CEST GOOD ");
        grilleAnalyse=1;
        return grilleAnalyse ;
    }
    if (conflitVERT == 1 || conflitHORI==1) 
    {
        //printf("\n thats NO GOOD  ");
        grilleAnalyse=0;
        return grilleAnalyse;
    }
    printf("\n");
}



int sans_conflit_voisines(int grille[9][9], int grilleAnalyseCELLULE){
    int decallage_ligne=0;
    
    int aucun_conflitCAR_GAUCHE=0;
    int conflitCAR_GAUCHE=0;
    int aucun_conflitCAR_MILIEU=0;
    int conflitCAR_MILIEU=0;
    int aucun_conflitCAR_DROITE=0;
    int conflitCAR_DROITE=0;

    int copy_ligne_tableauCELL[9];
    //int grilleAnalyseCELLULE=0;



    for(int ligne = 0; ligne < 3; ligne ++)
    {    
       
       int j=0;
       
       //---------------------CARRE DE GAUCHE , CARRE 1-4-7 |-------------------------------------- 
        for (int i = 0; i < 3; i++){  
            for(int colonne = 0; colonne < 3; colonne++)
            {
                copy_ligne_tableauCELL[j]=grille[i+decallage_ligne][colonne]; 
                j++;
            } 
        }


        // TRIAGE PAR ORDRE DE 1 a 9 
        for (int i = 0; i < 9-1; i++){       

            for (int j = 0; j < 9-i-1; j++){

                if (copy_ligne_tableauCELL[j] > copy_ligne_tableauCELL[j+1]) 
                {
                    int temp = copy_ligne_tableauCELL[j]; 
                    copy_ligne_tableauCELL[j] = copy_ligne_tableauCELL[j+1]; 
                    copy_ligne_tableauCELL[j+1] = temp; 
                }
            } 
        }

        //GESTION CONFLIT CELLULE GAUCHE 1-4-7 
        for (int j = 0; j < 8; j++) {     
            if(copy_ligne_tableauCELL[j] != copy_ligne_tableauCELL[j+1]) {
                
                aucun_conflitCAR_GAUCHE=1;
            }     
            else{
                conflitCAR_GAUCHE =1;   

            }
        }   


        //--------CARRE DU MILIEU , CARRE 2-5-8 |-------------------------------------- 
        j=0;
        for (int i = 0; i < 3; i++){  
            for(int colonne = 3; colonne < 6; colonne++)
            {
                copy_ligne_tableauCELL[j]=grille[i+decallage_ligne][colonne];   
                
                j++;
            } 
        }
        
        // TRIAGE PAR ORDRE DE 1 a 9 
        for (int i = 0; i < 9-1; i++){       

            for (int j = 0; j < 9-i-1; j++){

                if (copy_ligne_tableauCELL[j] > copy_ligne_tableauCELL[j+1]) 
                {
                    int temp = copy_ligne_tableauCELL[j]; 
                    copy_ligne_tableauCELL[j] = copy_ligne_tableauCELL[j+1]; 
                    copy_ligne_tableauCELL[j+1] = temp; 
                }
            } 
        }

        //GESTION CONFLIT CELLULE MILIEU  2-5-8 
        for (int j = 0; j < 8; j++) {     
            if(copy_ligne_tableauCELL[j] != copy_ligne_tableauCELL[j+1]) {
                
                aucun_conflitCAR_MILIEU=1;
            }     
            else{
                conflitCAR_MILIEU =1;   
            }
        }   


        //--------CARRE DE DROITE CARRE 3-6-9 |-------------------------------------- 
        j=0;
        for (int i = 0; i < 3; i++){  
            for(int colonne = 6; colonne < 9; colonne++)
            {
                copy_ligne_tableauCELL[j]=grille[i+decallage_ligne][colonne];   
                j++;
            } 
        }
  
         // TRIAGE PAR ORDRE DE 1 a 9 
        for (int i = 0; i < 9-1; i++){       

            for (int j = 0; j < 9-i-1; j++){

                if (copy_ligne_tableauCELL[j] > copy_ligne_tableauCELL[j+1]) 
                {
                    int temp = copy_ligne_tableauCELL[j]; 
                    copy_ligne_tableauCELL[j] = copy_ligne_tableauCELL[j+1]; 
                    copy_ligne_tableauCELL[j+1] = temp; 
                }
            } 
        }      

        //GESTION CONFLIT CELLULE DROITE  3-6-9 
        for (int j = 0; j < 8; j++) {     
            if(copy_ligne_tableauCELL[j] != copy_ligne_tableauCELL[j+1]) {
                
                aucun_conflitCAR_DROITE=1;
            }     
            else{
                conflitCAR_DROITE =1;   
                
            }
        }   

        decallage_ligne=decallage_ligne+3;
    
    }


    if( conflitCAR_GAUCHE == 0 && conflitCAR_MILIEU == 0 && conflitCAR_DROITE==0 && aucun_conflitCAR_GAUCHE==1 
        && aucun_conflitCAR_MILIEU==1 && aucun_conflitCAR_DROITE==1) 
        {
        //printf("\n CEST bon ");
        grilleAnalyseCELLULE=1;
        return grilleAnalyseCELLULE ;
    }

    if (conflitCAR_GAUCHE == 1 || conflitCAR_MILIEU==1 || conflitCAR_DROITE==1) 
    {
        //printf("\n Cest pas bon  ");
        grilleAnalyseCELLULE=0;
        return grilleAnalyseCELLULE;
    }
}



int correct_emplacement(int grille_alea[9][9], int ligne_alea, int colonne_alea, int numero_alea) {
    int i, j;
    for (i = 0; i < 9; i++) { //On compare le nombre avec tout les chiffre sur la colonne ou la ligne
        if (grille_alea[ligne_alea][i] == numero_alea || grille_alea[i][colonne_alea] == numero_alea) 
        {
            return 0; //si cest faux 
        }
    }


    for (i = 0; i < 3; i++) { // Donc cest un carré on fait 3
        for (j = 0; j < 3; j++) 
        {

            // On cherche a voir petit a petit que sa apparait pas de nouveau dans le meme carré 3x3 et pas tout le tableau
            int debut_analyse_ligne=0;
            if (ligne_alea== 0 ||ligne_alea== 1 || ligne_alea== 2 )
            {
                debut_analyse_ligne=0;
            }
            else if (ligne_alea== 3 ||ligne_alea== 4 || ligne_alea== 5 )
            {
                debut_analyse_ligne=3;
            }
            else{
                debut_analyse_ligne=6;
            }
        

            int debut_analyse_colonne = 0 ;
            if (colonne_alea== 0 ||colonne_alea== 1 || colonne_alea== 2 )
            {
                debut_analyse_colonne=0;
            }
            else if (colonne_alea== 3 ||colonne_alea== 4 || colonne_alea== 5 )
            {
                debut_analyse_colonne=3;
            }
            else{
                debut_analyse_colonne=6;
            }

            if (grille_alea[debut_analyse_ligne + i ][debut_analyse_colonne + j ] == numero_alea) { // donc on avance de 3 maximum et descend de 3 maximum pour faire les carré 
                return 0; //si cest faux 
            }
        }
    }

    // Si il y a aucune erreur et donc le nombre est correct et on retourne 1
    return 1;
}







int resolveur_grille_alea(int grille_alea[9][9], int ligne_alea, int colonne_alea) {
    int i;

    
    if (colonne_alea == 0 && ligne_alea == 9 ) { // si on est sur la premiere case en dehors du tableau
        return 1;               // on return 1 , ca veut dire que la case [8][8] a ete faite sinon elle se fait pas
    }
    else if (colonne_alea == 9) 
    {
        return resolveur_grille_alea(grille_alea, ligne_alea + 1, 0); // si on est passé sur la derniere colonne on revient en arrière , 8 sa aurait pas fait 
    }
    
    


    if (grille_alea[ligne_alea][colonne_alea] != 0 ) 
    {
        return resolveur_grille_alea(grille_alea, ligne_alea, colonne_alea + 1); // si le nombre est different de 0 donc sa veut dire quil a ete modifier on avance 
    }


    for (i = 1; i <= 9; i++) {
        int numero_a_inserer= i;
        if (correct_emplacement(grille_alea, ligne_alea, colonne_alea, numero_a_inserer)) 
        {
            //printf("LIGNE OU ON PLACE: %d, \n COLONNE OU ON PLACE : %d, NUMERO QUON PLACE :%d\n", ligne_alea,colonne_alea,numero_a_inserer);
            
            grille_alea[ligne_alea][colonne_alea] = numero_a_inserer; // on essaie de placer les numero dans lordre mais on verifie que sa pose pas de probleme et on continue 
            //afficher_grille(grille_alea);
            if (resolveur_grille_alea(grille_alea, ligne_alea, colonne_alea + 1)) 
            {
                return 1;
            }
            grille_alea[ligne_alea][colonne_alea] = 0; // si ca marche ps on revient a letat initial et on retounre 0 pour indiquer que ca marche pas 
        }
    }
    return 0;
}







int generateur_grille_alea() {
    int i, j;
    int grille_alea[9][9];
    srand(time(0)); // initialise la fonction random

    // On rempli le tout avec le nombre 0 
    for (i = 0; i < 9; i++) {
        for (j = 0; j < 9; j++) {
            grille_alea[i][j] = 0;
        }
    } 

    // On va remplir quelque case de la grille aleatoirement  pour recrer artificiellement les .txt qui ont de base des nombre place au hasard
    //ca va aider a remplir et a completer
    for (i = 0; i < 9; i++) {
        for (j = 0; j < 9; j++) {

            if (rand() % 9 == 0) {// Ici on fait un radom qui a une chance de 1/9 detre egale a 0
                int nb_alea_des_debut = rand() % 9 + 1; // si cest le cas on met un nombre a leatoire en 1 et 9
                if (correct_emplacement(grille_alea, i, j, nb_alea_des_debut)) {
                    grille_alea[i][j] = nb_alea_des_debut; // les conditions sont bonnes on rempli
                }
            }
        }
    }

    

    // Et la on complete en commencant par [0][0] si la ca bloque cest que cest pas possible 
    resolveur_grille_alea(grille_alea, 0, 0);

    //enregistrement de la grille solution dans un fichier txt 
    
    
    char *nom_fichier_grille= "grille_generer_alea_solution.txt";
    char* nom_fichier_sauvegarde = "sauvegarde_Niveau_Alea.txt";
    ecrire_grille(nom_fichier_grille,grille_alea); 


    //on place un nombre de 0 aleatoire qui seront les case a completer plus tard par le joueur et on lenregistre plus tard 
    
    int nb_cases_vides = rand() % 35+ 20 ; // donc entre 20 et 45  numero 0 a placer 
    //nb_cases_vides = 0;  //ici pour calibrer le nb de case vide pour test
    
    while (0<nb_cases_vides)
    {
        int ligne_vide= rand() % 9 + 1; // ligne et colonne aleatoire
        int colonne_vide= rand() % 9 + 1;
        grille_alea[ligne_vide][colonne_vide] = 0;  // et la case devient 0

        nb_cases_vides--;
    }
    

    nom_fichier_grille= "grille_generer_alea.txt";
    nom_fichier_sauvegarde = "sauvegarde_Niveau_Alea.txt";
    ecrire_grille(nom_fichier_grille,grille_alea); 

    return 0;
}









int main()
{
    char *nom_fichier_grille; 
    char *nom_fichier_sauvegarde;
    nom_fichier_sauvegarde = "sauvegarde.txt";
    int grille[9][9];
    int grille_rempli[9][9];
    int grilleAnalyse=0;
    int grilleAnalyseCELLULE=0;

    int rejouer1=1;
    int rejouer2=1;    

    //---------- INTRODUCTION DU JEU ----------------------

    while (rejouer1 == 1 && rejouer2 == 1){

        printf("\n-----------------------------------------------------------------------------------------------------------------------------\n");
        printf("------------------------- !!! SUDOKU !!! Par D-TheProgrammer ----------------------------------------------\n");
        printf("-----------------------------------------------------------------------------------------------------------------------------\n");    
        printf("\n");
        printf("\n");  

        regles();
        printf("\n"); 
        printf("\n"); 

        comment_jouer();
        printf("\n"); 
        printf("\n"); 

    //---------- MENU PRINCIPAL ----------------------
        int choixJoueurMenu=0;
        int choixNiveau=0;
        printf("Bienvenue dans le Sudoku !! Tout d'abord petite question\n");
        while (! (0<choixJoueurMenu && choixJoueurMenu <=3)){
            printf("Voulez -vous ?\n");
            printf("---------------------------------------------------------------------------------------------------------\n");
            printf("| 1 :  Jouer au jeux Normalement   |   2 :  Charger et Reprendre Une Partie   | 3 :  Quitter le Jeux    |\n");
            printf("---------------------------------------------------------------------------------------------------------\n");
            scanf("%d",&choixJoueurMenu);
        }
        
        //---------- Choix du niveau de jeux ----------------------
        if (choixJoueurMenu==1){
            while (! (0<choixNiveau && choixNiveau <=6)){
                printf("\n"); 
                printf("Quel niveau voulez vous faire ? Veuillez choisir en indiquant le bon numéro\n");
                printf("-------------------------------------------------------------------------------------------------------------------------------------------------\n");
                printf("| 1 :  Tester Avec une Grille Victorieuse  |  2 : Facile   |  3 : Moyen   |  4 : Difficile   |  5 : Grille Aleatoire   |  6 : Retour en arriere |\n");
                printf("-------------------------------------------------------------------------------------------------------------------------------------------------\n");
                scanf("%d",&choixNiveau);
            }
        }

        //---------- Attribution de la grille selon le niveau de jeu ----------------------
        if (choixJoueurMenu==1){

            int partie=1;
            int print_grile_1fois=1;
            int choix_in_game=0;


            if (choixNiveau==1){
                nom_fichier_grille= "grille_victorieuse.txt";
                nom_fichier_sauvegarde = "sauvegarde_Niveau0.txt";
                lire_grille(nom_fichier_grille,grille);
            }
            
            if (choixNiveau==2){
                nom_fichier_grille= "grille_facile.txt";
                nom_fichier_sauvegarde = "sauvegarde_Niveau1.txt";
                lire_grille(nom_fichier_grille,grille);
            }

            if (choixNiveau==3){
                nom_fichier_grille= "grille.txt"; 
                nom_fichier_sauvegarde = "sauvegarde_Niveau2.txt";
                lire_grille(nom_fichier_grille,grille);
            }
            if (choixNiveau==4){
                nom_fichier_grille= "grille_difficile.txt";
                nom_fichier_sauvegarde = "sauvegarde_Niveau3.txt";
                lire_grille(nom_fichier_grille,grille);
            }

            if (choixNiveau==5){
                generateur_grille_alea();
                nom_fichier_grille= "grille_generer_alea.txt";
                nom_fichier_sauvegarde = "sauvegarde_Niveau_Alea.txt";
                lire_grille(nom_fichier_grille,grille);
            }

            if (choixNiveau==6){
                choixJoueurMenu=0;
                partie=0;
            }

            
            while (partie==1){
                int choix_in_game=0;

                if(print_grile_1fois==1){
                    afficher_grille(grille);
                    print_grile_1fois=0;
                }

                jouer(grille);

                //---------- Choix une fois la grille commencer ----------------------

                while (! (0<choix_in_game && choix_in_game <=6)){
                    printf("\n"); 
                    printf("Que voulez vous faire ?  ATTENTION IL Y A 2 LIGNE DE CHOIX! Veuillez choisir en indiquant le bon numéro\n");
                    printf("-----------------------------------------------------------------------------------------------------------------------------------------------\n");
                    printf("| 1 :  Continuer A Jouer  |  2 : Sauvegarder et Continuer A joueur   |  3 :   Sauvegarder et Arreter de Jouer   |  4: Quitter Sans Sauvegarder |\n");
                    printf("------------------------------------------------------------------------------------------------------------------------------------------------\n");
                    printf("| 5:  Verifier si la grille est bien rempli et voir si tu as gagner  |  6 :  Utiliser le Solver pour Resoudre la Grille  |\n");
                    printf("--------------------------------------------------------------------------------------------------------------------------\n");
                    
                    scanf("%d",&choix_in_game);

                }

                if (choix_in_game==2)//---------- Sauvegarder et jouer ----------------------
                {
                    ecrire_grille(nom_fichier_sauvegarde,grille);
                }

                if (choix_in_game==3) //---------- Sauvegarder et quitter ----------------------
                {
                    ecrire_grille(nom_fichier_sauvegarde,grille);
                    partie=0;
                }
                
                if (choix_in_game==4) //---------- Quitter  ----------------------
                {
                    partie=0;
                }

                if (choix_in_game==5) //---------- Verifier la grille  ----------------------
                {
                    grilleAnalyse=sans_conflit(grille,grilleAnalyse);
                
                    grilleAnalyseCELLULE=sans_conflit_voisines(grille,grilleAnalyseCELLULE);
                
                    if (grilleAnalyse == 1 && grilleAnalyseCELLULE==1 ){
                        printf("\n BRAVO TU AS TROUVER LA SOLUTION !!!!\n");
                        partie=0;
                    }
                    
                    else{
                        printf("Malheureusement tu n'as pas trouver la solution\n");
                    }
                }


                if (choix_in_game==6){ //---------- Solveur de la grille  ----------------------  
                    resolveur_grille_alea(grille, 0, 0);
                    printf("\n Vous avez utilisez le solveur !!!\n");
                    afficher_grille(grille);

                    grilleAnalyse=sans_conflit(grille,grilleAnalyse);
                
                    grilleAnalyseCELLULE=sans_conflit_voisines(grille,grilleAnalyseCELLULE);
                
                    if (grilleAnalyse == 1 && grilleAnalyseCELLULE==1 ){
                        printf("\n IL AS TROUVER LA SOLUTION !!!!\n");
                        partie=0;
                    }
                    
                    else{
                        printf("Malheureusement il n'as pas trouver la solution\n");
                    }
                }
            }


        
            if (choixNiveau != 6){ //---------- Demande pour Rejouer  ----------------------

                rejouer1= 0;
                while (! (0<rejouer1 && rejouer1 <=2)){
                    printf("Attention Voulez-vous  rejouer ?  Veuillez choisir en indiquant le bon numero\n");
                    printf("-------------------------\n");
                    printf("| 1 :  OUI |  2 : NON   |  \n");
                    printf("-------------------------\n");
                    scanf("%d",&rejouer1);

                }

                printf("\n");

                if (rejouer1 == 1) {
                    printf("Tres bien c'est reparti! Voici les consignes !!\n");
                    rejouer1=1;
                }
                if (rejouer1 == 2) {
                    printf("Merci beaucoup d'avoir jouer !! Au revoir \n");
                    rejouer1= 0; 
                }
            }   
        }


        //----------  Choix de la sauvegarde ----------------------
        if (choixJoueurMenu==2){
            while (! (0<choixNiveau && choixNiveau <=6)){
                printf("\n"); 
                printf("Quel Sauvegarde de niveau voulez vous lancer ? Veuillez choisir en indiquant le bon numero ATTENTION il y a 2 lignes \n");
                printf("---------------------------------------------------------------------------------------------------------------\n");
                printf("| 1 :  Tester Avec une Grille Victorieuse  |  2 : Sauvegarde Niveau Facile   |  3 : Sauvegarde Niveau Moyen   |\n");
                printf("---------------------------------------------------------------------------------------------------------------\n");
                printf("| 4 : Sauvegarde Niveau Difficile   | 5 : Sauvegarde Grille Aleatoire   | 6 : Retour en arriere |\n");
                printf("-------------------------------------------------------------------------------------------------\n");
                scanf("%d",&choixNiveau);
            }
        }


        if (choixJoueurMenu==2){

            int partie=1;
            int print_grile_1fois=1;
            int choix_in_game=0;
            
            //----------  Verification si les fichier sont Vide , sil sont vide on retourne en arriere SINON la grille est charger ----------------------
            if (choixNiveau==1){
                nom_fichier_grille= "sauvegarde_Niveau0.txt";
                nom_fichier_sauvegarde = "sauvegarde_Niveau0.txt";
                int vide_Ou_Pas=lire_grille_vide(nom_fichier_grille);
                if ( vide_Ou_Pas == 0){
                    partie=0;
                    printf("\n");
                }
                lire_grille(nom_fichier_grille,grille);
                
            }
            
            if (choixNiveau==2){
                nom_fichier_grille= "sauvegarde_Niveau1.txt";
                nom_fichier_sauvegarde = "sauvegarde_Niveau1.txt";
                int vide_Ou_Pas=lire_grille_vide(nom_fichier_grille);
                if ( vide_Ou_Pas == 0){
                    partie=0;
                    printf("\n");
                }
                lire_grille(nom_fichier_grille,grille);
            }

            if (choixNiveau==3){
                nom_fichier_grille= "sauvegarde_Niveau2.txt"; 
                nom_fichier_sauvegarde = "sauvegarde_Niveau2.txt";
                int vide_Ou_Pas=lire_grille_vide(nom_fichier_grille);
                if ( vide_Ou_Pas == 0){
                    partie=0;
                    printf("\n");
                }
                lire_grille(nom_fichier_grille,grille);
            }

            if (choixNiveau==4){
                nom_fichier_grille= "sauvegarde_Niveau3.txt";
                nom_fichier_sauvegarde = "sauvegarde_Niveau3.txt";
                int vide_Ou_Pas=lire_grille_vide(nom_fichier_grille);
                if ( vide_Ou_Pas == 0){
                    partie=0;
                    printf("\n");
                }
                lire_grille(nom_fichier_grille,grille);
            }


            if (choixNiveau==5){
                nom_fichier_grille= "sauvegarde_Niveau_Alea.txt";
                nom_fichier_sauvegarde = "sauvegarde_Niveau_Alea.txt";
                int vide_Ou_Pas=lire_grille_vide(nom_fichier_grille);
                if ( vide_Ou_Pas == 0){
                    partie=0;
                    printf("\n");
                }
                lire_grille(nom_fichier_grille,grille);
            }


            if (choixNiveau==6){
                choixJoueurMenu=0;
                partie=0;
            }

            
            while (partie==1){
                int choix_in_game=0;

                if(print_grile_1fois==1){
                    afficher_grille(grille);
                    print_grile_1fois=0;
                }

                jouer(grille);

                while (! (0<choix_in_game && choix_in_game <=6)){
                    printf("\n"); 
                    printf("Que voulez vous faire ?  ATTENTION IL Y A 2 LIGNE DE CHOIX! Veuillez choisir en indiquant le bon numéro\n");
                    printf("-----------------------------------------------------------------------------------------------------------------------------------------------\n");
                    printf("| 1 :  Continuer A Jouer  |  2 : Sauvegarder et Continuer A joueur   |  3 :   Sauvegarder et Arreter de Jouer   |  4: Quitter Sans Sauvegarder |\n");
                    printf("------------------------------------------------------------------------------------------------------------------------------------------------\n");
                    printf("| 5:  Verifier si la grille est bien rempli et voir si tu as gagner  |  6 :  Utiliser le Solver pour Resoudre la Grille  |\n");
                    printf("--------------------------------------------------------------------------------------------------------------------------\n");
                    
                    scanf("%d",&choix_in_game);

                }

                if (choix_in_game==2)
                {
                    ecrire_grille(nom_fichier_sauvegarde,grille); //---------- Continuer a jouer ----------------------
                }

                if (choix_in_game==3)
                {
                    ecrire_grille(nom_fichier_sauvegarde,grille);//---------- Sauvegarder et jouer ----------------------
                    partie=0;
                }
                if (choix_in_game==4)
                {
                    partie=0; //---------- Quitter ----------------------
                }

                if (choix_in_game==5)//---------- Verifier la grille  ----------------------  
                {
                    grilleAnalyse=sans_conflit(grille,grilleAnalyse);
                
                    grilleAnalyseCELLULE=sans_conflit_voisines(grille,grilleAnalyseCELLULE);
                
                    if (grilleAnalyse == 1 && grilleAnalyseCELLULE==1 ){
                        printf("\n BRAVO TU AS TROUVER LA SOLUTION !!!!\n");
                        partie=0;
                    }
                    
                    else{
                        printf("Malheureusement tu n'as pas trouver la solution\n");
                    }
                }


                if (choix_in_game==6){//---------- Solveur de la grille  ----------------------  
                    resolveur_grille_alea(grille, 0, 0);
                    printf("\n Vous avez utilisez le solveur !!!\n");
                    afficher_grille(grille);

                    grilleAnalyse=sans_conflit(grille,grilleAnalyse);
                
                    grilleAnalyseCELLULE=sans_conflit_voisines(grille,grilleAnalyseCELLULE);
                
                    if (grilleAnalyse == 1 && grilleAnalyseCELLULE==1 ){
                        printf("\n IL  A TROUVER LA SOLUTION !!!!\n");
                        partie=0;
                    }
                    
                    else{
                        printf("Malheureusement il n'a pas trouver la solution\n");
                    }
                }
    


            }

            
       
            if (choixNiveau != 6){ //---------- Demande pour Rejouer  ----------------------

                rejouer2= 0;
                while (! (0<rejouer2 && rejouer2 <=2)){
                    printf("Attention Voulez-vous  rejouer ?  Veuillez choisir en indiquant le bon numero\n");
                    printf("-------------------------\n");
                    printf("| 1 :  OUI |  2 : NON   |  \n");
                    printf("-------------------------\n");
                    scanf("%d",&rejouer2);
                }

                printf("\n");

                if (rejouer2 == 1) {
                    printf("Tres bien c'est reparti! Voici les consignes !!\n");
                    rejouer2=1;
                }
                if (rejouer2 == 2) {
                    printf("Merci beaucoup d'avoir jouer !! Au revoir \n");
                    rejouer2= 0; 
                }
            }
        }


        if (choixJoueurMenu==3){
            printf("Merci d'avoir lancer ce programme");
            return 1;
        }
        printf("\n"); 
        printf("\n");
        printf("\n"); 
    } 
    return 0;
}

