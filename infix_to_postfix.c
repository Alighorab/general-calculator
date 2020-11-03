#include <stdlib.h>
#include <string.h>
#include "infix_to_postfix.h"
#include "stack.h"

char* ConvertToPostfix(char infix[], char postfix[]) {
	Stack_t s;
	StackInit(&s);
	char ch = 0, op = 0;
	int j = 0;
	for(int i = 0; (ch = infix[i]) != '\0'; i++) {
		/*
		 * you have four probabilities:
			1- digit: push it.
			2- negative sign: push it if there is a space in top.
			3- operator: pop two elements from stack and do operation on them, then push the result.
			4- right paranthese: wait untile finding the left.
			5- left paranthese: pop all operators and push it into postfix array.
			6- dot.. soon..
		*/
		if(IsSign(ch)) {
			postfix[j++] = ch;
		}
		else if(IsDigit(ch)) {
			postfix[j++] = ch;
		}
		else if(IsOperator(ch)) {
			if(!StackEmpty(&s)) {
				/*
					* i.e, there is operators, so, you need to check precedence
				*/
				op = StackTop(&s);
				while(!StackEmpty(&s) && Precedence(op, ch)) {
					op = StackTop(&s);
					StackPop(&op, &s);
					postfix[j++] = NEW_TOKEN_ID;
					postfix[j++] = op;
				}
			}
			
			postfix[j++] = NEW_TOKEN_ID;
			StackPush(ch, &s);
		}
		else {
			/* wrong operator */
			ClearStack(&s);
			return NULL;
		}
	}
	
	while(!StackEmpty(&s)) {
		StackPop(&op, &s);
		postfix[j++] = NEW_TOKEN_ID;
		postfix[j++] = op;
	}
	
	return postfix;
}

int IsSign(char c) {
	return (c == '-');
}

int IsOperator(char c) {
	return ( (c == '+') || (c == '_') || (c == '*') || (c == '/') || (c == '^') );
}

int IsDigit(char c) {
	return ( (c >= '0') && (c <= '9') );
}

int IsNewToken(char c){
	return (c == NEW_TOKEN_ID);
}

int Precedence(char operator1, char operator2) {
	if(operator1 == '^')
		return 1;
		
	if(operator1 == '*' || operator1 == '/')
		return (operator2 != '^');
		
	if(operator1 == '+' || operator1 == '_')
		return ((operator2 != '^') && (operator2 != '*') && (operator2 != '/'));
		
	return -1;
}