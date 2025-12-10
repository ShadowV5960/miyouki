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
   

#include "interaction.h"


//************************************
// Création du tableau des couleurs
// indicé par les noms des couleurs
// Renvoie un pointeur de type SDL_Color* sur le taleau créé;

SDL_Color* initCouleurs(void)
{
	SDL_Color *couleurs = malloc(NB_COULEURS * sizeof(SDL_Color));

	couleurs[C_NOIR] = (SDL_Color){0, 0, 0, 1};
	couleurs[C_BLEU_FONCE] = (SDL_Color){0, 0, 128, 1};
	couleurs[C_VERT_FONCE] = (SDL_Color){0, 128, 0, 1};
	couleurs[C_CYAN_FONCE] = (SDL_Color){255, 255, 0, 1};
	couleurs[C_ROUGE_FONCE] = (SDL_Color){128, 0, 0, 1};
	couleurs[C_MAGENTA_FONCE] = (SDL_Color){255, 255, 0, 1};
	couleurs[C_OCRE] = (SDL_Color){128, 128, 0, 1};
	couleurs[C_GRIS_CLAIR] = (SDL_Color){192, 192, 192, 1};
	couleurs[C_GRIS] = (SDL_Color){128, 128, 128, 1};
	couleurs[C_BLEU] = (SDL_Color){0, 0, 255, 1};
	couleurs[C_VERT] = (SDL_Color){0, 255, 0, 1};
	couleurs[C_CYAN] = (SDL_Color){0, 255, 255, 1};
	couleurs[C_ROUGE] = (SDL_Color){255, 0, 0, 1};
	couleurs[C_MAGENTA] = (SDL_Color){255, 255, 0, 1};
	couleurs[C_JAUNE] = (SDL_Color){255, 255, 0, 1};
	couleurs[C_BLANC] = (SDL_Color){255, 255, 255, 1};

	return couleurs;
}



// Fonction qui vide le buffer d'entrée
void flushin()
{
	char c;
	do
		c = getchar();
	while (c != '\n' && c != EOF);
}



//************************************
// Les interactions se font dans le terminal
// via des menus textuels

// Menu principal de l'interaction dans le terminal
// Arguments : 
// - fig,  un pointeur sur la figure
// - lescouleurs, le tableaux des couleurs prédéfinies 
//   par la fonction initCouleurs

void menu(T_FIGURE *fig, SDL_Color *lesCouleurs)
{
	int choix = -1;
	printf("\n*************************");
	printf("\n Interaction\n");
	do
	{
		printf("\nAjouter un objet         1");
		printf("\nSauver la figure         2");
		printf("\nCharger un figure        3");
		printf("\nRe-initialiser la figure 4");
		printf("\nAnnuler                  0");
		printf("\n                   Choix ");
		if (scanf("%d", &choix) != 1)
			flushin();
	} while (choix < 0 || choix > 4);

	switch (choix)
	{
	case 1:
		menu_ajoute(fig, lesCouleurs);
		break;
	case 2:
		menu_sauver(fig);
		break;
	case 3:
		menu_charger(fig);
		break;
	case 4:
		menu_init(fig);
		break;
	default:
		break;
	}
	return;
}





// Sous-enu pour confirmer la ré-initialisation de la figure courante
// Retourne 1 si la figure a bien etait re-initialisée, 0 sinon
int menu_init(T_FIGURE *fig)
{
	char c[10];
	do
	{
		printf("\nTous les objet de la figure vont être supprimés.");
		printf("\nConfirmation (o/n) : ");
		scanf("%s", c);
	} while (!(strcmp(c, "o") || strcmp(c, "O") || strcmp(c, "n") || strcmp(c, "N")));
	if (strcmp(c, "o") == 0 || strcmp(c, "O") == 0)
	{
		del_figure(fig);
		init_figure(fig);
		printf("\nLa figure est ré-initialisée");
		return 1;
	}
	return 0;
}




// Sous-menu pour l'ajout d'objet à la figure
// Cette fonction fait appel à ajout_objet
// Arguments :
// - fig, un pointeur sur la figure
// - lesCouleurs, le tableaux des couleurs prédéfinies 
//   par la fonction initCouleurs

