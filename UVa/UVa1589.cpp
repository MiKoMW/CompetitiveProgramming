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

struct Pie{
    int x,y;
    char type;
}pies[10];


int board[12][12];
int R[12][12];
int C[12][12];
int G[12][12];
int H[12][12];
int moves[12][12];


void pMove(int tempx, int tempy);

void printBoard();

void readInput(int piece);

void printPiece();

void initC(Pie p);

void initR(Pie p);

void initG(Pie p);

void initH(Pie p);

void init(int piece);

int validate();

void clearBoard();



void printMoves(){
    for(int y = 1; y < 11; y++){

        for(int x = 1; x < 11; x++){

            printf("%d ",C[x][y]);

        }

        printf("\n");

    }
}

int checkDuilian(int x, int y){
    int tempx = 0;
    int tempy = 0;
    int ans = 0;



    for(int con = 0; con < 10; con++){
        if(pies[con].type == 'G'){
            tempx = pies[con].x;
            tempy = pies[con].y;
            break;
        }
    }

    if(tempx != x){
        return 1;
    }

    for(int con = tempy - 1; con > y; con--){
        ans += board[tempx][con];
    }

    return ans;

}



int main(){

    int piece = 0;
    int tempx = 0;
    int tempy = 0;

    //freopen("rand.out", "r", stdin);

    //freopen("test.out","w",stdout);

    while(scanf("%d",&piece) && piece){

        scanf("%d%d",&tempy,&tempx);

        memset(board,0,sizeof(board));
        memset(pies,0, sizeof(pies));
        clearBoard();
        memset(moves,0, sizeof(moves));

        board[tempx][tempy] = 2;

        pMove(tempx,tempy);

        readInput(piece);

        init(piece);

        if(checkDuilian(tempx,tempy)){
            printf(validate()?"NO\n":"YES\n");
        }else{
            printf("NO\n");
        }

        //printMoves();

    }

    return 0;
}

void clearBoard(){
    for(int x = 0; x < 12; x ++){
        for(int y = 0; y < 12; y++){
            C[x][y] = 1;
            R[x][y] = 1;
            G[x][y] = 1;
            H[x][y] = 1;
        }
    }
    return;
}

int validate(){

    int ans = 0;

    for(int x = 4; x <= 6; x++){
        for(int y = 1; y <= 3; y++){
            ans += (G[x][y] * R[x][y] * H[x][y] * C[x][y] * moves[x][y]);
        }
    }
    return ans;

}


void init(int piece){

    for(int con = 0; con < piece; con ++){

        switch(pies[con].type){
            case 'C':
                initC(pies[con]);
                //cout << "C at piece" << con << endl;
                break;
            case 'R':
                initR(pies[con]);
                //cout << "R at piece" << con << endl;
                break;
            case 'G':
                initG(pies[con]);
                //cout << "G at piece" << con << endl;
                break;
            case 'H':
                initH(pies[con]);
                //cout << "H at piece" << con << endl;
                break;
            default:
                return;
        }
    }

}

void initH(Pie p){

    for(int x = 4; x <= 6; x ++){
        for(int y = 1; y <= 3; y++){
            if((x - p.x) == 2 && (y - p.y) * (y - p.y) == 1 && board[x-1][p.y] != 1){
                H[x][y] = 0;
            }

            if((x - p.x) == -2 && (y - p.y) * (y - p.y) == 1 && board[x+1][p.y] != 1){
                H[x][y] = 0;
            }

            if((y - p.y) == 2 && (x - p.x) * (x - p.x) == 1 && board[p.x][y - 1] != 1){
                H[x][y] = 0;
            }

            if((y - p.y) == -2 && (x - p.x) * (x - p.x) == 1 && board[p.x][y + 1] != 1){
                H[x][y] = 0;
            }

        }
    }

}

void initG(Pie p){

    int flag = 0;
    for(int con = p.y + 1; con < 12; con++){
        if(!flag){
            G[p.x][con] = 0;
        }
        flag = (board[p.x][con] == 1) || flag;

    }

    flag = 0;
    for(int con = p.y - 1; con >= 0; con--){
        if(!flag){
            G[p.x][con] = 0;
        }
        flag = (board[p.x][con] == 1) || flag;
    }

}

