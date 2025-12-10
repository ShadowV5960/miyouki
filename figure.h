/*
 *  figure.h
 *
 *  Regis Girard  06/10/25
 *
 */

#include "geometrie.h"

#ifndef H_FIGURE
#define H_FIGURE


// Projection d'un point 3D en point 2D pour affichage sur l'écran
// en fonction de l'orientation du repère 3D et de la position de l'origine
extern T_POINT2D proj_point(T_POINT3D p, T_POINT2D pori, float omega, float alpha, float coeff);


// Affichage d'un segment dans la fenêtre graphique
extern void dessine_segment(SDL_Renderer* fond, T_SEGMENT3D* s, SDL_Color couleur, T_POINT2D pori, float omega, float alpha, float coeff);


// Affichage d'un cube dans la fenêtre graphique
extern void dessine_cube(SDL_Renderer* fond, T_CUBE* c, SDL_Color couleur, T_POINT2D pori, float omega, float alpha, float coeff);


// Affichage d'une sphère dans la fenêtre graphique
extern void dessine_sphere(SDL_Renderer* fond, T_SPHERE* s, SDL_Color couleur, T_POINT2D pori, float omega, float alpha, float coeff);


// Affichage d'une pyramide dans la fenêtre graphique
extern void dessine_pyramide(SDL_Renderer* fond, T_PYRAMIDE* py, SDL_Color couleur, T_POINT2D pori, float omega, float alpha, float coeff);


// Initialisation de la figure
// On initilise la figure avec 3 segments blancs correspondant aux axes du repère
// L'origine du repère est positionnée au centre de la fenêtre
extern void init_figure(T_FIGURE* fig);


// Destruction de tous les objets d'une figure et libération de la mémoire
extern void del_figure(T_FIGURE* fig);


// Affichage d'une figure 3D projetée en 2D dans la fenêtre graphique
extern void dessine_figure(SDL_Renderer* fond, T_FIGURE* fig, T_POINT2D pori, float omega, float alpha, float coeff);


#endif