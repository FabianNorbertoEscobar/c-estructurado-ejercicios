#include<stdio.h>
#include<conio.h>
#include<locale.h>
void main()
    {
    setlocale(LC_CTYPE,"Spanish");
    int mes,ano,dia;
    printf("\n Ingrese el número de un mes:\n\n\t");
    do
        {
        scanf("%d",&mes);
        }
    while(mes<1||mes>12);
    printf("\n\n Ingrese el año:\n\n\t");
    scanf("%d",&ano);
    if(mes==4||mes==6||mes==9||mes==11)
        dia=30;
    else
        if(mes==2)
            if(ano%4==0||(ano%400==0&&ano%100!=0))
                dia=29;
            else
                dia=28;
        dia=31;
    printf("\n\n El mes %d tiene %d días\n\n",mes,dia);
    getch();
    }
