#include <iostream>
#include <cstdlib>
#include <cstring>

using namespace std;

#define maxn 100010

char in[maxn];
char compare[maxn];

int main() {
    memset(in, 0, sizeof(in));
    memset(compare, 0, sizeof(compare));
    while (~scanf("%s%s", in, compare)) {
        int lenc = strlen(compare);
        int lenin = strlen(in);
        int idx = 0;
        int flag = 0;
        for(int con = 0; con < lenc;con++){
            if(compare[con] == in[idx]){
                idx++;
            }
            flag += (idx == (lenin));
        }
        if(flag){
            printf("Yes\n");
        }else{
            printf("No\n");
        }

    }
    return 0;
}