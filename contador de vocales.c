#include<stdio.h>
#include<conio.h>
#include<locale.h>
void main()
    {
    setlocale(LC_CTYPE,"Spanish");
    int voc;
    char c;
    printf("\n\n Ingrese caracteres de a uno por vez, confirmando cada uno con enter:");
    printf("\n Ingrese asterisco para terminar\n\n");
    voc=0;
    fflush(stdin);
    scanf("%c",&c);
    c=toupper(c);
    while(c!='*')
        {
        if(c=='A'||c=='E'||c=='I'||c=='O'||c=='U')
            voc++;
        fflush(stdin);
        scanf("%c",&c);
        c=toupper(c);
        }
    printf("\n\n Cantidad de vocales:%d \n\n",voc);
    getch();
    }
