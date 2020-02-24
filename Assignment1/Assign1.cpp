#include <iostream>
#include <string.h>
#include <algorithm>
#include "Stack.h"
#include "Stack.cpp"
using namespace std;

int priority(char);
int pow(int,int);

class Expression
{
	string str;
	string result;//member variables
	public :
		void getString()
		{
			str.clear();
			cin >> str;
	    }
		void display()
		{
			cout << str << endl;
		}
		string InfixtoPostfix();
		string InfixtoPrefix();
		int PostEval();
		int PreEval();
		int valString();//member functions
};


int main()
{
	int choice;
	Expression exp;//declares object of class
	do{

	cout << "\n\tMENU :\n1.Input expression\n2.Display expression\n"
			"3.Conversion of expression infix to postfix\n"
			"4.Conversion of expression infix to prefix\n"
			"5.Evaluation of expression(Postfix)\n6.Evaluation of expression(Prefix)\n7.Exit\nEnter choice : ";
	cin >> choice;
	switch(choice)
	{
		case 1 : cout << "\nEnter expression : ";
				 exp.getString();
		         while(exp.valString()==-1){
					 cout << "\nInvalid expression.\nEnter expression again : ";
					 exp.getString();//validation
				 }
				 break;

		case 2 : cout << "\nGiven expression : ";
				 exp.display();
				 break;

		case 3 : cout << "\nInfix to  Postfix : " <<endl;
				 exp.InfixtoPostfix();
		         break;

		case 4 : cout << "\nInfix to  Prefix : " <<endl;
				 exp.InfixtoPrefix();
		         break;

		case 5 : cout << "\nEnter postfix expression : ";
				 exp.getString();
			     cout << "\nEvaluation of postfix expression : " << exp.PostEval() << endl;
				 break;

		case 6 : cout << "\nEnter prefix expression : ";
				 exp.getString();
				 cout << "\nEvaluation of prefix expression : " << exp.PreEval() << endl;
				 break;

		case 7 : return 0;
	}

  }while(1);
}

int priority(char c)//sets priorities to every operator
{
	int i;
	if(c==')') i=4;
	else if( c=='^' )  i=3;
	else if( c=='*' || c=='/' || c=='%' ) i=2;
	else if( c=='+' || c=='-' ) i=1;
	else if(c=='(') i=0;
	else if((c>='a' && c<='z') || (c>='A' && c<='Z') || (c>='1' && c<='9')) i=-1;
	else i=5;
	return i;
}

int Expression :: valString()//validations
{
	Stack<char> stk;
	int i;
	char x;
	for(i=0;i<str.length();i++)
	{
		if(priority(str[i])==5)//if char is neither operator nor operand
		{
			return -1;
		}
		if(priority(str[i])!=4 && priority(str[i])!=0)//if char is not a bracket
		{
			stk.push(str[i]);//push the elements in stack
		}
	}
	i=0;
	while(!stk.isEmpty())
	{
		x = stk.pop();
		if(i%2==0)
		{
			if(priority(x)!=-1) return -1;//operand should be at even position
		}
		else if(i%2!=0)
		{
			if(priority(x)==-1) return -1;//operator should be at odd position
		}
		i++;//checks position
	}
	return 0;
}

string Expression :: InfixtoPostfix()
{
	Stack<char> stk;
	int i;
	result.clear();
    cout << "\nInfix Expression : " << str << endl;

	for(i=0;i<str.length();i++)
	{

		if(priority(str[i])==-1) result+=str[i];//operand is entered
		else
		{//operator is entered

			if(stk.isEmpty()) stk.push(str[i]);//stack is empty,directly push the operator
			else{


					if(priority(str[i])==4)
					{ //if closing bracket

						while(priority(stk.peep())!=0)
						{
							if(stk.isEmpty()) break;
							result += stk.pop();//pop until opening bracket
						}
						if(!stk.isEmpty())
							stk.pop();//pop the opening bracket
					}

					else if(priority(str[i])==3 || priority(str[i])==2 || priority(str[i])==1)
					{

						while(priority(stk.peep())>=priority(str[i]))//ISP>=ICP
						{
							if(stk.isEmpty()) break;
							result+=stk.pop();
						}
						stk.push(str[i]);
					}

					else if(priority(str[i])==0)//if opening bracket, push directly in stack
						stk.push(str[i]);
			   }

		}

	}

	while(!stk.isEmpty()) result+= stk.pop();//empty the stack
	cout << "Postfix expression : " << result << endl;
	return result;

}


string Expression :: InfixtoPrefix()
{
	Stack<char> stk;
    result.clear();
	int i;
    cout << "\nInfix Expression : " << str << endl;
	reverse(str.begin(), str.end());//reverse the expression

	for(i=0;i<str.length();i++)
	{

		if(priority(str[i])==-1) result+=str[i];//operand is entered
		else
		{//operator is entered

			if(stk.isEmpty())
			{
				if(str[i]!='(' && str[i]!=')')
			 	stk.push(str[i]);//stack is empty,directly push the operator
			}
			else{

					if(str[i]==')')//if closing bracket
					{
						stk.push('(');//perform operation for opening bracket
					}

					else if(priority(str[i])==3)//right associative operator
					{
						while(priority(stk.peep())>=priority(str[i]))
							{//doubt !isEmpty()
								if(stk.isEmpty()) break;
								result+=stk.pop();
							}
						stk.push(str[i]);
					}

					else if(priority(str[i])==2 || priority(str[i])==1)
					{

						while(priority(stk.peep())>priority(str[i]))//ISP>ICP
						{
							if(stk.isEmpty()) break;
							result+=stk.pop();
						}
						stk.push(str[i]);
					}

					else if(str[i]=='(')//if opening bracket
					{
						//perform operation for closing bracket
						while(stk.peep()!='(')
						{
							if(stk.isEmpty()) break;
							result += stk.pop();//pop until opening bracket
						}
						if(!stk.isEmpty())
							stk.pop();
					}

			  }

		}

	}

	while(!stk.isEmpty()) result+= stk.pop();
	reverse(result.begin(), result.end());//reverse result
	cout << "Prefix expression : " << result << endl;
	return result;
}

