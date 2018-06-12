#include <iostream>
#include <cstdlib>
#include <cstring>

using namespace std;

#define maxn 3010

int idx[maxn];
int digs[maxn];

int main()
{
    int nume;
    int deno;
    while(scanf("%d%d",&nume,&deno) != EOF){
        memset(idx,-1,sizeof(idx));
        memset(digs,0, sizeof(digs));
        int temp = nume;
        int mod = -1;
        int first = -1;

        int con = 0;
        while(true){
            digs[con] = nume/deno;
            mod = nume%deno;

            if(idx[mod] != -1){
                first = idx[mod];
                break;
            }

            idx[mod] = con;

            nume = mod * 10;

            con++;
        }

        printf("%d/%d = %d",temp,deno,digs[0]);
        printf(".");
        if(!first){
            printf("(");
        }
        for(int i = 1; i < con + 1;i++){
            if(i==51){
                break;
            }
            printf("%d",digs[i]);
            if(i==first){
                printf("(");
            }
        }


        if (con > 50) printf("...");

        printf(")\n");

        printf("   %d = number of digits in repeating cycle\n\n",con-first);

    }

    return 0;
}
