#include	<stdio.h>
#include	<stdlib.h>
#include	<time.h>
#include	<unistd.h>
#include	<ncurses.h>
#include	"fonct.h"

int choixImage( FILE** image , int valeur ) {	//permet de choisir l'image en fonction du chiffre qui est lu

  switch( valeur ) {
  case 0:
    *image = fopen( "/home/greenslimes/projet EXIASaver/Horloge/PBM/0.pbm", "r");
    break;
  case 1:
    *image = fopen( "/home/greenslimes/projet EXIASaver/Horloge/PBM/1.pbm", "r");
    break;
  case 2:
    *image = fopen( "/home/greenslimes/projet EXIASaver/Horloge/PBM/2.pbm", "r");
    break;
  case 3:
    *image = fopen( "/home/greenslimes/projet EXIASaver/Horloge/PBM/3.pbm", "r");
    break;
  case 4:
    *image = fopen( "/home/greenslimes/projet EXIASaver/Horloge/PBM/4.pbm", "r");
    break;
  case 5:
    *image = fopen( "/home/greenslimes/projet EXIASaver/Horloge/PBM/5.pbm", "r");
    break;
  case 6:
    *image = fopen( "/home/greenslimes/projet EXIASaver/Horloge/PBM/6.pbm", "r");
    break;
  case 7:
    *image = fopen( "/home/greenslimes/projet EXIASaver/Horloge/PBM/7.pbm", "r");
    break;
  case 8:
    *image = fopen( "/home/greenslimes/projet EXIASaver/Horloge/PBM/8.pbm", "r");
    break;
  case 9:
    *image = fopen( "/home/greenslimes/projet EXIASaver/Horloge/PBM/9.pbm", "r");
    break;
  }
}

int temps_attente( int x , int temps ) {	//fonction permettant de faire un delai de rafraichissement 

  int i = 0, j = 0 , x_ = 0 , l = 0 ;

  printf("\n\n");
  if ( temps > 1 ) {
    for( i = 0 ; i<temps ; i++ ) {
      x_ = (x-(23+i+temps))/2;
      for ( l = 0 ; l<x_ ; l++ ) {
	printf(" ");
      }
      printf("L'horloge s'actualisera dans %d sec", temps );
      for( j = 0 ; j<i ; j++) {
	printf(".");
      }
      fflush(stdout);
      sleep(1);
      printf("\r");
    }
  }
  else {
    sleep(1);
  }
  return 0;
}

int main() {	//appelle toute les fonctions pour afficher le programme

  while(1) {
    time_t secondes;
    struct tm instant;
    time(&secondes);
    instant=*localtime(&secondes);
    heureActuel Decomposition;
    
    int hauteurP = 5, largeurP = 3 , i = 0;
    int **tab;
    tab = malloc((hauteurP*8) * sizeof(*tab));
    for( i = 0 ; i < (hauteurP*8) ; i++){
      tab[i] = malloc(largeurP * sizeof(**tab) );
    }
    int temps = 5;
    
    decompositionChiffre( instant.tm_hour , &Decomposition.dizaineH , &Decomposition.uniteH );
    decompositionChiffre( instant.tm_min , &Decomposition.dizaineM , &Decomposition.uniteM );
    decompositionChiffre( instant.tm_sec , &Decomposition.dizaineS , &Decomposition.uniteS );
    
    insertionValeurs( tab , Decomposition );
    
    agrandir( tab , hauteurP , largeurP );

    changementValeurs( tab , hauteurP , largeurP );
    
    affichage( tab , hauteurP , largeurP , temps );
    
        system("clear");
  }
  return 0;
}
