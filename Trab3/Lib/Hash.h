#include "Produto.h"

#ifndef HASH_H
#define HASH_H

typedef struct hash{
  int tableSize;
  int qtd;
  Produto **item;
}hash;

hash* criaHash(int tableSize); //cria tabela hash
void liberaHash(hash* h); //esvazia tabela e destroi
int chaveDivisao(int chave, int tableSize); //calculo da insercao do produto na tabela
int chaveMultiplica(int chave, int tableSize); //outro metodo do calculo da insercao
int insereHash_semColisa(hash* h, Produto p); //insere produto
int sondagemLinear(int pos,int i, int tableSize); //tratamento de colisao
int buscaHash_enderAberto(hash* h, int id, Produto *p); 



#endif
