#include<stdio.h>
#include<conio.h>
#include<locale.h>
void main()
    {
    setlocale(LC_CTYPE,"Spanish");
    int num1,num2,coc;
    printf("\n\n CÁLCULO DE COCIENTE");
    printf("\n\n Ingrese un número entero:\n\n\t\t");
    scanf("%d",&num1);
    printf("\n\n Ingrese otro número entero:\n\n\t\t");
    scanf("%d",&num2);
    if(num2==0)
        printf("\n\n\a\a No se puede dividir por cero \n\n");
    else
        {
        coc=num1/num2;
        printf("\n\n Cociente: \t %d \n\n",coc);
        }
    getch();
    }
