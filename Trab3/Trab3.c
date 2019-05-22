#include "./Lib/Trab3.h"
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

void MostraProduto(Produto current){
	printf("Id = %d Modelo = %d Custo = %.2f Nome = %s Quantidade = %d\n", current.id, current.modelo, current.custo, current.nome, current.quantidade);
}