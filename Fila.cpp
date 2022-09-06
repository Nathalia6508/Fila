#include <stdio.h>
#include <stdlib.h>
#include <iostream>

#define DIMENSAO 5


typedef struct 
{
	int tamanho;
	int item[DIMENSAO];	
} FILA;

void inicializar(FILA &f);
void adicionar(FILA &f2, int item);
bool filacheia(FILA &f);
int menu();
void mostrarFila(FILA &f2);
int remover(FILA &f2);

int main(int argc, char** argv)
{
	FILA f;
	int opcao;
	
	do
	{
		opcao = menu();
		switch (opcao)
		{
			case 1: {
				inicializar(f);
				break;
			}
			case 2:{
				int item;
				printf ("Digite um número: ");
				scanf("%i", &item);
				adicionar(f, item);
				break;
			}
			case 3:{
				mostrarFila(f);
				break;
			}
			case 4:{
				remover(f);
				break;
			}
		}
	}
	while (opcao != 0);
		return 0;

}

void inicializar(FILA &f2)
{
	f2.tamanho = 0;
	printf("\nFila inicializada\n");
}

void adicionar(FILA &f2, int item)
{
	if (filacheia(f2))
	{
		printf("Fila cheia\n");
	}
	
	else
	{	
		f2.item[f2.tamanho] = item;
		f2.tamanho++;
		printf("\nAdicionado %i a fila", item);
	}
}

bool filacheia(FILA &f)
{
	return(f.tamanho == DIMENSAO);
}

int menu()
{
	int opcao;
	printf("1- inicializar\n");
	printf("2- Adicionar\n");
	printf("3- Mostrar\n");
	printf("4- Remover\n");
	printf("0- Sair\n");
	printf("Selecione a opcao: ");
	scanf("%i", &opcao);
	return opcao;
}

void mostrarFila(FILA &f2)
{
	int i;
	for(i=0; i<f2.tamanho; i++)
	{
		printf("%i\n", f2.item[i]);
	}
}

int remover(FILA &f2)
{
	int item = f2.item[0];
	int i;
	
	for(i=1; i<f2.tamanho; i++)
	{
		f2.item[i-1] = f2.item[i];
	}
	
	f2.tamanho--;
	return item;
}
