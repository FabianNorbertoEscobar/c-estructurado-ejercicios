#include<stdio.h>
#include<conio.h>
#include<locale.h>
void main()
    {
    setlocale(LC_CTYPE,"Spanish");
    float D,d,per,ar;
    do
        {
        printf("\n Ingrese la longitud de la diagonal mayor de un rombo: \n\t\t");
        scanf("%f",&D);
        }
    while(D<0);
    do
        {
        printf("\n Ingrese la longitud de la diagonal menor de un rombo: \n\t\t");
        scanf("%f",&d);
        }
    while(d<0);
    per=2*D+2*d;
    ar=(float)D*d/2;
    printf("\n Perímetro del rombo: %.2f \n\n Área del rombo: %.2f \n\n",per,ar);
    getch();
    }
