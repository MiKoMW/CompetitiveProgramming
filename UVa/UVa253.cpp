//
// Created by Hu on 2018/6/12.
//
#include <iostream>
#include <string>
#include <cmath>
#include <string.h>
#include <algorithm>
#include <cstdlib>

using namespace std;

char input[20];

struct Die{
    char a;
    char b;
    bool operator < (const Die& rha) const {
        if (a == rha.a) return b < rha.b;
        return a < rha.a;
    }
};

Die dies1[3];
Die dies2[3];


int main(){

    //cout << ('r' > 'd');

    memset(input,0, sizeof(input));
    while(scanf("%s",input) != EOF){

        memset(dies1,0, sizeof(dies1));
        memset(dies2,0, sizeof(dies2));

        // a 大的 b 小的

        if(input[0] > input[5]){
            dies1[0].a = input[0];
            dies1[0].b = input[5];
        }else{
            dies1[0].a = input[5];
            dies1[0].b = input[0];
        }

        if(input[1] > input[4]){
            dies1[1].a = input[1];
            dies1[1].b = input[4];
        }else{
            dies1[1].a = input[4];
            dies1[1].b = input[1];
        }

        if(input[2] > input[3]){
            dies1[2].a = input[2];
            dies1[2].b = input[3];
        }else{
            dies1[2].a = input[3];
            dies1[2].b = input[2];
        }


        if(input[6] > input[11]){
            dies2[0].a = input[6];
            dies2[0].b = input[11];
        }else{
            dies2[0].a = input[11];
            dies2[0].b = input[6];
        }

        if(input[7] > input[10]){
            dies2[1].a = input[7];
            dies2[1].b = input[10];
        }else{
            dies2[1].a = input[10];
            dies2[1].b = input[7];
        }

        if(input[8] > input[9]){
            dies2[2].a = input[8];
            dies2[2].b = input[9];
        }else{
            dies2[2].a = input[9];
            dies2[2].b = input[8];
        }

        sort(dies1,dies1+3);
        sort(dies2,dies2+3);

        int ans = 1;

        for(int con = 0; con < 3; con++){
            ans *= (dies1[con].a == dies2[con].a);
            ans *= (dies1[con].b == dies2[con].b);
        }

        if(ans){
            printf("TRUE\n");
        }else{
            printf("FALSE\n");
        }
    }
}