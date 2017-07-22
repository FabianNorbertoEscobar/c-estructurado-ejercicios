#include<stdio.h>
#include<conio.h>
#include<string.h>
void main()
{
char original[15],copia[15];
printf("\n Ingrese una cadena que va a ser luego copiada \n\t");
gets(original);
strcpy(copia,original);
printf("\n La cadena original es: %s y la copia es: %s \n",original,copia);
getch();
}
