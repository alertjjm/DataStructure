#include<string.h>
#include<ctype.h>
#include"ListBaseStack_my.h"
int opchartoint(char op) {
	switch (op) {
	case '*':
	case '/':
		return 5;
	case '+':
	case '-':
		return 3;
	case '(':
		return 1;
	}
	return -1;
}
int whoisprecede(char op1, char op2) {
	int opnum1 = opchartoint(op1);
	int opnum2 = opchartoint(op2);
	if (opnum1 <= opnum2)
		return 1;
	else
		return -1;
}
int isdigit(char a) {
	if (a >= '0'&&a <= '9')
		return TRUE;
	else
		return FALSE;
}
void ConvToRPNExp(char exp[]) {
	int len = strlen(exp);
	int i;
	int idx = 0;
	char token;
	char* convExp = (char*)malloc(sizeof(len + 1));
	memset(convExp, 0, sizeof(char)*len + 1);
	Stack stack;
	StackInit(&stack);
	for (i = 0; i < len; i++) {
		token = exp[i];
		if (isdigit(token))
			convExp[idx++] = token;
		else {
			switch (token)
			{
			case '(':
				SPush(&stack, token);
				break;
			case ')':
				while (!SIsEmpty(&stack)) {
					char t = SPop(&stack);
					if (t == '(');
					else
						convExp[idx++] = t;
				}
				break;
			case '+':
			case '-':
			case '*':
			case '/':
				if (SIsEmpty(&stack))
					SPush(&stack, token);
				else {
					if (whoisprecede(SPeek(&stack), token) >= 0) {
						SPush(&stack, token);
					}	
					else {
						while (!SIsEmpty(&stack)) {
							convExp[idx++] = SPop(&stack);
						}
						SPush(&stack, token);
					}
				}
				break;
			}
		}
	}
	while (!SIsEmpty(&stack)) {
		convExp[idx++] = SPop(&stack);
	}
	convExp[idx] = '\0';
	strcpy(exp, convExp);
}
int EvalInfixExp(char exp[]) {
	Stack stack;
	StackInit(&stack);

	int len = strlen(exp);
	int result;
	int op1, op2;
	for (int i = 0; i < len; i++) {
		char t = exp[i];
		if (isdigit(t)) {
			SPush(&stack, t);
		}
		else {
			op1 = SPop(&stack)-'0';
			op2 = SPop(&stack)-'0';
			switch (t){
			case '*':
				result = op1*op2;
				SPush(&stack, result+'0');
				break;
			case '/':
				result = op2 / op1;
				SPush(&stack, result + '0');
				break;
			case '+':
				result = op1 + op2;
				SPush(&stack, result + '0');
				break;
			case '-':
				result = op2 - op1;
				SPush(&stack, result + '0');
				break;
			}
		}
	}
	while(!SIsEmpty(&stack))
	{
		Data d = SPop(&stack);
	}

	return result;
}
