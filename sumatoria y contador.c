#include<stdio.h>
#include<conio.h>
void main()
    {
    int i,cont=0;
    float sum=0,n;
    for(i=1;i<=20;i++)
        {
        printf("\n Ingrese un valor real: \t\t");
        scanf("%f",&n);
        sum+=n;
        if(n>35)
            cont++;
        }
    printf("\n Sumatoria total: %8.2f \n\n Porcentaje de mayores a 35: %d \n\n",sum,cont*100/20);
    getch();
    }
