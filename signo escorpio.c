#include<stdio.h>
#include<conio.h>
#include<locale.h>
void main()
{
setlocale(LC_CTYPE,"Spanish");
int dia, mes;
do
    {
    printf("\n Ingresa en números el día de tu cumpleaños\n\n\t");
    scanf("%d",&dia);
    printf("\n Ingresa en números el mes de tu cumpleaños\n\n\t");
    scanf("%d",&mes);
    }
while((dia<1)||(dia>31)||(mes<1)||(mes>12));
if(((mes==10)&&(dia>=24))||((mes==11)&&(dia<=22)))
        printf("\n Tu signo es Escorpio\n");
else
        printf("\n Tu signo no es Escorpio\n");
getch();
}