void initR(Pie p){

    int flag = 0;
    for(int con = p.x + 1; con < 12; con++){
        if(!flag){
            R[con][p.y] = 0;
        }
        flag = (board[con][p.y] == 1) || flag;
    }

    flag = 0;
    for(int con = p.x - 1; con >= 0; con--){
        if(!flag){
            R[con][p.y] = 0;
        }
        flag = (board[con][p.y] == 1) || flag;
    }

    flag = 0;
    for(int con = p.y + 1; con < 12; con++){
        if(!flag){
            R[p.x][con] = 0;
        }
        flag = (board[p.x][con] == 1) || flag;

    }

    flag = 0;
    for(int con = p.y - 1; con >= 0; con--){
        if(!flag){
            R[p.x][con] = 0;
        }
        flag = (board[p.x][con] == 1) || flag;
    }


}


void initC(Pie p){

    int flag = 0;
    for(int con = p.x + 1; con < 12; con++){
        if(flag){
            C[con][p.y] = 0;
            if(board[con][p.y] == 1){
                break;
            }
        }
        flag += (board[con][p.y] == 1);
    }

    flag = 0;
    for(int con = p.x - 1; con >= 0; con--){
        if(flag){
            C[con][p.y] = 0;
            if(board[con][p.y] == 1){
                break;
            }
        }
        flag += (board[con][p.y] == 1);
    }

    flag = 0;
    for(int con = p.y - 1; con >= 0; con--){
        if(flag){
            C[p.x][con] = 0;
            if(board[p.x][con] == 1){
                break;
            }
        }
        flag += (board[p.x][con] == 1);
    }

    flag = 0;
    for(int con = p.y + 1; con < 12; con++){
        if(flag){
            C[p.x][con] = 0;
            if(board[p.x][con] == 1){
                break;
            }
        }
        flag += (board[p.x][con] == 1);
    }

}




void printPiece(){

    int con = 0;
    while(pies[con].type != 0){
        cout << pies[con].type << " " << pies[con].x << " " << pies[con].y << endl;
        con++;
    }

}

void readInput(int piece){


    for(int con = 0; con < piece; con++){

        char type;
        int xPos = 0;
        int yPos = 0;

        cin >> type;
        cin >> yPos;
        cin >> xPos;

        pies[con].x = xPos;
        pies[con].y = yPos;
        pies[con].type = type;

        board[xPos][yPos] = 1;

    }

    return;
}






void printBoard(){
    for(int y = 0; y < 12; y++){

        for(int x = 0; x < 12; x++){

            printf("%d ",board[x][y]);

        }

        printf("\n");

    }
}

void pMove(int tempx, int tempy) {
    if(tempx == 4){
        switch (tempy){
            case 1:
                moves[4][2] = 1;
                moves[5][1] = 1;
                //moves[5][2] = 1;
                return;
            case 2:
                moves[4][1] = 1;
                moves[4][3] = 1;
                moves[5][2] = 1;
                return;
            case 3:
                moves[4][2] = 1;
                moves[5][3] = 1;
                //moves[5][2] = 1;
                return;
            default:
                return;
        }
    }
    if(tempx == 5){
        switch (tempy){
            case 1:
                moves[4][1] = 1;
                moves[6][1] = 1;
                moves[5][2] = 1;
                return;
            case 2:
                // moves[4][1] = 1;
                moves[4][2] = 1;
                //moves[4][3] = 1;
                moves[5][1] = 1;
                moves[5][3] = 1;
                //moves[6][1] = 1;
                moves[6][2] = 1;
                //moves[6][3] = 1;
                return;
            case 3:
                moves[4][3] = 1;
                moves[6][3] = 1;
                moves[5][2] = 1;
                return;
            default:
                return;
        }
    }
    if(tempx == 6){
        switch(tempy){
            case 1:
                moves[5][1] = 1;
                moves[6][2] = 1;
                //moves[5][2] = 1;
                return;
            case 2:
                moves[6][1] = 1;
                moves[6][3] = 1;
                moves[5][2] = 1;
                return;
            case 3:
                moves[5][3] = 1;
                moves[6][2] = 1;
                //moves[5][2] = 1;
                return;
            default:
                return;
        }
    }



}