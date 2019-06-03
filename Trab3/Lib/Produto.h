#include <stdio.h>
#ifndef TRAB3_H
#define TRAB3_H

typedef struct Produto{
	int id; 		//4	(CHAVE)
	int modelo;  	// 4
	float custo; 	// 4
	char nome[32];	// 32
	int quantidade; //4
}Produto;

//Construct function
Produto create(int id, int mdl, float c, char n[], int qtd);

//Generate 10 Products
void GenerateProducts(FILE* fp);

//Print the product
void MostraProduto(Produto current);

//Comparatives of Cost
int EqualCostThan(Produto *tmp, float* cost);
int LessCostThan(Produto *tmp, float *cost);
int LessOrEqualCostThan(Produto *tmp, float *cost);
int GreaterCostThan(Produto *tmp, float *cost);
int GreaterOrEqualCostThan(Produto *tmp, float* cost);

//Comparatives of Names
int EqualNameThan(Produto *tmp, char* name);
int LessNameThan(Produto *tmp, char* name);
int LessOrEqualNameThan(Produto *tmp, char* name);
int GreaterNameThan(Produto *tmp, char* name);
int GreaterOrEqualNameThan(Produto *tmp, char* name);

//Amount of product
int EqualAmountThan(Produto *tmp, int* amount);
int LessAmountThan(Produto *tmp, int* amount);
int LessOrEqualAmountThan(Produto *tmp, int* amount);
int GreaterAmountThan(Produto *tmp, int* amount);
int GreaterOrEqualAmountThan(Produto *tmp, int* amount);

#endif

