/**
 * @file p_permutation.h
 * @author Weinberg Benjamin
 * @brief contient des fonctions utilitaires simples.
 * @version 0.1
 * @date 2022-07-20
 * 
 * @copyright Copyright (c) 2022
 * 
 */

#ifndef P_PERMUTATION_H
#define P_PERMUTATION_H
#include <stdlib.h>
#include "p_base.h"

/**
 * @brief Ce type permet de gère une permutation. 
 * Une permutation est une application bijective de l'ensemble de N objets dans lui-même.
 * Cette application sera représentée par une tableau de N cases,
 * contenant les valeurs toutes les valeurs allant de 0 à N-1.
 * 
 * Une fois initialiser, le nombre d'objets N sera <em>fixe</em>.
 * Attention ! Vous <em>devez</em> ne pas utiliser l'affectation sur les permutations.
 * Vous <strong>utiliserez</stong> la fonction de <em>copie</em> prévu à cet effet.
 */
typedef int* t_permutation;
#define NON_INITIALISE_PERMUTATION NULL

/**
 * @brief Cette fonction doit être utilisée une seule fois dans votre programme pour définir le nombre d'objets concernés dans la permutation.
 * 
 * @param taille : int : la taille des permutations.
 * @return t_boolean : VRAI lors de sa première utilisation ; FAUX sinon.
 */
t_boolean initialiser_p_permutation(int taille);

/**
 * @brief retourne VRAI si la bibliothèque a été initialisée ; FAUX sinon.
 * 
 * @return t_boolean : VRAI si la bibliothèque a été initialisée ; FAUX sinon.
 */
t_boolean est_p_permutation_initialise();

/**
 * @brief permet de retrouver la taille des permutations.
 * 
 * @param taille : int* : l'adresse de la variable qui contiendra la taille.
 * @return t_boolean : VRAI si la bibliothèque a été initialisée ; FAUX sinon.
 */
t_boolean donner_taille_permutation(int* taille);

/**
 * @brief allouer un tableau de <taille> entiers, où taille est la valeur qui a été fournit lors de l'initialisation de la bibliothèque.
 * la permutation initialisée sera l'identité.
 * @example 
 * Pour une permutation de taille 6, on obtiendra :
 * [ 0 1 2 3 4 5 ]
 *  
 * @param ceci : l'adresse de la permutation à initialiser.
 * @return t_boolean : VRAI si la bibliothèque a été initialisée ; FAUX sinon.
 */
t_boolean initialiser_permutation(t_permutation* ceci);

/**
 * @brief libère la mémoire pour une permutation.
 * 
 * @param ceci : l'adresse de la permutation à libérer.
 * @return t_boolean : VRAI si la permutation avait été initialisée ; FAUX sinon.
 */
t_boolean finaliser_permutation(t_permutation* ceci);

/**
 * @brief place dans chaque case de la permutation un numéro égale à son indice.
 * (i.e. Après cette fonction, on a pour tout i dans [[0, N-1]], ceci[i] = i)
 * 
 * @param ceci la permutation qui devient l'identité.
 * @return t_boolean 
 */
t_boolean identite_permutation(t_permutation ceci);

/**
 * @brief copie <ceci> dans <cela>.
 * 
 * @param ceci : la permutation à copier.
 * @param cela : la permutation qui contiendra la copie.
 * @return t_boolean : VRAI si la permutation avait été initialisée ; FAUX sinon.
 */
t_boolean copier_permutation(t_permutation ceci, t_permutation cela);

/**
 * @brief affiche le contenu de la permutation.
 * le format est le suivant :
 * les valeurs du tableau représentant la permutation écrites entre crochets et séparé par des espaces.
 * @example : 
 * Pour une permutation de taille 6, on pourra obtenir :
 * [ 5 0 2 3 4 1 ]
 * 
 * @param ceci : la permutation à afficher.
 * @return t_boolean : VRAI si la bibliothèque a été initialisée ; FAUX sinon.
 */
t_boolean debugger_permutation(t_permutation ceci);

/**
 * @brief retourne VRAI si <position> est un indice possible pour une permutation.
 * (i.e. <position> est positive & inférieur à la taille des permutations).
 * @param position 
 * @return t_boolean 
 */
t_boolean est_indice_valide(int position);

/**
 * @brief melange les valeurs du tableau représentant la permutation.
 * 
 * @param ceci : la permutation à mélanger
 * @return t_boolean : VRAI si la bibliothèque a été initialisée ; FAUX sinon.
 */
