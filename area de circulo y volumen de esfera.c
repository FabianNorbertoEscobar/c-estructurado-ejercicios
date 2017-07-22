#include<stdio.h>
#include<conio.h>
#include<locale.h>
#define Pi 3.14
void main()
    {
    setlocale(LC_CTYPE,"Spanish");
    float rad,circ,esf;
    do
        {
        printf("\n\n Ingrese la longitud de un radio: \n\n\t\t");
        scanf("%f",&rad);
        }
    while(rad==0);
    circ=Pi*rad*rad;
    esf=4/3*Pi*rad*rad*rad;
    printf("\n\n Superficie del círculo de radio %8.2f: %8.2f",rad,circ);
    printf("\n\n Volumen de la esfera engendrada por la revolución de ese círculo: %8.2f \n\n",esf);
    getch();
    }
