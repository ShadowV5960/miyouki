/*
 *  figure.c
 *
 *  Regis Girard on 06/10/25
 *
 */

#include <math.h>
#include "figure.h"


// Projection d'un point 3D en point 2D pour affichage sur l'écran
// en fonction de l'orientation du repère 3D et de la position de l'origine
T_POINT2D proj_point(T_POINT3D p, T_POINT2D pori, float omega, float alpha, float coeff){
	T_POINT2D p2d;
	
	p2d.x = pori.x + coeff * (p.x*cos(omega) + p.y*sin(omega));
	p2d.y = pori.y - coeff * (p.x*sin(omega)*sin(alpha) - p.y*cos(omega)*sin(alpha) + p.z*cos(alpha));
	
	return p2d;
} 




// Affichage d'un segment dans la fenêtre graphique
void dessine_segment(SDL_Renderer* fond, T_SEGMENT3D *s, SDL_Color couleur, T_POINT2D pori, float omega, float alpha, float coeff){
	T_POINT2D p1, p2;
	// On calcule les points 2D correspondant à la position du repère
	p1 = proj_point(s->p1, pori, omega, alpha, coeff);
	p2 = proj_point(s->p2, pori, omega, alpha, coeff);
	SDL_SetRenderDrawColor(fond, couleur.r, couleur.g, couleur.b, couleur.a);
	SDL_RenderDrawLine(fond, p1.x, p1.y, p2.x, p2.y);
	return;
}


// Affichage d'un cube dans la fenêtre graphique
void dessine_cube(SDL_Renderer* fond, T_CUBE *c, SDL_Color couleur, T_POINT2D pori, float omega, float alpha, float coeff){
	int i;
	
	for (i=0; i<12; i++)
		dessine_segment(fond, c->aretes[i], couleur, pori, omega, alpha, coeff);
	return;
}



// Affichage d'une sphère dans la fenêtre graphique
void dessine_sphere(SDL_Renderer* fond, T_SPHERE *s, SDL_Color couleur, T_POINT2D pori, float omega, float alpha, float coeff){
	int i;
	
	for (i=0; i<600; i++)
		dessine_segment(fond, s->aretes[i], couleur, pori, omega, alpha, coeff);
	return;
}


// Affichage d'une pyramide dans la fenêtre graphique
void dessine_pyramide(SDL_Renderer* fond, T_PYRAMIDE *py, SDL_Color couleur, T_POINT2D pori, float omega, float alpha, float coeff){
	int i;
	
	for (i=0; i<8; i++)
		dessine_segment(fond, py->aretes[i], couleur, pori, omega, alpha, coeff);
	return;
}



// ---------------------------
//          A ECRIRE  
// ---------------------------
// Initialisation de la figure
// On initilise la figure avec 3 segments blancs correspondant aux axes du repère
// L'origine du repère est positionnée au centre de la fenêtre
void init_figure(T_FIGURE *fig){
	
}
// ---------------------------





// ---------------------------
//          A ECRIRE  
// ---------------------------
// Destruction de tous les objets d'une figure et libération de la mémoire
void del_figure(T_FIGURE* fig){

}
// ---------------------------





// ---------------------------
//          A ECRIRE  
// ---------------------------
// Affichage d'une figure 3D projetée en 2D dans la fenêtre graphique
void dessine_figure(SDL_Renderer* fond, T_FIGURE* fig, T_POINT2D pori, float omega, float alpha, float coeff){
	
}
// ---------------------------


