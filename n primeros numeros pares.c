#include<stdio.h>
#include<conio.h>
#include<locale.h>
void main()
    {
    setlocale(LC_CTYPE,"Spanish");
    int n,i,par;
    printf("\n Ingrese un numero mayor o igual a cero:\n\n\t");
    scanf("%d",&n);
    printf("\n Los primeros %d numeros pares son:\n",n);
        for(i=1;i<=n;i++)
            {
            par=2*i;
            printf("\n %d \n",par);
            }
    getch();
    }
