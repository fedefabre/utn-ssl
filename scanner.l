%{
#include <stdio.h>
#include "tokens.h"
#include "main.c"
%}
%option noinput
%option nounput
%option header-file="scanner.h"
%option outfile="scanner.c"
letra [a-zA-Z]
digito [0-9]
letra_digito {letra}|{digito}
identificador {letra}{letra_digito}*
desconocido [^-+*/(),; \t\n\r0-9a-zA-Z]
%%
"programa"									return Programa;
"variables"									return Variables;
"definir"										return Definir;
"codigo"										return Codigo;
"leer"											return Leer;
"escribir"									return Escribir;
"fin"												return Fin;
[-+*/]											return OPERADOR;
:=													return ASIGNACION;
{identificador}							return IDENTIFICADOR;
{digito}+										return CONSTANTE;
[,;()]											return PUNTUACION;
"//".*											;
[[:space:]]									;
{digito}{letra_digito}+		  return ERRORCO;
{identificador}{desconocido}({letra_digito}|{desconocido})*	return ERRORIN;
{desconocido}*								return ERRORCA;
%%
