#include <stdio.h>
#include <string.h>
#include <math.h>
#define N 110
#define INF 0x3f3f3f3f
int n;
int i,j;
double map[N][N];
bool vis[N];
double low[N];
int x[N],y[N];
double dis(int i,int j)
{
    return sqrt(1.0*(x[i]-x[j])*(x[i]-x[j])+(y[i]-y[j])*(y[i]-y[j]));
}
void input()
{
    for(i=1;i<=n;++i)
        scanf("%d%d",&x[i],&y[i]);
    for(i=1;i<=n;++i)
        for(j=1;j<=n;++j)
        {
            map[i][j]=dis(i,j);
            if(map[i][j]>1000||map[i][j]<10)
            {
                map[i][j]=INF;
            }
        }
}

void prim()
{
    double sum=0;
    memset(vis,0,sizeof(vis));
    int pos=1;
    for(i=1;i<=n;i++)
    {
        low[i]=map[1][i];
    }
    vis[1]=1;

    for(i=1;i<n;++i)
    {
        double min=INF;
        for(j=1;j<=n;++j)
        {
            if(!vis[j]&&min>low[j])
            {
                min=low[j];
                pos=j;
            }
        }
        if(min==INF)
        {
            printf("oh!\n");
            return ;
        }
        sum+=min;
        vis[pos]=1;
        for(j=1;j<=n;++j)
        {
            if(!vis[j]&&low[j]>map[pos][j])
            {
                low[j]=map[pos][j];
            }
        }
    }
    printf("%.1lf\n",sum*100);
}
int main()
{
    int T;
    scanf("%d",&T);
    while(T--)
    {
        scanf("%d",&n);
        input();
        prim();
    }
    return 0;
}