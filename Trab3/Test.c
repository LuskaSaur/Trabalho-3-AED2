#include <stdio.h>
#include <string.h>
#include "./Lib/Trab3.h"

char Nomes[10][30] = {"Avental", "Leite", "Arroz", "Pote", "Tempero", "Farinha", "Batata", "Tomate", "Laranja","Panela"};

int main(){
    FILE *fp;

    fp = fopen("teste", "wb");
    
    for(int i=0; i<10; i++){
    	Produto tmp;
    	tmp.id = i;
    	tmp.quantidade = i*i;
    	tmp.modelo = 400*i + (1+i)*10 + i;
    	tmp.custo = i*i/2.0;
    	strcpy(tmp.nome, Nomes[i]);
    	fwrite(&tmp, sizeof(Produto), 1,fp);
    }
    
    fclose(fp);

    fp = fopen("teste", "rb");
    
    for(int i=0; i<10; i++){
    	Produto aux;
    	fread(&aux, sizeof(Produto), 1,fp);
    	MostraProduto(aux);
    }
    
    fclose(fp);
    
    return 0;
}