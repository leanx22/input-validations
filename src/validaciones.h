
/// @brief Funcion para obtener un string puro, de un minimo de tres caracteres y un maximo especificado.
///
/// @param array Puntero a cadena donde se guardara el resultado de la lectura.
/// El array esta "seguro" hasta que se valide el ingreso del usuario.
/// @param msj Mensaje que se le mostrara al usuario.
/// @param eMsj Mensaje para el usuario en caso de error.
/// @param maxSize Maximo de caracteres que se leeran desde la entrada del usuario.
/// @param reintentos Numero de intentos.
/// @return Retorna 0(CORRECTO) o -1(ERROR).
int val_getStr(char* array,char* msj,char* eMsj,int maxSize,int reintentos);

/// @brief Funcion parecida a getStr a diferencia de que esta PERMITE ESPACIOS en el ingreso.
///	S(Space)
/// @param array Puntero a cadena donde se guardara el resultado de la lectura.
/// El array esta "seguro" hasta que se valide el ingreso del usuario.
/// @param msj Mensaje que se le mostrara al usuario.
/// @param eMsj Mensaje para el usuario en caso de error.
/// @param maxSize Maximo de caracteres que se leeran desde la entrada del usuario.
/// @param reintentos Numero de intentos.
/// @return Retorna 0(CORRECTO) o -1(ERROR).
int val_getStrS(char* array,char* msj,char* eMsj,int maxSize,int reintentos);

/// @brief Funcion parecida a getStr a diferencia de que esta PERMITE ESPACIOS Y PUNTUACIONES en el ingreso.
///	SP(Space&Points)
/// @param array Puntero a cadena donde se guardara el resultado de la lectura.
/// El array esta "seguro" hasta que se valide el ingreso del usuario.
/// @param msj Mensaje que se le mostrara al usuario.
/// @param eMsj Mensaje para el usuario en caso de error.
/// @param maxSize Maximo de caracteres que se leeran desde la entrada del usuario.
/// @param reintentos Numero de intentos.
/// @return Retorna 0(CORRECTO) o -1(ERROR).
int val_getStrSP(char* array,char* msj,char* eMsj,int maxSize,int reintentos);

/// @brief Funcion para obtener un email, permitiendo numeros,"-" y "_".
///  La direccion debe contener solo un arroba(@),mas de tres(3) caracteres,
/// un punto(.) y por lo menostres(2) caracteres luego de este para ser validada.
///
/// @param array Puntero a cadena donde se guardara el resultado de la lectura.
/// El array esta "seguro" hasta que se valide el ingreso del usuario.
/// @param msj Mensaje que se le mostrara al usuario.
/// @param eMsj Mensaje para el usuario en caso de error.
/// @param maxSize Maximo de caracteres que se leeran desde la entrada del usuario.
/// @param reintentos Numero de intentos.
/// @return Retorna 0(CORRECTO) o -1(ERROR).
int val_getEmail(char* array,char* msj,char* eMsj,int maxSize,int reintentos);

/// @brief Funcion para obtener un entero.
/// NOTA: La funcion NO ADMITE NUMEROS NEGATIVOS, por ende el minimo numero obtenible es 0.
/// @param resultado Puntero a variable entera donde se guardara la lectura UNA VEZ VALIDADA.
/// @param msj Mensaje que se le mostrara al usuario.
/// @param eMsj Mensaje que se mostrara en caso de error en la validacion.
/// @param min Numero minimo que se puede ingresar. (NO PUEDE SER MENOR A 0).
/// @param max Numero maximo que se puede ingresar.
/// @param reintentos Cantidad de reintentos.
/// @return La funcion retorna: -1 Error o no hay mas reintentos. | 0 Operacion concretada sin errores.
int val_getint(int* resultado,char* msj,char* eMsj,int min,int max,int reintentos);

/// @brief
///
/// @param resultado
/// @param msj
/// @param eMsj
/// @param min
/// @param max
/// @param reintentos
/// @return
int val_getFloat(float* resultado,char* msj,char* eMsj,float min,float max,int reintentos);

/// @brief Funcion que valida que un array sea alfanumerica. (Solo numeros y letras)
///
/// @param str Cadena a validar.
/// @return Retorna true(1) si la cadena es alfanumerica, o false(0) si no lo es.
int val_isAlphaNumeric(char* str);

/// @brief Esta funcion valida que todos los caracteres de la cadena indicada sean ALFABETICOS SOLAMENTE.
///
/// @param str Cadena a verificar.
/// @return Retorna true(1) si la validacion es positiva,
/// o false(0) en caso de encontrar un caracter no alfabetico.
int val_isAllChar(char* str);







