//
// Created by Hu on 2018/6/12.
//

#include <stdio.h>
#include <string.h>
#include <iostream>

using namespace std;

int pairs[510][510];
int visited[510];
int cp_A[510];
int cp_B[510];


int size_A,size_B;

int hungary(int u)
{
    for (int v=1;v<=size_B;v++)
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
    for(int i=1;i<=size_A;i++)
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
    while(scanf("%d",&size)!=EOF && size)
    {

        int ans = 0;
        int a,b;

        scanf("%d%d",&size_A,&size_B);
        memset(pairs,0,sizeof(pairs));
        memset(cp_B,0,sizeof(cp_B));
        memset(cp_A,0,sizeof(cp_A));

        for(int i=0;i<size;i++)
        {
            scanf("%d%d",&a,&b);
            pairs[a][b]=1;
        }

        ans = max_match();
        printf("%d\n", ans);

    }
}