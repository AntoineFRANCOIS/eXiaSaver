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
      int z = 0,z2 = 0;
      int i = 0, j = 0, largeur = 0, hauteur = 0;
      FILE* image = NULL;
      FILE* save = NULL;
      pid_t pid = fork();
      
      if (pid == 0)	//processus fils
	{
	  
	  switch(aleatoire())	//appelle de la fonction aléatoire et sélection des images
	    {
	    case 0:
	      image = fopen("/home/greenslimes/projet EXIASaver/statique/pbm/img1.pbm","r");
	      
	      break;
	    case 1:
	      image = fopen("/home/greenslimes/projet EXIASaver/statique/pbm/yoda.pbm", "r");
	      
	      break;
	    case 2:
	      image = fopen("/home/greenslimes/projet EXIASaver/statique/pbm/img3.pbm", "r");
	      
	      break;
	    case 3:
	      image = fopen("/home/greenslimes/projet EXIASaver/statique/pbm/coupe.pbm", "r");
	      
	      break;
	    case 4:
	      image = fopen("/home/greenslimes/projet EXIASaver/statique/pbm/img5.pbm", "r");
	      
	      break;
	      
	    }
	  
	  fseek(image, 3, SEEK_SET);	//saute les 3 premiers charactères de l'image
	  fscanf(image, "%d %d", &largeur, &hauteur);	// permet de lire les valeurs de l'image 								   
	  fgetc(image);	// passe le retour à la ligne
	  int tab[hauteur*largeur];	
	  for( j = 0 ; j<hauteur ; j++ )	//stock les valeurs de l'image dans un tableau 
	    {
	      for( i = 0 ; i<largeur ; i++ )
		{
		  tab[(j*hauteur)+i] = fgetc(image);
		  fgetc(image);
		}
	    }	  
	  changementCarre( tab , hauteur , largeur );	//appelle la fonction changement de caractère
	  affichage( tab , hauteur , largeur);	//appelle la fonction d'affichage de l'image
	  fclose(image);
	}
      system("stty cbreak -echo");	//permet de fermer l'écran grâce à une touche de l'utilisateur
      getchar();
      system("stty cooked echo");
      system("clear");
     
    }
}


