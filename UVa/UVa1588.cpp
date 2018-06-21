#include<stdio.h>
#include<string.h>
char h1[110],h2[110];
int main()
{
    while(scanf("%s%s",h1,h2)!=EOF)
    {
        int i,j,t,l1,l2;
        int temp,conut1,conut2;
        i=j=t=0;
        int a;

        l1=strlen(h1);
        l2=strlen(h2);


        while(j<l1&&i<l2)
        {
            if(h1[j]+h2[i]-96<=3)
            {
                i++,j++;
            }
            else
                t++,i=0,j=t;
        }



        conut1=l1+l2-i;
        i=j=t=0;
        while(j<l2&&i<l1)
        {
            if(h2[j]+h1[i]-96<=3)
            {
                i++,j++;
            }
            else
                t++,i=0,j=t;
        }
        conut2=l1+l2-i;
        printf("%d\n",conut1 < conut2 ? conut1 : conut2 );
    }
    return 0;
}
