#include<stdio.h>
#include<conio.h>
#include<locale.h>
void main()
    {
    setlocale(LC_CTYPE,"Spanish");
    int i,ordmax,ordmin,cont;
    float tmp,max,min,acum,prom;
    acum=0;
    cont=0;
    printf("\n\n Ingrese 18 temperaturas (distintas de cero)\n\n");
    for(i=1;i<=18;i++)
        {
        scanf("%f",&tmp);
        if(i==1||tmp>max)
            {
            max=tmp;
            ordmax=i;
            }
        if(i==1||tmp<min)
            {
            min=tmp;
            ordmin=i;
            }
        if(tmp<0)
            {
            acum+=tmp;
            cont++;
            }
        }
    if(cont>0)
        {
        prom=acum/cont;
        printf("\n\n El promedio de temperaturas negativas es %8.2f grados \n\n",prom);
        }
    else
        printf("\n\n No se puede calcular el promedio \n\n");
    printf("\n\n mayor temperatura:%8.2f \t Orden:%d \n",max,ordmax);
    printf("\n Menor temperatura:%8.2f \t Orden:%d \n",min,ordmin);
    getch();
    }
