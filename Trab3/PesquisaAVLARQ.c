#include<stdio.h>
#include<stdlib.h>
#include "avl.h"

#define TAM 10

char Nomes[10][30] = {"Avental", "Leite", "Arroz", "Pote", "Tempero", "Farinha", "Batata", "Tomate", "Laranja","Panela"};

int main(){
    FILE *fp;
    avl *arv;
    arv = criaAvl();
    printf("ooi");
    fp = fopen("listaprod.bin", "wb+");
    arv = ArvIndexada(fp,arv,Nomes);
    BuscaArvArq(fp,arv,7);
}
