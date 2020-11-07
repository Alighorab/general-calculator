#ifndef _POSTFIX_EVALUATOR_h
#define _POSTFIX_EVALUATOR_h
#include "infix_to_postfix.h"
#include "stack.h"

double EvaluatePostfixExpression(char *expression);

void PopOperand(double *operand, Stack_t *ps);
void PushResult(double result, Stack_t *ps);

double Calculator(double operand1, double operand2 , char operator);
double Add(double operand1, double operand2);
double Sub(double operand1, double operand2);
double Mul(double operand1, double operand2);
double Div(double operand1, double operand2);
double Pow(double base, double exponent);
double Round(double var);

int ToInteger(char ch);
char* reverseString(char* str);
void Swap(char *e1, char *e2);

#endif