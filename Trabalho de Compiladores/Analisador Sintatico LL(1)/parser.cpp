#include<iostream>
#include<queue>

#include "transitionTable.cpp"

int main() {

	transitionTable TT;
	std::queue<std::string> q;
	std::string str;

	while(std::cin>>str) {
		q.push(str);
		if(str == "ID" || str == "NUM")
			std::cin>>str;
	}
	q.push("$");

	while (!q.empty()) {
		switch (TT.getNextInst(q.front())) {
		case 0:
			break;
		case 1:
			q.pop();
			break;
		default:
			throw std::invalid_argument( "Falha na sintaxe." );
			return 1;
		}	
	}
		
	if(!TT.stkCheck())
		throw std::invalid_argument( "Falha na sintaxe." );

	std::cout<<"Compilação bem sucedida."<<std::endl;
	return 0;
}
