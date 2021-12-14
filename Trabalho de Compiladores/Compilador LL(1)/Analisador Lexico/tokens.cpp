#include<string>

enum TokenTypes {
	PONTUACAO = 0,
	IDENTIFICADOR = 1,
	NUMERO = 2,
	
	//Palavras Chave
	VAR = 3, 
	IF = 4,
	THEN = 5,
	ENDIF = 6,
	WHILE = 7,
	REPEAT = 8,
	ENDWHILE = 9,

	//Operador de Atribuicao
	EQ = 10,	// Igual

	//Operadores Relacionais
	EQEQ = 11,	// Igualdade
	NOTEQ = 12,	// Diferente
	GT = 13, 	// Maior
	GTEQ = 14,	// Maior Igual
	LT = 15,	// Menor
	LTEQ = 16,	// Menor Igual

	//Operadores Aritmeticos
	PLUS = 17,
	MINUS = 18,
	ASTERISK = 19,
	SLASH = 20,
};

struct Token {
    TokenTypes tokenID;
	std::string tokenText;	
    int linha, coluna;	
};