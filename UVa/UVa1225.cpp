#include <stdio.h>
#include <iostream>
#include <string.h>
#include <math.h>
using namespace std;

#define maxn 11

int main() {

    int size;
    scanf("%d",&size);

    int ans[maxn];

    for(int s = 0; s < size; s++) {
        memset(ans, 0, sizeof(ans));

        int n = 0;
        scanf("%d",&n);

        for(int con = 1; con <= n; con++){

            int temp = con;
            while(temp > 0){
                ans[temp%10]++;
                temp /= 10;
            }
        }

        for(int con = 0; con <=9; con++){

            if(con){
                putchar(' ');
            }
            printf("%d",ans[con]);
        }
        cout<<endl;

    }




    return 0;

}