int operation(int op1,int op2,char op)//performs operations
{
	switch(op)
	{
		case '+' : return op1+op2;
				   break;

		case '-' : return op1-op2;
				   break;

		case '*' : return op1*op2;
				   break;

		case '/' : return op1/op2;
				   break;

		case '^' : return pow(op1,op2);

		default : return 0;
	}
}

int pow(int op1,int op2)
{
	int i,res=1;
	for(i=0;i<op2;i++)
		res = op1*res;
	return res;//exponent
}


int Expression :: PostEval()
{
	Stack<int> stk;
	int i=0,res;
	int op1,op2;
	while(str[i]!='\0')
	{
		if(priority(str[i])==-1)
		{
			if(isalpha(str[i]))
			{
				cout << "\nEnter value of " << str[i] << " : ";
				cin >> str[i];//if variable, ask for its value
				i--;//decrement index
			}
			else
			{
				stk.push(str[i]-48);//push the operand in stack
			}
		}
		else if(priority(str[i])==3 || priority(str[i])==2 || priority(str[i])==1)
		{
			op2 = stk.pop();
			op1 = stk.pop();
			stk.push(operation(op1,op2,str[i]));//perform operation by popping 2 elements from stack
			res = operation(op1,op2,str[i]);
		}
		i++;//increment index
	}
	return res;
}


int Expression :: PreEval()
{
	Stack<int> stk;
	int i,res;
	int op1,op2;
	for(i=str.length()-1;i>=0;i--)
	{
		if(priority(str[i])==-1)
		{
			if(isalpha(str[i]))
			{
				cout << "\nEnter value of " << str[i] << " : ";
				cin >> str[i];//if variable, ask for its value
				i++;
			}
			else
			{
				stk.push(str[i]-48);//push the operand in stack
			}
		}
		else if(priority(str[i])==3 || priority(str[i])==2 || priority(str[i])==1)
		{

			op1 = stk.pop();
			op2 = stk.pop();
			stk.push(operation(op1,op2,str[i]));//perform operation by popping 2 elements from stack
			res = operation(op1,op2,str[i]);
		}
	}
	return res;
}

/*
 *
	MENU :
1.Input expression
2.Display expression
3.Conversion of expression infix to postfix
4.Conversion of expression infix to prefix
5.Evaluation of expression(Postfix)
6.Evaluation of expression(Prefix)
7.Exit
Enter choice : 1

Enter expression : (A+B)+C*D-E^F^G+H

	MENU :
1.Input expression
2.Display expression
3.Conversion of expression infix to postfix
4.Conversion of expression infix to prefix
5.Evaluation of expression(Postfix)
6.Evaluation of expression(Prefix)
7.Exit
Enter choice : 2

Given expression : (A+B)+C*D-E^F^G+H

	MENU :
1.Input expression
2.Display expression
3.Conversion of expression infix to postfix
4.Conversion of expression infix to prefix
5.Evaluation of expression(Postfix)
6.Evaluation of expression(Prefix)
7.Exit
Enter choice : 3

Infix to  Postfix :

Infix Expression : (A+B)+C*D-E^F^G+H
Postfix expression : AB+CD*+EF^G^-H+

	MENU :
1.Input expression
2.Display expression
3.Conversion of expression infix to postfix
4.Conversion of expression infix to prefix
5.Evaluation of expression(Postfix)
6.Evaluation of expression(Prefix)
7.Exit
Enter choice : 4

Infix to  Prefix :

Infix Expression : (A+B)+C*D-E^F^G+H
Prefix expression : +-++AB*CD^E^FGH

	MENU :
1.Input expression
2.Display expression
3.Conversion of expression infix to postfix
4.Conversion of expression infix to prefix
5.Evaluation of expression(Postfix)
6.Evaluation of expression(Prefix)
7.Exit
Enter choice : 5

Enter postfix expression : 98+382/*2+-

Evaluation of postfix expression : 3

	MENU :
1.Input expression
2.Display expression
3.Conversion of expression infix to postfix
4.Conversion of expression infix to prefix
5.Evaluation of expression(Postfix)
6.Evaluation of expression(Prefix)
7.Exit
Enter choice : 6

Enter prefix expression : +A*+BCD

Enter value of D : 9

Enter value of C : 3

Enter value of B : 5

Enter value of A : 6

Evaluation of prefix expression : 78

	MENU :
1.Input expression
2.Display expression
3.Conversion of expression infix to postfix
4.Conversion of expression infix to prefix
5.Evaluation of expression(Postfix)
6.Evaluation of expression(Prefix)
7.Exit
Enter choice : 7
 *
 */

