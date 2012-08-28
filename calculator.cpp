typedef double Stack_entry;

#include "stack.h"

char get_command()
{
	char command;
	bool waiting = true;
	cout << "Select command and press <Enter> : ";
	while(waiting) 
	{
		cin >> command;
		command = tolower(command);
		if(command == '?' || command == '=' || command == '+' || command == '-' || command == '*' || command == '/' || command == 'q') 
			waiting = false;
		else
		{
			cout << "Please enter a valid command: " << endl
			     << "[?]push to stack [=]print top" << endl
			     << "[+][-][*][/] are arithmetic operations" << endl
			     << "[Q]uit" << endl;
		}
	}
	
	return command;
}

bool do_command (char command, Stack &numbers)
{
	double p,q;
	switch(command)
	{
		case '?':
			cout << "Enter a real number: " << flush;
			cin >> p;
			if(numbers.push(p) == overflow)
				cout << "Warning:Stack full, lost number" << endl;
			break;

		case '=':
			if(numbers.top(p) == underflow)
				cout << "Stack empty" << endl;
			else
				cout << p << endl;
			break;

		case '+':
			if(numbers.top(p) == underflow)
				cout << "Stack empty" << endl;
			else
			{
				numbers.pop();
				if(numbers.top(q) == underflow)
				{
					cout << "Stack has just one entry" << endl;
					numbers.push(p);
				}
				
				else
				{
					numbers.pop();
					if(numbers.push(p + q) == overflow)
						cout << "Warning : Stack full, lost result" << endl;
				}
			}
			
			break;
		
		case '-':
			if(numbers.top(p) == underflow)
				cout << "Stack empty" << endl;
			else
			{
				numbers.pop();
				if(numbers.top(q) == underflow)
				{
					cout << "Stack has just one entry" << endl;
					numbers.push(p);
				}
				
				else
				{
					numbers.pop();
					if(numbers.push(p - q) == overflow)
						cout << "Warning : Stack full, lost result" << endl;
				}
			}
			
			break;
		
		
		case '*':
			if(numbers.top(p) == underflow)
				cout << "Stack empty" << endl;
			else
			{
				numbers.pop();
				if(numbers.top(q) == underflow)
				{
					cout << "Stack has just one entry" << endl;
					numbers.push(p);
				}
				
				else
				{
					numbers.pop();
					if(numbers.push(p * q) == overflow)
						cout << "Warning : Stack full, lost result" << endl;
				}
			}
			
			break;
		
		
		case '/':
			if(numbers.top(p) == underflow)
				cout << "Stack empty" << endl;
			else
			{
				numbers.pop();
				if(numbers.top(q) == underflow)
				{
					cout << "Stack has just one entry" << endl;
					numbers.push(p);
				}
				
				else
				{
					numbers.pop();
					if(numbers.push(p / q) == overflow)
						cout << "Warning : Stack full, lost result" << endl;
				}
			}
			
			break;
		
		case 'q':
			cout << "Calculation finished\n";
			return false;
	}
		
		return true;
}

void instructions()
{
	cout << "Welcome to Reverse Polish Calculator" << endl
	    << "-----------------------------------------" << endl
	    << "Enter ? to read a number and push it onto stack" << endl
	    << "Enter = to print result of an operation from top of stack" << endl
	    << "Enter +,-,*,/ for arithmetic operations" << endl;	
}


int main()
{
	Stack stored_numbers;
	instructions();
	while(do_command(get_command(), stored_numbers));
}
		
