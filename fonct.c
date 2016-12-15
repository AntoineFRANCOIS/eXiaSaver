#include	<stdio.h>
#include	<stdlib.h>
#include	<time.h>
#include	<unistd.h>
#include	<ncurses.h>
#include	"fonct.h"

void	decompositionChiffre( int chiffre , int *dizaine , int *unite ) {

  *dizaine = chiffre/10;	//decompose le chiffre en dizaine
  *unite = chiffre%10;		//decompose le chiffre en unité
}

void	insertionValeurs( int **tab , heureActuel Decomposition ) {	//fonction permettant de choisir les images à 										  afficher en fonction de choix images et 									          d'insertion image 							  

  FILE* image = NULL;

  choixImage( &image , Decomposition.dizaineH );
  insertionImage( tab , &image , 0 );
  fclose(image);

  choixImage(&image, Decomposition.uniteH);
  insertionImage( tab , &image , 5 );
  fclose(image);

  image = fopen("/home/greenslimes/projet EXIASaver/Horloge/PBM/tiret.pbm", "r");
  insertionImage( tab , &image , 10 );
  fclose(image);

  choixImage( &image , Decomposition.dizaineM );
  insertionImage( tab , &image , 15 );
  fclose(image);

  choixImage( &image , Decomposition.uniteM );
  insertionImage( tab , &image , 20 );
  fclose(image);

  image = fopen("/home/greenslimes/projet EXIASaver/Horloge/PBM/tiret.pbm", "r");
  insertionImage( tab , &image , 25 );
  fclose(image);

  choixImage( &image , Decomposition.dizaineS );
  insertionImage( tab , &image , 30 );
  fclose(image);

  choixImage( &image , Decomposition.uniteS );
  insertionImage( tab , &image , 35 );
  fclose(image);
}

int	insertionImage( int **tab , FILE** image , int j ) {	//fonction permettant de stocker les valeurs de l'image

  int j_ = j+5;
  int i = 0;

  fseek( *image , 7 , SEEK_SET );
  for( j ; j<j_ ; j++ ) {
    for( i = 0 ; i < 3 ; i++ ) {
      tab[j][i] = fgetc( *image );
      fgetc( *image );
    }
  }
  return 0;
}


void	agrandir( int **tab , int hauteurP , int largeurP ) {	//fonction permettant d'agrandir la taille de l'horloge 								  en fonction de la console
	
  if( ((2*largeurP)-1) != hauteurP ) {
    printf("error\n");
  }
  else {
    int i = 0 , j = 0 , k = 0;
    int **tab2;

    tab2 = malloc((hauteurP*8) * sizeof(*tab2));
    for( i = 0 ; i < (hauteurP*8) ; i++){
      tab2[i] = malloc(largeurP * sizeof(**tab2) );
    }

    for( j = 0 ; j<40 ; j++ ) {
      for( i = 0 ; i<largeurP ; i++ ) {
	if( i == 0 ) {
	  tab2[j][i] = tab[j][i];
	}
	else if ( i == (largeurP-1) ) {
	  tab2[j][i] = tab[j][2];
	}
	else {
	  tab2[j][i] = tab[j][1];
	}
      }
    }
    int moitierH = (hauteurP/2);

    for( k = 0 ; k<8 ; k++ ) {
      for( j = 0 ; j<hauteurP ; j++ ) {
	for( i = 0 ; i<largeurP ; i++ ) {
	  if( j == 0 ) {
	    tab[j+(k*hauteurP)][i] = tab2[(k*5)+0][i];
	  }
	  if( j == moitierH ) {
	    tab[j+(k*hauteurP)][i] = tab2[(k*5)+2][i];
	  }
	  if( j == hauteurP-1 ) {
	    tab[j+(k*hauteurP)][i] = tab2[(k*5)+4][i];
	  }
	  if( j < moitierH && j != 0 ) {
	    tab[j+(k*hauteurP)][i] = tab2[(k*5)+1][i];
	  }
	  if( j > moitierH && j != (hauteurP-1) ) {
	    tab[j+(k*hauteurP)][i] = tab2[(k*5)+3][i];
	  }
	}
      }
    }
  }
}

void	changementValeurs( int **tab , int hauteurP , int largeurP ) {	//permet la conversion des valeurs de l'image en 										  caractère

  int j , i;

  for( j = 0 ; j < hauteurP*8 ; j++ ) {
    for( i = 0 ; i < largeurP ; i++ ) {
      switch( tab[j][i] ) {
      case 48:
	tab[j][i] = 255;
	break;
      case 49:
	tab[j][i] = 219;
	break;
      default:
	printf("error.\n");
	break;
      }
    }
  }
}


void	affichage( int **tab , int hauteurP , int largeurP , int temps ) {	//permet d'afficher une image

  int j = 0 , i = 0 , k = 0 , l = 0 , x = 0 , y = 0 , x_ = 0 , y_ = 0 ;
  initscr();
  getmaxyx( stdscr , y , x );
  endwin();
  system("clear");

  y_ = (y-hauteurP)/2;
  x_ = (x-((largeurP*8)+7))/2;

  for( j = 0 ; j<y_ ; j++ ) {
    printf("\n");
  }
  for( j = 0 ; j<hauteurP ; j++ ) {
    for ( l = 0 ; l<x_ ; l++ ) {
      printf(" ");
    }
    for( k = 0 ; k<8 ; k++ ) {
      for( i = 0 ; i<largeurP ; i++ ) {
	printf("%c", tab[j+k*hauteurP][i]);
      }
      printf(" ");
    }
    printf("\n");
  }
  temps_attente( x , temps);
}
