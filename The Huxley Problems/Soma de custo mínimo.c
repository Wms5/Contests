
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int  v[100001],seed, a,b,c, n, size=1;

void heapfy(int i){
    int r,l, m, aux;
    l = 2*i;
    r = (2*i) +1;
    m = i;
    if( size >= l && v[l] <= v[m]){
        m = l;
    }
    if(size >= r && v[r] <= v[m]){
        m = r;
    }
    if( m != i){
        aux = v[m];
        v[m] = v[i];
        v[i] = aux;
        heapfy(m);
    }
}
int delete(){
    int r, aux;
    r = v[1];
    aux = v[1];
    v[1] = v[size];
    v[size] = v[1];
    size--;
    heapfy(1);
    return r;
}
void bolha(){
    int i = size;
    int aux;
    while(i >1 && v[i] <= v[i/2]){
        aux = v[i];
        v[i] = v[i/2];
        i = i/2;
    }
}
void insert(int valor){
    v[size+1] = valor;
    bolha();
    size++;
}
int main(){
    //freopen("entrada.in", "r",stdin);
    //freopen("saida1.out", "w",stdout);
   int i, j,som=0, custo=0;
   int a, b,c;
    while(scanf("%d %d %d %d %d", &n, &seed, &a,&b,&c) == 5){
        size= 1;
        custo=0;
        v[1] = seed;
        som = seed;
        for( i=2; i<n+1; i++){
            v[i] = ((v[i-1]*a)+b) % c;
            som += v[i];
            size++;
        }
        //for(i=1; i<=30; i++){
           //printf("%d ",v[i]);
       // }
       // printf("\n");
         for(j = n/2; j>0; j--){
             heapfy(j);
         }
         //for(i=1; i<=30; i++){
           //printf("%d ",v[i]);
        //}
         while(size > 1){
            a = delete();
            b = delete();
            c = a+b;
            custo += c;
            insert(c);
         }
         //printf("\nacaba aqui\n\n");
         printf("%d %d\n",som, custo);
    }
    return 0;
}
