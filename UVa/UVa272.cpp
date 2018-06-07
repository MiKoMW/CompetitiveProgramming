#include <stdio.h>
#include <iostream>
#include <string.h>
#include <math.h>
using namespace std;

int main(){

    int ch;
    int l = 1;

    while((ch = getchar()) != EOF){
        if(ch == '"'){
            if(l){
            printf("%s","``");
            }
            else{
                printf("%s","''");
            }
            l = !l;
        }
        else{
            printf("%c",ch);
        }
    }



    return 0;
}