#include<stdio.h>
#include<conio.h>
#include<locale.h>
void main()
    {
    setlocale(LC_CTYPE,"Spanish");
    int cd;
    float caj50,caj10,sueltos,neto,desc,tot;
    printf("\n\n Ingrese la cantidad de CD\'s:\n\n\t");
    scanf("%d",&cd);
    caj50=cd/50;
    caj10=cd%50/10;
    sueltos=cd%50%10;
    neto=caj50*35+caj10*8+sueltos;
    if(cd>100)
        desc=neto/10;
    else
        desc=0;
    tot=neto-desc;
    printf("\n\n Precio:%8.2f \n\n",tot);
    getch();
    }
