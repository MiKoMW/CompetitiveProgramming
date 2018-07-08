//
// Created by Hu on 2018/6/12.
//
#include <iostream>
#include <sstream>
#include <string>
#include <cmath>
#include <string.h>
#include <algorithm>
#include <stdlib.h>


char input1[110];
char input2[110];

char counter1[30];
char counter2[30];

using namespace std;

int cmp( const void *a, const void *b){
    return (*(int *)a - *(int *)b);
}

int main(){


    memset(input1,0, sizeof(input1));
    memset(input2,0, sizeof(input2));

    while(scanf("%s%s",input1,input2) != EOF){

        memset(counter1,0, sizeof(counter1));
        memset(counter2,0, sizeof(counter2));

        for(int con = 0; input1[con]; con++){
            counter1[input1[con]-'A'] ++;
        }

        for(int con = 0; input2[con]; con++){
            counter2[input2[con]-'A'] ++;
        }


        //qsort(counter1,26, sizeof(int), cmp);
        //qsort(counter2,26, sizeof(int), cmp);

        sort(counter1,counter1+26);
        sort(counter2,counter2+26);


        int ans = 1;

        for (int i = 0; i < 26; ++i) {
            ans *= (counter1[i] == counter2[i]);
        }

        if(ans){
            cout<<"YES" << endl;
        } else{
            cout <<"NO" << endl;
        }

        memset(input1,0, sizeof(input1));
        memset(input2,0, sizeof(input2));
    }
    return 0;
}