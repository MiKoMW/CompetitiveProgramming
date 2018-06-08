#include <stdio.h>
#include <iostream>
#include <string.h>
#include <math.h>
using namespace std;

int main(){

    int ch;
    char qwerty[] = "`1234567890-=QWERTYUIOP[]\\ASDFGHJKL;'ZXCVBNM,./";

    while((ch = getchar()) != EOF){

        char* pq = strchr(qwerty,ch);
        if(pq == NULL){
            putchar(ch);
        }else{
            putchar(pq[-1]);
        }

    }

    return 0;
}