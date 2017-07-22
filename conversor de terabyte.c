#include<stdio.h>
#include<conio.h>
void main()
    {
    float tb,gb,mb,kb,byte;
    printf("\n Ingrese un valor expresado en Terabyte:\n\n\t");
    scanf("%f",&tb);
        gb=tb*1024;
        mb=gb*1024;
        kb=mb*1024;
        byte=kb*1024;
    printf("\n %f terabyte equivale a:\n\n %f gigabyte \n\n %f megabyte \n\n %f kilobyte \n\n %f byte\n\n",tb,gb,mb,kb,byte);
    getch();
    }
