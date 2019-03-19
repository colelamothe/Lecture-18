// Lecture 18 supplementary program
// Functions continued

#include<iostream>
#include<string>

using namespace std;

// Function prototypes
int inputRange(int , int);
void displayInfo(string name, int age, double salary);
int counterStatic();
int counterNormal();
// Global variables are defined outside of the main loop and then can be accessed from anywhere in the program
// Global variables can be useful but make tracing errors through your code hard to trace since any function can now edit it and needs to be checked.
int discount = 10; // This variable will now be able to be read and written from any function.

int main() { // Since nothing can call the main function, we can exchange int main() for void main() and change return 0; to return; with no effect to our program.
	/* Two types of functions:
			- Value return functions:
				- returns a value of some variable type as defined
			- Void functions:
				- returns nothing, used to send output, create files, etc.
	*/
	
	// Calls the input range function
	int numberRead = inputRange(0, 27); // This is a local variable only accesible from inside of the main loop being assigned by the value return function

	cout << numberRead << endl;
	
	displayInfo("Cole", 27, 0); // string, int, int as defined by the parameters of the function. void function returns nothing to this location only outputs parameters.
	

	// Memory management
	/* Variables can be assigned to 4 different locations:
			- auto: memory assigned for local variables is not reserved when that function is exited
			- external: memory is reserved throughout the execution of the program for global variables
			- static: requests that the memory be reserved for a local variable even after the function has ended. maintaining the value from last call Can be used to count the number of times a function was called
			- register: High priority memory on the first page of the processor.
	*/
	register int dist = 10;


	// Normal outputs 1 each time while static increments by one each time because the value is kept between runs.
	cout << "Normal variable: " << counterNormal() << " Static Variable: " << counterStatic() << endl;
	cout << "Normal variable: " << counterNormal() << " Static Variable: " << counterStatic() << endl;
	cout << "Normal variable: " << counterNormal() << " Static Variable: " << counterStatic() << endl;
	cout << "Normal variable: " << counterNormal() << " Static Variable: " << counterStatic() << endl;
	cout << "Normal variable: " << counterNormal() << " Static Variable: " << counterStatic() << endl;





	system("pause");
	return 0;
}

// gets a number within a certain range
// input: min value, max value
int inputRange(int min, int max) {
	// These are local variables only accesible from inside of the inputRange function.
	int number;
	bool failed;
	do {
		do {
			failed = false;
			cout << "Insert a number between " << min << " and " << max << endl;
			cin >> number;
			if (cin.fail() == true) { // validates the input to only integer values that can be successfully assigned to the variable.
				cin.clear();
				cin.ignore();
				failed = true;
			}
		} while (failed == true);
	} while (number < min || number > max);
	return number;
}

// Displays a series of variables 
// input: name, age, salary.
void displayInfo(string name, int age, double salary) { // since this is a void function it will only output to the command line and not return anything to the main function when called.
	cout << "Name: " << name << " age: " << age << " salary: " << salary << endl;
	cout << "Discount rate: " << discount << endl; // calling a global variable.
	return; // in void functions you can use the return command so long as nothing follows it to signify the end of the function.
}


// Static variable stores it's value outside of each call. Permenantly stored like a global variable but only locally available.
int counterStatic() {
	static int c = 0;
	return ++c;
}

// Normal variable is dumped at the end of each loop
int counterNormal() {
	int a = 0;
	return ++a;
}