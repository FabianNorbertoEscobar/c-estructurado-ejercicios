#include<stdio.h>
#include<conio.h>
#include<locale.h>
void main()
    {
    setlocale(LC_CTYPE,"Spanish");
    int band,i,acum,mad,men,ord;
    i=acum=band=0;
    printf("\n CONTROL DE CORTES DE MADERA \n");
    do
        {
        printf("\n Ingrese la medida del corte de madera: \n\n");
        scanf("%d",&mad);
        }
    while(!((mad>=15&&mad>=45)||mad==-1));
    while(mad!=-1)
        {
        i++;
        acum+=mad;
        if(band==0||mad<men)
            {
            band=1;
            men=mad;
            ord=i;
            }
        do
            {
            printf("\n Ingrese la medida del corte de madera: \n\n");
            scanf("%d",&mad);
            }
        while(!((mad>=15&&mad>=45)||mad==-1));
        }
    if(i!=0)
        {
        printf("\n El valor promedio de los cortes de maderas es de %.2f \n\n",(float)acum/i);
        printf("\n El menor valor de corte es %d e ingresó en el orden %d \n\n",men,ord);
        }
    else
        printf("\n No se ingresaron cortes \n\n");
    getch();
    }
