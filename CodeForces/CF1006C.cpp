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
#include <deque>
#define maxn 1000100

char input[1000000];

using namespace std;

int main(){

    int a;
    int temp;

    cin >> a;

    deque<int> qu;
    for(int con = 0; con < a; con++){
        scanf("%d",&temp);
        qu.push_back(temp);
    }
    long long max1 = 0;
    long long max3 = 0;

    long long ans = 0;
    bool flag = 1;

    while(!qu.empty()){
        if(max1 > max3){
            max3 += qu.back();
            qu.pop_back();
        } else if(max1 < max3){
            max1 += qu.front();
            qu.pop_front();
        }else{
            ans = max1;
            max1 += qu.front();
            qu.pop_front();
        }
    }

    if(max1 == max3){
        ans = max1;
    }

    cout << ans << endl;



    return 0;

}

