#include<stdio.h>
#include<conio.h>
#include<locale.h>
void main()
{
setlocale(LC_CTYPE,"Spanish");
printf("\n #include<locale.h> \n\n void main()");
printf("\n {\n\t setlocale(LC_CTYPE,\"Spanish\");\n }\n");
printf("\n Con ésta librería y éste seteo de la librería en Spanish");
printf("\n o en cualquier otro idioma, se pueden escribir caracteres como ñ o ü \n\n");
getch();
}
