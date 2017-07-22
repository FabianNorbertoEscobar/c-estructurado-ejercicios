#include<stdio.h>
#include<conio.h>
#include<locale.h>
void main()
    {
    setlocale(LC_CTYPE,"Spanish");
    int i,n,acum;
    acum=0;
    for(i=0;i<10;i++)
        {
        printf("\n Ingrese un número:\n\n");
        scanf("%d",&n);
        acum+=n;
        }
    printf("\n Promedio: %.2f \n\n",(float)acum/10);
    getch();
    }
