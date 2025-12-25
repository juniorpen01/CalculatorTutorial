// CalculatorTutorial.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream> // <> looks in system directories; "" looks in project directories, what <> also does later

#include "Calculator.h" // i wanna separate std, third party, and project level

// no using namespace std cuz it sucks; supposed to bring namespace std into scope

int main()
{
	std::cout << R"(Calculator Console Application

Please enter an operation to perform. Format: a+b | a-b | a*b | a/b
)"; // << some weird ahh operator but ye usually for out; in this case stdout; raw string cuz it look better imo; couldve chosen either \n or endl, but \n generally better practice for it doesnt instantly flush buffer
	// ends in semicolons btw
	// main is linker entry point i think

	while (true) {
		double x, y; char oper; Calculator c; // idk why decl all on same line

		if (!(std::cin >> x >> oper >> y)) { // apparenly cin has a bool operator; but ye cin can go fail state and not take any input cuz of it
			std::cin.clear(); // clears state
			std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // numeric limit max of stream size; ignores that many until \n
			std::cout << "Invalid input\n";
			continue;
		}
		else if (oper == '/' && y == 0) {
			std::cout << "Invalid division by zero\n";
			continue;
		}

		double result = // apparently autos in debugger up to three lines from current line; there is also locals; can also be modded there
			c.Calculate(x, oper, y);
		std::cout << "Result of " << x << oper << y << " is: " << result << '\n';
	}
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
