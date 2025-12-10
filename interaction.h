/*
 *  interaction.h
 *
 *  Regis Girard  06/10/25
 *
 */

#include <stdio.h>
#include <stdlib.h>
#include <SDL2/SDL.h>
#include "figure.h"

#ifndef H_INTERACTION
#define H_INTERACTION


// ****************************************************** 
// Définition et initialisation d'un tableau de SDL_Color

// Définition d'un type énuméré pour les noms des couleurs
enum {
	C_NOIR, C_BLEU_FONCE, C_VERT_FONCE, C_CYAN_FONCE, C_ROUGE_FONCE,
	C_MAGENTA_FONCE, C_OCRE, C_GRIS_CLAIR, C_GRIS, C_BLEU, C_VERT,
	C_CYAN, C_ROUGE, C_MAGENTA, C_JAUNE, C_BLANC,
	
	NB_COULEURS
};



//************************************
// Fonction de création du tableau des couleurs
// indicé par les noms des couleurs
// Renvoie un pointeur de type SDL_Color* sur le taleau créé;

extern SDL_Color* initCouleurs(void);

// ****************************************************** 



// Fonction utilitaire qui vide le buffer d'entrée 
extern void flushin();


// Menu principal de l'interaction dans le terminal
extern void menu(T_FIGURE *fig, SDL_Color *lesCouleurs);

// Sous-menu pour l'ajout d'objet à la figure
extern void menu_ajoute(T_FIGURE *fig, SDL_Color *lesCouleurs);

// Fonction qui gère l'ajout d'un objet à une figure
// Renvoie 1 si l'objet a pu être insérer dans la figure, 0 sinon
extern int ajout_objet(T_FIGURE *fig, T_FORME forme, void *obj, SDL_Color coul);


// Menu pour la sauvegarde de la figure courante dans un fichier binaire
extern void menu_sauver(T_FIGURE *fig);

// Menu pour le chargement d'une figure enregistrée dans un fichier binaire
extern void menu_charger(T_FIGURE *fig);

// Menu pour confirmer la ré-initialisation de la figure courante
// renvoie 1 si la figure est ré-initialisée, 0 sinon
extern int menu_init(T_FIGURE *fig);

#endif
