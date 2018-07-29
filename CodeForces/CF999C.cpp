//
// Created by Hu on 2018/6/12.
//
#include <iostream>
#include <string>
#include <cmath>
#include <string.h>
#include <algorithm>
#include <cstdlib>
#include <set>
#include <math.h>
#include <set>
#include <queue>

#define maxn 1000100

char input[1000000];

using namespace std;

int main(){

    int a;
    int remove;
    memset(input,0, sizeof(input));
    cin >> a >> remove;
    scanf("%s",input);

    char temp = 'a';

    int index = 0;

    while(true){

        if(remove == 0){
            for(int con = 0; con < a; con++){
                if(isalpha(input[con])){
                    printf("%c",input[con]);
                }
            }
            return 0;
        }

        if(index == (a-1)){
            temp++;
            index = 0;
        }

        for(int con = index; con < a; con++){
            index = con;
            if(input[index] == temp){
                input[index] = 0;
                remove--;
                break;
            }

        }

    }


    return 0;

}

