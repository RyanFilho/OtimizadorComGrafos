#ifndef GRAFO_H
#define GRAFO_H

#include "Aresta.h"
#include "Vertice.h"
typedef struct grafo Grafo;


Grafo * criar_grafo();
void destruir_grafo(Grafo * g);

void adicionar_vertice(Grafo * g, Vertice * v);
void adicionar_aresta(Grafo * g, Aresta * a);

void remover_aresta(Grafo * g, Aresta * a);
void remover_vertice(Grafo * g, Vertice * v);

int arestas_grafo(Grafo * g);
int vertices_grafo(Grafo * g);

int buscar_vertice(Grafo * g, Vertice * v);
int buscar_aresta(Grafo * g, Aresta * a);

void imprimir_grafo(Grafo * g);

#endif
