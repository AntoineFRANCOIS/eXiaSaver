#include	<stdio.h>
#include	<stdlib.h>
#include	<ncurses.h>
#include	<time.h>
#include	"fonctions.h"
#define		ESC 27


void	stat()
{
  printf("bonjour voici les stats : \n");
}

int main(int ac , char **av)
{
  if (ac == 1)
    {
       system("clear");
      int i = 0, j = 0, largeur = 0, hauteur = 0;
      FILE* image = NULL;
      switch(aleatoire())
	{
	case 0:
	  image = fopen("img1.pbm","r");
	  break;
	case 1:
	  image = fopen("img2.pbm", "r");
	  break;
	case 2:
	  image = fopen("img3.pbm", "r");
	  break;
	case 3:
	  image = fopen("coupe.pbm", "r");
	  break;
	case 4:
	  image = fopen("img5.pbm", "r");
	  break;
	}
      fseek(image, 3, SEEK_SET);
      fscanf(image, "%d %d", &largeur, &hauteur);
      fgetc(image);
      int tab[hauteur*largeur];
      for( j = 0 ; j<hauteur ; j++ )
	{
	  for( i = 0 ; i<largeur ; i++ )
	    {
	      tab[(j*hauteur)+i] = fgetc(image);
	      fgetc(image);
	    }
	}	  
      changementCarre( tab , hauteur , largeur );
      affichage( tab , hauteur , largeur);
      system("stty cbreak -echo");
      getchar();
      system("stty cooked echo");
      system("clear");
    }
  else if (av[1][0] == '-' && av[1][1] == 's')
    stat();
}


