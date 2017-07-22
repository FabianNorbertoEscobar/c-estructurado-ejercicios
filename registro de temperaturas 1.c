#include<stdio.h>
#include<conio.h>
#include<locale.h>
void main()
    {
    setlocale(LC_CTYPE,"Spanish");
    int m,d,h,horamax,diamax,mesmax,men;
    float acum,max,tmp,prom;
    printf("\n\n Ingrese las temperaturas(cada medición corresponderá a una hora) \n\n");
    acum=0;
    max=0;
    for(m=1;m<=12;m++)
        {
        for(d=1;d<=30;d++)
            for(h=1;h<=24;h++)
                {
                scanf("%f",&tmp);
                if((m==1&&d==1&&h==1)||tmp>max)
                    {
                    max=tmp;
                    horamax=h;
                    diamax=d;
                    mesmax=m;
                    }
                acum+=tmp;
                }
        prom=acum/30/24;
        acum=0;
        if(m==1||prom<men)
            men=m;
        printf("\n\n Promedio de las temperaturas del mes %d: %f \n\n",m,prom);
        }
    printf("\n\n En el mes %d, día %d y hora %d se produjo la temperatura máxima,\n que fue de %d grados\n\n",mesmax,diamax,horamax,max);
    printf("\n\n El mes con el menor promedio de temperaturas fue %d \n\n",men);
    getch();
    }