void menu_ajoute(T_FIGURE *fig, SDL_Color *lesCouleurs)
{
	int choix = -1;
	int couleur = -1;
	SDL_Color coul;

	while (choix < 0 || choix > 4)
	{
		printf("\n ** Ajout d'un objet à la figure :\n");
		printf("\nAjout d'une sphere     1");
		printf("\nAjout d'un cube        2");
		printf("\nAjout d'une pyramide   3");
		printf("\nAjout d'un segment     4");
		printf("\nAnnuler                0");
		printf("\n              Choix : ");
		if (scanf("%d", &choix) != 1)
			flushin();
	}
	if (choix == 0)
		return;
	while (couleur < 0 || couleur > 5)
	{
		printf("\n ** Couleur de l'objet :\n");
		printf("\nBlanc    1");
		printf("\nRouge    2");
		printf("\nVert     3");
		printf("\nBleu     4");
		printf("\nJaune    5");
		printf("\n              Choix : ");
		if (scanf("%d", &couleur) != 1)
			flushin();
	}
	switch (couleur)
	{
	case 1:
		coul = lesCouleurs[C_BLANC];
		break;
	case 2:
		coul = lesCouleurs[C_ROUGE];
		break;
	case 3:
		coul = lesCouleurs[C_VERT];
		break;
	case 4:
		coul = lesCouleurs[C_BLEU];
		break;
	case 5:
		coul = lesCouleurs[C_JAUNE];
		break;
	default:
		break;
	}
	switch (choix)
	{
	case 1:
		ajout_objet(fig, sphere, creer_sphere(), coul);
		break;
	case 2:
		ajout_objet(fig, cube, creer_cube(), coul);
		break;
	case 3:
		ajout_objet(fig, pyramide, creer_pyramide(), coul);
		break;
	case 4:
		ajout_objet(fig, segment3D, saisie_segment(), coul);
		break;
	default:
		// on ajouterait à la suite d'autre figures géométriques simples
		// cyclindre, cone, etc...
		break;
	}
}



// ---------------------------
//          A ECRIRE  
// ---------------------------
// Fonction qui gère l'ajout d'un objet à une figure
// Renvoie 1 si l'objet a pu être insérer dans la figure, 0 sinon
// Arguments :
// - fig, un pointeur sur la figure
// - forme, qui indique le type de l'objet à ajouter
// - obj, un pointeur générique sur l'objet à ajouter
// - coul, la couleur de l'objet
// Il s'agit d'ajouter dans le tableau des objets qui constituent la figure
// l'objet demandé.
int ajout_objet(T_FIGURE* fig, T_FORME forme, void* obj, SDL_Color coul)
{
	
	return 1;
}
// ---------------------------




// Sous-menu enu pour la sauvegarde de la figure courante dans un fichier binaire
void menu_sauver(T_FIGURE *fig)
{
	char nomfich[32];
	FILE *fich;
	int i, nba;

	printf("\nDonner le nom du fichier de sauvegarde : ");
	scanf("%s", nomfich);

	if ((fich = fopen(nomfich, "wb")) == NULL)
	{
		fprintf(stderr, "\nImpossible de créer le fichier %s", nomfich);
		return;
	}
	// On écrit, le nombre d'objet de la figure
	fwrite(&(fig->nbobj), sizeof(int), 1, fich);
	// Puis on écrit les objets
	for (i = 0; i < fig->nbobj; i++)
	{
		printf(".");
		// la forme de l'objet i
		fwrite(&(fig->tabobj[i].forme), sizeof(T_FORME), 1, fich);
		fwrite(&(fig->tabobj[i].couleur), sizeof(SDL_Color), 1, fich);
		switch (fig->tabobj[i].forme)
		{
		case cube:
			for (nba = 0; nba < 12; nba++)
				fwrite(((T_CUBE *)(fig->tabobj[i].obj))->aretes[nba], sizeof(T_SEGMENT3D), 1, fich);
			break;
		case sphere:
			for (nba = 0; nba < 600; nba++)
				fwrite(((T_SPHERE *)(fig->tabobj[i].obj))->aretes[nba], sizeof(T_SEGMENT3D), 1, fich);
			break;
		case pyramide:
			for (nba = 0; nba < 12; nba++)
				fwrite(((T_PYRAMIDE *)(fig->tabobj[i].obj))->aretes[nba], sizeof(T_SEGMENT3D), 1, fich);
			break;
		case segment3D:
			fwrite(fig->tabobj[i].obj, sizeof(T_SEGMENT3D), 1, fich);
			break;
		default:
			break;
		}
	}
	fclose(fich);
	printf("\nSauvegarde terminée\n");
}





// ---------------------------
//          A ECRIRE  
// ---------------------------
// Menu pour le chargement d'une figure enregistrée dans un fichier binaire
void menu_charger(T_FIGURE *fig)
{
	
}
// ---------------------------


