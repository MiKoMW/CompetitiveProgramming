#include <stdio.h>
#include <iostream>
#include <string.h>
#include <math.h>
using namespace std;

int main(){

    const char* rev1 = "AEHIJLMOSTUVWXYZ12358";
    const char* rev2 = "8ZES15YXWVUT2OMJLIH3A";
    const char* msg[] = {"not a palindrome", "a regular palindrome", "a mirrored string", "a mirrored palindrome"};

    char s[100];

    while(scanf("%s",s) != EOF){
        int len = strlen(s);
        int isPali = 1;
        int isMirr = 1;

        for(int con = 0; con < (len + 1) /2; con++){
            isPali *= (s[con]== s[len - 1 - con]);
            isMirr *= ((strchr(rev1,s[con]) - rev1 ) + (strchr(rev2,s[len - 1 - con]) - rev2) == 20);
        }

        printf("%s -- is %s.\n\n", s, msg[isMirr*2+isPali]);

    }


    return 0;
}