#include <stdio.h>
#include <string.h>
#include <limits.h>
#include "infix_to_postfix.h"
#include "postfix_evaluator.h"

int main()
{
	char expression[100] = "", postfix[100] = "";
	long result = 0;
	
	printf("*****  This is a calculator program.                  *****\n");
	printf("*****  Enter the calculation consecutively.           *****\n");
	printf("***** (subtraction symbol is \"_\", i.e, underscore).   *****\n");
	printf("***** (negative sign is the symbol \"-\", i.e, hyohen). *****\n\n");
	
	while(1) {
		printf("Enter expression (enter to quit): ");
		gets(expression);
		
		if(!strcmp(expression, ""))
			break;
			
		ConvertToPostfix(expression, postfix);
		result = EvaluatePostfixExpression(postfix);
		
		if(result != LONG_MAX) {
			printf("= %ld\n", result);
		}
		
	}
	
	return 0;
}



