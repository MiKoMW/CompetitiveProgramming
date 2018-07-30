//
// Created by Hu on 2018/7/26.
//

#include <iostream>
#include <cstring>
#include <cstdio>
#include <climits>
#include <queue>
#include <map>

using namespace std;

#define maxn 500
#define INF INT_MAX

int size_ver, size_edge;

int capacity[maxn][maxn];
int flow[maxn];
int pre[maxn];
map<string,int> recp;

queue<int> que;

int BFS(int src,int dest){

    while(!que.empty()){
        que.pop();
    }

    for(int con = 0; con <= size_ver; con++){
        pre[con] = -1;
    }

    pre[src] = 0;

    flow[src] = INF;

    que.push(src);

    int u;

    while(!que.empty()){
        u = que.front();
        que.pop();
        if(u == dest) break;

        for(int v  = 0; v <= size_ver ; v++){

            if(v != src && capacity[u][v] > 0 && pre[v] == -1){
                pre[v] = u;
                flow[v] = min(capacity[u][v],flow[u]);
                que.push(v);
            }
        }
    }

    if(pre[dest] == -1){
        return -1;
    }
    return (pre[dest]==-1)?-1:flow[dest];

}

int maxFlow(int scr, int dest){
    int increase = 0;
    int ans = 0;

    while((increase = BFS(scr,dest)) != -1){

        int v = dest; // Edge : u -> v
        int u;
        while(v != scr){
            u = pre[v];
            capacity[u][v] -= increase;
            capacity[v][u] += increase;
            v = u;
        }
        ans += increase;

    }
    return ans;
}

int main(){

    ios::sync_with_stdio(false);
    int u,v,cap;
    int ans;
    string buf1,buf2;
    int size_rece;
    int size_device;
    int size_trans;
    int counter = 1;

    memset(capacity,0,sizeof(capacity));
    memset(flow,0, sizeof(flow));
    memset(pre,0, sizeof(pre));

    cin >> size_rece;

    for(int con = 0; con < size_rece; con++){
        cin >> buf1;
        recp[buf1] = counter++;
        capacity[recp[buf1]][maxn-1]++;
    }

    cin >> size_device;

    for(int con = 1; con <= size_device; con++){
        cin >> buf1 >> buf2;
        recp[buf1] = counter++;
        if(recp[buf2]==0)
            recp[buf2] = counter++;
        capacity[recp[buf1]][recp[buf2]] = 1;
        capacity[0][recp[buf1]] = 1;
    }

    cin >> size_trans;

    for(int con = 1; con <= size_trans; con++){

        cin >> buf1 >> buf2;
        if(recp[buf1] == 0){
            recp[buf1] = counter++;
        }
        if(recp[buf2] == 0){
            recp[buf2] = counter++;
        }
        capacity[recp[buf1]][recp[buf2]] = INF;
    }

    size_ver = maxn - 1;

    ans = maxFlow(0,maxn - 1);

    ans = size_device - ans;

    cout << ans << endl;
    return 0;
}