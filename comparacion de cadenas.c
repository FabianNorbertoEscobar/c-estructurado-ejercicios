#include<stdio.h>
#include<conio.h>
#include<string.h>
void main()
{
char receptor[20],interna[]="PARA COMPARAR";//inicialización de una cadena
printf("\n Ingrese una cadena a comparar con una cadena interna \n\t");
gets(receptor);
if(strcmp(receptor,interna)==0)
    printf("\n Ambas cadenas son iguales \n");
else
    if(strcmp(receptor,interna)>0)
       printf("\n La cadena ingresada es mayor que la cadena interna \n");
else
    printf("\n La cadena interna es mayor que la cadena ingresada \n");
getch();
}
