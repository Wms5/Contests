#include<bits/stdc++.h>
using namespace std;
# define INF 2147483647
int n,m,u1,v1,c,k,x,caso=1;

typedef pair<int, int> iPair;

int main()
{
        scanf("%d %d", &n, &m);
        list< pair<int, int> > *adj;
        adj = new list<pair<int, int>> [n];

        for(int i=0; i<m; i++){
            scanf("%d %d %d", &u1,&v1,&c);
            adj[u1-1].push_back(make_pair(v1-1,c));
            adj[v1-1].push_back(make_pair(u1-1,c));
        }
        priority_queue<iPair, vector<iPair>, greater<iPair>> pq;
        vector<int> dist(n,INF);
        dist[0]=0;
        pq.push(make_pair(0,0));
        while(!pq.empty()){
            int u = pq.top().second;
            pq.pop();
            list<pair<int,int>>::iterator i;
            for( i = adj[u].begin(); i!=adj[u].end(); ++i){

                int v = (*i).first;
                int weight = (*i).second;
                if(dist[v] > dist[u] + weight){
                    dist[v] = dist[u] + weight;
                    pq.push(make_pair(dist[v],v));
                }
            }
        }
        printf("%d\n", dist[n-1]);
    return 0;
}
