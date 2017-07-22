#include<stdio.h>
#include<conio.h>
#include<locale.h>
void main()
    {
    setlocale(LC_CTYPE,"Spanish");
    float l1,l2,l3;
    printf("\n\n Ingrese los tres valores de los lados de un triángulo: \n Confirma cada uno con enter \n\n");
    scanf("%f%f%f",&l1,&l2,&l3);
    if(l1>0&&l2>0&&l3>0)
        if(l1+l2>l3)
            if(l2+l3>l1)
                if(l3+l1>l2)
                    printf("\n\n Se forma triángulo \n\n");
                else
                    printf("\n\n No se forma triángulo \n\n");
            else
                printf("\n\n No se forma triángulo \n\n");
        else
            printf("\n\n No se forma triángulo \n\n");
    else
        printf("\n\n No se forma triángulo \n\n");
    getch();
    }
