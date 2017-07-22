#include<stdio.h>
#include<conio.h>
#include<locale.h>
void main()
    {
    setlocale(LC_CTYPE,"Spanish");
    int band,cont,cont2,cod;
    float acum,p,l,mayp,mayl;
    acum=0;
    band=cont=cont2=0;
    printf("\n CONTROL DE LAS MUESTRAS DE UN LABORATORIO \n");
    printf("\n Ingrese el código de la muestra (código -1 finaliza)\n\n");
    scanf("%d",&cod);
    while(cod!=-1)
        {
        printf("\n Ingrese el peso de la muestra: \n\n");
        do
            {
            scanf("%f",&p);
            }
        while(p<=0);
        printf("\n Ingrese la longitud de la muestra: \n\n");
        do
            {
            scanf("%f",&l);
            }
        while(l<=0);
        if(p>=39.5&&p<=64.8)
            cont++;
        if(l>15.30)
            {
            acum+=l;
            cont2++;
            }
        if(band==0||p>mayp)
            {
            band=1;
            mayp=p;
            mayl=l;
            }
        printf("\n Ingrese el código de la muestra (código -1 finaliza)\n\n");
        scanf("%d",&cod);
        }
    printf("\n La cantidad de muestras que pesan entre 39.5 y 64.8 es de %d \n\n",cont);
    if(cont2>0)
        printf("\n El promedio de la longitud de aquellas muestras cuya \n longitud supera los 15.30 es de %.2f \n\n",acum/cont2);
    else
        printf("\n No se ingresaron muestras cuya longitud supere los 15.30 \n\n");
    printf("\n La muestra con mayor peso tiene una longitud de %.2f \n y un peso de %.2f \n\n",mayp,mayl);
    getch();
    }
