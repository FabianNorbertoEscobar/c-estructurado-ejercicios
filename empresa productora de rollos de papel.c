#include<stdio.h>
#include<conio.h>
#include<locale.h>
void main()
    {
    setlocale(LC_CTYPE,"Spanish");
    int cont1,cont2,cont3,cont4,cont5,acum1,acum2,acum3,acum4,acum5,planta,rollos,mayr,mayp;
    cont1=cont2=cont3=cont4=cont5=0;
    acum1=acum2=acum3=acum4=acum5=0;
    printf("\n EMPRESA PRODUCTORA DE ROLLOS DE PAPEL \n");
    printf("\n Ingrese el número de planta (entre 1 y 5) \n (Ingrese 0 para finalizar)\n\n");
    do
        {
        scanf("%d",&planta);
        }
    while(!(planta>=0&&planta<=5));
    while(planta!=0)
        {
        printf("\n Ingrese la cantidad de rollos producidos en esa planta (entre 1 y 1000)\n\n");
        do
            {
            scanf("%d",&rollos);
            }
        while(!(rollos>=1&&rollos<=1000));
        switch(planta)
            {
            case 1: cont1++;
                    acum1+=rollos;
                    break;
            case 2: cont2++;
                    acum2+=rollos;
                    break;
            case 3: cont3++;
                    acum3+=rollos;
                    break;
            case 4: cont4++;
                    acum4+=rollos;
                    break;
            case 5: cont5++;
                    acum5+=rollos;
                    break;
            }
        printf("\n Ingrese el número de planta (entre 1 y 5) \n (Ingrese 0 para finalizar)\n\n");
        do
            {
            scanf("%d",&planta);
            }
        while(!(planta>=0&&planta<=5));
        }
    if(acum1>acum2)
        {
        mayr=acum1;
        mayp=1;
        }
    else
        {
        mayr=acum2;
        mayp=2;
        }
    if(acum3>mayr)
        {
        mayr=acum3;
        mayp=3;
        }
    if(acum4>mayr)
        {
        mayr=acum4;
        mayp=4;
        }
    if(acum5>mayr)
        {
        mayr=acum5;
        mayp=5;
        }
    if(cont1>0)
        printf("\n El promedio de rollos de la planta 1 es de %.2f \n",(float)acum1/cont1);
    else
        printf("\n La planta 1 no produjo \n");
    if(cont2>0)
        printf("\n El promedio de rollos de la planta 2 es de %.2f \n",(float)acum2/cont2);
    else
        printf("\n La planta 2 no produjo \n");
    if(cont3>0)
        printf("\n El promedio de rollos de la planta 3 es de %.2f \n",(float)acum3/cont3);
    else
        printf("\n La planta 3 no produjo \n");
    if(cont4>0)
        printf("\n El promedio de rollos de la planta 4 es de %.2f \n",(float)acum4/cont4);
    else
        printf("\n La planta 4 no produjo \n");
    if(cont5>0)
        printf("\n El promedio de rollos de la planta 5 es de %.2f \n",(float)acum5/cont5);
    else
        printf("\n La planta 5 no produjo \n");
    printf("\n La planta %d ha producido la mayor cantidad de rollos de papel \n\n",mayp);
    getch();
    }
