/*
 *  geometrie.h
 *
 *  Regis Girard  06/10/25
 *
 */

#include <SDL2/SDL.h>

#ifndef H_GEOMETRIE
#define H_GEOMETRIE


// Dimension de la fenêtre
#define F_LARG 800
#define F_HAUT 600

// Nombre d'objets maximum dans une figure
#define MAXOBJ 100

// Constante de projection
#define R_ALPHA 0
#define R_OMEGA 0
#define COEFF 0.6


// Enumeration des figures géométriques de bases prédéfinies
typedef enum forme {cube, sphere, pyramide, segment3D} T_FORME;


//*****************************************************************************
// Représentation des points géométriques
//*****************************************************************************


// Représentation d'un point de l'espace à 3 dimensions
typedef struct point3d {
	float x,y,z;
} T_POINT3D;


// Représentation d'un point de l'écran graphique
// Contiendra les coordonnées d'un pixels à afficher sur l'écran
typedef struct point2d {
	float x, y;
} T_POINT2D;



//******************************************************************************
// Définition des structures pour représenter des objets géométriques 3D simples
//******************************************************************************


// Un segment 3D est défini par de deux points 3D
typedef struct segment3D {
	T_POINT3D p1, p2;
} T_SEGMENT3D;



// Un cube est constitué de 12 segments correspondant à ses arêtes
typedef struct cube{
	T_SEGMENT3D* aretes[12];
} T_CUBE;




// Une pyramide régulière de base carrée est constituée de 8 segments
typedef struct pyramide{
	T_SEGMENT3D* aretes[8];
} T_PYRAMIDE;



// Une sphère est constituée de 600 segments correspondant aux lignes longitudinales
// et latitudinales espacées d'un angles PI/12 à la surface de la sphère
typedef struct sphere{
	T_SEGMENT3D* aretes[600];
} T_SPHERE;



//******************************************************************************
// Définition des structures pour représenter une figure géométrique complexe
//******************************************************************************

// Un figure est constituée d'un nombre maximum (MAXOBJ) d'objets géométriques simples
// qui sont rangés dans un tableau

// La structure objet permet d'abstraire les objets géométriques en les représentant 
// dans une seule structure a trois champs :
//   - forme qui indique quel est le type de l'objet
//   - couleur qui indique la couleur attribuée à l'objet
//   - obj : un pointeur générique vers l'objet géométrique lui-même, 
//           à savoir un cube, une sphère ... etc
typedef struct objet{
	T_FORME forme;
	SDL_Color couleur;
	void *obj; 		// pointeur générique vers un objet géométrique
} T_OBJET;


// Une figure géométrique complexe est alors constituée de nbobj objets simples
// rangés dans un tableau de taille MAXOBJ
typedef struct figure{
	int nbobj;
	T_OBJET tabobj[MAXOBJ];
} T_FIGURE;




//******************************************************************************
// Fonctions de création des objets géométriques simple
//******************************************************************************


// Création d'un segment 3D par saisie des coordonnées des deux extrémités
// Renvoie un pointeur sur le segment ou NULL
extern T_SEGMENT3D* saisie_segment();


// Création d'un segment à partir de deux points 3D
extern T_SEGMENT3D* creer_segment(T_POINT3D p1, T_POINT3D p2);



// Creation d'une pyramide dont les caractéristiques sont saisies : 
// valeurs du coté de la base carrée et de la hauteur
// Renvoie un pointeur sur la pyramide ou NULL si problème
extern T_PYRAMIDE* creer_pyramide();



// Création d'un cube dont par saisie :
// - des coordonnées du sommet situé en avant à gauche de la base
// - de la longueur des arêtes du cube
// Renvoie un pointeur sur la cube ou NULL
extern T_CUBE* creer_cube();


// Création d'une sphère avec saisie du rayon et des coordonnées du centre
// Renvoie un pointeur sur la sphère ou NULL
// Création des 600 segments constituant la sphère
extern T_SPHERE* creer_sphere();



#endif