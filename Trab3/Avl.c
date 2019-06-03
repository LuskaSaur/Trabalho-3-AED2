#include "./Lib/Avl.h"
#include <string.h>
#include "./Lib/Produto.h"
#define TAM 10

int max(int a, int b){
    if(a>b) return a;
    return b;
}

int altura(avl* atu){
    if(atu) return atu->altura;
    return -1;
}

avl* criaAvl(){
    return NULL;
}

avl* criaNo(int id, int index){
    avl *a = (avl*)malloc(sizeof(avl));
    a->dir = a->esq = NULL;
    a->altura = 0;
    a->id = id;
    a->index = index;
    return a;
}

avl* Lrot(avl* k2){
    avl* k1 = k2->esq;
    k2->esq = k1->dir;
    k1->dir = k2;
 
    k2->altura = max(altura(k2->esq), altura(k2->dir)) + 1;
    k1->altura = max(altura(k1->esq), altura(k2)) + 1;
    return k1; /* new root */
}

avl* Rrot(avl* k1){
    avl* k2 = k1->dir;
    k1->dir = k2->esq;
    k2->esq = k1;
 
    k1->altura = max(altura(k1->esq), altura(k1->dir)) + 1;
    k2->altura = max(altura(k2->dir), altura(k1)) + 1;
 
    return k2;  /* New root */
}

avl* RLrot(avl* k3){
    k3->esq = Rrot(k3->esq);
    return Lrot(k3);
}

avl* LRrot(avl* k1){
    k1->dir = Lrot(k1->dir);
    return Rrot(k1);
}
avl* inseriravl(avl* atu, int id, int index){
    if(atu == NULL) atu = criaNo(id, index);
    else if(id <= atu->id){
        atu->esq = inseriravl(atu->esq, id, index);
        if(altura(atu->esq) - altura(atu->dir) == 2){
            if(id < atu->esq->id) atu = Lrot(atu);
            else atu = RLrot(atu);
        }
    }
    else if(id > atu->id){
        atu->dir = inseriravl(atu->dir, id, index);
        if(altura(atu->dir) - altura(atu->esq) == 2){
            if(id > atu->dir->id) atu = Rrot(atu);
            else atu = LRrot(atu);
        }
    }
    atu->altura = max(altura(atu->esq), altura(atu->dir)) + 1;
    return atu;
}
 

avl* buscaavl(avl *a, int id) {
    avl *ret = NULL;
    if(a == NULL) {
        ret = NULL;
    }
    else if(id > a->id) {
        ret = buscaavl(a->dir,id);
    }
    else if(id < a->id) {
        ret = buscaavl(a->esq,id);
    }
    else {
        ret = a;
    }
    return ret;
}

void imprimeavl(avl *a, int val) {
    if(a!=NULL) {
        if(val==0) printf("%d\n",a->id);
        imprimeavl(a->esq,val);
        if(val==1) printf("%d\n",a->id);
        imprimeavl(a->dir,val);
        if(val==2) printf("%d\n",a->id);
    }
}

avl* liberaAvl(avl *a) {
    if(a != NULL) {
        liberaAvl(a->esq);
        liberaAvl(a->dir);
        free(a);
    }
    return NULL;
}
int taEmOrdem(avl *atu){
    int res = 1;
    if(atu->esq) res &= (taEmOrdem(atu->esq) && atu->esq->id <= atu->id);
    if(atu->dir) res &= (taEmOrdem(atu->dir) && atu->dir->id >= atu->id);
    return res;
}
int idElementos(avl *atu){
    int res = 0;
    if(atu) res = 1 + idElementos(atu->esq) + idElementos(atu->dir);
    return res;
}
int altura2(avl *atu){
    if(!atu) return 0;
    int res = 0;
    if(atu->esq) res += 1 + altura2(atu->esq);
    if(atu->dir) res=max(res, 1 + altura2(atu->dir));
    return res;
}
int taBalanceada(avl *atu){
    if(!atu) return 1;
    int bf = altura2(atu->dir) - altura2(atu->esq);
    if(bf>1 || bf<-1) return 0;
    return taBalanceada(atu->esq) && taBalanceada(atu->dir);
}
int taCerto(avl *atu, int n){
    return (taEmOrdem(atu) && idElementos(atu) == n && taBalanceada(atu));
}

void PreencheArq(FILE *fp, char nome[][30]){ 
    for(int i=0; i<TAM; i++){
        Produto tmp;
        tmp.id = i;
    	tmp.quantidade = i*i;
    	tmp.modelo = 400*i + (1+i)*10 + i;
    	tmp.custo = i*i/2.0;
    	strcpy(tmp.nome, nome[i]);
    	fwrite(&tmp, sizeof(Produto), 1,fp);
    }   
}
avl* ArvIndexada(FILE *fp, avl *arv, char nome[][30]){
    PreencheArq(fp,nome);    
    for(int i =0; i<TAM;i++){
        arv = inseriravl(arv,i,i);
    }
    return arv;
}
void BuscaArvArq(FILE *fp, avl *arv, int id){
    avl *result;
    Produto produtfinal;
    result = buscaavl(arv, id);
    if(!result){
        printf("Não achei saporra\n");
        return;
    }
    fseek(fp,sizeof(Produto)*result->index,SEEK_SET);
    fread(&produtfinal,sizeof(Produto),1,fp);
    MostraProduto(produtfinal);
}

void ConditionalSearch(FILE *fp, avl *arv, void *value, int(*f)(void*, void*)){
    if(arv == NULL)
        return;
    if(arv->esq)
        ConditionalSearch(fp, arv->esq, value, f);
    Produto tmp;
    fseek(fp,sizeof(Produto)*arv->id,SEEK_SET);
    fread(&tmp,sizeof(Produto),1,fp);
    if(f(&tmp, value) == 1)
        MostraProduto(tmp);
    if(arv->dir)
        ConditionalSearch(fp, arv->dir, value, f);
}