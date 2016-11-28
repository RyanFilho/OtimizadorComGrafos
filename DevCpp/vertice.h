#ifndef VERTICE_H
#define VERTICE_H

typedef struct vertice Vertice;

Vertice * criar_vertice(char * id);
void destruir_vertice(Vertice * v);

char * getID_vertice(Vertice * v);
float getDist_vertice(Vertice * v);
Vertice * getAnt_vertice(Vertice * v);
void setDist_vertice(Vertice * v, float d);
void setAnt_vertice(Vertice * v, Vertice * anterior);


void imprimir_vertice(Vertice * v);

#endif
