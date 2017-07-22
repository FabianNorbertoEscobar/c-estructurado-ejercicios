#include<stdio.h>
#include<conio.h>
void main()
{
int j,i,m;
printf("\n\t TABLAS DE MULTIPLICAR \n");
    for(j=1;j<=9;j++)
        {
            printf("\n\n\t Tabla del %d \n",j);
            for(i=1;i<=10;i++)
                {
                m=j*i;
                printf("\n\t %d * %d = %d",j,i,m);
                }
        }
getch();
}
