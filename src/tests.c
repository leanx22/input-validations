#include <stdio.h>
#include <stdlib.h>
#include "validaciones.h"

int main(void)
{
	setbuf(stdout,NULL);
	char cadenita[50];
	int numerito;
	float numeritoF;
/*
	if(val_getStr(cadenita,"Ingrese texto: ","[MENSAJE DE ERROR DE LA FUNCION]",50,3)==0)
	{
		printf("\nRetorno correcto | Resultado: [>%s<]",cadenita);
	}else{
		printf("\nFin de la funcion | Retorno incorrecto (!=0).");
	}
	printf("\n");
	system("PAUSE");
//----------------------------------------------------------------------------------------------
	system("CLS");
	if(val_getStrS(cadenita,"Ingrese texto con espacios: ","[MENSAJE DE ERROR DE LA FUNCION]",50,3)==0)
	{
		printf("\nRetorno correcto | Resultado: [>%s<]",cadenita);
	}else{
		printf("\nSalio todo como el orto, retorno algo distinto a 0.");
	}
	printf("\n");
	system("PAUSE");
//----------------------------------------------------------------------------------------------
	system("CLS");
	if(val_getStrSP(cadenita,"Ingrese texto con espacios y puntuaciones: ","[MENSAJE DE ERROR DE LA FUNCION]",50,3)==0)
	{
		printf("\nRetorno correcto | Resultado: [>%s<]",cadenita);
	}else{
		printf("\nSalio todo como el orto, retorno algo distinto a 0.");
	}
	printf("\n");
	system("PAUSE");
//----------------------------------------------------------------------------------------------

	system("CLS");
	if(val_getEmail(cadenita,"Ingrese un eMail: ","[MENSAJE DE ERROR DE LA FUNCION]",50,3)==0)
	{
		printf("\nRetorno correcto | Resultado: [>%s<]",cadenita);
	}else{
		printf("\nSalio todo como el orto, retorno algo distinto a 0.");
	}
	printf("\n");
	system("PAUSE");

//-----------------------------------------------------------------------------------------------

	system("CLS");
	if(val_getint(&numerito,"Ingrese un numero: ","[MENSAJE DE ERROR DE LA FUNCION]",0,999,3)==0)
	{
		printf("\nRetorno correcto | Resultado: [>%d<]",numerito);
	}else{
		printf("\nSalio todo como el orto, retorno algo distinto a 0.");
	}
	printf("\n");
	system("PAUSE");
//----------------------------------------------------------------------------------------------------
	system("CLS");
	if(val_getFloat(&numeritoF,"Ingrese un numero flotante: ","[MENSAJE DE ERROR DE LA FUNCION]",0,999,3)==0)
	{
		printf("\nRetorno correcto | Resultado: [>%.2f<]",numeritoF);
	}else{
		printf("\nSalio todo como el orto, retorno algo distinto a 0.");
	}
	printf("\n");
	system("PAUSE");
//-----------------------------------------------------------------------------------------------------

	system("CLS");
	if(val_isAlphaNumeric("Soy4lf4numeric0")==1)
	{
		printf("\nEl texto es alfa-numerico");
	}else{
		printf("\nN.");
	}
	printf("\n");
	system("PAUSE");
//-----------------------------------------------------------------------------------------------------
*/
	system("CLS");
	if(val_isAllChar("a")==1)
	{
		printf("\nTodos los caracteres son letras");
	}else{
		printf("\nHay un caracter no alfabetico!.");
	}
	printf("\n");
	system("PAUSE");

return 0;
}
