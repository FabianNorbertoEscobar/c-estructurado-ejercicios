#include <stdio.h>
#include <conio.h>
#include <locale.h>
void main()
{
setlocale(LC_CTYPE,"Spanish");
int a,b,c;
int sen=0;
printf("\n Ingrese tres valores enteros: \n");
printf("\n Ingrese el primer valor entero: \n\n\t\t");
scanf("%d",&a);
printf("\n Ingrese el segundo valor entero: \n\n\t\t");
scanf("%d",&b);
printf("\n Ingrese el tercer valor entero: \n\n\t\t");
scanf("%d",&c);
if(a==b+c)
    {
    sen++;
    printf("\n El primer valor ingresado es igual a la suma de los otros dos \n\n");
    }
if(b==a+c)
    {
    sen++;
    printf("\n El segundo valor ingresado es igual a la suma de los otros dos \n");
    }
if(c==a+b)
    {
    sen++;
    printf("\n El tercer valor ingresado es igual a la suma de los otros dos \n");
    }
if(sen==0)
    printf("\n Ninguno de estos números es igual a la suma de los otros dos \n");
getch();
}
