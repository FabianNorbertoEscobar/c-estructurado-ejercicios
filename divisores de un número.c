#include<stdio.h>
#include<conio.h>
#include<locale.h>
void main()
    {
    setlocale(LC_CTYPE,"Spanish");
    int n,i;
    printf("\n Ingrese un número natural \n\n\t");
    scanf("%d",&n);
    printf("\n\n Los divisores son: \n\n");
    for(i=1;i<=n;i++)
        if(n%i==0)
            printf("\t %d \n",i);
    getch();
    }
