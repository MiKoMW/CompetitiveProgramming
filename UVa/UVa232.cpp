#include <stdio.h>
#include <iostream>
using namespace std;

struct St
{
    int x,y;
    int r,c;
}st[111];

char board[12][12];
int r,c;


int main()
{
    int cas = 0;
    while(scanf("%d",&r) && r){

        scanf("%d",&c);

        for(int con = 0; con < r; con ++){
            scanf("%s",board[con]);
        }

        int idx = 1;

        for(int i = 0; i < r; i++) {

            for (int j = 0; j < c; j++) {

                if (board[i][j] != '*') {
                    if ((i - 1) < 0 || (j - 1) < 0 || board[i - 1][j] == '*' || board[i][j - 1] == '*') {
                        st[idx].x = i;
                        st[idx].y = j;
                        if ((j - 1) < 0 || board[i][j - 1] == '*') st[idx].r = 1; else st[idx].r = 0;
                        if ((i - 1) < 0 || board[i - 1][j] == '*') st[idx].c = 1; else st[idx].c = 0;
                        idx++;
                    }
                }
            }
        }


        if (cas)
            printf("\n");
        printf("puzzle #%d:\nAcross\n",++cas);
        for (int i=1;i<idx;i++)
        {
            if (st[i].r)
            {
                printf("%3d.",i);
                for (int j=st[i].y;j<c;j++)
                {
                    if (board[ st[i].x ][j]=='*')
                        break;
                    printf("%c",board[ st[i].x ][j]);
                }
                printf("\n");
            }
        }
        printf("Down\n");
        for (int i=0;i<idx;i++)
        {
            if (st[i].c)
            {
                printf("%3d.",i);
                for (int j=st[i].x;j<r;j++)
                {
                    if (board[j][ st[i].y ]=='*')
                        break;
                    printf("%c",board[j][ st[i].y ]);
                }
                printf("\n");
            }
        }
        
    }

    return 0;
}