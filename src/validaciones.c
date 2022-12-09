/*Funciones de entrada y validacion de datos.
 * Creada por: Guia Leandro.
 * github: https://github.com/leanx22
 * version: 1
 * NOTAS:
 * -Sos libre de utilizar, modificar, y/o compartir las siguientes funciones.
 * -No soy responsable del uso que se le de a este codigo.
 * -Cualquier mejora o arreglo es bienvenida, si la queres compartir manda pull request.
 * */


#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "validaciones.h"


/*	Esta funcion lee la entrada del usuario y la guarda en la cadena especificada usando fgets().
 * 	Reemplaza el caracter de salto de linea por el caracter nulo.
 *
 * 	PARAMETROS:
 * 	Str: Puntero a cadena donde se guardara la entrada del usuario.
 *	maxSize: Cantidad maxima de caracteres que seran leidos.
 *	Retorna -1 en caso de error, caso contrario sera 0.
 * */
static int readFromConsole(char* str,int maxSize)
{
	int ret = -1;

	fflush(stdin);
	if(str!=NULL && maxSize>0 && fgets(str,maxSize,stdin)==str)
	{
		if(str[strlen(str)-1]=='\n')
		{
			str[strlen(str)-1]='\0';
		}
		ret=0;
	}
	return ret;
}


//Funcion para obtener un string puro.
int val_getStr(char* array,char* msj,char* eMsj,int maxSize,int reintentos)
{
	int ret = -1;
	int contadorChars;
	char buffer[maxSize];

	if(array!=NULL && msj!=NULL && eMsj!=NULL && maxSize>0 && reintentos>0)
	{
		while(reintentos>0)
		{
			contadorChars=0;
			printf("\n>%s",msj);
			readFromConsole(buffer,maxSize);

			for(int i=0;i<maxSize;i++)
			{
				if(buffer[i]!='\0')
				{
					if(isalpha(buffer[i])==0)
					{
						reintentos--;
						printf("\n\a[!]%s",eMsj);
						break;
					}
					else
					{
						contadorChars++;
					}
				}
				else
				{
					if(contadorChars>=3)
					{
						strcpy(array,buffer);
						ret=0;
						reintentos=0;
						break;
					}
					else
					{
						printf("\n\a[!]Error: Se debe ingresar, por lo menos, mas de 3 caracteres!");
						reintentos--;
						break;
					}
				}
			}

		}
	}

	return ret;
}

//Funcion para obtener un string, permite espacios (S=space).
int val_getStrS(char* array,char* msj,char* eMsj,int maxSize,int reintentos)
{
	int ret = -1;
	int contadorChars;
	char buffer[maxSize];

	if(array!=NULL && msj!=NULL && eMsj!=NULL && maxSize>0 && reintentos>0)
	{
		while(reintentos>0)
		{
			contadorChars=0;
			printf("\n>%s",msj);
			readFromConsole(buffer,maxSize);

			for(int i=0;i<maxSize;i++)
			{
				if(buffer[i]!='\0')
				{
					if(isalpha(buffer[i])==0 && buffer[i]!=' ')
					{
						reintentos--;
						printf("\n\a[!]%s",eMsj);
						break;
					}
					else
					{
						if(isalpha(buffer[i])!=0&&buffer[i]!=' ')
						{
							contadorChars++;
						}
					}
				}
				else
				{
					if(contadorChars>=3)
					{
						strcpy(array,buffer);
						ret=0;
						reintentos=0;
						break;
					}
					else
					{
						printf("\n\a[!]Error: Se debe ingresar, por lo menos, mas de 3 caracteres!");
						reintentos--;
						break;
					}
				}
			}

		}
	}

	return ret;
}

//Funcion para obtener un string, permite espacios y puntuaciones (SP = space&point)
int val_getStrSP(char* array,char* msj,char* eMsj,int maxSize,int reintentos)
{
	int ret = -1;
	int contadorChars;
	char buffer[maxSize];

	if(array!=NULL && msj!=NULL && eMsj!=NULL && maxSize>0 && reintentos>0)
	{
		while(reintentos>0)
		{
			contadorChars=0;
			printf("\n>%s",msj);
			readFromConsole(buffer,maxSize);

			for(int i=0;i<maxSize;i++)
			{
				if(buffer[i]!='\0')
				{
					if(isalpha(buffer[i])==0 && buffer[i]!=' ' && buffer[i]!='.' && buffer[i]!=',')
					{
						reintentos--;
						printf("\n\a[!]%s",eMsj);
						break;
					}
					else
					{
						if(isalpha(buffer[i])!=0&&buffer[i]!=' '&&buffer[i]!='.' && buffer[i]!=',')
						{
							contadorChars++;
						}
					}
				}
				else
				{
					if(contadorChars>=3)
					{
						strcpy(array,buffer);
						ret=0;
						reintentos=0;
						break;
					}
					else
					{
						printf("\n\a[!]Error: Se debe ingresar, por lo menos, mas de 3 caracteres!");
						reintentos--;
						break;
					}
				}
			}

		}
	}

	return ret;
}

