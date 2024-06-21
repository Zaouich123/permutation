#ifndef P_BASE_H
#define P_BASE_H
/**
 * @file p_base.h
 * @author Weinberg Benjamin
 * @brief contient des fonctions utilitaires simples.
 * @version 0.1
 * @date 2022-07-20
 * 
 * @copyright Copyright (c) 2022
 * 
 */

/**
 * @brief le t_boolean servira à manipuler des valeurs
 * pouvant servir de condition en C.
 *      * 0 : FAUX;
 *      * 1 : VRAI.
 * De nombreuses fonctions de cette bibliothèque retourne un t_boolean :
 *      * FAUX : la fonction s'est mal déroulée (les Conditions d'utilisation ne sont pas remplies);
 *      * VRAI : la fonction s'est bien déroulée (les Conditions d'utilisation sont remplies).
 */
typedef enum e_boolean{FALSE = 0, TRUE = 1}t_boolean;

/**
 * @brief retourne un entier compris entre <a_inclus> et <b_exclu>.
 * @warning la borne <a_inclus> est une valeur possible de la fonction or
 * la borne <b_exclu> ne peut pas être retournée par la fonction.
 *  
 * @param a_inclus : la borne inférieur de l'intervalle de valeur.
 * @param b_exclu : la borne supérieur de l'intervalle de valeur.
 * @return int 
 */
int aleatoire_entre_a_et_b(int a_inclus, int b_exclu);

/**
 * @brief initialiser le contenu du tableau <ceci> avec les valeurs allant de 0 <nb_elements>-1.
 * 
 * @param ceci l'adresse du tableau à initialiser
 * @param nb_elements la taille du tableau.
 */
void identite_tableau(int* ceci, int nb_elements);

/**
 * @brief echange les valeurs indicées par <position_1> et <position_2> dans <ceci>.
 * 
 * @param ceci le tableau contenant les valeurs à intervertir.
 * @param position_1 : l'indice du premier élément à intervertir.
 * @param position_2 : l'indice du second élément à intervertir.
 */
void echanger_tableau(int* ceci, int position_1, int position_2);

/**
 * @brief inverse les <nb_entiers> premiers entiers pointés par l'adresse <tab>.
 * 
 * @param tab le tableau à inverser
 * @param nb_elements le nombre d'entiers dont la disposition est inversés.
 */
void croiser_tableau(int* tab, int nb_elements);

/**
 * @brief copie <nb_entiers> entiers pointés par l'adresse <tab> à l'adresse pointée par <dans>.
 * 
 * @param tab la source
 * @param dans la destination
 * @param nb_elements le nombre d'entiers copiés.
 */
void copier_tableau(int* tab, int* dans, int nb_elements);

/**
 * @brief copie <nb_entiers> entiers pointés par l'adresse <tab> à l'adresse pointée par <dans> mais en inversant l'ordre des éléments.
 * 
 * @param tab la source
 * @param dans la destination
 * @param nb_elements le nombre d'entiers copiés.
 */
void copier_croisement_tableau(int* tab, int* dans, int nb_elements);

/**
 * @brief retourne 1 si <ceci> est inférieur à <cela> relativement à l'ordre lexicographique.
 * 
 * @param ceci 
 * @param cela 
 * @param nb_elements 
 * @return int 
 */
int est_inferieur_strict_tableau(int* ceci, int* cela, int nb_elements);

#endif