#include<stdio.h>
#include<conio.h>
#include<locale.h>
void main()
    {
    setlocale(LC_CTYPE,"Spanish");
    float a,b,c,may,prom,sum;
    int op;
    printf("\n\n Ingrese una terna de números reales, ingresando los valores \n de a uno por vez y confirmando cada uno con enter \n\n");
    scanf("%f%f%f",&a,&b,&c);
    op=0;
    while(!(a<=b&&b<=c)&&op!=4)
        {
        printf("\n\n\t\t **OPCIONES POSIBLES** \n");
        printf("\n\n 1-Mayor valor \n 2-Promedio \n 3-Suma \n 4-Finalizar \n \t\t\t\t**Digite su opción: \n\n");
        do
            {
            scanf("%d",&op);
            }
        while(op<1||op>4);
        if(op==1)
            {
            if(a>b)
                may=a;
            else
                may=b;
            if(c>may)
                may=c;
            printf("\n\n Mayor: %8.2f \n\n",may);
            }
        else
            {
            if(op==2)
                {
                prom=(a+b+c)/3;
                printf("\n\n Promedio: %8.2f \n\n",prom);
                }
            else
                if(op==3)
                    {
                    sum=a+b+c;
                    printf("\n\n Suma: %8.2f \n\n",sum);
                    }
            }
        if(op!=4)
            {
            printf("\n\n Ingrese una terna de números reales, ingresando los valores \n de a uno por vez y confirmando cada uno con enter \n\n");
            scanf("%f%f%f",&a,&b,&c);
            }
        }
    printf("\n\n Fin del programa \n\n");
    getch();
    }
