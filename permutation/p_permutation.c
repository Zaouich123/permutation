#include "p_permutation.h"
#include "p_base.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int nombre_permutation = 0;


t_boolean initialiser_p_permutation(int taille){
    
    if(nombre_permutation == 0){

        nombre_permutation = taille;
        return TRUE;
    }
    else{
        return FALSE;
    }
}

t_boolean est_p_permutation_initialise(){
    if(nombre_permutation == 0){
        return FALSE;
    }
    else{
        return TRUE;
    }

}

t_boolean donner_taille_permutation(int* taille){

    if(!est_p_permutation_initialise()){
        return FALSE;
    }

    *taille = nombre_permutation;

    return TRUE;
}

t_boolean initialiser_permutation(t_permutation* ceci){

    if(ceci == NON_INITIALISE_PERMUTATION){
        return FALSE;
    }

    *ceci = (t_permutation)malloc(sizeof(int)* nombre_permutation);
    
    for (int i = 0; i < nombre_permutation; i++){
        (*ceci)[i] = i;
    }

    return TRUE;
}


t_boolean finaliser_permutation(t_permutation* ceci){

    if(ceci == NON_INITIALISE_PERMUTATION){
        return FALSE;
    }

    free(*ceci);
    return TRUE;
}


t_boolean identite_permutation(t_permutation ceci){

    if(ceci == NON_INITIALISE_PERMUTATION){
        return FALSE;
    }

    identite_tableau((int*)ceci, nombre_permutation);


    return TRUE;

}


t_boolean copier_permutation(t_permutation ceci, t_permutation cela){

    if(ceci == NON_INITIALISE_PERMUTATION && cela == NON_INITIALISE_PERMUTATION){
        return FALSE;
    }
    copier_tableau((int*)ceci,(int*)cela, nombre_permutation);


    return TRUE;
}


t_boolean debugger_permutation(t_permutation ceci){

    if(ceci == NON_INITIALISE_PERMUTATION){
        return FALSE;
    }
    printf("[ ");
    for(int i =0; i<nombre_permutation; i++){
        printf("%d ", ceci[i]);
    }
    printf("]\n");

    return TRUE;
}


t_boolean est_indice_valide(int position){
    
    if(position >= 0 && position < nombre_permutation){
        return TRUE;
    }
    else{
        return FALSE;
    }

}


t_boolean melanger_permutation(t_permutation ceci){
    if (!est_p_permutation_initialise()){
        return FALSE;
    }
    time_t t;
    srand((unsigned) time(&t));
    int tmp;
    for (int i = 0; i < nombre_permutation; i++){

        int j = rand() % nombre_permutation;
        tmp = ceci[i];
        ceci[i] = ceci[j];
        ceci[j] = tmp;
    }
    return TRUE;
}

t_boolean reciproque_permutation(t_permutation ceci, t_permutation cela){
    
    if(ceci == NON_INITIALISE_PERMUTATION){
        return FALSE;
    }
     if(cela == NON_INITIALISE_PERMUTATION){
        initialiser_permutation(&cela);

    }

    for(int i=0; i<nombre_permutation;i++){
        cela[ceci[i]] = i;
    }

    return TRUE;

}

t_boolean est_permutation_valide(t_permutation ceci){
   
    t_permutation check_double = (int*)malloc(sizeof(int)*nombre_permutation);


    if(ceci == NON_INITIALISE_PERMUTATION){
        return FALSE;
    }

    for(int i =0; i<nombre_permutation;i++){
        if(ceci[i] > nombre_permutation){
            return FALSE;
        }
        if(check_double[ceci[i]] == 0){
            check_double[ceci[i]]++;
        }else{
            return FALSE;
        }
    }
 
    return TRUE;
    

}

t_boolean est_inferieur_strict(t_permutation ceci, t_permutation cela){
    
    if(ceci == NON_INITIALISE_PERMUTATION){
        return FALSE;
    }

    if(!est_inferieur_strict_tableau((int*)ceci, (int*)cela, nombre_permutation)){
        return FALSE;
    }
    return TRUE;
}


t_boolean est_point_fixe_permutation(t_permutation ceci, int position){
    
    if(ceci == NON_INITIALISE_PERMUTATION){
        return FALSE;
    }

    if(ceci[position] == position){
        return TRUE;
    }

    return FALSE;

}

int nb_point_fixe(t_permutation ceci){
    if(ceci == NON_INITIALISE_PERMUTATION){
        return FALSE;
    }

    int nb_pf = 0;

    for(int i =0; i<nombre_permutation;i++){
        if(est_point_fixe_permutation(ceci,i)){
            nb_pf++;
        }
    }

    return nb_pf;
}




void inverser(t_permutation ceci, int indice_debut){
    for (int i = indice_debut; i < indice_debut + ((nombre_permutation-indice_debut)/2); i++){
        echanger_tableau(ceci, i, nombre_permutation-1-(i-indice_debut));
    }
}




t_boolean suivante_permutation(t_permutation ceci){


    if(ceci == NON_INITIALISE_PERMUTATION){
        return FALSE;
    }

    int indice = -1;

    int i = nombre_permutation - 1;

    while(ceci[i] >= indice){
        indice = ceci[i];
        i--;
    }

    if(i == -1){
        return FALSE;
    }

    int temp = nombre_permutation;
    int temp_position;

    for(int j=i+1;j<nombre_permutation; j++){
        if((ceci[j]>ceci[i]) && (ceci[j]<temp)){
            temp = ceci[j];
            temp_position = j;
        }
   
    }

    echanger_tableau((int*)ceci, i, temp_position);

    inverser((int*)ceci, i+1);


    return TRUE;

}


t_boolean copier_suivante_permutation(t_permutation ceci, t_permutation cela){
    if (!est_p_permutation_initialise()){
        return FALSE;
    }
    copier_tableau(ceci, cela, nombre_permutation);
    return suivante_permutation(cela);
}




t_boolean code_point_fixe_permutation(t_permutation ceci, int point_fixe, t_permutation cela){
    if (!est_p_permutation_initialise() || !est_point_fixe_permutation(ceci, point_fixe)){
        return FALSE;
    }

    cela[0] = point_fixe;
    for(int i=1; i<nombre_permutation; i++){
        if(i >=point_fixe+1){
            cela[i] = ceci[i];
        }
        else{
            cela[i] = ceci[i-1];
        }

    }


    return TRUE;



}



t_boolean decode_point_fixe_permutation(t_permutation ceci, t_permutation cela, int* point_fixe){
    
    *point_fixe = ceci[0];
    if (!est_p_permutation_initialise()){
        return FALSE;
    }

    cela[*point_fixe] = *point_fixe; 


    for(int i=0; i<nombre_permutation;i++){
        
        if(i < *point_fixe){
            cela[i] = ceci[i+1];
        }
        if(i>*point_fixe){
            cela[i] = ceci[i];
        }
    
    }


    return TRUE;

}

