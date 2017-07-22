#include<stdio.h>
#include<conio.h>
#include<locale.h>
void main()
    {
    setlocale(LC_CTYPE,"Spanish");
    int n;
    printf("\n\n Ingrese un número: \n\n\t\t");
    scanf("%d",&n);
    if(n>0)
        printf("\n\n El número es positivo \n\n");
    else
        if(n<0)
            printf("\n\n El número es negativo \n\n");
        else
            printf("\n\n El número es cero \n\n");
    getch();
    }
