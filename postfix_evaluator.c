#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include <limits.h>
#include "postfix_evaluator.h"

#define ERROR -999999999999

double EvaluatePostfixExpression(char *expression) {
	Stack_t stack;
	StackInit(&stack);
	
	double operand1 = 0, operand2 = 0;
	double result = 0;
	
	char ch = 0;
	for(int i = 0; (ch = expression[i]) != '\0'; i++) {
		/*
		 * you have four probabilities:
			1- digit: push it.
			2- negative sign: push it if there is a space in top.
			3- operator: pop two elements from stack and do operation on them, then push the result.
			4- token identifier: push it.
			5- dot.. soon..
		*/
		if(IsDigit(ch))
			StackPush(ch, &stack);
		
		else if(IsFloatingPoint(ch))
			StackPush(ch, &stack);
			
		else if(IsNewToken(ch))
			StackPush(ch, &stack);
			
		else if(IsSign(ch)) {
			// Don't push two signs on each others
			if( StackEmpty(&stack) || (StackTop(&stack) == ' ') )
				StackPush(ch, &stack);
			else {
				/* invalid expression, quit with -999999999999. */
				ClearStack(&stack);
				return ERROR;
			}
		}
		
		else if(IsOperator(ch)) {
			if( !IsDigit( StackTop(&stack) ) ) {
				RemoveTop(&stack);
			}
			PopOperand(&operand2, &stack);
			RemoveTop(&stack);
			PopOperand(&operand1, &stack);
			result = Calculator(operand1, operand2, ch);
			PushResult(result, &stack);
		}
		
	}
	if(!StackEmpty(&stack)) {
		PopOperand(&result, &stack);
	}
	ClearStack(&stack);
	result = Round(result);
	
	return result;
}

void PopOperand(double *operand, Stack_t *ps) {
#define MAX_SIZE 10
	char *op = (char*) malloc(MAX_SIZE), *temp = NULL;
	memset(op, '\0', MAX_SIZE);
	int i = 0;
	while( (!StackEmpty(ps)) && (!IsNewToken(StackTop(ps))) ) {
		StackPop(&op[i++], ps);
	}
	
	temp = op;
	op = reverseString(op);
	SafeFree(temp);
	
	sscanf(op, "%lf", operand);
}

void PushResult(double result, Stack_t *ps) {
	#define MAX_NUM 20
	char str[MAX_NUM] = "";
	
	// convert result from int to string.
	sprintf(str, "%.2lf", result);
	
	// if there is elements, seperate the result from them.
	if((!StackEmpty(ps)) && (!IsNewToken(StackTop(ps))) ) {
		StackPush(' ', ps);
	}
	
	int i = 0, length = strlen(str);
	while(length-- > 0) {
		StackPush(str[i++], ps);
	}
}


double Calculator(double operand1, double operand2, char operator) {
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

double Add(double operand1, double operand2) {
	return (operand1 + operand2);
}

double Sub(double operand1, double operand2) {
	return (operand1 - operand2);
}

double Mul(double operand1, double operand2) {
	return (operand1 * operand2);
}

double Div(double operand1, double operand2) {
	return (operand1 / operand2);
}

double Pow(double base, double exponent) {
	double result = 1;
	while (exponent != 0) {
        result *= base;
        --exponent;
    }
	return result;
}

double Round(double var) 
{ 
    // 37.66666 * 100 =3766.66 
    // 3766.66 + .5 =3767.16    for rounding off value 
    // then type cast to int so value is 3767 
    // then divided by 100 so the value converted into 37.67 
    float value = (int)(var * 100 + .5); 
    return (float)value / 100; 
} 

int ToInteger(char ch) {
	return ch - '0';
}

void Swap(char *e1, char *e2) {
	char temp = *e1;
	*e1 = *e2;
	*e2 = temp;
}

char* reverseString(char* str) 
{ 
    // find length of string 
    int len = strlen(str); 
  
    // create a dynamic pointer char array 
    char *rev = (char*) malloc(len + 1); 
  
    // copy of string to ptr array 
    strcpy(rev, str); 
  
    // Swap character starting from two corners 
    for (int i = 0, j = len - 1; i < j; i++, j--)
        Swap(&rev[i], &rev[j]);        
      
    // return pointer of the reversed string 
    return rev; 
}