/*Funcion para obtener un eMail, la direccion debe tener un(1) arroba, mas de tres(3) caracteres,
 * y por lo menos dos(2) caracteres luego del ultimo punto.
 * Permite guion bajo(_),guion medio(-) y numeros(1-9)*/
int val_getEmail(char* array,char* msj,char* eMsj,int maxSize,int reintentos)
{
	int ret = -1;
	int contadorChars;
	int arrobas; //Variable contador de arrobas(@)
	int afterPoint; //Variable contador de caracteres luego de un punto(.)
	int point; //0=El caracter NO es un  punto(.) | 1=El caracter ES un punto(.)
	char buffer[maxSize];

	if(array!=NULL && msj!=NULL && eMsj!=NULL && maxSize>0 && reintentos>0)
	{
		while(reintentos>0)
		{
			contadorChars=0;
			arrobas=0;
			afterPoint=0;
			point=0;
			printf("\n>%s",msj);
			readFromConsole(buffer,maxSize);

			for(int i=0;i<maxSize;i++)
			{
				if(buffer[i]!='\0')
				{
					//Si el caracter NO es alfabetico, NO es numerico, y NO es alguna de las excepciones.
					if(isalpha(buffer[i])==0 && buffer[i]!='.' && buffer[i]!='-' && buffer[i]!='_' && buffer[i]!='@' && isdigit(buffer[i])==0)
					{
						reintentos--;
						printf("\n\a[!]%s",eMsj);
						break;
					}
					else
					{
						//Si el caracter es permitido, entonces si ES alfabetico o numerico se suma la variable cont. de chars.
						if(isalpha(buffer[i])!=0 || isdigit(buffer[i])!=0)
						{
							contadorChars++;
							if(point==1)
							{
								afterPoint++;
							}
						}

						if(buffer[i]=='@') //Contador de arrobas(@)
						{
							arrobas++;
						}

						if(buffer[i]=='.') //Detectar puntos.
						{
							if(point==1)
							{
								afterPoint=0;
							}else
							{
								point=1;
							}
						}

						if(buffer[i]==' ')//NO se permiten espacios.
						{
							reintentos--;
							printf("\n\a[!]%s",eMsj);
							break;
						}

					}
				}
				else
				{
					//Validacion de reglas.
					if(contadorChars>=3 && afterPoint>=2 && arrobas==1)
					{
						strcpy(array,buffer);
						ret=0;
						reintentos=0;
						break;
					}
					else
					{
						printf("\n\a[!]Error: \n[REGLAS]\n-La direccion debe tener, POR LO MENOS, TRES(3) CARACTERES."
								"\n-Debe haber SOLO UN(1) ARROBA(@)."
								"\n-Debe haber por lo menos DOS(2) CARACTERES DESPUES DEL PUNTO(.com,.ar,etc.)"
								"\n-Solo se permiten los siguientes caracteres especiales-> [-][_]"
								"\n-Se permiten numeros.");
						reintentos--;
						break;
					}
				}
			}

		}
	}

	return ret;
}

/*
 * Funcion para obtener un entero(INT).
 * NOTA: No admite numeros negativos,
 * por lo que el parametro "min" no puede ser menor que 0.
 */
int val_getint(int* resultado,char* msj,char* eMsj,int min,int max,int reintentos)
{
	int ret=-1;
	int size=64;
	int contador;
	char buffer[size];

	if(resultado!=NULL && msj!=NULL && eMsj!=NULL && min>=0 && reintentos>0)
	{
		while(reintentos>0)
		{
			contador=0;
			printf("\n>%s",msj);
			readFromConsole(buffer,size);
			for(int i=0;i<size;i++)
			{
				if(buffer[i]!='\0')
				{
					if(buffer[i]<'0'||buffer[i]>'9')
					{
						reintentos--;
						printf("\n\a[!]%s",eMsj);
						break;
					}
					else
					{
						contador++;
					}
				}
				else
				{
					if(contador>=1 && atoi(buffer)>=min && atoi(buffer)<=max)
					{
						*resultado = atoi(buffer);
						reintentos=0;
						ret = 0;
						break;
					}else{
						printf("\n\a[!]%s",eMsj);
						reintentos--;
						break;
					}
				}
			}
		}
	}
	return ret;
}

