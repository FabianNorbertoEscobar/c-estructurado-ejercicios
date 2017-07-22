#include<stdio.h>
#include<conio.h>
#include<locale.h>
#include<string.h>
#include<stdlib.h>
struct info
    {
    int nc;
    char cl[26];
    int cod;
    float saldo;
    };
void main()
    {
    setlocale(LC_CTYPE,"Spanish");
    int nc,cod,i;
    i=0;
    char cl[26];
    float saldo;
    struct info aux;
    FILE *pf;
    pf=fopen("saldos.dat","ab");
    printf("\n Cargue los datos de los clientes. \n Tenga en cuenta que solo pueden haber hasta 700 cuentas corrientes \n\n");
    printf("\t CLIENTE N°%d \n",i+1);
    printf("\n Ingrese el número de cuenta (0 para finalizar): \n\n\t\t");
    do
        {
        scanf("%d",&nc);
        }
    while(nc<0);
    while(nc!=0&&i<700)
        {
        aux.nc=nc;
        printf("\n Ingrese el nombre del cliente (hasta 25 caracteres):\n\n\t\t");
        fflush(stdin);
        gets(cl);
        strcpy(aux.cl,cl);
        printf("\n Ingrese el código (1:deudor/débito; 2:acreedor/crédito):\n\n\t\t");
        do
            {
            scanf("%d",&cod);
            }
        while(cod!=1&&cod!=2);
        aux.cod=cod;
        printf("\n Ingrese el saldo de la cuenta: \n\n\t\t");
        do
            {
            scanf("%f",&saldo);
            }
        while(saldo<=0);
        aux.saldo=saldo;
        fwrite(&aux,sizeof(struct info),1,pf);
        i++;
        printf("\n\n\t CLIENTE N°%d \n",i+1);
        printf("\n Ingrese el número de cuenta (0 para finalizar): \n\n\t\t");
        do
            {
            scanf("%d",&nc);
            }
        while(nc<0);
        }
    fclose(pf);
    printf("\n Archivo creado/actualizado... \n\n");
    getch();
    }
