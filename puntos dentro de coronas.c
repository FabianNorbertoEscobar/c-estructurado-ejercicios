#include<stdio.h>
#include<conio.h>
#include<math.h>
#include<locale.h>
float lectura(float);
void main()
    {
    setlocale(LC_CTYPE,"Spanish");
    int i;
    float xc,yc,r1,r2,r3,xp,yp,d,cont1,cont2,cont3,cont4;
    cont1=0;
    cont2=0;
    cont3=0;
    cont4=0;
    printf("\n\n Ingrese las coordenadas del centro de una circunferencia \n de a una, y confirmando cada una con enter \n\n");
    scanf("%f%f",&xc,&yc);
    printf("\n\n Ingrese el radio de una circunferencia: \n\n");
    r1=lectura(0);
    printf("\n\n Ingrese el radio de una circunferencia concéntrica y mayor a la circunferencia anterior \n\n");
    r2=lectura(r1);
    printf("\n\n Ingrese el radio de una circunferencia concéntrica y mayor a la circunferencia anterior \n\n");
    r3=lectura(r2);
    i=1;
    printf("\n\n Ingrese las coordenadas del punto %d \n (ingrese el punto (0,0) para finalizar el proceso)\n\n",i);
    scanf("%f%f",&xp,&yp);
    while(xp!=0&&yp!=0)
        {
        d=sqrt(pow(xc-xp,2)+pow(yc-yp,2));
        if(d<r1)
            cont1++;
        else
            if(d<r2)
                cont2++;
            else
                if(d<r3)
                    cont3++;
                else
                    cont4++;
        i++;
        printf("\n\n Ingrese las coordenadas del punto %d \n (ingrese el punto (0,0) para finalizar el proceso)\n\n",i);
        scanf("%f%f",&xp,&yp);
        }
    printf("\n\n Puntos dentro de la circunferencia de radio %8.2f: %d \n",r1,cont1);
    printf("\n\n Puntos dentro de la corona de radio %8.2f: %8d \n",r2,cont2);
    printf("\n\n Puntos dentro de la corona de radio %8.2f: %d \n",r3,cont3);
    printf("\n\n Puntos fuera de la circunferencia de radio %8.2f: %d",r3,cont4);
    getch();
    }
float lectura(float x)
    {
    float y;
    do
        {
        scanf("%f",&y);
        }
    while(y<x);
    return y;
    }
