#include<stdio.h>
#include<conio.h>
#include<locale.h>
void main()
    {
    setlocale(LC_CTYPE,"Spanish");
    char c;
    int num,may,min,nalf,band;
    num=0;
    may=0;
    min=0;
    nalf=0;
    printf("\n Ingrese caracteres de cualquier tipo, de a uno por vez, \n confirmándolos con enter: \n (finalice ingresando asterisco)\n\n");
    scanf("%c",&c);
    while(c!='*')
        {
        band=1;
        if(c=='a'||c=='b'||c=='c'||c=='d'||c=='e'||c=='f'||c=='g'||c=='h'||c=='i'||c=='j'||c=='k'||c=='l'||c=='m'||c=='n'||c=='o'||c=='p'||c=='q'||c=='r'||c=='s'||c=='t'||c=='u'||c=='v'||c=='w'||c=='x'||c=='y'||c=='z')
            {
            min++;
            band=0;
            }
        if(c=='A'||c=='B'||c=='C'||c=='D'||c=='E'||c=='F'||c=='G'||c=='H'||c=='I'||c=='J'||c=='K'||c=='L'||c=='M'||c=='N'||c=='O'||c=='P'||c=='Q'||c=='R'||c=='S'||c=='T'||c=='U'||c=='V'||c=='W'||c=='X'||c=='Y'||c=='Z')
            {
            may++;
            band=0;
            }
        if(c=='0'||c=='1'||c=='2'||c=='3'||c=='4'||c=='5'||c=='6'||c=='7'||c=='8'||c=='9')
            {
            num++;
            band=0;
            }
        if(band==1)
            nalf++;
        fflush(stdin);
        scanf("%c",&c);
        }
    printf("\n\n Caracteres numéricos:%d \n Caracteres alfabéticos minúsculos:%d \n Caracteres alfabéticos mayúsculos:%d \n Caracteres no alfanuméricos:%d \n\n",num,min,may,nalf);
    getch();
    }
