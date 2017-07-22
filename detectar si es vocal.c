#include<stdio.h>
#include<conio.h>
#include<locale.h>
void main()
    {
    setlocale(LC_CTYPE,"Spanish");
    char car;
    printf("\n Ingrese un caracter alfanumérico:\n\n\t");
    scanf("%c",&car);
        if((car=='a')||(car=='A')||(car=='e')||(car=='E')||(car=='i')||(car=='I')||(car=='o')||(car=='O')||(car=='u')||(car=='U'))
            printf("\n %c es vocal \n",car);
        else(printf("\n %c no es vocal \n",car));
    getch();
    }
