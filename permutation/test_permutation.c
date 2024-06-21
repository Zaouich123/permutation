#include <stdlib.h>
#include <stdio.h>
#include "p_permutation.h"

void tester_enumeration(){
    t_permutation ma_permutation_1 = NON_INITIALISE_PERMUTATION;
    t_permutation ma_permutation_2 = NON_INITIALISE_PERMUTATION;
    initialiser_permutation(&ma_permutation_1);
    initialiser_permutation(&ma_permutation_2);
    debugger_permutation(ma_permutation_1);
    int somme = nb_point_fixe(ma_permutation_1);
    while(copier_suivante_permutation(ma_permutation_1, ma_permutation_2)){
        if(! est_permutation_valide(ma_permutation_2)){
            debugger_permutation(ma_permutation_2);
            printf("permutation invalide\n");
            exit(-1);
        }
        if(! est_inferieur_strict(ma_permutation_1, ma_permutation_2)){
            debugger_permutation(ma_permutation_2);
            printf("permutation mal rangee\n");
            exit(-1);
        }
        copier_permutation(ma_permutation_2, ma_permutation_1);
        debugger_permutation(ma_permutation_1);
        somme += nb_point_fixe(ma_permutation_1);
    }
    printf("Nb total de points fixes : %d\n", somme);
    finaliser_permutation(&ma_permutation_1);
    finaliser_permutation(&ma_permutation_2);
}

void tester_codage(){
    t_permutation ma_permutation_1 = NON_INITIALISE_PERMUTATION;
    t_permutation ma_permutation_2 = NON_INITIALISE_PERMUTATION;
    t_permutation ma_permutation_3 = NON_INITIALISE_PERMUTATION;
    initialiser_permutation(&ma_permutation_1);
    initialiser_permutation(&ma_permutation_2);
    initialiser_permutation(&ma_permutation_3);
    printf("AVANT tester codage\n");
    melanger_permutation(ma_permutation_1);
    debugger_permutation(ma_permutation_1);
    int ma_taille, j;
    donner_taille_permutation(&ma_taille);
    for(int i = 0; i < ma_taille; i++){
        if(est_point_fixe_permutation(ma_permutation_1, i)){
            code_point_fixe_permutation(ma_permutation_1, i, ma_permutation_2);
            debugger_permutation(ma_permutation_2);
            decode_point_fixe_permutation(ma_permutation_2, ma_permutation_3, &j);
            debugger_permutation(ma_permutation_3);
            printf("%d\n", j);
        }
    }
    finaliser_permutation(&ma_permutation_1);
    finaliser_permutation(&ma_permutation_2);
}

int main(){

    printf("DEBUT du TEST\n");
    if(initialiser_p_permutation(6)){
        printf("initialiser_p_permutation   [ OK ]\n");
    }
    printf("AVANT declaration variable %d\n", est_p_permutation_initialise());
    t_permutation ma_permutation_0 = NON_INITIALISE_PERMUTATION;
    printf("AVANT initialisation variable\n");
    if(initialiser_permutation(&ma_permutation_0)){
        printf("initialiser_permutation(&ma_permutation_0)   [ OK ]\n");
    }
    printf("AVANT affichage variable\n");
    debugger_permutation(ma_permutation_0);
    printf("AVANT melange variable\n");
    melanger_permutation(ma_permutation_0);
    debugger_permutation(ma_permutation_0);
    tester_enumeration();
    tester_codage();
    printf("AVANT finalisation variable\n");
    finaliser_permutation(&ma_permutation_0);
    return 0;
}