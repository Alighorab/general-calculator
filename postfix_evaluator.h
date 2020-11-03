#ifndef _POSTFIX_EVALUATOR_h
#define _POSTFIX_EVALUATOR_h
#include "infix_to_postfix.h"
#include "stack.h"

long EvaluatePostfixExpression(char *expression);

void PopOperand(long *operand, Stack_t *ps);
void PushResult(long result, Stack_t *ps);

long Calculator(long operand1, long operand2 , char operator);
long Add(long operand1, long operand2);
long Sub(long operand1, long operand2);
long Mul(long operand1, long operand2);
long Div(long operand1, long operand2);
long Pow(long base, long exponent);

int ToInteger(char ch);


#endif