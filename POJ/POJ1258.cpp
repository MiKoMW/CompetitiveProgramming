//
// Created by Hu on 2018/6/12.
//

#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;
const int INFINITE = 1 << 30;

struct Node{
    int x;
    int y;
} node[105];

struct Edge {
    int v; //边端点，另一端点已知
    int w; //边权值，也用来表示v到在建最小生成树的距离
    Edge(int v_ = 0, int w_ = INFINITE):v(v_),w(w_) { }
    bool operator<(const Edge &e) const {
        return w > e.w; //在队列里，边权值越小越优先
    }
};

vector< vector <Edge> > G(110); //图的邻接表

int HeapPrim(const vector<vector<Edge> > & G, int n){
    int i,j,k;
    Edge xDist(0,0);
    priority_queue<Edge> pq;
    vector<int> vDist(n);
    vector<int> vUsed(n);
    int nDoneNum = 0;
    for( i = 0;i < n;i ++ ) {
        vUsed[i] = 0; vDist[i] = INFINITE;
    }
    nDoneNum = 0;
    int nTotalW = 0; //最小生成树总权值
    pq.push(Edge(0,0));

    while( nDoneNum < n && !pq.empty() ) {
        do {
            xDist = pq.top(); pq.pop();
        } while( vUsed[xDist.v] == 1 && ! pq.empty());
        if( vUsed[xDist.v] == 0 ) {
            nTotalW += xDist.w; vUsed[xDist.v] = 1;
            nDoneNum ++;
            for( i = 0;i < G[xDist.v].size();i ++ ) {
                int k = G[xDist.v][i].v;
                if( vUsed[k] == 0) {
                    int w = G[xDist.v][i].w ;
                    if( vDist[k] > w ) {
                        vDist[k] = w;
                        pq.push(Edge(k,w)); }
                }
            }
        }
    }
    if( nDoneNum < n )
        return -1; //图不连通