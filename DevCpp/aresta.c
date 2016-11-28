#define _CRT_SECURE_NO_WARNINGS
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "Aresta.h"
#include "Vertice.h"


#define true 1
#define false 0

struct aresta
{
	char* id;
	int peso;
	Vertice* origem;
	Vertice* destino;
};

Aresta * criar_aresta(char * id, Vertice * origem, Vertice * destino, int peso) {
	if (origem != NULL || destino != NULL) {
		Aresta * a = (Aresta*)malloc(sizeof(Aresta));
		a->id = (char*)malloc(30 * sizeof(char));

		/*
		a->origem = (Vertice*)malloc(sizeof(Vertice));
		a->destino = (Vertice*)malloc(sizeof(Vertice));
		*/

		a->origem = origem;
		a->destino = destino;
		a->peso = peso;
		strncpy(a->id, id, 3);

		return a;
	}
	return NULL;
}

void destruir_aresta(Aresta * a) {
	if (a == NULL) {
		printf("\nErro");
		return;
	}
	free(a->id);
	free(a->origem);
	free(a->destino);
	free(a);
}

char * getID_aresta(Aresta * a) {
	if (a != NULL) {
		return a->id;
	}
	else {
		return false;
	}
}

int getPeso_aresta(Aresta * a) {
	if (a != NULL) {
		return a->peso;
	}
	else {
		return false;
	}
}

Vertice * getOrigem_aresta(Aresta * a) {
	if (a != NULL) {
		return a->origem;
	}
	else {
		return false;
	}
}

Vertice * getDest_aresta(Aresta * a) {
	if (a != NULL) {
		return a->destino;
	}
	else {
		return false;
	}
}
void trocar_peso_aresta(Aresta * a, int x) {
	a->peso = x;
}

void imprimir_aresta(Aresta * a) {
	if (a != NULL) {
		printf("\n Identificador: %s; Origem: %s; Destino: %s; Peso: %d", a->id, getID_vertice(a->origem), getID_vertice(a->destino), a->peso);
		//printf("\n\t Peso: %d\n", a->peso);
		//printf("\n\t V?rtice Origem: %s", a->origem);
		//printf("\n\t V?rtice Destino: %s", a->destino);
	}
	else {
		printf("\nErro");
	}
}
