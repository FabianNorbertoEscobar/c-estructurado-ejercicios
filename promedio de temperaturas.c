#include<stdio.h>
#include<conio.h>
#include<locale.h>
void main()
    {
    setlocale(LC_CTYPE,"Spanish");
    int cont,i;
    float tmp,prom,acum;
    acum=0;
    cont=0;
    printf("\n Ingrese 120 valores de temperatura: \n\n");
    for(i=1;i<=120;i++)
        {
        scanf("%f",&tmp);
        if(tmp>=5&&tmp<=25)
            {
            acum+=tmp;
            cont++;
            }
        }
    if(cont>0)
        prom=acum/cont;
    else
        prom=0;
    printf("\n\n El promedio de las temperaturas entre 5 y 25 grados es %4.2f \n\n",prom);
    getch();
    }
