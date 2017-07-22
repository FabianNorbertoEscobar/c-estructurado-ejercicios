#include <stdio.h>
#include <conio.h>
#include <ctype.h>
#include <locale.h>
void main()
{
setlocale(LC_CTYPE,"Spanish");
int i;
printf("\n\t\t\t   **************** \n");
printf("  \t\t\t   * CÓDIGO ASCII *\n");
printf("  \t\t\t   ****************\n");
printf("\n\t\t\t CARACTERES DE CONTROL\n");
for(i=0;i<=9;i++)
    printf("\n\t\t Código Ascii:\t %d _____ Caracter: %c \n",i,i);
printf("\n \t\t Código Ascii:\t %d _____ Caracter: %c",10,10);
for(i=11;i<=31;i++)
    printf("\n\t\t Código Ascii:\t %d _____ Caracter: %c \n",i,i);
printf("\n\t\t\t    CARACTERES IMPRIMIBLES\n");
for(i=32;i<=127;i+=2)
    printf("\n Código Ascii:\t %d _____ Caracter: %c \t Código Ascii:\t %d _____ Caracter: %c \n",i,i,i+1,i+1);
printf("\n\t\t    CARACTERES IMPRIMIBLES EXTENDIDO\n");
for(i=128;i<=255;i+=2)
    printf("\n Código Ascii:\t %d _____ Caracter: %c \t Código Ascii:\t %d _____ Caracter: %c \n",i,i,i+1,i+1);
getch();
}
