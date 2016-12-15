#ifndef	FONCT_H_
#define	FONCT_H_

typedef struct heureActuel heureActuel;
struct heureActuel {
  int dizaineH;
  int uniteH;
  int dizaineM;
  int uniteM;
  int dizaineS;
  int uniteS;
};

void	decompositionChiffre(int chiffre, int *dizaine, int *unite);
void	insertionValeurs(int **tab, heureActuel Decomposition);
int	insertionImage(int **tab, FILE** image, int j);
void	agrandir(int **tab, int hauteurP, int largeurP);
void	changementValeurs(int **tab, int hauteurP, int largeurP);
void	affichage(int **tab, int hauteurP, int largeurP, int temps);
int	choixImage(FILE** image, int valeur);
int	temps_attente(int x, int temps);

#endif /*FONCT_H_*/
