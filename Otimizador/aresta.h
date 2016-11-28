#ifndef ARESTA_H
#define ARESTA_H

#include "vertice.h"

typedef struct aresta Aresta;


Aresta * criar_aresta(char * id, Vertice * origem, Vertice * destino, int peso);
void destruir_aresta(Aresta * a);

void trocar_peso_aresta(Aresta * a, int x);

char * getID_aresta(Aresta * a);
int getPeso_aresta(Aresta * a);
Vertice * getOrigem_aresta(Aresta * a);
Vertice * getDest_aresta(Aresta * a);

void imprimir_aresta(Aresta * a);
#endif