#include	<stdio.h>
#include	<stdlib.h>
#include	<ncurses.h>
#include	<time.h>
#include	"fonctions.h"
#define		ESC 27


void changementCarre( int *tab , int hauteur , int largeur ) {
  int j , i , x , y;
  for( j = 0 ; j<hauteur ; j++ ) {
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

void affichage( int *tab , int hauteur , int largeur ) {

  int j , i , x , y;

  initscr();
  getmaxyx(stdscr, y, x);
  endwin();
  x = (x-largeur)/2 ; y = (y-hauteur)/2 ;
  for( j = 0 ; j<y ; j++ ) {
    printf("\n");
  }
  for( j = 0 ; j<hauteur ; j++ ) {
    for( y = 0 ; y<x ; y++ ) {
      printf(" ");
    }
    for( i = 0; i<largeur ; i++ ) {
      printf("%c ", tab[(j*hauteur)+i]);
    }
    printf("\n");
  }
}

int aleatoire() {
  srand(time(NULL));
  int alea = rand()%(5);
  return alea;
}
