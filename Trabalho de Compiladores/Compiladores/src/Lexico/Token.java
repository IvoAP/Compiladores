package Lexico;

public class Token {
	
	private int type;
	private String text;
	
	public static final int TK_IDENTIFIER = 0;
	public static final int TK_NUMBER = 1;
	public static final int TK_OPERATOR = 2;
	public static final int TK_PONCTUATION = 3;
	public static final int TK_ASSIGN = 4;
	
	public Token() {
		super();
	}

	public Token(int type, String text) {
		super();
		this.type = type;
		this.text = text;
	}

	public int getType() {
		return type;
	}

	public void setType(int type) {
		this.type = type;
	}

	public String getText() {
		return text;
	}

	public void setText(String text) {
		this.text = text;
	}
	
	public String toString() {
		return "Token [type =  " + this.type + " text = " + this.text + " ]";
		
	}
}
