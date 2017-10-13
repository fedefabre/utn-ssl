/*
Universidad Tecnológica Nacional
Facultad Regional Buenos Aires

2017

Trabajo Práctico N.º 3

Grupo 09

Integrantes

Apellido y Nombre	Legajo

Barreto Cristian	1223707
Bascietto Francisco	1291488
Fabre Federico		1571254
Ramirez Orrego Nicolás	1479143
*/

char *token_names[] = {"FDT", "Programa", "Variables", "Definir", "Codigo", "Leer", "Escribir", "Fin","IDENTIFICADOR", "CONSTANTE", "OPERADOR", "PUNTUACION", "ASIGNACION", "ERRORCA", "ERRORCO", "ERRORIN"};

int main() {
	enum token t;
	while ((t = yylex()) != FDT){
		if ((token_names[t]=="IDENTIFICADOR")||(token_names[t]=="CONSTANTE")){
		    printf("Token: %s\t\tLexema: %s\n", token_names[t], yytext);
		}
    else if (token_names[t]=="ASIGNACION"){
        printf("Token: %s\n", token_names[t]);
    }
    else if (token_names[t]=="ERRORCA"){
        printf("Error léxico: cadena desconocida: %s\n", yytext);
    }
    else if (token_names[t]=="ERRORCO"){
        printf("Error léxico: constante con sufijo inválido: %s\n", yytext);
    }
    else if (token_names[t]=="ERRORIN"){
        printf("Error léxico: identificador inválido: %s\n", yytext);
    }
		else printf("Token: %s\n", yytext);
  }
	return 0;
}
