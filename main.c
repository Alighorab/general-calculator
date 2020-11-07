#include <stdio.h>
#include <string.h>
#include <limits.h>
#include "infix_to_postfix.h"
#include "postfix_evaluator.h"


int main()
{
	char expression[50] = "", postfix[100] = "";
	double result = 0.0;
	
	printf("*****  This is a calculator program.                  *****\n");
	printf("*****  Enter the calculation consecutively.           *****\n");
	printf("***** (subtraction symbol is \"_\", i.e, underscore).   *****\n");
	printf("***** (negative sign is the symbol \"-\", i.e, hyphen). *****\n\n");
	
	while(1) {
		printf("Enter expression (enter to quit): ");
		gets(expression);
		
		if(!strcmp(expression, ""))
			break;
			
		if( !ConvertToPostfix(expression, postfix) ) {
			printf("Wrong expression!\n");
			continue;
		}
	
		if( (result = EvaluatePostfixExpression(postfix)) != LONG_MAX )
			printf("= %.2lf\n", result);
		else 
			printf("Wrong expression!\n");
		
	}
	return 0;
}



