#include <stdio.h>
#include <conio.h>
#include <ctype.h>
void main()
{
char l;
printf("\n Ingrese un caracter alfanumerico:\n\n\t\t");
scanf("%c",&l);
l=tolower(l);
switch (l)
    {
    case 'a':
    case 'e':
    case 'i':
    case 'o':
    case 'u': printf("\n\n %c es vocal y su valor en codigo Ascii es %d \n\n",l,l);
    break;
    default : printf("\n\n %c no es vocal y su valor en codigo Ascii es %d \n\n",l,l);
    }
getch();
}
