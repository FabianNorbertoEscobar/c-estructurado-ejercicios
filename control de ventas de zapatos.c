//Una zapatería que vende zapatos para hombre y mujer decidió aumentar sus ingresos aceptando diversas
//formas de pago.   Las formas de pago admitidas son: ‘E’ (Efectivo en pesos), ‘D’ (tarjera de Débito en pesos)
//y ‘T’ (Tarjeta de Crédito en pesos). La nueva estrategia consiste en realizar un 10% de descuento a las ventas
//en Efectivo en pesos, y un 5% de descuento a las ventas con Tarjeta de Débito.  Las ventas efectuadas con
//tarjeta de crédito no tienen descuentos.Por cada venta se ingresa el tipo de zapato (“H” para zapatos de hombre
//y “M” para zapatos de mujeres).También se ingresa el valor del zapato y la forma de pago(descripta anteriormente).
//Cuando se ingresa la forma de pago “F” indica que no se realizarán más ventas.
//Se quiere saber:
// -Cantidad e importe total de las ventas realizadas, discriminadas según la forma de pago
//    (los importes deben ser los efectivamente  cobrados luego de efectuar los descuentos).
// -Porcentaje que representan las ventas de zapatos de mujer (en cantidades de ventas, no importe de las mismas).
// -Monto promedio de las ventas efectuadas con tarjeta de Crédito.

#include<stdio.h>
#include<conio.h>
#include<locale.h>
void main()
    {
    setlocale(LC_CTYPE,"Spanish");
    int conttot,contE,contD,contT,contmujer;
    float impE,impD,impT,prom,porc,precio,dto;
    char fp,tz;
    conttot=contE=contD=contT=contmujer=0;
    impE=impD=impT=0;
    printf("\n\t\t CONTROL DE VENTAS DE LA ZAPATERÍA \n");
    printf("\n Ingrese forma de pago (E, D o T). F para terminar \n\n");
    do
        {
        fflush(stdin);
        scanf("%c",&fp);
        fp=toupper(fp);
        }
    while(fp!='E'&&fp!='D'&&fp!='T'&&fp!='F');
    while(fp!='F')
        {
        printf("\n Ingrese el tipo de zapato (H para hombre,M para mujer)\n\n");
        do
            {
            fflush(stdin);
            scanf("%c",&tz);
            tz=toupper(tz);
            }
        while(tz!='H'&&tz!='M');
        printf("\n Ingrese el precio del zapato: \n\n");
        do
            {
            scanf("%f",&precio);
            }
        while(precio<0);
        conttot++;
        if(fp=='E')
            {
            dto=precio*0.1;
            impE+=(precio-dto);
            contE++;
            }
        else
            if(fp=='D')
                {
                dto=precio*0.05;
                impD+=(precio-dto);
                contD++;
                }
            else
                {
                impT+=precio;
                contT++;
                }
        if(tz=='M')
            contmujer++;
        printf("\n Ingrese forma de pago (E, D o T). F para terminar \n\n");
        do
            {
            fflush(stdin);
            scanf("%c",&fp);
            fp=toupper(fp);
            }
        while(fp!='E'&&fp!='D'&&fp!='T'&&fp!='F');
        }
    printf("\n FORMA DE PAGO\t\t\tCANTIDAD\tIMPORTE COBRADO \n");
    printf("\n Efectivo:\t\t\t%d\t\t%.2f",contE,impE);
    printf("\n Tarjeta de Débito:\t\t%d\t\t%.2f",contD,contD);
    printf("\n Tarjeta de Crédito:\t\t%d\t\t%.2f",contT,impT);
    if(contmujer>0)
        {
        porc=(float)(contmujer/conttot)*100;
        printf("\n\n El porcentaje de zapatos de mujer vendidos es de %.2f \n\n",porc);
        }
    else
        printf("\n No se han vendido zapatos de mujer \n\n");
    if(contT>0)
        {
        prom=impT/contT;
        printf("\n El promedio de las ventas efectudas con tarjeta de crédito es de %.2f \n\n",prom);
        }
    else
        printf("\n No se han vendido zapatos con tarjeta de crédito \n\n");
    getch();
    }
