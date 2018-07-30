#include<cstdio>
#include<cstring>
#include<utility>
#include<queue>
#include<vector>
using namespace std;

const int N=105;
const int INF=9999999;

typedef pair<int,int>pii;
vector<pii>G[N];
priority_queue<pii, vector<pii>, greater<pii> >q;

int d[N], first[N], u[N], v[N], w[N], next[N],n,m;
bool vis[N];


// 无向图的输入，注意没输入的一条边要看作是两条边
void read_graph(){
    for(int i=1; i<=n; ++i)
        G[i].clear();
    int a,b,c;
    for(int i=1; i<=m; ++i){
        scanf("%d%d%d",&a,&b,&c);
        G[a].push_back(make_pair(b,c));
        G[b].push_back(make_pair(a,c));
    }
}

void Dijkstra(int src){
    memset(vis, 0, sizeof(vis));
    for(int i=1; i<=n; ++i) d[i] = INF;
    d[src] = 0;
    q.push(make_pair(d[src], src));
    while(!q.empty()){
        pii t = q.top(); q.pop();
        int u = t.second;
        if(vis[u]) continue;
        vis[u] = true;
        for(int v=0; v<G[u].size(); ++v)if(d[G[u][v].first] > d[u]+G[u][v].second){
                d[G[u][v].first] = d[u]+G[u][v].second;
                q.push(make_pair(d[G[u][v].first], G[u][v].first));
            }
    }
}

int main(){
    int a,b,c;
    while(~scanf("%d%d",&n,&m)&&n+m){
        read_graph();
        Dijkstra(1);
        printf("%d\n", d[n]);
    }
    return 0;
}