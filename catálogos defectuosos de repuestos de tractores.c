#include<stdio.h>
#include<conio.h>
#include<locale.h>
void main()
    {
    setlocale(LC_CTYPE,"Spanish");
    int cat;
    printf("\n\n Ingrese el número de catálogo:\n (recuerde que los catálogos varían entre 1200 y 90000)\n\n\t");
    do
        scanf("%d",&cat);
    while(cat<1200||cat>90000);
    if(((cat>=12121)&&(cat<=18081)||((cat>=30012)&&(cat<=45565))||((cat>=67000)&&(cat<=68000))))
        printf("\n\n El repuesto de tractor es defectuoso \n\n");
    else
        printf("\n\n El repuesto de tractor no es defectuoso \n\n");
    getch();
    }
