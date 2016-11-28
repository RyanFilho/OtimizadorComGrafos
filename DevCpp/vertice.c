#define _CRT_SECURE_NO_WARNINGS
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <math.h>
#include "Vertice.h"


#define true 1
#define false 0

struct vertice
{
	char* id;
	float distancia;
	Vertice *anterior;
};

Vertice * criar_vertice(char * id) {
	Vertice * v = (Vertice*)malloc(sizeof(Vertice));
	v->id = (char*)malloc(10 * sizeof(char));

	strcpy(v->id, id);
	v->distancia = INFINITY;
	v->anterior = NULL;

	return v;
}


void destruir_vertice(Vertice * v) {
	if (v == NULL) {
		printf("\nErro");
		return;
	}
	free(v->id);
	free(v->anterior);
	free(v);
}

char * getID_vertice(Vertice * v) {
	if (v != NULL) {
		return v->id;
	}
	else {
		return false;
	}
}

float getDist_vertice(Vertice * v) {
	if (v != NULL) {
		return v->distancia;
	}
	else {
		return -1;
	}
}

Vertice * getAnt_vertice(Vertice * v) {
	if (v != NULL) {
		return v->anterior;
	}
	else {
		return false;
	}
}

void setDist_vertice(Vertice * v, float d) {
    if (v != NULL) {
        v->distancia = d;
    }
}

void setAnt_vertice(Vertice * v, Vertice * anterior) {
    if (v != NULL) {
        v->anterior = anterior;
    }
}

void imprimir_vertice(Vertice * v) {
	if (v != NULL) {

		printf("\n Id: %s; Distancia: %f", v->id, v->distancia);
	}
	else {
		printf("\nErro");
	}
}
