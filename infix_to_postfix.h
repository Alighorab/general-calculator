#ifndef _INFIX_TO_POSTFIX_h
#define _INFIX_TO_POSTFIX_h

#define RIGHT_PARANTHESE '('
#define LEFT_PARANTHESE  ')'
#define NEW_TOKEN_ID ' '

char* ConvertToPostfix(char infix[], char postfix[]);
int IsSign(char c);
char FlippedSign(char sign);
int IsOperator(char c);
int IsDigit(char c);
int IsNewToken(char c);
int IsRightParanthese(char c);
int IsLeftParanthese(char c);
	
int Precedence(char operator1, char operator2);


#endif