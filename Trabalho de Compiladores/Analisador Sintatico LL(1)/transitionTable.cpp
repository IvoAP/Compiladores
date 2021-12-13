#include<utility>
#include<string>
#include<vector>
#include<stack>
#include<map>

/* Tokens 
	//Especiais
	$,

	//Não Terminais
	COMANDO, CHAVE, ATRIB, DECL, COMP, REL, EX, EXL, TIPO, OP,	
	
	//Terminais
	PONTO, VAR, ID, NUM,
	IF, THEN, ENDIF, WHILE, REPEAT, ENDWHILE,
	EQ, EQEQ, NOTEQ, GT, GTEQ, LT, LTEQ,
	PLUS, MINUS, ASTERISK, SLASH
*/

class transitionTable {
	private:
		std::stack<std::string> stk;
		std::map< std::pair<std::string, std::string>, std::vector<std::string> > mp;
	public:
		transitionTable() {
			stk.push("$");
			stk.push("COMANDO");

			mp[{"COMANDO","$"}] = {};
			mp[{"COMANDO","IF"}] = {"COMANDO", "PONTO", "CHAVE"};
			mp[{"COMANDO","ENDIF"}] = {};
			mp[{"COMANDO","WHILE"}] = {"COMANDO", "PONTO", "CHAVE"};
			mp[{"COMANDO","ENDWHILE"}] = {};
			mp[{"COMANDO","VAR"}] = {"COMANDO", "PONTO", "CHAVE"};
			mp[{"COMANDO","ID"}] = {"COMANDO", "PONTO", "ATRIB", "TIPO"};
			mp[{"COMANDO","NUM"}] = {"COMANDO", "PONTO", "ATRIB", "TIPO"};
			mp[{"CHAVE","IF"}] = {"ENDIF", "COMANDO", "THEN", "COMP", "IF"};
			mp[{"CHAVE","WHILE"}] = {"ENDWHILE", "COMANDO", "REPEAT", "COMP", "WHILE"};
			mp[{"CHAVE","VAR"}] = {"DECL"};
			mp[{"DECL","VAR"}] = {"ATRIB", "ID", "VAR"};
			mp[{"ATRIB","PONTO"}] = {};
			mp[{"ATRIB","EQ"}] = {"EX", "EQ"};
			mp[{"COMP","ID"}] = {"TIPO", "REL", "TIPO"};
			mp[{"COMP","NUM"}] = {"TIPO", "REL", "TIPO"};
			mp[{"EX","ID"}] = {"EXL", "TIPO"};
			mp[{"EX","NUM"}] = {"EXL", "TIPO"};
			mp[{"EXL","PONTO"}] = {};
			mp[{"EXL","PLUS"}] = {"EXL", "TIPO", "OP"};
			mp[{"EXL","MINUS"}] = {"EXL", "TIPO", "OP"};
			mp[{"EXL","ASTERISK"}] = {"EXL", "TIPO", "OP"};
			mp[{"EXL","SLASH"}] = {"EXL", "TIPO", "OP"};
			mp[{"TIPO","ID"}] = {"ID"};
			mp[{"TIPO","NUM"}] = {"NUM"};
			mp[{"OP","PLUS"}] = {"PLUS"};
			mp[{"OP","MINUS"}] = {"MINUS"};
			mp[{"OP","ASTERISK"}] = {"ASTERISK"};
			mp[{"OP","SLASH"}] = {"SLASH"};
			mp[{"REL","EQEQ"}] = {"EQEQ"};
			mp[{"REL","NOTEQ"}] = {"NOTEQ"};
			mp[{"REL","GT"}] = {"GT"};
			mp[{"REL","GTEQ"}] = {"GTEQ"};
			mp[{"REL","LT"}] = {"LT"};
			mp[{"REL","LTEQ"}] = {"LTEQ"};
		}

		bool stkCheck() {
			return stk.empty();
		}

		int getNextInst(std::string &str) {
			if(stk.empty()) return -1;
			if(stk.top() == str) {
				stk.pop();
				return 1;
			}
			
			if( !mp.count( std::make_pair(stk.top(), str) ) )  return -1;
			std::vector<std::string> &aux = mp[{stk.top(), str}];

			stk.pop();
			for(auto &i : aux) 
				stk.push(i);
			return 0;
		}

};
