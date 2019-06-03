#include <stdio.h>
#include <stdlib.h>
#include "./Lib/Hash.h"
#include "./Lib/Produto.h"

hash* criaHash(int tableSize){
  int i;
  hash* h = (hash*) malloc(sizeof(hash));
  if(h != NULL){
    h->tableSize = tableSize;
    h->item = (Produto*) malloc(sizeof(Produto));
    if(h->item ==  NULL){
      free(h);
      return NULL;
    }
    h->qtd = 0;
    for(i=0;i < (h->tableSize); i++){
      h->item[i] = NULL;
    }
  }
  return h;
}

void liberaHash(hash* h){
  int i;
  if(h != NULL){
    for(i = 0; i < (h->tableSize);i++){
      if(h->item[i] != NULL){
        free(h->item[i]);
      }
    }
    free(h->item);
    free(h);
  }
}

int chaveDivisao(int chave, int tableSize){
  return(chave & 0x7FFFFFFF) % tableSize;
}

int chaveMultiplica(int chave, int tableSize){
  float a = 0.618033898;
  float val = chave*a;
  val = val - (int)val;
  return (int) (tableSize*val)
}

int insereHash_semColisao(hash* h, Produto *p){
  if(h == NULL || h->qtd == h->tableSize){
    return 0;
  }
  int chave = p.id;
  int pos = chaveDivisao(chave, h->tableSize);
  Produto *new;
  new = (Produto*) malloc(sizeof(Produto));
  if(new == NULL){
    return 0;
  }
  new = p;
  h->item[pos] = novo
  h->qtd++;
  return 1;
}

int buscaHash_semColisao(hash* h, int id, Produto *p){
  if(h == NULL){
    return 0;
  }
  int pos = chaveDivisao(id, h->tableSize);
  if(h->item[pos] == NULL){
    return 0;
  }
  *p = *(h->item[pos])
  return 1;
}


int sondagemLinear(int pos,int i, int tableSize){
  return ((pos + i) & 0x7FFFFFFF) & tableSize;
}

int insereHash_enderAberto(hash* h, Produto *p){
  if(h == NULL || h->qtd == h->tableSize){
    return 0;
  }
  int chave = p.id;
  int i, pos, newPos;
  pos = chaveDivisao(chave, h->tableSize);
  for(i=0;i<h->tableSize;i++){
    newPos = sondagemLinear(pos,i, h->tableSize);
    if(h->item[newPos] == NULL){
      Produto *new;
      new = (Produto*) malloc(sizeof(Produto));
      if(novo == NULL){
        return 0;
      }
      *novo = p;
      h->item[newPos] = novo;
      h->qtd++;
      return 1;
    }
    return 0;
  }
}
int buscaHash_enderAberto(hash* h, int id, Produto *p){
  if(h == NULL){
    return 0;
  }
  int i,pos, newPos;
  int pos = chaveDivisao(id, h->tableSize);
  for(i=0;i < h->tableSize; i++){
    newPos = sondagemLinear(pos,i,h->tableSize);
    if(h->item[newPos] == NULL){
      return 0;
    }
    if(h->item[newPos]->id == id){
      *p = *(h->item[newPos]);
      return 1;
    }
  }
  return 0;

}