#include <stdio.h>
#include <iostream>
#include <string.h>
using namespace std;

#define maxSize 55
#define maxLen 1010

struct St{

    int A,G,C,T;
    char most;
    int max;

}seq[maxLen];

int main()
{
    int icase = 0;
    scanf("%d",&icase);

    char input[maxSize][maxLen];

    while(icase --){

        memset(input,0, sizeof(input));
        memset(seq,0, sizeof(seq));


        int size;
        int length;
        scanf("%d",&size);
        scanf("%d",&length);

        for(int con = 0; con < size; con ++){
            scanf("%s",input[con]);
        }

        for(int i = 0; i < length; i++){
            for(int j = 0; j < size ; j++){
                if(input[j][i] == 'A'){
                    seq[i].A++;
                }
                if(input[j][i] == 'C'){
                    seq[i].C++;
                }
                if(input[j][i] == 'G'){
                    seq[i].G++;
                }
                if(input[j][i] == 'T'){
                    seq[i].T++;
                }
            }
            int max = seq[i].A;
            seq[i].most = 'A';
            if(seq[i].C > max){
                seq[i].most = 'C';
                max = seq[i].C;
            }
            if(seq[i].G > max){
                seq[i].most = 'G';
                max = seq[i].G;
            }
            if(seq[i].T > max){
                seq[i].most = 'T';
                max = seq[i].T;
            }
            seq[i].max = max;
        }

        int diff = 0;
        for(int con = 0; con < length; con++){
            printf("%c",seq[con].most);
            diff += (seq[con].A + seq[con].C + seq[con].G + seq[con].T - seq[con].max);
        }
        cout<<endl;
        printf("%d",diff);
        cout<<endl;

    }

    return 0;
}