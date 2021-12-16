#include<utility>
#include<string>
#include<vector>
#include<stack>
#include<map>

/* Tokens 
	//Especiais
	$,

	//Não Terminais
	E, EL, T, OP,	
	
	//Terminais
	ID, NUM, PLUS, MINUS, ASTERISK, SLASH
*/

class transitionTable {
	private:
		std::stack<std::string> stk;
		std::map< std::pair<std::string, std::string>, std::vector<std::string> > mp;
	public:
		transitionTable() {
			mp[{"S","ID"}] =			{"$", "E"};
			mp[{"S","NUM"}] =			{"$", "E"};
			mp[{"E","ID"}] =			{"EL", "T"};
			mp[{"E","NUM"}] =			{"EL", "T"};
			mp[{"EL","$"}] =			{};
			mp[{"EL","PLUS"}] =			{"EL", "T", "OP"};
			mp[{"EL","MINUS"}] =		{"EL", "T", "OP"};
			mp[{"EL","ASTERISK"}] =		{"EL", "T", "OP"};
			mp[{"EL","SLASH"}] =		{"EL", "T", "OP"};
			mp[{"T","ID"}] =			{"ID"};
			mp[{"T","NUM"}] =			{"NUM"};
			mp[{"OP","PLUS"}] =			{"PLUS"};
			mp[{"OP","MINUS"}] =		{"MINUS"};
			mp[{"OP","ASTERISK"}] =		{"ASTERISK"};
			mp[{"OP","SLASH"}] =		{"SLASH"};
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
