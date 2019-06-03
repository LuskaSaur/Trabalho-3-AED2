#include <stdio.h>
#include <stdlib.h>
#include "./Lib/Arquivo.h"
#include "./Lib/Produto.h"
#include "./Lib/Avl.h"
//For compile this code: gcc -w Avl.c Arquivo.c Produto.c main.c -o main

int main(){
	FILE *fp;
	fp = fopen("MHW", "rw");;
	GenerateProducts(fp);

	char name[] = "Panela";
	Produto ans = *((Produto*)SequentialSearchInFile(name, sizeof(Produto), fp, EqualNameThan));
	MostraProduto(ans);

	int size;
	float x = 10.0;
	Produto* array = SequentialConditionalSearchInFile(&x, sizeof(Produto), fp, LessCostThan, &size);
	for(int i=0; i<size; i++)
		MostraProduto(array[i]);
	
	printf("Parte da arvore\n");
	avl *arv;
	char Nomes[10][30] = {"Avental", "Leite", "Arroz", "Pote", "Tempero", "Farinha", "Batata", "Tomate", "Laranja","Panela"};
	arv = ArvIndexada(fp,arv,Nomes);
    BuscaArvArq(fp,arv,7);
    float value = 13.0;
    ConditionalSearch(fp, arv, &value, LessCostThan);
    liberaAvl(arv);

	return 0;
}