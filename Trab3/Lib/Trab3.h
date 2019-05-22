#ifndef TRAB3_H
#define TRAB3_H

typedef struct Produto{
	int id; 		//4	(CHAVE)
	int modelo;  	// 4
	float custo; 	// 4
	char nome[32];	// 32
	int quantidade; //4
}Produto;

Produto create(int id, int mdl, float c, char n[], int qtd); // Construct function
void MostraProduto(Produto current); // Print the product

#endif

