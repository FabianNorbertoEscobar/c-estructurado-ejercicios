#include<stdio.h>
#include<conio.h>
void main()
    {
    int sum,i;
    sum=0;
    for(i=100;i>=50;i-=5)
        sum+=i;
    printf("\n\n La sumatoria de la serie 100+95+90+...+50 es %d \n\n",sum);
    getch();
    }
