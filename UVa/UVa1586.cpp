#include <stdio.h>
#include <iostream>
#include <string.h>
#include <math.h>
using namespace std;

#define maxn 110

double getMass(char ch){
    if(ch == 'C'){
        return 12.01;
    }
    if(ch == 'H'){
        return 1.008;
    }
    if(ch == 'O'){
        return 16.00;
    }
    if(ch == 'N'){
        return 14.01;
    }
    else{
        return 0;
    }


}

int main() {

    int size;
    scanf("%d",&size);

    char input[maxn];

    for(int s = 0; s < size; s++){
        memset(input,0, sizeof(input));

        scanf("%s",input);

        int len = strlen(input);

        int num = 0;
        double mol = 0;
        double ans = 0;

        for(int con = 0; con < len; con++){
            double temp = getMass(input[con]);
            if(temp){
                ans += temp;
                mol = temp;
                num = 0;
            }else{
                if(!num){
                    num = input[con] - '0';
                    ans += (mol * (num - 1));
                }else{
                    ans += (mol * num * 9);
                    num = input[con] - '0';
                    ans += (mol * num);
                }
            }
        }


        printf("%.3f\n",ans);

    }


    return 0;

}