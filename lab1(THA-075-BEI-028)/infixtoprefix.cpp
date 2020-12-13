//WAP to convert an infix expression into a prefix expression
#include <iostream>
#include <stack>
#include <algorithm>
using namespace std;
// Function to get the precedence of operators
int precedence(char op) {
if(op == '^')
return 3;
else if (op == '*' || op == '/')
return 2;
else if (op == '+' || op == '-')
return 1;
else
return -1;
}
// function to convert infix to postfix (returns a string)
string infixToPostfix(string infix) {

// add '(' and ')' at the start & end of infix respectively
	infix = '(' + infix + ')';
	int len = infix.length();
	stack <char> st;
	string postfix;
         // loop through the infix string
	for(int i = 0; i < len; i++) {
if((infix[i] >= 'a' && infix[i] <= 'z') || (infix[i] >= 'A' && infix[i] <= 'Z')) {
			postfix += infix[i];
		}
                    else if (infix[i] == '(')
			st.push('(');
                      else if (infix[i] == ')') {
			while(st.top() != '(') {
				postfix += st.top();
				st.pop();
			}
			// remove '(' from the stack
			st.pop();
		}
		else {
			// Operator is found in scanned char
			while(precedence(infix[i]) <= precedence(st.top())) {
				postfix += st.top();
				st.pop();
			}
			st.push(infix[i]);
		}
	}
		return postfix;
}
// Infix to prefix
string infixToPrefix(string infix) {
int l = infix.length();
// Reverse the infix expression
reverse(infix.begin(), infix.end());
// Replace ( with ) and vice versa to the reversed string
	for(int i = 0; i < l; i++) {
		if(infix[i] == '(') {
			infix[i] = ')';
			i++;
		}
		else if (infix[i] == ')') {infix[i] = '(';	i++;}}
string prefix = infixToPostfix(infix);
// reversing the postfix expression
reverse(prefix.begin(), prefix.end());
return prefix;
}

int main() {
    string infix;
    cout<<"***************Infix to prefix converter*******************"<<endl;
    cout<<"Enter the infix expression \t";
    cin>>infix;
    cout<<"The prefix expression of "<<infix<<"  is\t";
	cout << infixToPrefix(infix) << endl;
	return 0;
}