/*Funcion para obtener un flotante(FLOAT).
 * NOTA: No admite numeros negativos,
 * por lo que el parametro "min" no puede ser menor que 0.
*/
int val_getFloat(float* resultado,char* msj,char* eMsj,float min,float max,int reintentos)
{
	int ret=-1;
	int size=64;
	int contador;
	char buffer[size];

	if(resultado!=NULL && msj!=NULL && eMsj!=NULL && min>=0 && reintentos>0)
	{
		while(reintentos>0)
		{
			contador=0;
			printf("\n>%s",msj);
			readFromConsole(buffer,size);
			for(int i=0;i<size;i++)
			{
				if(buffer[i]!='\0')
				{
					if(buffer[i]<'0'||buffer[i]>'9')
					{
						if(buffer[i]!='.')
						{
							reintentos--;
							printf("\n\a[!]%s",eMsj);
							break;
						}
					}
					else
					{
						contador++;
					}
				}
				else
				{
					if(contador>=1 && atof(buffer)>=min && atof(buffer)<=max)
					{
						*resultado = atof(buffer);
						reintentos=0;
						ret = 0;
						break;
					}else{
						printf("\n\a[!]%s",eMsj);
						reintentos--;
						break;
					}
				}
			}
		}
	}
	return ret;
}

//Funcion que valida que una cadena sea alfanumerica(solo letras y numeros).
int val_isAlphaNumeric(char* str)
{
	int ret = -1;
	int size;

	if(str!= NULL)
	{
		size = strlen(str);
		for(int i=0;i<size;i++)
		{
			if(isalpha(str[i])!=0 || isdigit(str[i])!=0)
			{
				ret =1;
			}else{
				ret = 0;
				break;
			}
		}
	}
	return ret;
}

//Funcion que valida que todos los elementos de la cadena sean alfabeticos.
int val_isAllChar(char* str)
{
	int ret=1;
	int size;
	int contador=0;

	if(str!=NULL)
	{
		size=strlen(str);
		for(int i=0;i<size;i++)
		{
			if((*(str+i))!='\0')
			{
				if(isalpha(str[i])==0)
				{
					ret=0;
					break;
				}else{
					contador++;
				}
			}

		}

		if(contador==0)
		{
			ret=0;
		}

	}else{
		printf("\n\a[!]ERROR: Array NULL.\n");
		system("PAUSE");
	}

	return ret;
}

/*Funcion que valida que todos los elementos de la cadena sean alfabeticos o un espacio(S=space).
 * Suele usarse para verificar nombres(nombre apellido).
*/
int val_isAllCharS(char* str)
{
	int ret=1;
	int size;
	int contador=0;

	if(str!=NULL)
	{
		size=strlen(str);
		for(int i=0;i<size;i++)
		{
			if((*(str+i))!='\0')
			{
				if(isalpha(str[i])==0&&str[i]!=' ')
				{
					ret=0;
					break;
				}else{
					contador++;
				}
			}

		}

		if(contador==0)
		{
			ret=0;
		}

	}else{
		printf("\n\a[!]ERROR: Array NULL.\n");
		system("PAUSE");
	}

	return ret;
}

/* Funcion para pedir el ingreso de un numero de identificacion(sin guiones)DNI.
 * NOTAS:
 *	-Se trabaja con el tipo de dato LONG.
 *	-El minimo y el maximo de digitos PUEDEN SER IGUALES si se desea obligar al usuario a ingresar
 *	una cantidad de digitos exacta.
 *	-No se admiten guiones.
 */
int val_getDNI(long int* resultado,char* msj,char* eMsj,int minDigitos,int maxDigitos,int reintentos)
{
	int ret=-1;
	int size=64;
	int contador;
	char buffer[size];

	if(resultado!=NULL && msj!=NULL && eMsj!=NULL && reintentos>0)
	{
		while(reintentos>0)
		{
			contador=0;
			printf("\n>%s",msj);
			readFromConsole(buffer,size);
			for(int i=0;i<size;i++)
			{
				if(buffer[i]!='\0')
				{
					if(buffer[i]<'0'||buffer[i]>'9')
					{
						reintentos--;
						printf("\n\a[!]%s",eMsj);
						break;
					}
					else
					{
						contador++;
					}
				}
				else
				{
					if(contador>=1)
					{
						if(contador<minDigitos || contador>maxDigitos)
						{
							if(minDigitos!=maxDigitos)
							{
								printf("\n\a[!]ERROR: El DNI debe tener, minimo %d y maximo %d digitos.",minDigitos,maxDigitos);
							}else{
								printf("\n\a[!]ERROR: El DNI debe tener %d digitos, ni mas, ni menos.",minDigitos);
							}
							break;
						}else
						{
							*resultado = atol(buffer);
							reintentos=0;
							ret = 0;
							break;
						}
					}else{
						printf("\n\a[!]%s",eMsj);
						reintentos--;
						break;
					}
				}
			}
		}
	}
	return ret;
}
