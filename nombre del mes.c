#include<stdio.h>
#include<conio.h>
#include<locale.h>
int validadato(int,int,int);
void main()
{
setlocale(LC_CTYPE,"Spanish");
int mes;
    printf("\n Ingrese un número correspondiente a un mes:\n\n\t");
    do
    {scanf("%d",&mes);
    }
    while(!validadato(mes,1,12));
    switch(mes)
        {
        case 1: printf("\n Enero \n");
        break;
        case 2: printf("\n Febrero \n");
        break;
        case 3: printf("\n Marzo \n");
        break;
        case 4: printf("\n Abril \n");
        break;
        case 5: printf("\n Mayo \n");
        break;
        case 6: printf("\n Junio \n");
        break;
        case 7: printf("\n Julio \n");
        break;
        case 8: printf("\n Agosto \n");
        break;
        case 9: printf("\n Septiembre \n");
        break;
        case 10: printf("\n Octubre \n");
        break;
        case 11: printf("\n Noviembre \n");
        break;
        default: printf("\n Diciembre \n");
        }
getch();
}
int validadato(int dato,int li,int ls)
{
    if(dato>=li&&dato<=ls)
        return 1;
    else
        return 0;
}
