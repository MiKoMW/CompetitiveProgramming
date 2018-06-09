#include <stdio.h>
#include <iostream>
#include <string.h>
#include <math.h>
using namespace std;

#define maxn 100

int main() {

    int size;
    scanf("%d",&size);

    char input[maxn];

    while(size--) {
        memset(input, 0, sizeof(input));

        scanf("%s",input);

        int len = strlen(input);

        for(int con = 1; con <= len; con++){
            if(!(len % con)){
                int isSub =1;
                for(int sub = 0; sub < len;sub++){
                    isSub *= (input[sub] == input[sub%con]);
                }
                if(isSub){
                    printf("%d\n",con);
                    con += len;
                }
            }

        }

        if(size){
            printf("\n");
        }




    }


    return 0;

}