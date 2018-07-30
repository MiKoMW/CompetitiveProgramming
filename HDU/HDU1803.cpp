//
// Created by Hu on 2018/6/12.
//

#include <stdio.h>
#include <string.h>
#include <iostream>

#define maxN 510
using namespace std;


int pairs[maxN][maxN];
int visited[maxN];
int cp_A[maxN];
int cp_B[maxN];


int P,N;

int hungary(int u)
{
    for (int v=1;v<=N;v++)
    {
        if (pairs[u][v]==1 && visited[v]==0)
        {
            visited[v]=1;

            if (cp_B[v]==0 || hungary(cp_B[v]))
            {
                cp_A[u] = v;
                cp_B[v] = u;
                return 1;
            }
        }
    }
    return 0;
}

int max_match()
{

    int ans = 0;
    for(int i=1;i<=P;i++)
    {

        if(cp_A[i] == 0) {
            memset(visited, 0, sizeof(visited));
            ans += hungary(i);
        }
    }
    return ans;
}

int main()
{
    int size;
    scanf("%d",&size);
    while(size--)
    {

        int ans = 0;
        int a,b;

        scanf("%d%d",&P,&N);
        memset(pairs,0,sizeof(pairs));
        memset(cp_B,0,sizeof(cp_B));
        memset(cp_A,0,sizeof(cp_A));


        for(int i=1;i<=P;i++)
        {
            scanf("%d",&a);
            for(int con = 1; con <= a; con++){
                scanf("%d",&b);
                pairs[i][b]=1;
            }
        }


        ans = max_match();

        if(ans == P){
            printf("YES\n");
        }else{
            printf("NO\n");
        }
    }

    return 0;
}