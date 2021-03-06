#include <stdio.h>
#include <locale.h>
#include "Grafo.h"
#include "Aresta.h"
#include "Vertice.h"

int main() {
	setlocale(LC_ALL, "");
	Grafo * g = criar_grafo();
	Vertice * v1 = criar_vertice("v1");
	Vertice * v2 = criar_vertice("v2");
	Vertice * v3 = criar_vertice("v3");
	Vertice * v4 = criar_vertice("v4");
	Aresta * a1 = criar_aresta("a1", v1, v2, 20);
	Aresta * a2 = criar_aresta("a2", v2, v3, 10);
	Aresta * a3 = criar_aresta("a3", v3, v4, 40);

	adicionar_vertice(g, v1);
	adicionar_vertice(g, v2);
	adicionar_vertice(g, v3);
	adicionar_vertice(g, v4);
	adicionar_aresta(g, a1);
	adicionar_aresta(g, a2);
	adicionar_aresta(g, a3);


	imprimir_grafo(g);
	
	printf("digite qualquer coisa para finalizar\n");
	getchar();
	return 0;
}