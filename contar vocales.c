#include<stdio.h>
#include<conio.h>
int contarvocal(char);
void mostrar(int);
void main()
    {
    char car;
    int cont;
    printf("\n Ingrese un caracter: (finalice con asterisco) \t\t");
    fflush(stdin);
    scanf("%c",&car);
    while(car!='*')
        {
        cont+=contarvocal(car);
        printf("\n Ingrese un caracter: (finalice con asterisco) \t\t");
        fflush(stdin);
        scanf("%c",&car);
        }
    mostrar(cont);
    getch();
    }
int contarvocal(char c)
    {
    c=tolower(c);
    switch(c)
        {
        case 'a':
        case 'e':
        case 'i':
        case 'o':
        case 'u':return 1;
            break;
        default:return 0;
        }
    }
void mostrar(int c)
    {
    printf("\n La cantidad de vocales es %d \n\n",c);
    }
