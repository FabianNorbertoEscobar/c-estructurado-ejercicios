#include<stdio.h>
#include<conio.h>
#include<locale.h>
void main()
    {
    setlocale(LC_CTYPE,"Spanish");
    int leg,a,b;
    printf("\n\n Ingrese un número de legajo. Legajo negativo para finalizar \n\n");
    scanf("%d",&leg);
    while(leg>=0)
        {
        printf("\n\n Ingrese las notas de ambos parciales, de a una, confirmando cada uno con enter \n\n");
        scanf("%d%d",&a,&b);
        printf("\n\n Legajo:%d \t 1er parcial:%d \t\t 2do parcial:%d \n",leg,a,b);
        if(a>=7&&b>=7)
            printf("\n\n Condición final:\t Promociona la materia \n\n");
        else
            if(a>=4&&b>=4)
                printf("\n\n Condición final:\t Rinde examen final \n\n");
            else
                printf("\n\n Condición final:\t Reprobó la materia \n\n");
        printf("\n\n Ingrese un número de legajo. Legajo negativo para finalizar \n\n");
        scanf("%d",&leg);
        }
    getch();
    }