t_boolean melanger_permutation(t_permutation ceci);

/**
 * @brief construire dans <cela> la réciproque de <ceci>.
 * 
 * @param ceci : la permutation dont on cherche la réciproque.
 * @param cela : une permutation (initialiser) qui pourra accueillir la réciproque de ceci.
 * @return t_boolean : VRAI si la bibliothèque a été initialisée ET si on a réussi à construire la permutation réciproque ; FAUX sinon.
 */

//echange valeur indice

t_boolean reciproque_permutation(t_permutation ceci, t_permutation cela);

/**
 * @brief retourne VRAI si la bibliothèque a été initialisée ET si <ceci> est une permutation valide;
 * FAUX sinon
 * 
 * @param ceci : un tableau de valeur dont on teste la validité comme permutation.
 * @return t_boolean : VRAI si la bibliothèque a été initialisée ET si <ceci> est une permutation valide;
 * FAUX sinon.
 */

//check si il y a tous les nombres et pas de double.

t_boolean est_permutation_valide(t_permutation ceci);



/**
 * @brief 
 * 
 * @param ceci 
 * @param cela 
 * @return t_boolean : VRAI si la bibliothèque a été initialisée ET si <ceci> est une permutation valide;
 * FAUX sinon.
 */
t_boolean est_inferieur_strict(t_permutation ceci, t_permutation cela);

/**
 * @brief retourne VRAI si <ceci> possède un point fixe en <position>,
 * FAUX sinon.
 * 
 * @param ceci : la permutation dont on teste la présence de point fixe.
 * @param position : l'indice testé pour le point fixe.
 * @return t_boolean : VRAI si <ceci> possède un point fixe en <position>,
 * FAUX sinon.
 */
//indice = valeur ( point fixe)

t_boolean est_point_fixe_permutation(t_permutation ceci, int position);

/**
 * @brief retourne le nombre de points fixe dans la permutation.
 * 
 * @param ceci : la permutation dont on compte les points fixes.
 * @return int : le nombre de points fixe dans la permutation.
 * @remark si la bibliothèque n'est pas initialisée alors cette fonction retourne 0.
 */
int nb_point_fixe(t_permutation ceci);

/**
 * @brief transforme <ceci> en sa permutation suivante <ceci>.
 * 
 * @param ceci : la permutation à transformer.
 * @return t_boolean : VRAI si la bibliothèque a été initialisée ET si <ceci> possède une permutation suivante;
 * FAUX sinon.
 */
t_boolean suivante_permutation(t_permutation ceci);

/**
 * @brief copie dans <cela> la permutation qui arrive après <ceci>.
 * 
 * @param ceci : la permutation initiale.
 * @param cela : la permutation suivante.
 * @return t_boolean : VRAI si la bibliothèque a été initialisée ET si <ceci> possède une permutation suivante;
 * FAUX sinon.
 */
t_boolean copier_suivante_permutation(t_permutation ceci, t_permutation cela);

/**
 * @brief Écrit dans <cela> une representation du <point_fixe> de <ceci>
 * 
 * @param ceci : la permutation dont on souhaite coder un point fixe.
 * @param point_fixe : l'indice du point fixe de <ceci> qu'on souhaite coder.
 * @param cela : le codage du point fixe.
 * @return t_boolean : VRAI si la bibliothèque a été initialisée ET si <point_fixe> est réellement un point fixe de <ceci>;
 * FAUX sinon.
 */
t_boolean code_point_fixe_permutation(t_permutation ceci, int point_fixe, t_permutation cela);

/**
 * @brief Écrit dans <cela> la permutation support du point fixe de <ceci> et écrit à l'adresse *<point_fixe> la position du point fixe.
 * 
 * @param ceci : un codage de point fixe
 * @param point_fixe : l'adresse où écrire l'indice du point fixe de <cela> codé dans <ceci>.
 * @param cela : la permutation support de <ceci>.
 * @return t_boolean : VRAI si la bibliothèque a été initialisée ET si <point_fixe> est réellement un point fixe de <ceci>;
 * FAUX sinon.
 */
t_boolean decode_point_fixe_permutation(t_permutation ceci, t_permutation cela, int* point_fixe);

//Montrer que la fonction code_point_fixe est injective

//Montrer que la fonction decode_point_fixe est injective

//Pour implanter code_point_fixe et decode_point_fixe,
//l'énoncé affirme que ces fonctions réalisent des travaux réciproque l'un de l'autre.
//Prouvez-le !

//Que peut-on en déduire que le nombre de codage des points fixes ?

#endif



