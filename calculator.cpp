typedef double Stack_entry;

#include "stack.h"

/* function declarations */
void instructions();
char get_command();
bool do_command(char, Stack&);
void swapTop(Stack&);
void findSum(Stack&);
void findAverage(Stack&);

/* main function */
int main()
{
	Stack stored_numbers;
	instructions();
	while(do_command(get_command(), stored_numbers));
}

/* function to receive and validate user inputs */
char get_command()
{
	char command;
	bool waiting = true;
	cout << "Select command and press <Enter> : ";
	while(waiting) 
	{
		cin >> command;
		command = tolower(command);
		if(command == '?' || command == '=' || command == '+' || command == '-' || command == '*' || command == '/' || command == 'i' || command == 's' || command == 'a' || command == 'q') 
			waiting = false;
		else
		{
			cout << "Please enter a valid command: " << endl
			     << "[?]push to stack [=]print top" << endl
			     << "[+][-][*][/] are arithmetic operations" << endl
			     << "[I]nterchange numbers on top of stack" << endl
			     << "[S]um all numbers in stack " << endl
			     << "[A]verage all numbers in stack " << endl
			     << "[Q]uit" << endl;
		}
	}
	
	return command;
}

/* function to process calculations */
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
		
		case 'i':
			swapTop(numbers);
			break;
		
		case 's':
			findSum(numbers);
			cout << "All numbers added and sum pushed onto stack" << endl;
			break;

		case 'a':
			findAverage(numbers);
			cout << "Average calculated and result pushed onto stack" << endl;
			break;

		case 'q':
			cout << "Calculation finished\n";
			return false;
	}
		
		return true;
}

/* functions to print instructions of usage */
void instructions()
{
	cout << "Welcome to Reverse Polish Calculator" << endl
	    << "-----------------------------------------" << endl
	    << "Enter ? to read a number and push it onto stack" << endl
	    << "Enter = to print result of an operation from top of stack" << endl
	    << "Enter +,-,*,/ for arithmetic operations" << endl	
	    << "Enter 'I' to interchange numbers on top" << endl
	    << "Enter 'S' to sum all numbers" << endl
	    << "Enter 'A' to find average of all numbers" << endl;
}

/* function to interchange top 2 numbers */
void swapTop(Stack &numbers)
{
	double temp1, temp2;
	numbers.top(temp1);
	numbers.pop();
	numbers.top(temp2);
	numbers.pop();
	numbers.push(temp1);
	numbers.push(temp2);
	cout << "Top 2 numbers interchanged" << endl;
}

/* funtion to calculate average of all numbers on stack */
void findAverage(Stack &numbers)
{
	int totalNumbers;
	double sum, average;
	totalNumbers = numbers.size();
	findSum(numbers);
	numbers.top(sum);
	numbers.pop();
	average = sum / totalNumbers;
	numbers.push(average);
}

/* function to calculate sum of all numbers on stack */
void findSum(Stack &numbers)
{
	double sum = 0, entry;
	
	while(numbers.size() != 0)
	{
		numbers.top(entry);
		sum = sum + entry;
		numbers.pop();
	} 
	numbers.push(sum);
}


		
