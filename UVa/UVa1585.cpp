#include <stdio.h>
#include <iostream>
#include <string.h>
#include <math.h>
using namespace std;

#define maxn 110

int main() {

    int size;
    scanf("%d",&size);

    char input[maxn];

    for(int s = 0; s < size; s++){
        memset(input,0, sizeof(input));

        scanf("%s",input);

        int len = strlen(input);

        int ans = 0;
        int temp = 0;

        for(int con = 0; con < len; con ++){
            if(input[con] == 'O'){
                temp++;
                ans += temp;
            }else{
                temp = 0;
            }
        }

        cout << ans << endl;

    }


    return 0;

}