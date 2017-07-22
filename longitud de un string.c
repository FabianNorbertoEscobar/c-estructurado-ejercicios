#include<stdio.h>
#include<conio.h>
#include<string.h>
void main()
{
char cadena[21];
printf("\n Ingrese una cadena de no mas de 20 caracteres: \n\t");
gets(cadena);
printf("\n La cadena ingresada contiene: %d caracteres \n",strlen(cadena));
getch();
}
