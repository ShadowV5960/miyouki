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
#include <string.h>
#include <math.h>

#include <SDL2/SDL.h>
#include "figure.h"
#include "interaction.h"






int main(int argc, char *argv[]){
	// -----------------------
	// Initialisation du tableau des couleurs, indicé par les noms des couleurs
	// Ce tableau contient des SDL_Color au format RGB+alpha
	SDL_Color* lesCouleurs = initCouleurs();
	
	
	// -----------------------
	// Paramètres de position de la figure 3D
	
	T_POINT2D pori = {F_LARG/2, F_HAUT/2}; // Origine du repère au centre de la fenêtre
	float dxori=0, dyori=0;				// Déplacement de l'origine
	float omega = 2, domega=0;			// Rotation autour de l'axe Z
	float alpha = -0.4, dalpha=0;   	// Rotation autour de l'axe Y
	float coeff = 1, dcoeff = 0;		// Coefficient de zoom
	
	// Variation de l'angle de rotation lorsqu'on fait tourner la figure
	// Chaque appuie sur une touche fléchée augmentera l'angle de deltaPI
	float deltaPI = M_PI / 360;			

	// -----------------------
	// Initialisation de la figure avec uniquement les axes du repère en blanc
	T_FIGURE fig;
	init_figure(&fig);

	// -----------------------
	// Déclarations de la fenêtre, du renderer et de la texture
	SDL_Window* fenetre = NULL;		// La fenetre de l'appli
	SDL_Renderer* fond = NULL;		// Le fond de la fenetre
	SDL_Texture* texture = NULL;	// La teture ou on dessine

		
	// Initialise le système de gestion de rendu VIDEO de la SDL
    if (SDL_Init(SDL_INIT_VIDEO | SDL_INIT_EVENTS) != 0){
        fprintf(stderr, "Erreur SDL_Init : %s\n", SDL_GetError());
        SDL_Quit();
        return EXIT_FAILURE;
    }
	
	// Creation de la fenêtre  
    // titre : PROJ25
    // position centrée sur l'ecran en largeur et hauteur
    // dimension F_LARG x F_HAUT
    // mode visible
    fenetre = SDL_CreateWindow("PROJ25", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED,
         F_LARG , F_HAUT, SDL_WINDOW_SHOWN | SDL_WINDOW_MAXIMIZED);
	if (fenetre == NULL){
        fprintf(stderr, "Erreur CreatWindow : %s\n", SDL_GetError());
        SDL_Quit();
        return EXIT_FAILURE;
    }
	

	// Création du renderer associe a la fenetre
    // on utilise la carte graphique et le rendu est synchronise avec 
    // le raffraichissement de l'ecran
    fond = SDL_CreateRenderer(fenetre, -1, SDL_RENDERER_ACCELERATED|SDL_RENDERER_PRESENTVSYNC);
    if(fond == NULL) {
            fprintf(stderr, "Erreur CreateRenderer : %s\n", SDL_GetError());
            SDL_Quit();
            return EXIT_FAILURE;
    }

	// Création d'une texture associé au renderer et de mêmes dimensions
    // Les pixels sont au format RGB alpha, 
    texture = SDL_CreateTexture(fond, SDL_PIXELFORMAT_RGBA32, \
            SDL_TEXTUREACCESS_TARGET, F_LARG, F_HAUT);



	// -----------------------
	//Boucle d'interaction
	int fin = 0;
	int clicsouris=0;       // pour savoir si le boutton clic souris est enfoncé 0=non 1=oui
	SDL_Event event;		// Evènement à traiter

	while ( !fin ) {
		
		/* On traite les evenements */
		while ( SDL_PollEvent(&event) ) {
			switch (event.type) {
				// ----------------------------------
				//         A ECRIRE
				// ----------------------------------
				// Ajouter la gestion de la souris pour  
				// le déplacement de l'origine du repère



				// Appuie sur une touche du clavier
				// Mise à jour des variations des paramètrres d'afficvhage
				// angles, zoom, déplacement
				case SDL_KEYDOWN:
					printf("Appuie sur une touche du clavier\n");
					switch (event.key.keysym.sym){
						// On fait tourner le repère 3D
						case SDLK_LEFT:
							domega = deltaPI;
							break;
						case SDLK_RIGHT:
							domega = - deltaPI;
							break;
						case SDLK_UP:
							dalpha = deltaPI;
							break;
						case SDLK_DOWN:
							dalpha = - deltaPI;
							break;
						// Dezzoomer
						case SDLK_COLON:
						case SDLK_SLASH:
							dcoeff = - 0.01;
							break;
						// Zoomer
						case SDLK_EQUALS:
						case SDLK_PLUS:
							dcoeff = 0.01;
							break;
						// Déplacement de l'origine du repère
						case SDLK_a:
							dyori = -1;
							break;
						case SDLK_q:
							dyori = 1;
							break;
						case SDLK_w:
							dxori = -1;
							break;
						case SDLK_x:
							dxori = 1;
							break;
						case SDLK_p:
							// Juste pour avoir des infos sur l'orientation des axes
							printf("\n omega=%f alpha=%f coeff=%f\n",omega, alpha, coeff);
							break;
						// Affichage du menu interactif
						case SDLK_ESCAPE:
							menu(&fig, lesCouleurs);
							break;
						default:
							break;
					}
					break;
				// Quand relache la touche du clavier, les paramètres
				// sont ré-initialisés
				case SDL_KEYUP:
					switch (event.key.keysym.sym){
						case SDLK_LEFT:
						case SDLK_RIGHT:
							domega =0;
							break;
						case SDLK_UP:
						case SDLK_DOWN:
							dalpha = 0;
							break;
						case SDLK_COLON:
						case SDLK_SLASH:
						case SDLK_EQUALS:
						case SDLK_PLUS:
							dcoeff=0;
							break;
						case SDLK_a:
						case SDLK_q:
							dyori = 0;
							break;
						case SDLK_w:
						case SDLK_x:
							dxori = 0;
							break;
						default:
							break;
					}
					break;
					
				// Quitter l'appli
				case SDL_QUIT:
					printf("\nAu revoir ...\n");
					fin = 1;
					break;
				default:
					break;
			}

		
		}

		// Mise à jour des angles de rotation
		omega = remainder(omega + domega, 2*M_PI);
		alpha = remainder(alpha + dalpha, 2*M_PI);
		// Mise à jour des coordonnées de l'origine
		pori.x +=dxori;
		pori.y +=dyori;
		// Mise à jour du zoom
		coeff += dcoeff;
		if (coeff <0.01) coeff = 0.01;	// valeur mini du zoom
		if (coeff > 5) coeff = 5;		// valeur maxi du zoom


		// Affichage de la figure
		// On désigne la texture comme cible 
		SDL_SetRenderTarget(fond, texture);
		// Dessin de la figure sur la texture : on efface et on redessine
		// On efface la texture
		SDL_Color coul = lesCouleurs[C_NOIR];
		SDL_SetRenderDrawColor(fond, coul.r, coul.g, coul.b, coul.a);
    	SDL_RenderClear(fond);
		// On dessine la figure mise à jour
		dessine_figure(fond, &fig, pori, omega, alpha, coeff);
        // Copie de la texture sur le renderer
        SDL_SetRenderTarget(fond, NULL);
        SDL_RenderCopy(fond, texture, NULL, NULL);

        // Raffraichissement du renderer
        SDL_RenderPresent(fond);
		SDL_Delay(1);  // delai minimal pour ne pas monopoliser le processeur
		
	}
	
	/* On quitte proprement */
	SDL_Quit();
	return(0);
}
