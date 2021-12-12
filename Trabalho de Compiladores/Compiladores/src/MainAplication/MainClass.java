package MainAplication;


import Exceptions.LexicalException;
import Exceptions.SyntaxException;
import Lexico.ScannerFile;
import Lexico.Token;

public class MainClass {

	public static void main(String[] args) {
		try {
			ScannerFile sc = new ScannerFile("input.txt");
			Token t = null;
			
			do {
			    t = sc.nextToken();
				if(t != null) {
					System.out.println(t);
				}
			}while(t != null);
			
		
		} catch (LexicalException ex) {
			System.out.println("Lexical Error : " + ex.getMessage());
		}
		
		 catch (SyntaxException ex) {
			 System.out.println("Syntax Error : " + ex.getMessage());
		}
		
		catch(Exception ex) {
			System.out.println("Generic Error");
		}
	}

}
