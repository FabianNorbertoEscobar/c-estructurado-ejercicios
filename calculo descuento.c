#include<stdio.h>
#include<conio.h>
#include<locale.h>
void main()
    {
    setlocale(LC_CTYPE,"Spanish");
    float imp,desc,neto;
    printf("\n\n Ingrese el importe del precio: \n\n\t");
    scanf("%f",&imp);
    if(imp<55)
        desc=imp*4.5/100;
    else
        if(imp<=100)
            desc=imp*8/100;
        else
            desc=imp*10.5/100;
    neto=imp-desc;
    printf("\n\n\t Importe:%8.2f\n\t Descuento:%8.2f \n\t Precio neto:%8.2f \n\n",imp,desc,neto);
    getch();
    }
