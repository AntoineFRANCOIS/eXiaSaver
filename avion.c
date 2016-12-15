
#include <stdlib.h>
#include <stdio.h>
#include <ncurses.h>


int main()
{
/* Initialisation de toutes les valeurs liées à l'affichage*/
FILE* image = NULL;
FILE* imageHaut = NULL;
FILE* imageBas = NULL;
FILE* imageDroite = NULL;
FILE* imageGauche = NULL;

int resultx, resulty, ytot, xtot, movx, movy, yforme, xforme, inter, transfertx, transferty;
int intery = 0;
int interx = 0;

char userinput = 0; // Variable qui contiendra la touche de l'utilisateur
char userlast = 8; // Variable qui contient la dernière touche utilisée par l'utilisateur, initialisée à "haut"
initscr();
getmaxyx(stdscr, ytot, xtot);
endwin();

image = fopen("/home/antoine/exia/projet/exiasaver/proj3/upship.pbm", "r"); 

fseek(image, 3, SEEK_SET); 

fscanf(image, "%d %d", &xforme, &yforme); 

fgetc(image);

int* tableau = NULL; // Initialisation du tableau dynamique qui contiendra l'image
tableau = malloc(xforme*yforme * sizeof(int)); // On alloue un tableau qui pourra contenir jusqu'à xtot*ytot valeurs en int, liées à la taille totale de la console.


 imageHaut = fopen("/home/antoine/exia/projet/exiasaver/proj3/upship.pbm", "r");
fseek(imageHaut, 7, SEEK_SET);

imageBas = fopen("/home/antoine/exia/projet/exiasaver/proj3/downship.pbm", "r");
fseek(imageBas, 7, SEEK_SET);

imageDroite = fopen("/home/antoine/exia/projet/exiasaver/proj3/rightship.pbm","r");
fseek(imageDroite, 7, SEEK_SET);

imageGauche = fopen("/home/antoine/exia/projet/exiasaver/proj3/leftship.pbm", "r");
fseek(imageGauche, 7, SEEK_SET);

image = imageDroite;

inter = 0; 
for (int i = 0; i < yforme; i++)
	{
		for(int j = 0; j < xforme; j++)
		{
		tableau[inter+j] = fgetc(image); 
		fgetc(image); 
		}
		inter = inter + xforme; 
	}

for (int i = 0; i < yforme*xforme; i++)  
{
	switch (tableau[i]){
		case  48:
		tableau[i] = 255;
			break;
		case  49:
			tableau[i] = 254;
			break;
		default:
			//printf("Error\n");
			break;
	}
}

inter = xforme/2;
resultx = (xtot/2) - inter;

inter = yforme/2;
resulty = (ytot/2) - inter;

for (int i = 0; i < resulty; i++)
{
	printf("\n");
}

inter = 0;
for (int i = 0; i < yforme; i++)
{
	for (int j = 0; j < resultx; j++)
	{
		printf(" ");
	}
	for (int j = 0; j < xforme; j++)
	{
		printf("%c", tableau[inter+j]);
	}
	inter = inter + xforme;
	printf("\n");
}
for (int i = 0; i < resulty; i++)
{
	printf("\n");
}

while (1) //Boucle répétant la demande d'input, et qui gère l'affichage de l'avion selon l'appui.
{
	scanf("%c", &userinput);

	switch (userinput)
	{
		case 100:		// Pour d, l, 2
		case 108:
		case 50:
			image = imageBas;
			userlast = userinput;
			fseek(image, 7, SEEK_SET);
			movy = movy + 1;
			break;
		case 101:		// Pour e, o, 8
		case 111:
		case 56:
			image = imageHaut;
			userlast = userinput;
			fseek(image, 7, SEEK_SET);
			movy = movy - 1;
			break;
		case 115:		// Pour s, k, 4
		case 107:
		case 52:
			image = imageGauche;
			userlast = userinput;
			fseek(image, 7, SEEK_SET);
			movx = movx - 1;
			break;
		case 102:		// Pour f, m, 6
		case 109:
		case 54:
			image = imageDroite;
			userlast = userinput;
			fseek(image, 7, SEEK_SET);
			movx = movx + 1;
			break;
		case 113:		// Pour q, Q
		case 81:
			system("clear");
			exit(0);
		default : 		// Pour tout le reste, on vérifie la dernière commande
			switch (userlast)
		{
			case 100:
			case 108:
			case 50:
				fseek(image, 7, SEEK_SET);
				movy = movy + 1;
				break;
			case 101:
			case 111:
			case 56:
				fseek(image, 7, SEEK_SET);
				movy = movy - 1;
				break;
			case 115:
			case 107:
			case 52:
				fseek(image, 7, SEEK_SET);
				movx = movx - 1;
				break;
			case 102:
			case 109:
			case 54:
				fseek(image, 7, SEEK_SET);	
				movx = movx + 1;
				break;
		}
		break;
	}
		inter = 0;
		for (int i = 0; i < yforme; i++)
		{
			for(int j = 0; j < xforme; j++)
			{
				tableau[inter+j] = fgetc(image); 
				fgetc(image); 
			}
			inter = inter + xforme; 
		}

		system("clear");
	
		if (movx <= xtot/2 - xtot)
		{
			movx = xtot/2;
		}
		else if (movx >= xtot - xtot/2)
		{
			movx = -(xtot/2);
		}
			
		if (movy <= ytot/2 - ytot)
		{
			movy = ytot/2;
		}
		else if (movy >= ytot - ytot/2)
		{
			movy = -(ytot/2);
		}
			

	for (int i = 0; i < yforme*xforme; i++)  
		{
		switch (tableau[i]){
			case  48:
				tableau[i] = 255;
				break;
			case  49:
				tableau[i] = 254;
				break;
			default:
				//printf("Error\n");
				break;
		}
		
	if (movx >= xtot - (xforme/2))
	{
		transfertx = movx - (xtot/2) + (xforme/2);
	}
	else if (movx <= (xforme/2) - (xtot/2) )
	{
		transfertx = -(xforme + movx);
	}
	else transfertx = 0;
	
	if (movy >= ytot - (yforme/2))
	{
		transferty = movy - (ytot/2) + (yforme/2);
	}
	else if (movy <= (yforme/2) - (ytot/2))
	{
		transferty = -(yforme + movy);
	}
	else transferty = 0;
	
	inter = 0;
	if (transferty == 0 && transfertx == 0) // Cas quand l'avion ne traverse pas de bords
	{

		for (int i = 0; i < ((ytot/2) + movy - (yforme/2)); i++)
		{
			printf("\n");
		}
		
		for (int i = 0; i < yforme; i++)
		{
			for (int j = 0; j < ((xtot/2) + movx - (xforme/2)); j++)
			{
				printf(" ");
			}
			
			for (int j = 0; j < xforme; j++)
			{
				printf("%c ", tableau[j+inter]);
			}
			
			printf("\n");
			inter = inter + xforme;
		}
		
		for (int i = 0; i < ((ytot/2)- movy - (yforme/2));i++)
		{
			printf("\n");
		}
	}
	
	else if (transferty != 0 && transfertx == 0) // Cas où l'avion traverse le Haut ou le Bas
	{
		if (movy > 0)
		{
			for (int i = yforme - transferty; i < yforme; i++)
			{
				for (int j = 0; j < ((xtot/2) - movx - xforme/2); j++)
				{
					printf(" ");
				}	
			
				for (int j = 0 ; j < xforme; j++)
				{
					printf("%c ", tableau[(i*xforme)+j]);
				}
				
				printf("\n");
			}
			
			for (int i = 0; i < ytot - yforme; i++)
			{
				printf("\n");
			}
		
			for (int i = 0; i < yforme - transferty; i++)
			{
				for (int j = 0; j < (xtot/2) - movx - xforme/2; j++)
				{
					printf(" ");
				}
		
				for (int j = 0; j < xforme; j++)
				{
					printf("%c ", tableau[(i*xforme)+j]);
				}
				
				printf("\n");
			}
		}

		else
		{
			for (int i = transferty; i < yforme; i++)
			{
				for (int j = 0; j < (xtot/2) + movx - xforme/2; j++)
				{
					printf(" ");
				}	
			
				for (int j = 0 ; j < xforme; j++)
				{
					printf("%c ", tableau[(i*xforme)+j]);
				}
				
				printf("\n");
			}
			
			for (int i = 0; i < ytot - yforme; i++)
			{
				printf("\n");
			}
		
			for (int i = 0; i < transferty; i++)
			{
				for (int j = 0; j < (xtot/2) + movx - xforme/2; j++)
				{
					printf(" ");
				}
		
				for (int j = 0; j < xforme; j++)
				{
					printf("%c ", tableau[(i*xforme)+j]);
				}
				
				printf("\n");
			}
		}
	}

	else if (transferty == 0 && transfertx != 0) // Cas où l'avion traverse la Gauche ou la Droite
	{

		for (int i = 0; i < ((ytot/2)- movy - (yforme/2));i++)
		{
			printf("\n");
		}
		
		for (int i = 0; i < yforme; i++)
		{
			for (int j = transfertx; j < xforme; j++)
			{
				printf("%c ", tableau[(i*xforme)+j]);
			}
		
			for (int j = 0; j < xtot - xforme; j++)
			{
				printf(" ");
			}
		
			for (int j = 0; j < xforme - transfertx; j++)
			{
				printf("%c ", tableau[(i*xforme)+j]);
			}
			
			printf("\n");
		}
		for  (int i = 0; i < ((ytot/2)- movy - (yforme/2)); i++)
		{
			printf("\n");
		}
	}
	else 	// Cas où le centre de l'avion se trouve dans un coin
	{
		if (movx > 0 && movy > 0) // Coin bas droite
		{			
			for (int i = transferty; i < yforme; i++)
			{
				for (int j = transfertx; j < xforme; j++)
				{
					printf("%c ", tableau[(i*xforme)+j]);
				}
				
				for (int j = 0; j < xtot - xforme; j++)
				{
					printf(" ");
				}
				
				for (int j = 0; j < xforme - transfertx; j++)
				{
					printf("%c ", tableau[(i*xforme)+j]);
				}
			}

			for (int i = 0; i < ytot - yforme; i++);
			{
				printf("\n");
			}

			for (int i = 0; i < transferty; i++)
			{
				for (int j = 0; j < transfertx; j++)
				{
					printf("%c", tableau[(i*xforme)+j]);
				}

				for (int j = 0; j < xtot - xforme; j++)
				{
					printf(" ");
				}

				for (int j = 0; j < transfertx; j++)
				{
					printf("%c ", tableau[(i*xforme)+j]);
				}
			}
		}

		else if (movx > 0 && movy < 0) // Coin haut droite
		{
			for (int i = transferty; i < yforme; i++)
			{
				for (int j = xforme - transfertx; j < xforme;j++)
				{
					printf("%c ", tableau[(i*xforme)+j]);
				}
				
				for (int j = 0; j < xtot - xforme; j++)
				{
					printf(" ");
				}

				for (int j = 0; j < xforme - transfertx; j++)
				{
					printf("%c ", tableau[(i*xforme)+j]);
				}

				printf("\n");
			}
			for (int i = 0; i < ytot - yforme; i++)
			{
				printf("\n");
			}
			for (int i = 0; i < transferty; i++)
			{
				for (int j = xforme - transfertx; j < xforme;j++)
				{
					printf("%c ", tableau[(i*xforme)+j]);
				}
				
				for (int j = 0; j < xtot - xforme; j++)
				{
					printf(" ");
				}

				for (int j = 0; j < xforme - transfertx; j++)
				{
					printf("%c ", tableau[(i*xforme)+j]);
				}

				printf("\n");	
			}
		}
		else if (movx < 0 && movy > 0) // Coin bas gauche
		{
					
		}
		else 			       // Coin haut gauche
		{
			
		}
		}
	}
}
fclose(image);
system("clear");
}
