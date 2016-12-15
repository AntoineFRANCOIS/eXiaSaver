#include	<stdio.h>
#include	<stdlib.h>
#include	<ncurses.h>
#include	<time.h>
#include	"fonctions.h"
#define		ESC 27


void changementCarre( int *tab , int hauteur , int largeur ) {	//fonction qui va convertir les valeurs de l'image en 									caractère

  int j , i , x , y;
  for( j = 0 ; j<hauteur ; j++ ) {	//permet de convertir toute les valeurs de l'images en caractères
    for( i = 0 ; i<largeur ; i++ ) {
      switch(tab[(j*hauteur)+i]) {
      case 48:
	tab[(j*hauteur)+i] = 255;
	break;
      case 49:
	tab[(j*hauteur)+i] = 254;
	break;
      default:
	printf("error.\n");
	break;
      }
    }
  }
}

void affichage( int *tab , int hauteur , int largeur ) {	//fonction d'affichage de l'image

  int j , i , x , y;

  initscr();	//permet d'initialiser la fenêtre ncurses
  getmaxyx(stdscr, y, x);	//permet d'obtenir la taille de la fenêtre
  endwin();	//ferme la fenêtre ncurses
  x = (x-largeur)/2 ; y = (y-hauteur)/2 ;	//affiche l'image grâce au tableau contenant les valeurs converties
  for( j = 0 ; j<y ; j++ )
    printf("\n");
  for( j = 0 ; j<hauteur ; j++ ) {
    for( y = 0 ; y<x ; y++ )
	  printf(" ");
    for( i = 0; i<largeur ; i++)
      printf("%c ", tab[(j*hauteur)+i]); 
    printf("\n");
  }
}

int aleatoire() {	//fonction qui permet la génération d'un nombre aléatoire
  srand(time(NULL));
  int alea = rand()%(5);
  return (alea);
}
