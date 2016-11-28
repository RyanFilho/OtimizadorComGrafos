#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <math.h>
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
	
	system("pause");
	return 0;
}

int caminhoMinimo(Grafo * g, Vertice * origem, Vertice * destino){
	int i = 0;
	int j = 0;
	Vertice ** vs = (Vertice **) malloc(50 * sizeof(Vertice *));
	vs = todos_vertices(g);
	
	Aresta ** as = (Aresta **) malloc(50 * sizeof(Aresta *));
	as = todas_arestas(g);
	
	for(i = 0; i < vertices_grafo(g); i++){
		if (vs[i] == origem){
			setDist_vertice(origem, 0);
			
		}else{
			setDist_vertice(vs[i], INFINITY);
			setAnt_vertice(vs[i], NULL);
		}
	}
	
	for (i = 1; i <= vertices_grafo(g) - 1; ++i)
	{
		for (j = 0; j < arestas_grafo(g); ++j)
		{
			Vertice * origem = getOrigem_aresta(as[j]);
			Vertice * destino = getDest_aresta(as[j]);
			int peso = getPeso_aresta(as[j]);

			if (getDist_vertice(origem) != INFINITY && getDist_vertice(origem) + peso < getDist_vertice(destino))
				getDist_vertice(destino) = getDist_vertice(origem) + peso;
				setAnt_vertice(destino, origem);
		}
	}
	
	for (i = 0; i < arestas_grafo(g); ++i)
	{
		Vertice * origem = getOrigem_aresta(as[j]);
		Vertice * destino = getDest_aresta(as[j]);
		int peso = getPeso_aresta(as[j]);

		if (getDist_vertice(origem) != INFINITY && getDist_vertice(origem) + peso < getDist_vertice(destino))	
			printf("O grafo possui um ciclo de peso negativo.");
	}
	
	return 0;
}
