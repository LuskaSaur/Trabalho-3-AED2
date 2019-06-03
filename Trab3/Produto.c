#include "./Lib/Produto.h"
#include <stdio.h>
#include <string.h>

Produto create(int id, int mdl, float c, char n[], int qtd){
	Produto tmp;
	tmp.id = id;
	tmp.modelo = mdl;
	tmp.custo = c;
	strcpy(tmp.nome, n);
	tmp.quantidade = qtd;
	return tmp;
}

void GenerateProducts(FILE *fp){
	char Nomes[10][30] = {"Avental", "Leite", "Arroz", "Pote", "Tempero", "Farinha", "Batata", "Tomate", "Laranja","Panela"};
	for(int i=0; i<10; i++){
    	Produto tmp;
    	tmp.id = i;
    	tmp.quantidade = i*i;
    	tmp.modelo = 400*i + (1+i)*10 + i;
    	tmp.custo = i*i/2.0;
    	strcpy(tmp.nome, Nomes[i]);
    	fwrite(&tmp, sizeof(Produto), 1,fp);
    }
}

void MostraProduto(Produto current){
	printf("Id = %d Modelo = %d Custo = %.2f Nome = %s Quantidade = %d\n", current.id, current.modelo, current.custo, current.nome, current.quantidade);
}

int EqualCostThan(Produto *tmp, float* cost){
	if(tmp->custo == *cost)
		return 1;
	return 0;
}

int LessCostThan(Produto *tmp, float *cost){
	if(tmp->custo < *cost)
		return 1;
	return 0;
}

int LessOrEqualCostThan(Produto *tmp, float *cost){
	if(tmp->custo <= *cost)
		return 1;
	return 0;
}

int GreaterCostThan(Produto *tmp, float *cost){
	if(tmp->custo > *cost)
		return 1;
	return 0;
}

int GreaterOrEqualCostThan(Produto *tmp, float* cost){
	if(tmp->custo >= *cost)
		return 1;
	return 0;
}

int EqualNameThan(Produto *tmp, char* name){
	if(strcmp(tmp->nome, name) == 0)
		return 1;
	return 0;
}

int LessNameThan(Produto *tmp, char* name){
	if(strcmp(tmp->nome, name) < 0)
		return 1;
	return 0;
}

int LessOrEqualNameThan(Produto *tmp, char* name){
	if(strcmp(tmp->nome, name) <= 0)
		return 1;
	return 0;
}

int GreaterNameThan(Produto *tmp, char* name){
	if(strcmp(tmp->nome, name) > 0)
		return 1;
	return 0;
}

int GreaterOrEqualNameThan(Produto *tmp, char* name){
	if(strcmp(tmp->nome, name) >= 0)
		return 1;
	return 0;
}

int EqualAmountThan(Produto *tmp, int* amount){
	if(tmp->quantidade == *amount)
		return 1;
	return 0;
}

int LessAmountThan(Produto *tmp, int* amount){
	if(tmp->quantidade > *amount)
		return 1;
	return 0;
}

int LessOrEqualAmountThan(Produto *tmp, int* amount){
	if(tmp->quantidade >= *amount)
		return 1;
	return 0;
}

int GreaterAmountThan(Produto *tmp, int* amount){
	if(tmp->quantidade > *amount)
		return 1;
	return 0;
}

int GreaterOrEqualAmountThan(Produto *tmp, int* amount){
	if(tmp->quantidade >= *amount)
		return 1;
	return 0;
}
