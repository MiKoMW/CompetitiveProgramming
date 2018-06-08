#include <stdio.h>
#include <iostream>
#include <string.h>
#include <math.h>
using namespace std;

#define maxn 110

int main() {

    char in[maxn];
    memset(in,0, sizeof(in));

    int size;
    scanf("%d",&size);

    for(int con = 0 ; con < size; con++){

        scanf("%s",in);
        int len = strlen(in);

        int ans = 0;

        for(int idx = 1; idx < len; idx ++){

            for(int i = 0; i < len; i++){
                if(in[(idx + i)%len] < in[(ans + i)%len]){
                    ans = idx;
                    break;
                }else if(in[(idx + i)%len] > in[(ans + i)%len]){
                    break;
                }
            }
        }

        for(int i = 0; i < len; i++)
            putchar(in[(i+ans)%len]);
        printf("\n"); //???
    }

    return 0;
}