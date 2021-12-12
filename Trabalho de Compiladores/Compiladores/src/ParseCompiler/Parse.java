package ParseCompiler;

import Exceptions.SyntaxException;
import Lexico.ScannerFile;
import Lexico.Token;

public class Parse {
	
	private ScannerFile scanner;
	private Token token;
	
	public Parse (ScannerFile scanner) {
		this.scanner = scanner;
	}
	
	public void E() {
		T();
		El();
	}
	
	public void El() {
		token = scanner.nextToken();
		if(token != null) {
			T();
			El();
		}
	}
	
	public void T() {
		token = scanner.nextToken();
		if(token.getType() != Token.TK_IDENTIFIER && token.getType() != Token.TK_NUMBER) {
			throw new SyntaxException("Expect ID or number");
		}
	}

}
