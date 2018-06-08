#include <stdio.h>
#include <iostream>
#include <string.h>
#include <math.h>
using namespace std;

#define maxn 100010

int dig[maxn];

int main() {

    memset(dig,0, sizeof(dig));

    for(int con = 0; con < maxn; con ++){

        int temp = con;
        int sum = con;

        while(temp > 0){
            sum += (temp%10);
            temp = temp/10;
        }

        if(sum > maxn){
            continue;
        }

        if(!dig[sum]){
            dig[sum] = con;
        }

    }

    int size;

    cin>>size;

    for(int con = 0; con < size; con++){
        int temp;
        cin >> temp;
        cout<<dig[temp]<<endl;
    }

    return 0;
}