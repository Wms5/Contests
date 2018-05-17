#include <stdio.h>
#include <stdlib.h>
struct listaa{
    int viz[202];
    int grau;
};
typedef struct listaa lista;
lista matriz[202];
int p[202];
int bol=0;
void dfs(int s){
    int v, i=1,j=1, c=0,k;
    p[s]=1;
    for(j=1;j<=matriz[s].grau;j++){
        k=matriz[s].viz[j];
        if(p[k]==1){
            c++;
        }
    }
    if(c>=2){
        bol=1;
    }
    v=matriz[s].viz[i];
    while(v!=-1){
        if(p[v]==0){
            c=0;
            dfs(v);
        }
        i++;
        v=matriz[s].viz[i];
    }
}
int main(){
    int n, m, a ,b, q1,q2, caso=1, i, j;
    //freopen("Ciclos.in", "r", stdin);
    //freopen("out", "w", stdout);
    while(scanf("%d %d", &n, &m)==2){
        for(i=0;i<n+2;i++){
            for(j=0;j<n+2;j++){
                matriz[i].viz[j]=-1;
            }
            matriz[i].grau=1;
            p[i]=0;
        }
        for(i=0;i<m;i++){
            scanf("%d %d", &a, &b);
            q1=matriz[a].grau;
            q2=matriz[b].grau;
            matriz[a].viz[q1]=b;
            matriz[b].viz[q2]=a;
            matriz[a].grau++;
            matriz[b].grau++;
        }
        for(i=1;i<=n;i++){
            if(p[i]==0){
                dfs(i);
            }
        }
        if(bol==1){
            printf("%d 1\n", caso);
        }
        else{
            printf("%d 0\n", caso);
        }
        caso++;
        bol=0;
    }
    return 0;
}
