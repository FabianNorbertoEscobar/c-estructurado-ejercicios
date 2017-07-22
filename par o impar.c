#include<stdio.h>
#include<conio.h>
#include<locale.h>
void main()
    {
    setlocale(LC_CTYPE,"Spanish");
    int n;
    printf("\n\n Ingrese un número:\n\n\t\t");
    scanf("%d",&n);
    if(n%2==0)
        printf("\n\n El número es par \n\n");
    else
        printf("\n\n El número es impar \n\n");
    getch();
    }
