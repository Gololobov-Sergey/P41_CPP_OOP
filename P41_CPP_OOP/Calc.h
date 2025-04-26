#pragma once
#include "Stack.h"

class Calc
{
	Stack<int, 10> numbers;
	Stack<char, 10> oper;
	string expression;

	int getPriority(char op)
	{
		switch (op)
		{
		case '+': case '-': return 1;
		case '*': case '/': return 2;
		case '^': return 3;
		}
	}

	int calc(int a, int b, char op) 
	{
		switch (op)
		{
		case '+': return a + b;
		case '-': return b - a;
		case '/': return a / b;
		case '*': return a * b;
		case '^': return pow(b, a);
		}
	}

public:
	Calc(string expr) : expression(expr) {	}

	int getResult()
	{
		int i = 0;
		while (expression[i] != '\0')
		{
			if (isdigit(expression[i]))
			{
				numbers.push(expression[i] - 48);
			}
			else
			{
				if (oper.isEmpty())
				{
					oper.push(expression[i]);
				}
				else if (getPriority(expression[i]) > getPriority(oper.peek()))
				{
					oper.push(expression[i]);
				}
				else
				{
					int a = numbers.peek();
					numbers.pop();
					int b = numbers.peek();
					numbers.pop();
					char op = oper.peek();
					oper.pop();
					int res = calc(a, b, op);
					numbers.push(res);
					oper.push(expression[i]);
				}
				
			}
			i++;
		}

		while (!oper.isEmpty())
		{
			int a = numbers.peek();
			numbers.pop();
			int b = numbers.peek();
			numbers.pop();
			char op = oper.peek();
			oper.pop();
			int res = calc(a, b, op);
			numbers.push(res);
		}

		return numbers.peek();
	}
};

