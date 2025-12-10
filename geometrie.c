/*
ETUDIANT 1
Numero : 
Nom Prenom :

ETUDIANT 2
Numero : 
Nom Prenom :


 *  main.c
 *
 *  co-écrit Regis Girard  06/10/25
 *
 */
   

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "geometrie.h"



// Création d'un segment 3D à partir de deux points 3D
T_SEGMENT3D* creer_segment(T_POINT3D p1, T_POINT3D p2){
	T_SEGMENT3D *s;
	if ((s = malloc(sizeof(T_SEGMENT3D))) == NULL) {
		fprintf(stderr, "\nErreur d'allocation. Impossible de créer le segment");
		return NULL;
	}
	s->p1 = p1;
	s->p2 = p2;
	return s;
}


// Création d'une sphère avec saisie du rayon et des coordonnées du centre
// Renvoie un pointeur sur la sphère ou NULL
// Création des 600 segments constituant la sphère
T_SPHERE* creer_sphere(){
	T_SPHERE *sph;
	T_POINT3D centre,p1, p2, p3;
	float rayon; // Rayon de la sphère
	int nbseg; // Nombre de segements constituant la figure

	// Les variables permettant de réaliser les calculs 
	float a,b, cosa, cosb, sina, sinb, cosbb, sinbb, cosaa, sinaa;
	
	
	printf("\n Coordonnées du centre : x y z : ");
	if (scanf("%f %f %f", &centre.x, &centre.y, &centre.z) != 3) {
		fprintf(stderr, "\nErreur de saisie");
		return NULL;
	}
	printf("\n Rayon :");
	if (scanf("%f", &rayon) != 1) {
		fprintf(stderr, "\nErreur de saisie");
		return NULL;
	}
	if ((sph = malloc(sizeof(T_SPHERE))) == NULL) {
		fprintf(stderr, "\nErreur d'allocation. Impossible de créer la sphère");
		return NULL;
	}
	
	nbseg=0; // Nombre de segments constituant la figure
	// On calcule les points de la sphère en "parcourant" sa surface
	// L'angle a fait le tour de la sphère suivant la latitude avec un pas de PI/12
	// L'angle b fait le tour de la spère suivant la longitude avec un pas de PI/12
	a=0;  // Angle de départ
	while (a < 2*M_PI) {
		cosa=cos(a); cosaa=cos(a+M_PI/12);
		sina=sin(a); sinaa=sin(a+M_PI/12);
		b = -M_PI/2;
		while (b <= 5*M_PI/12) {
			cosb=cos(b); cosbb=cos(b+M_PI/12);
			sinb=sin(b); sinbb=sin(b+M_PI/12);
			
			// On calcule les coordonnées du point courant 
			// à la surface de la sphère 
			p1.x = centre.x + rayon * cosa * cosb;
			p1.y = centre.y + rayon * sina * cosb;
			p1.z = centre.z + rayon * sinb;
			
			// Ainsi que les coordonnées des extrémités des 2 segments
			// à tracer à partir du point p1
			// Extrémité du segment en suivant la longitude
			p2.x = centre.x + rayon * cosb * cosaa;
			p2.y = centre.y + rayon * cosb * sinaa;
			p2.z = centre.z + rayon * sinb;
			// Extrémité du segment en suivant la latitude
			p3.x = centre.x + rayon * cosbb * cosa;
			p3.y = centre.y + rayon * cosbb * sina;
			p3.z = centre.z + rayon * sinbb;
			
			// On ajoute les 2 segments dans la figure
			sph->aretes[nbseg] = creer_segment(p1, p2);
			sph->aretes[nbseg+1] = creer_segment(p1, p3);
			
			nbseg += 2; // On a jouté deux segments à la figure
			b += M_PI/12; // Variation de l'angle en longitude
		}
		a += M_PI/12; // Variation de l'angle en latitude
	}
	return sph;
}



// ---------------------------
//          A ECRIRE  
// ---------------------------
// Création d'un segment 3D par saisie des coordonnées des deux extrémités
// Renvoie un pointeur sur le segment ou bien NULL
T_SEGMENT3D* saisie_segment(){

	return NULL;
}
// ---------------------------




// ---------------------------
//          A ECRIRE  
// ---------------------------
// Creation d'une pyramide dont les caractéristiques sont saisies : 
// - la longueur d'un côté de la base carrée
// - les coordonnées du coin en avant à gauche de la base
// - la hauteur
// Renvoie un pointeur sur la pyramide ou NULL si problème
T_PYRAMIDE* creer_pyramide(){
	
	return NULL;
}
// ---------------------------





// ---------------------------
//          A ECRIRE  
// ---------------------------
// Création d'un cube dont les caractéristiques sont saisie :
// - les coordonnées du sommet situé en avant à gauche de la base
// - de la longueur des arêtes du cube
// Renvoie un pointeur sur la cube ou NULL
T_CUBE* creer_cube(){
	
	return NULL;
}
// ---------------------------

