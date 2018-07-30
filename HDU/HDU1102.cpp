//
// Created by Hu on 2018/7/26.
//

#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cmath>
using namespace std;
#define N 150
#define INF 99999999
int ma[N][N];
long long d[N],vis[N];
int n;
long long prim(int s)
{
    for(int i=1; i<=n; i++)
        d[i]=i==s?0:ma[s][i];
    vis[s]=1;
    long long ans=0;
    for(int i=1; i<n; i++)
    {
        int maxn=INF,v;
        for(int j=1; j<=n; j++)
            if(!vis[j]&&maxn>d[j])
            {
                maxn=d[j];
                v=j;
            }
        vis[v]=1;
        ans+=maxn;
        for(int j=1; j<=n; j++)
            if(!vis[j]&&ma[v][j]<d[j])
                d[j]=ma[v][j];
    }
    return ans;
}
int main()
{
    int m;
    int s,e;
    while(~scanf("%d",&n))
    {
        memset(vis,0,sizeof(vis));
        for(int i=1; i<=n; i++)
            for(int j=1; j<=n; j++)
                scanf("%d",&ma[i][j]);
        scanf("%d",&m);
        while(m--)
        {
            scanf("%d %d",&s,&e);
            ma[s][e]=0;
            ma[e][s]=0;
        }
        long long ans=prim(1);
        printf("%lld\n",ans);
    }
    return 0;
}