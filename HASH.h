#ifndef HASH_H
#define HASH_H

typedef struct Produto{
	int id; 		//4	(CHAVE)
	int modelo;  	// 4
	float custo; 	// 4
	char nome[32];	// 32
	int quantidade; //4
}Produto;

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



#endif
