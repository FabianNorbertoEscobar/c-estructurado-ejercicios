#include<stdio.h>
#include<conio.h>
#include<locale.h>
void main()
    {
    setlocale(LC_CTYPE,"Spanish");
    int sum,fact,ser,i,cant;
    sum=0;
    fact=1;
    ser=0;
    printf("\n\n Ingrese un número:\n\n\t");
    scanf("%d",&cant);
    for(i=1;i<=cant;i++)
        {
        sum+=i;
        fact*=i;
        ser=ser+1/i;
        }
    printf("\n\n Suma de %d primeros números naturales:%d \n\n Factorial del número:%d \n\n Suma de la serie armónica:%d \n\n",cant,sum,fact,ser);
    getch();
    }
