#include<stdio.h>
#include<stdlib.h>

typedef struct avl{
  int id, altura,index;
  struct avl* esq;
  struct avl* dir;
  struct avl* pai;
}avl;

typedef struct Produto{
	int id; 		//4	(CHAVE)
	int modelo;  	// 4
	float custo; 	// 4
	char nome[32];	// 32
	int quantidade; //4
}Produto;


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
