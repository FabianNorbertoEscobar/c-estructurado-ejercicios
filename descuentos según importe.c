#include<stdio.h>
#include<conio.h>
#include<locale.h>
void main()
    {
    setlocale(LC_CTYPE,"Spanish");
    float pr,desc,net;
    printf("\n\n Ingrese un precio: (finalice el proceso ingresando un precio ilógico) \n\n\t");
    scanf("%f",&pr);
    while(pr>=0)
        {
        if(pr<50)
            desc=pr*3.5/100;
        else
            if(pr<=150)
                desc=pr/10;
            else
                if(pr<=300)
                    desc=pr*20/100;
                else
                    desc=pr*25/100;
        net=pr-desc;
        printf("\n\n Precio:%8.2f \t Descuento :%8.2f \t Neto:%8.2f \n\n",pr,desc,net);
        printf("\n\n Ingrese un precio: (finalice el proceso ingresando un precio ilógico) \n\n\t");
        scanf("%f",&pr);
        }
    getch();
    }
