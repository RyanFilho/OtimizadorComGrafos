#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "Grafo.h"
#include "Aresta.h"
#include "Vertice.h"

#define true 1
#define false 0


struct grafo {
	Aresta ** aresta;
	Vertice ** vertice;
	int qtd_arestas; //Total de arestas no grafo
	int qtd_vertices; //Total de vertices no grafo
};


Grafo * criar_grafo() {
	Grafo * g = (Grafo *)malloc(sizeof(Grafo));
	g->vertice = (Vertice **)malloc(50 * sizeof(Vertice *));
	g->aresta = (Aresta **)malloc(50 * sizeof(Aresta *));

	g->qtd_arestas = 0;
	g->qtd_vertices = 0;

	return g;
}

void destruir_grafo(Grafo * g) {
	if (g == NULL) {
		printf("\nErro");
		return;
	}

	if (g->aresta != NULL) {
		int i = 0;
		int tam = g->qtd_arestas;
		do {
			destruir_aresta(g->aresta[i]);
			i++;
		} while (i < tam);
	}

	if (g->vertice != NULL) {
		int i = 0;
		int tam = g->qtd_vertices;
		do {
			destruir_vertice(g->vertice[i]);
			i++;
		} while (i < tam);
	}
	g->qtd_arestas = 0;
	g->qtd_vertices = 0;
	free(g->vertice);
	free(g->aresta);
	free(g);
}


void adicionar_vertice(Grafo * g, Vertice * v) {
	if (g != NULL && v != NULL) {
		int tam = g->qtd_vertices;
		g->vertice[tam++] = v;
		g->qtd_vertices++;
	}
}

void adicionar_aresta(Grafo * g, Aresta * a) {
	if (g != NULL && a != NULL) {
		int tam = g->qtd_arestas;
		g->aresta[tam++] = a;
		g->qtd_arestas++;
	}
}

void remover_aresta(Grafo * g, Aresta * a) {
	if (g != NULL && a != NULL) {
		int i, tam;
		tam = g->qtd_arestas;

		for (i = 0; i < tam; i++) {
			if (g->aresta[i] == a) {
				int j = i;
				while (j < tam) {
					g->aresta[j] = g->aresta[j + 1];
					j++;
				}
				g->qtd_arestas--;
			}
		}
	}
}

void remover_vertice(Grafo * g, Vertice * v) {
	if (g != NULL && v != NULL) {
		int i, tam_v, tam_a;
		tam_v = g->qtd_vertices;
		tam_a = g->qtd_arestas;

		for (i = 0; i < tam_a; i++) {
			if (getOrigem_aresta(g->aresta[i]) == v || getDest_aresta(g->aresta[i]) == v) {
				remover_aresta(g, g->aresta[i]);
			}
		}

		for (i = 0; i < tam_v; i++) {
			if (g->vertice[i] == v) {
				int j = i;
				while (j < tam_v) {
					g->vertice[j] = g->vertice[j + 1];
					j++;
				}
				g->qtd_vertices--;
			}
		}

	}
}

int arestas_grafo(Grafo * g) {
	if (g != NULL && g->qtd_arestas != NULL) {
		return g->qtd_arestas;
	}
	return false;
}

int vertices_grafo(Grafo * g) {
	if (g != NULL && g->qtd_vertices != NULL) {
		return g->qtd_vertices;
	}
	return false;
}

int buscar_vertice(Grafo * g, Vertice * v) {
	if (g != NULL) {
		int i, tam;
		tam = g->qtd_vertices;

		for (i = 0; i < tam; i++) {
			if (g->vertice[i] == v) {
				return true;
			}
		}
	}
	return false;
}

int buscar_aresta(Grafo * g, Aresta * a) {
	if (g != NULL) {
		int i, tam;
		tam = g->qtd_arestas;

		for (i = 0; i < tam; i++) {
			if (g->aresta[i] == a) {
				return true;
			}
		}
	}
	return false;
}

void imprimir_grafo(Grafo * g) {
	/*  imprime o grafo na tela. Para definir a forma que seu programa deve imprimir o grafo na
	tela, considere um grafo com n v�rtices, m arestas, identificadores de v�rtices v1, v2, ...,
	vn, identificadores de arestas a1, a2, ..., am com respectivos valores x1, x2, ..., xm. Assuma
	ainda que ui e wi representam os identificadores dos v�rtices em que a aresta ai incide,
	sendo extra�dos do conjunto {v1, ..., vn}. A sa�da do comando deve ser a seguinte:
	Qtd de v�rtices: n
	v1 v2 ... vn
	Qtd de arestas: m
	a1 u1 w1 x1
	a2 u2 w2 x2
	...
	am um wm xm
	Os identificadores de v�rtices devem ser impressos em ordem crescente: v1 < v2 < ... < vn
	Os identificadores de arestas devem ser impressos em ordem crescente: a1 < a2 < ... < am
	Os identificadores de v�rtices em que a aresta ai incide devem ser impressos em ordem
	crescente: ui < wi */

	if (g != NULL) {
		int i = 0;
		printf("\n Informações do Grafo");
		printf("\n Vértices:");
		printf("\n Quantidade de Vértices: %d", vertices_grafo(g));
		

		if (g->vertice != NULL) {
			int tam = g->qtd_vertices;
			do {
				imprimir_vertice(g->vertice[i++]);
			} while (tam > i);
		}
		else {
			printf("\n\tErro");
		}
		i = 0;
		printf("\n\n Arestas:");
		printf("\n Quantidade de Arestas: %d", arestas_grafo(g));

		if (g->aresta != NULL) {
			int tam = g->qtd_arestas;
			do {
				imprimir_aresta(g->aresta[i++]);
			} while (tam > i);
		}
		else {
			printf("\n\tErro");
		}
		printf("\n");

	}
	else {
		printf("\nErro");
	}
}


int caminhoMinimo() {
	return -1;
}