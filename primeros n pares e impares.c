#include<stdio.h>
#include<conio.h>
#include<locale.h>
void main()
    {
    setlocale(LC_CTYPE,"Spanish");
    int cant,i;
    printf("\n Ingrese la cantidad de números pares e impares que desea: \n\n\t");
    scanf("%d",&cant);
    printf("\n\n\t IMPARES \t PARES \n");
    for(i=1;i<=cant*2;i+=2)
        printf("\n\t %d \t\t %d",i,i+1);
    getch();
    }
