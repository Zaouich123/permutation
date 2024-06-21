#include "p_base.h"
#include <stdio.h>
#include <time.h>
#include <stdlib.h>

int aleatoire_entre_a_et_b(int a_inclus, int b_exclu){


    time_t t;
    srand((unsigned) time(&t));
    int n = rand()%b_exclu + a_inclus;
    return n;
}

void identite_tableau(int* ceci, int nb_elements){
    ceci = (int*)malloc(sizeof(int) * nb_elements);
    for(int i=0;i<nb_elements;i++){
        ceci[i] = i;
    }
}

void echanger_tableau(int* ceci, int position_1, int position_2){
    int tmp;
    tmp=ceci[position_1];
    ceci[position_1]=ceci[position_2];
    ceci[position_2]=tmp;
}

void croiser_tableau(int* tab, int nb_elements){
    for (int i = 0; i < nb_elements / 2; i++)
    {
        echanger_tableau(tab, i, nb_elements - i - 1);
    }
}

void copier_tableau(int* tab, int* dans, int nb_elements){
    for(int i=0; i<nb_elements; i++){
        dans[i]=tab[i];
    }
}

void copier_croisement_tableau(int* tab, int* dans, int nb_elements){
    copier_tableau(tab,dans,nb_elements);
    croiser_tableau(dans,nb_elements);
}

int est_inferieur_strict_tableau(int* ceci, int* cela, int nb_elements){ 
    for(int i=0; i<nb_elements; i++){
        if(ceci[i]<cela[i]){
            return 1;
        }
    }
    return 0;
}