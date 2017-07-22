#include<stdio.h>
#include<conio.h>
#include<locale.h>
void recuadro(int,char);
void guiones(int);
void main()
    {
    int cant;
    char car;
    setlocale(LC_CTYPE,"Spanish");
    printf("\n Ingrese el caracter para el cual desea que se imprima \n un recuadro de guiones y corchetes\n\n");
    scanf("%c",&car);
    do
        {
        printf("\n Ingrese la cantidad de pares de corchetes que desea: \n\n");
        scanf("%d",&cant);
        }
    while(cant<0);
    recuadro(cant,car);
    getch();
    }
void recuadro(int cancor,char caracter)
    {
    int j;
    printf("\t");
    guiones(cancor*2+3);
    printf("\n\t ");
    for(j=1;j<=cancor;j++)
        printf("[");
    printf("%c",caracter);
    for(j=1;j<=cancor;j++)
        printf("]");
    printf("\n\t");
    guiones(cancor*2+3);
    printf("\n");
    }
void guiones(int can)
    {
    int k;
    for(k=1;k<=can;k++)
    printf("-");
    }
