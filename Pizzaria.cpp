#include<bits/stdc++.h>
using namespace std;
# define INF 2147483647

int total=0;
int n,m,t,u1,v1,c,k,x,caso=1;
typedef pair<int, int> iPair;

int main()
{
    cin >> t;
    while(t){
        t--;
        scanf("%d %d", &n, &m);
        list< pair<int, int> > *adj;
        adj = new list<iPair> [n];

        for(int i=0; i<m; i++){
            scanf("%d %d %d", &u1,&v1,&c);
            adj[u1-1].push_back(make_pair(v1-1, c));
            adj[v1-1].push_back(make_pair(u1-1, c));
        }
        priority_queue< iPair, vector <iPair> , greater<iPair> > pq;
        vector<int> dist(n, INF);
        dist[0] = 0;
        pq.push(make_pair(0, 0));
        while (!pq.empty()){
            int u = pq.top().second;
            pq.pop();
            list< pair<int, int> >::iterator i;
            for ( i = adj[u].begin(); i != adj[u].end(); ++i){

                int v = (*i).first;
                int weight = (*i).second;
                if (dist[v] > dist[u] + weight){
                    dist[v] = dist[u] + weight;
                    pq.push(make_pair(dist[v], v));
                }
            }
        }

        cin >> k;
        for(int i=0; i<k; i++){
            scanf("%d", &x);
            total += 2*dist[x-1];
        }
        printf("caso %d: %d\n",caso, total);
        caso++;
        total =0;
    }
    return 0;
}
