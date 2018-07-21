//
// Created by Hu on 2018/6/12.
//
#include <iostream>
#include <string>
#include <cmath>
#include <string.h>
#include <algorithm>
#include <cstdlib>

using namespace std;

int v[30][30];
int h[30][30];

int ans[10];

int checkSq(int size, int x, int y){
    int ans = 1;
    for(int con = 0; con < size; con ++){
        ans *= h[x+con][y];
        ans *= h[x+con][y+size];
        ans *= v[x][y+con];
        ans *= v[x+size][y+con];
    }

    return ans;

}

void printboard(){
    for(int con = 1; con < 11; con++){
        for(int sub = 1; sub < 11; sub ++){

            printf("%d ",h[con][sub]);

        }

        printf("\n");
    }

    cout << endl;

    for(int con = 1; con < 11; con++){
        for(int sub = 1; sub < 11; sub ++){

            printf("%d ",v[con][sub]);

        }

        printf("\n");
    }
}


int main() {


    int num = 0;
    int size = 0;
    int input = 0;
    char type;
    int x = 0;
    int y = 0;


    while (scanf("%d%d", &size, &input)  == 2 ) {


        num++;
        memset(v, 0, sizeof(v));
        memset(h, 0, sizeof(h));
        memset(ans, 0, sizeof(ans));

        for (int con = 0; con < input; con++) {

            cin >> type >> x >> y;


            if (type == 'H') {
                h[y][x]++;
            } else {
                v[x][y]++;
            }

        }

        for (int x = 1; x <= size; x++) {
            for (int y = 1; y <= size; y++) {

                for (int con = 1; con <= size; con++) {
                    ans[con] += checkSq(con, x, y);
                }

            }
        }


        if (num != 1)
            cout << endl << "**********************************" << endl << endl;
        cout << "Problem #" << num << endl << endl;
        int flag = 1;

        for (int con = 1; con <= size; con++) {
            if (ans[con]) {
                cout << ans[con] << " square (s) of size " << con << endl;
                flag = 0;
            }
        }

        if (flag){
            cout << "No completed squares can be found." << endl;

        }


    }



    return 0;


}

