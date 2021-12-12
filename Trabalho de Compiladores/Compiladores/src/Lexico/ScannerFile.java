package Lexico;


import java.nio.charset.StandardCharsets;
import java.nio.file.Files;
import java.nio.file.Paths;

import Exceptions.LexicalException;



public class ScannerFile {
	private char[] content;
	private int state;
	private int index; 
	
	public ScannerFile(String filename) {
		try {
			String txtcontent;
			txtcontent = new String(Files.readAllBytes(Paths.get(filename)), StandardCharsets.UTF_8);
			System.out.println("DEBUG  ----------------");
			System.out.println(txtcontent);
			System.out.println("------------------------");
			this.content = txtcontent.toCharArray();
			index = 0;
		}catch(Exception ex) {
			ex.printStackTrace();
		}
	}
	
	public Token nextToken() {
		char currentChar;
		String term = "";
		Token token;
		
		if(isEOF()) {
			System.out.println("Passei aqui");
			return null;
		}
		
		int estado = 0;
		while(true) {
			currentChar = nextChar();
			
			switch(estado) {
			case 0 :
				if(isChar(currentChar)) {
					term+= currentChar;
					estado = 1;
				}
				else if(isDigit(currentChar)) {
					estado = 3;
					term+= currentChar;
				}
				else if(isSpace(currentChar)) {
					estado = 0;
				}
				else if(isOperator(currentChar)) {
					estado = 5;
					term+=currentChar;
				}
				else {
					throw new LexicalException("Unrecognized Symbol");
				}
				break;
			case 1:
				if(isChar(currentChar) || isDigit(currentChar)) {
					estado = 1;
					term+= currentChar;
				}
				else if(isSpace(currentChar) || isOperator(currentChar)) {
					estado = 2;
				}
				else {
					throw new LexicalException("Malformed Identifier");
				}
				break;
			case 2:
				back();
				token = new Token();
				token.setType(token.TK_IDENTIFIER);
				token.setText(term);
				return token;
			case 3:
				if(isDigit(currentChar)) {
					estado = 3;
					term+= currentChar;
				}
				else if(!isChar(currentChar)) {
					estado = 4;
				}else {
					throw new LexicalException("Unrecognized Number");
				}
				break;
			case 4:
				token = new Token();
				token.setType(Token.TK_NUMBER);
				token.setText(term);
				back();
				return token;
			case 5:
				term += currentChar;
				token = new Token();
				token.setType(Token.TK_OPERATOR);
				token.setText(term);
				return token;
			}
		}
	}
	
	public Boolean isDigit(char c) {
		return (c >= '0' && c<= '9');
	}
	
	public Boolean isChar(char c) {
		return (c >= 'A' && c<= 'Z') || (c>= 'a' && c <= 'z');
	}
	
	public Boolean isOperator(char c) {
		return c == '>' || c == '<' || c == '=' || c == '!';
	}
	
	public Boolean isSpace(char c) {
		return c == ' ' || c == '\n' || c == '\t' || c == '\r';
	}
	
	public char nextChar() {
		return this.content[index++];
	}
	
	public boolean isEOF() {
		return index == content.length;
	}
	
	public void back() {
		
	}
}
