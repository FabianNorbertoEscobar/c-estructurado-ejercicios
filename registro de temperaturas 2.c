#include<stdio.h>
#include<conio.h>
#include<locale.h>
void main()
    {
    setlocale(LC_CTYPE,"Spanish");
    int m,d,h,cont,horamen,diamen,mesmen,may,may2,mesmay;
    float acum,tmp,men,prom;
    printf("\n\n Ingresar las temperaturas (cada medición corresponderá a una hora)\n\n");
    acum=0;
    cont=0;
    may=0;
    for(m=1;m<=12;m++)
        {
        for(d=1;d<=30;d++)
            {
            for(h=1;h<=24;h++)
                {
                scanf("%f",&tmp);
                if(tmp>600)
                    may++;
                if(h==1||tmp>men)
                    {
                    men=tmp;
                    horamen:h;
                    diamen:h;
                    mesmen:m;
                    }
                acum+=tmp;
                cont++;
                }
            printf("\n\n La menor temperatura del día %d, mes %d, fue de %4.2f grados en la hora %d \n\n",diamen,mesmen,men,horamen);
            men=0;
            horamen=0;
            diamen=0;
            mesmen=0;
            }
        if(m==1||may>may2)
            {
            may2=may;
            mesmay=m;
            }
        may=0;
        }
    prom=acum/cont;
    printf("\n\n La temperatura promedio de todas las mediciones es de %8.2f grados \n\n",prom);
    printf("\n\n El mes en el que se produjeron más temperaturas mayores a 600 grados fue el mes %d \n\n",mesmay);
    getch();
    }
