#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
typedef struct Cellule* Liste;
struct Cellule
{
	int nombre;
	struct Cellule* suivant;
};
Liste initialisation(int nombre);
void insertion_fin(Liste debut, int data);
void insertion_debut(Liste* debut, int data);
void insertion_milieu(Liste debut, int data,int position);
void supprimer_cellule(Liste debut, int position);
void afficher_liste(Liste debut);
int count(Liste debut);
int main()
{
	Liste debut = NULL;
	insertion_debut(&debut, 2);
	insertion_debut(&debut, 3);
	insertion_fin(debut, 4);
	insertion_fin(debut, 5);
	insertion_milieu(debut, 6, 3); //les incice b7al les tableau za3ma : 0-1-2-3 ....
	afficher_liste(debut);
	supprimer_cellule(debut,3);
	printf("===============================\n");
	afficher_liste(debut);
	int t;
	return 0;
}

Liste initialisation(int nombre)
{
	Liste temp = malloc(sizeof(struct Cellule));
	//if (temp == NULL) exit(EXIT_FAILURE);
	temp->nombre = nombre;
	temp->suivant = NULL;
	return temp;
}

void insertion_fin(Liste debut, int data)
{
	Liste temp, p;
	temp = initialisation(data);
	if (debut == NULL)
	{
		debut = temp;
	}
	else
	{
		p = debut;
		while (p->suivant != NULL)
		{
			p = p->suivant;
		}
		p->suivant = temp;
	}
}

void insertion_debut(Liste* debut, int data)
{
	Liste temp;
	temp = initialisation(data);
	if (*debut == NULL)
	{
		*debut = temp;

	}
	else
	{
		temp->suivant = *debut;
		*debut = temp;
	}
}

void insertion_milieu(Liste debut, int data, int position)
{
	//assert(position > 0 || position < count(debut));
	Liste temp, p;
	temp = initialisation(data);
	p = debut;
	for (int i = 0; i < position-1; ++i)
	{
		p = p->suivant;
	}
	temp->suivant = p->suivant;
	p->suivant = temp;

}

void supprimer_cellule(Liste debut, int position)
{
	//assert(position > 0 || position < count(debut));
	Liste p;
	p = debut;
	for (int i = 0; i < position - 1; ++i)
	{
		p = p->suivant;
	}
	p->suivant = p->suivant->suivant;
}

void afficher_liste(Liste debut)
{
	Liste p;
	p = debut;
	while (p != NULL)
	{
		printf("%d -> ", p->nombre);
		p = p->suivant;
	}
	printf("NULL\n");
}

int count(Liste debut)
{
	int cpt = 0;
	Liste p = debut;
	while (p != NULL)
	{
		cpt++;
		p = p->suivant;
	}
	return cpt;
}

