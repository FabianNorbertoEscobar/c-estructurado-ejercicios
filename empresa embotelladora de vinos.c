#include<stdio.h>
#include<conio.h>
#include<locale.h>
void main()
    {
    setlocale(LC_CTYPE,"Spanish");
    int band,cont1005,cont5805,acum,vino,lote,unid,mayunid,maylote,mayvino;
    band=cont1005=cont5805=acum=0;
    printf("\n EMPRESA EMBOTELLADORA DE VINOS \n");
    printf("\n Ingrese el número de la clase de vino \n\n");
    do
        {
        scanf("%d",&vino);
        }
    while(vino<0);
    while(vino!=0)
        {
        printf("\n Ingrese el número de lote \n\n");
        do
            {
            scanf("%d",&lote);
            }
        while(lote<=0);
        printf("\n Ingrese la cantidad de unidades \n\n");
        do
            {
            scanf("%d",&unid);
            }
        while(unid<=0);
        if(vino==1005)
            cont1005+=lote;
        if(vino==5805)
            {
            acum+=unid;
            cont5805++;
            }
        if(band==0||unid>mayunid)
            {
            band=1;
            mayunid=unid;
            mayvino=vino;
            maylote=lote;
            }
        printf("\n Ingrese el número de la clase de vino \n\n");
        do
            {
            scanf("%d",&vino);
            }
        while(vino<0);
        }
    printf("\n La cantidad de lotes que hay de clase de vino 1005 es de %d \n\n",cont1005);
    if(cont5805>0)
        printf("\n El promedio de las unidades de clase de vino 5805 es de %.2f \n\n",(float)acum/cont5805);
    else
        printf("\n No hubo vinos de clase 5805 \n\n");
    printf("\n El vino que tuvo la mayor cantidad de unidades en un ingreso \n fue de clase %d e ingresó con un lote de %d \n\n",mayvino,maylote);
    getch();
    }
