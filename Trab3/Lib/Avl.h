#include <stdio.h>
#include <stdlib.h>
#include "Produto.h"

#ifndef AVL_H
#define AVL_H

typedef struct avl{
  int id, altura,index;
  struct avl* esq;
  struct avl* dir;
  struct avl* pai;
}avl;

avl* criaAvl();

int taCerto(avl *atu, int n);

avl* inserirAvl(avl *a,int id);

void imprimeAvl(avl *a, int val);

avl* buscaAvl(avl *a, int id);

avl* liberaAvl(avl *a);

int taBalanceada(avl *atu);

void BuscaArvArq(FILE *fp,avl *arv, int id);

avl* ArvIndexada(FILE *fp, avl *arv, char nome[][30]);

void PreencheArq(FILE *fp, char nome[][30]);

void MostraProduto(Produto current);

void ConditionalSearch(FILE *fp, avl *arv, void *value, int(*f)(void*, void*));

#endif