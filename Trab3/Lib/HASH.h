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
int sondagemLinear(int pos,int i, int tableSize); //sondagem linear para colisa
int insereHash_enderAberto(hash* h, Produto *p); //insere produto colisao
int buscaHash_enderAberto(hash* h, int id, Produto *p); //busca produto colisao





#endif
