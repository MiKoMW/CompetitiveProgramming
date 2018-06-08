#include <stdio.h>
#include <iostream>
#include <string.h>
#include <math.h>
using namespace std;

#define maxn 1000 + 10

int main() {
    int size = 0;
    int kase = 0;
    int ans[maxn];
    int input[maxn];

    int ans_counter[10];
    int in_counter[10];

    while(scanf("%d", &size) == 1){
        if(!size){
            return 0;
        }

        printf("Game %d:\n", ++kase);

        memset(ans_counter,0, sizeof(ans_counter));

        for(int con = 0; con < size; con++){
            scanf("%d",&ans[con]);
            ans_counter[ans[con]]++;
        }


        while(true){
            int end = 0;
            int a = 0; int b = 0;

            memset(in_counter,0, sizeof(ans_counter));

            for(int con = 0; con < size; con++) {
                scanf("%d", &input[con]);
                if(ans[con] == input[con]){
                    a++;
                }

                in_counter[input[con]]++;

                end += input[con];
            }

            if(!end){
                break;
            }

            for(int con = 1; con <= 9; con++){
                b += min(ans_counter[con],in_counter[con]);
            }
            b = b - a;
            printf("    (%d,%d)\n", a, b);

        }

    }

    return 0;
}