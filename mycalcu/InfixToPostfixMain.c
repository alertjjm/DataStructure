#include<stdio.h>
#include"InfixToPostfix.h"
int main(void) {
	char exp1[] = "1+2*3";
	char exp2[] = "(1+2)*3";
	char exp3[] = "((1-2)+3)*(5-2)";
	ConvToRPNExp(exp1);
	ConvToRPNExp(exp2);
	ConvToRPNExp(exp3);
	printf("%s=\n", exp1);
	//printf("%s=%d \n", exp2, EvalInfixExp(exp2));
	//printf("%s=%d\n", exp3, EvalInfixExp(exp3));
	return 0;
}