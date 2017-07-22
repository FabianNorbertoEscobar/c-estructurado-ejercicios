#include<stdio.h>
#include<conio.h>
#include<locale.h>
void main()
    {
    setlocale(LC_CTYPE,"Spanish");
    float tmp1,tmp2,tmp3,sum,prom;
    printf("\n\n Ingrese una temperatura:\n\n\t\t");
    scanf("%f",&tmp1);
    printf("\n\n Ingrese otra temperatura:\n\n\t\t");
    scanf("%f",&tmp2);
    printf("\n\n Ingrese una última temperatura:\n\n\t\t");
    scanf("%f",&tmp3);
    sum=tmp1+tmp2+tmp3;
    prom=sum/3;
    printf("\n\n Suma de las temperaturas:\t %10.2f \n Promedio de temperaturas:\t %10.2f \n\n",sum,prom);
    }
