#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define DEBUG 0

struct NO{
	int valor;
	struct NO *next;
};
typedef struct NO no;

struct Tab{
	int val;
	no *head;
};
typedef struct Tab tab;

tab *t;
tab *aux;
int m, n, num, cont=0;

int hash(int valor){
	int o;
	o = valor%m;
	return o;
}
void ad2(int valor, int op){
	no *cur, *curr;
	curr = (no*)malloc(sizeof(no));
	curr->valor = valor;
	curr->next = (aux[op]).head;
	(aux[op]).head = curr;
	(aux[op]).val++;
}

void rehhash(){
	float a;
	int i, M, pos;
	no *cur, *curr;
	a = ((float)cont)/((float)m);
	if(a>=0.75){
		M =  m;
		m = (2*m)-1;
		aux = (tab*)malloc(m*sizeof(tab));
		for(i = 0; i<M; i++){
			no * cur;
			for (cur = t[i].head;cur != NULL;cur = cur->next)
			{
				pos = (cur->valor)%m;
				ad2(cur->valor,pos);
			}
		}
		free(t);
		t = aux;
		aux = NULL;
	}
}

int ad(int valor, int op){
	no *cur, *curr;
	cur = (t[op]).head;
	for(cur; cur!=NULL;cur = cur->next){
		num++;
		if (DEBUG){
			printf("%d %d\n", cur->valor, valor);
		}
		if(cur->valor == valor){
			return 0;
		}
	}
	curr = (no*)malloc(sizeof(no));
	curr->valor = valor;
	curr->next = (t[op]).head;
	(t[op]).head = curr;
	(t[op]).val++;
	cont++;
	return 1;
}

int del(int valor, int op){
	no *cur= (t[op]).head, *ant;
	if(cur != NULL && cur == t[op].head && cur->valor == valor){
		no *aax = cur;
		cur = cur->next;
		(t[op]).head =  cur;
		free(aax);
		(t[op]).val--;
		cont--;
		++num;
		return 1;
	}
	else{
		cur=(t[op]).head;
		while (cur!=NULL){
			++num;
			if (DEBUG == 2){
				printf("%d %d\n", cur->valor, valor);
			}
			if(cur->valor == valor){
				ant->next=cur->next;
				free(cur);
				(t[op]).val--;
				cont--;
				return 1;
			}
			ant=cur;
			cur=cur->next;
		}

	}
	return 0;
}
int haas(int valor, int op){
	no *cur;
	if((t[op]).head== NULL){
		return 0;
	}
	else{
		cur = (t[op]).head;
		while(cur!= NULL){
			num++;
			if (DEBUG){
				printf("%d %d\n", cur->valor, valor);
			}
			if(cur->valor == valor ){
				return 1;
			}
			else{
				cur=cur->next;
			}
		}
		return 0;
	}
}
void prrt(){
	int maior,i;
	maior = (t[0]).val;
	for(i=0; i<m; i++){
		if((t[i]).val > maior){
			maior = (t[i]).val;
		}
	}
	printf("%d %d %d %d\n",n,m,cont,maior);
	n++;
}
int main(){
	char ins[5], add[]="ADD", DEL[]="DEL",has[]="HAS", prt[]="PRT";
	int valor, op,bol;
	m=7, n=0, num=0;

	t = (tab*)malloc(m*sizeof(tab));

	while(scanf("%s", ins) == 1){
		if(strcmp(ins,add)==0){
			scanf("%d",&valor);

			op = hash(valor);
			bol=ad(valor,op);
			printf("%d %d %d\n",n, bol, num);
			n++;
			num =0;
			rehhash();
		}
		else if(strcmp(ins,DEL)==0){
			scanf("%d",&valor);
			op = hash(valor);
			bol = del(valor,op);
			printf("%d %d %d\n",n, bol, num);
			n++;
			num= 0;
		}
		else if(strcmp(ins,has)==0){
			scanf("%d",&valor);
			op = hash(valor);
			bol = haas(valor, op);
			printf("%d %d %d\n",n, bol, num);
			n++;
			num=0;
		}
		else if(strcmp(ins,prt)==0){
			prrt(valor, op);
		}
	}
	return 0;
}

