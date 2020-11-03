#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include <limits.h>
#include "postfix_evaluator.h"


long EvaluatePostfixExpression(char *expression) {
	Stack_t stack;
	StackInit(&stack);
	
	long operand1 = 0, operand2 = 0;
	long result = 0;
	
	int expLength = strlen(expression);
	for(int i = 0; i < expLength; i++) {
		/*
		 * you have four probabilities:
			1- digit: push it.
			2- negative sign: push it if there is a space in top.
			3- operator: pop two elements from stack and do operation on them, then push the result.
			4- token identifier: push it.
			5- dot.. soon..
		*/
		if(IsDigit(expression[i])) { 
			StackPush(expression[i], &stack);
		}
		else if(IsNewToken(expression[i])) {
			StackPush(expression[i], &stack);
		}
		else if(IsSign(expression[i])) {
			if( StackEmpty(&stack) || (StackTop(&stack) == ' ') ) {
				StackPush(expression[i], &stack);
			}
			else{
				/* invalid expression, quit with LONG_MAX. */
				ClearStack(&stack);
				return LONG_MAX;
			}
		}
		else if(IsOperator(expression[i])) {
			if( !IsDigit( StackTop(&stack) ) ) {
				RemoveTop(&stack);
			}
			PopOperand(&operand2, &stack);
			PopOperand(&operand1, &stack);
			result = Calculator(operand1, operand2, expression[i]);
			PushResult(result, &stack);
		}
		
	}
	ClearStack(&stack);
	
	return result;
}

void PopOperand(long *operand, Stack_t *ps) {
	int weight = 1;
	char top = 0;
	
	*operand = 0;
	do {
			StackPop(&top, ps);
			if(IsDigit(top)) {
				top = ToInteger(top);
				*operand += (long) top * weight;
				weight *= 10;
			}
			else if(IsSign(top)) {
				*operand *= (-1);
			}
	}
	while( (!IsNewToken(top)) && (!StackEmpty(ps)) );
	
}

void PushResult(long result, Stack_t *ps) {
	#define MAX_NUM 20
	char str[MAX_NUM] = "";
	
	// convert result from int to string.
	sprintf(str, "%ld", result); 
	
	// if there is elements, seperate the result from them.
	if(!StackEmpty(ps)) {
		StackPush(' ', ps);
	}
	
	int i = 0, length = strlen(str);
	while(length-- > 0) {
		if(IsDigit(str[i])) {
			StackPush(str[i++], ps);
		}
		else if(IsSign(str[i])) {
			StackPush(str[i++], ps);
		}
	}
}


long Calculator(long operand1, long operand2, char operator) {
	switch(operator) {
		case '+':
			return Add(operand1, operand2);
		case '_':
			return Sub(operand1, operand2);
		case '*':
			return Mul(operand1, operand2);
		case '/':
			return Div(operand1, operand2);
		case '^':
			return Pow(operand1, operand2);
	}
	return -1;
}

long Add(long operand1, long operand2) {
	return (operand1 + operand2);
}

long Sub(long operand1, long operand2) {
	return (operand1 - operand2);
}

long Mul(long operand1, long operand2) {
	return (operand1 * operand2);
}

long Div(long operand1, long operand2) {
	return (operand1 / operand2);
}

long Pow(long base, long exponent) {
	long result = 1;
	while (exponent != 0) {
        result *= base;
        --exponent;
    }
	return result;
}

int ToInteger(char ch) {
	return ch - '0';
}








