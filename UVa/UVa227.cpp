#include <stdio.h>
#include <iostream>
#include <string.h>
#include <math.h>
using namespace std;

#define maxMove 1010


int main() {

    char game[5][5];
    int blankx  = 0;
    int blanky  = 0;
    char moves[maxMove];
    int isLegal = 1;
    int size = 0;

    while(true){

        memset(game,0, sizeof(game));
        memset(moves,0, sizeof(moves));
        isLegal = 1;

        for(int con = 0; con < 25; con++){
            scanf("%c",&game[con/5][con%5]);
            if(game[con/5][con%5] == '\n'){
                scanf("%c",&game[con/5][con%5]);
            }

            if(game[0][0] =='Z'){
                return 0;
            }

            if(game[con/5][con%5] ==' '){
                blankx = con/5;
                blanky = con%5;
            }
        }

        int con = 0;
        while(true){
            scanf("%c",&moves[con]);
            if(moves[con] =='0'){
                break;
            }
            if(moves[con] == 'A' || moves[con] == 'B' || moves[con] == 'R' || moves[con] == 'L'){
                con++;
            }
        }


        for(int a = 0; a < con; a ++){
            int thisMove = (moves[a] == 'A') + (2 * (moves[a] == 'B')) + (3* (moves[a] == 'R')) + (4* (moves[a] == 'L'));

            int tempx = blankx;
            int tempy = blanky;
            if(thisMove < 3){
                tempx += ((moves[a] == 'B') - (moves[a] == 'A'));
            }else{
                tempy += ((moves[a] == 'R') - (moves[a] == 'L'));
            }

            if(tempx < 0 || tempx >= 5 || tempy < 0 || tempy >=5){
                isLegal = 0;
                break;
            }

            if(isLegal){
                game[blankx][blanky] = game[tempx][tempy];
                game[tempx][tempy] = ' ';
                blankx = tempx;
                blanky = tempy;
            }
        }




        if (size++) printf("\n");
        printf("Puzzle #%d:\n",size);

         if(!isLegal){
             printf("This puzzle has no final configuration.\n");
         } else{
             for(int con = 0; con < 25; con++){
                 printf("%c",game[con/5][con%5]);
                 if((con+1)%5){
                     printf(" ");
                 }
                 if((con+1)%5==0){
                     cout<<endl;
                 }

             }
         }

    }

}