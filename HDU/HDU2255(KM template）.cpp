//
// Created by Hu on 2018/6/12.
//

#include<iostream>
#include <climits>
#include<cstdio>
#include<cstring>

using namespace std;

const int N=310;
const int INF=INT_MAX;

int n,size_x,size_y;

int linker[N],lx[N],ly[N],slack[N];  //lx,ly为顶标，size_x,size_y分别为x点集y点集的个数
int visited_x[N],visited_y[N],weight[N][N];

int DFS(int x){
    visited_x[x]=1;
    for(int y=1;y<=size_y;y++){
        if(visited_y[y])
            continue;
        int temp=lx[x]+ly[y]-weight[x][y];
        if(temp==0){
            visited_y[y]=1;
            if(linker[y]== -1 || DFS(linker[y])){
                linker[y] = x;
                return 1;
            }
        }else if(slack[y]>temp){
            slack[y]=temp;
        }
    }
    return 0;
}

int KM(){
    int i,j;
    memset(linker,-1,sizeof(linker));
    memset(ly,0,sizeof(ly));

    for(i=1;i<=size_x;i++) {
        lx[i] = -INF;
        for (j = 1; j <= size_y; j++){
            if (weight[i][j] > lx[i]) lx[i] = weight[i][j];
        }
    }

    for(int x=1;x<=size_x;x++){
        for(i=1;i<=size_y;i++)
            slack[i]=INF;
        while(1){

            memset(visited_x,0,sizeof(visited_x));
            memset(visited_y,0,sizeof(visited_y));

            if(DFS(x))
                break;

            int d=INF;

            for(i=1;i<=size_y;i++)
                if(!visited_y[i] && d>slack[i])
                    d=slack[i];

            for(i=1;i<=size_x;i++)
                if(visited_x[i])
                    lx[i]-=d;

            for(i=1;i<=size_y;i++)
                if(visited_y[i])
                    ly[i]+=d;
                else
                    slack[i] -= d; // 目测更新为了优化，不影响结果。

        }
    }
    int res=0;
    for(i=1;i<=size_y;i++)
        if(linker[i]!=-1)
            res+=weight[linker[i]][i];
    return res;
}

int main(){

    while(scanf("%d",&n) != EOF){
        size_x=size_y=n;
        for(int i=1;i<=n;i++)
            for(int j=1;j<=n;j++)
                scanf("%d",&weight[i][j]);
        int ans = KM();
        printf("%d\n",ans);
    }
    return 0;
}