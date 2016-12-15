#include	<unistd.h>
#include	<stdlib.h>
#include	<stdio.h>
#include	<sys/types.h>
#include	<sys/wait.h>
#include	<time.h>

int	aleatoire()
{
  srand(time(NULL));
  int alea = rand()%(3);
  return (alea);
}

int     historique(int alea)
{
  FILE* fichier = NULL;
  time_t t = time(NULL);
  fichier = fopen("historique.txt", "a");
  if (fichier != NULL)
    {
      fputs("\n\n______________________________________________________", fichier);
      fputs("\n************ Heure d'ouverture du fichier ************|\n\n", fichier);
      fprintf(fichier,"               %s", ctime(&t));
      switch(alea)
	{
	case 0:
	  fprintf(fichier,"\n             exia_saver_static a ete lance\n");
	  fputs("\n______________________________________________________|", fichier);
	  break;
	case 1:
	  fprintf(fichier, "\n           exia_saver_dynamique a ete lance\n");
	  fputs("\n______________________________________________________|", fichier);
	  break;
	case 2:
	  fprintf(fichier, "\n           exia_saver_interactif a ete lance\n");
	  fputs("\n______________________________________________________|", fichier);
	  break;
	}
      fclose(fichier);
    }
  else
    printf("erreur");
  return 0;
}

int stats( int variable ) {
  int img[5], prog[3];
  if( variable < 8 && variable > 0 ) {
    FILE* stat = NULL;
    stat = fopen("stats.s", "r");
    fscanf(stat, "%d %d %d %d %d %d %d %d", &img[0], &img[1], &img[2], &img[3], &img[4], &prog[0], &prog[1], &prog[2]);
    fclose(stat);
    stat = fopen("stats.s", "w+");
    switch(variable) {
    case 1:
      img[0] = img[0] + 1;
      prog[0] = prog[0] + 1;
      break;
    case 2:
      img[1] = img[1] + 1;
      prog[0] = prog[0] + 1;
      break;
    case 3:
      img[2] = img[2] + 1;
      prog[0] = prog[0] + 1;
      break;
    case 4:
      img[3] = img[3] + 1;
      prog[0] = prog[0] + 1;
      break;
    case 5:
      img[4] = img[4] + 1;
      prog[0] = prog[0] + 1;
      break;
    case 6:
      prog[1] = prog[1] + 1;
      break;
    case 7:
      prog[2] = prog[2] + 1;
      break;
    default:
      printf("Erreur, valeur incorrect");
      break;
    }
    fseek(stat, 0, SEEK_SET);
    fprintf(stat, "%d %d %d %d %d %d %d %d", img[0], img[1], img[2], img[3], img[4], prog[0], prog[1], prog[2]);
  }
  else {
    menu();
  }
  return 0;
}

int menu () {
  int choix = 0, img[5], prog[3];
  system("clear");
  puts("***************************");
  puts("*                         *");
  puts("*      Statistique        *");
  puts("*                         *");
  puts("***************************\n");
  puts("1. Nombre d'execution des programmes");
  puts("2. Aide");
  puts("3. ExiaSaver_Static");
  puts("4. ExiaSaver_Dynamique");
  puts("5. ExiaSaver_Interactif");
  puts("6. Quittez");
  printf("Entrez le numero du menu souhaite: ");
  FILE* stat = NULL;
  stat = fopen("stats.s", "r");
  fscanf(stat, "%d %d %d %d %d %d %d %d", &img[0], &img[1], &img[2], &img[3], &img[4], &prog[0], &prog[1], &prog[2]);
  fclose(stat);
  scanf("%d", &choix);
  switch( choix ) {
  case 1:
    system("clear");
    puts("***************************");
    puts("*                         *");
    puts("*       Programme         *");
    puts("*                         *");
    puts("***************************\n");
    printf("Le programme statique a ete execute: %d fois\n", prog[0]);
    printf("Le programme dynamique a ete execute: %d fois\n", prog[1]);
    printf("Le programme interactif a ete execute: %d fois\n", prog[2]);
    printf("\n**On a donc dans l'ordre execute les programmes**\n");
    tri( prog , 3 );
    printf("      %d fois, %d fois et %d fois\n\n", prog[0], prog[1], prog[2]);
    break;
  case 2:
    system("clear");
    puts("*****Fonctionnalite des programmes*****\n");
    puts("**Programme statique**");
    puts("Le programme affiche une image choisi aleatoirement dans");
    puts("une selection de 5 images.");
    puts("Action utilisateur: Aucune\n");
    puts("**Programme dynamique**");
    puts("Le programme affiche une horloge s'actualisant a un temps");
    puts("t choisi dans le code du programme et a une taille elle aussi");
    puts("choisi dans le code du programme.");
    puts("Action utilisateur: Possible modification des variables tailles et temps\n");
    puts("**Programme interactif**");
    puts("Le programme affiche un avion pouvant se deplacer dans l'espace");
    puts("et traverser les murs.");
    puts("Action utilisateur: E,S,D,F pour controler l'avion.\n");
    break;
  case 3:
    system("clear");
    system("/home/antoine/exia/projet/exiasaver/exia_saver_statique");
    break;
  case 4:
    system("clear");
    system("/home/antoine/exia/projet/exiasaver/exia_saver_dynamique");
    break;
  case 5:
    system("clear");
    system("/home/antoine/exia/projet/exiasaver/exia_saver_interactif");
    break;
  case 6:
    return 0;
    break;
  default:
    menu();
    break;
  }
}

int tri( int *tab , int taille ) {
  int passage = 0;
  int permutation = 1;
  int en_cours;
  while ( permutation == 1 ) {
    permutation = 0;
    passage ++;
    en_cours=0;
    for ( en_cours ; en_cours<taille-passage ; en_cours++ ) {
      if (tab[en_cours]>tab[en_cours+1]){
	permutation = 1;
	int temp = tab[en_cours];
	tab[en_cours] = tab[en_cours+1];
	tab[en_cours+1] = temp;
      }
    }
  }
  return (0);
}

int	main(int ac, char **av)
{
  int i;
  int z;
  if (ac == 1)
    {
      z = 0;
      system("clear");
      int alea  = aleatoire();
      switch(alea)
	{
	case 0:
	  system("/home/antoine/exia/projet/exiasaver/exia_saver_statique");
	  stats(1);
	  break;
	case 1:
	  system("/home/antoine/exia/projet/exiasaver/exia_saver_dynamique");
	  stats(6);
	  break;
	case 2:
	  system("/home/antoine/exia/projet/exiasaver/exia_saver_interactif");
	  stats(7);
	  break;
	}
      historique(alea);
    }
  else if (av[1][0] == '-' && av[1][1] == 's' && av[1][2] == 't' && av[1][3] == 'a' && av[1][4] == 't')
    stats(0);
  return (0);
}


