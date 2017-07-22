#include<stdio.h>
#include<conio.h>
#include<locale.h>
void main()
    {
    setlocale(LC_CTYPE,"Spanish");
    int hist,imp;
    char cod;
    printf("\n\n Ingrese número de historia y código(A, D, F, M ó T) \n confirma cada uno con enter\n\n");
    scanf("%d%s",&hist,&cod);
    if(cod=='A')
        imp=20;
    else
        if(cod=='D')
            imp=40;
        else
            if(cod=='F')
                imp=60;
            else
                if(cod=='M'||cod=='T')
                    imp=150;
                else
                    printf("\n\n Código erróneo \n\n");
    printf("\n\n Historia:%d \t Código:%c \t Importe:%d \n\n",hist,cod,imp);
    getch();
    }
