// =============================================================================
// PROGRAMMING FUNDAMENTALS — Assignment 9
// =============================================================================
//
// TASK: Console-Based Simple Calculator
//
// Build a calculator program that runs in the console and performs basic
// arithmetic operations based on the user's input.
//
// -----------------------------------------------------------------------------
// OPERATIONS YOUR CALCULATOR MUST SUPPORT
// -----------------------------------------------------------------------------
//
//   1. Addition          ( + )    e.g.  10 + 3  =  13
//   2. Subtraction       ( - )    e.g.  10 - 3  =  7
//   3. Multiplication    ( * )    e.g.  10 * 3  =  30
//   4. Division          ( / )    e.g.  10 / 3  =  3.33
//   5. Modulus           ( % )    e.g.  10 % 3  =  1  (remainder)
//   6. Exponentiation    ( ^ )    e.g.  2 ^ 8   =  256
//   7. Quit
//
// -----------------------------------------------------------------------------
// HOW THE MENU SHOULD LOOK
// -----------------------------------------------------------------------------
//
//   ============================
//        SIMPLE CALCULATOR
//   ============================
//   1. Addition
//   2. Subtraction
//   3. Multiplication
//   4. Division
//   5. Modulus
//   6. Exponentiation
//   7. Quit
//   Select an operation (1-7):
//
// -----------------------------------------------------------------------------
// EXPECTED INTERACTION EXAMPLE
// -----------------------------------------------------------------------------
//
//   Select an operation (1-7): 4
//   Enter first number : 10
//   Enter second number: 3
//   Result: 10 / 3 = 3.33
//
//   Select an operation (1-7): 4
//   Enter first number : 5
//   Enter second number: 0
//   Error: Cannot divide by zero.
//
//   Select an operation (1-7): 7
//   Goodbye!
//
// -----------------------------------------------------------------------------
// REQUIREMENTS
// -----------------------------------------------------------------------------
// - Each arithmetic operation MUST be written as its own function.
// - Use a loop so the calculator keeps running until the user selects Quit.
// - Division by zero must be caught and handled with a clear error message
//   (do NOT let the program crash).
// - Use fixed and setprecision(2) to display results to 2 decimal places.
// - Handle invalid menu choices gracefully.
// - For exponentiation use a loop or the pow() function from <cmath>.
//

// =============================================================================
// YOUR CODE BELOW — remove the // symbols from the scaffold and fill it in
// =============================================================================


#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;

double addNumbers(double x, double y)
{
    return x + y;
}

double subtractNumbers(double x, double y)
{
    return x - y;
}

double multiplyNumbers(double x, double y)
{
    return x * y;
}

double divideNumbers(double x, double y)
{
    return x / y;
}

int findModulus(int x, int y)
{
    return x % y;
}

double calculatePower(double base, int power)
{
    double result = 1;

    for(int i = 0; i < power; i++)
    {
        result = result * base;
    }

    return result;
}

void displayMenu()
{
    cout << "\n--- SIMPLE CALCULATOR ---\n";
    cout << "1. Addition\n";
    cout << "2. Subtraction\n";
    cout << "3. Multiplication\n";
    cout << "4. Division\n";
    cout << "5. Modulus\n";
    cout << "6. Exponentiation\n";
    cout << "7. Quit\n";
    cout << "Select an operation (1-7): ";
}

int main()
{
    int option;
    double numberOne;
    double numberTwo;

    do
    {
        displayMenu();
        cin >> option;

        if(option == 7)
        {
            cout << "Goodbye!\n";
            break;
        }

        if(option < 1 || option > 7)
        {
            cout << "Invalid option. Please choose between 1 and 7.\n";
            continue;
        }

        cout << "Enter first number: ";
        cin >> numberOne;

        cout << "Enter second number: ";
        cin >> numberTwo;

        cout << fixed << setprecision(2);

        switch(option)
        {
            case 1:
                cout << "Result: " << numberOne << " + "
                     << numberTwo << " = "
                     << addNumbers(numberOne, numberTwo) << endl;
                break;

            case 2:
                cout << "Result: " << numberOne << " - "
                     << numberTwo << " = "
                     << subtractNumbers(numberOne, numberTwo) << endl;
                break;

            case 3:
                cout << "Result: " << numberOne << " * "
                     << numberTwo << " = "
                     << multiplyNumbers(numberOne, numberTwo) << endl;
                break;

            case 4:
                if(numberTwo == 0)
                {
                    cout << "Error: Cannot divide by zero.\n";
                }
                else
                {
                    cout << "Result: " << numberOne << " / "
                         << numberTwo << " = "
                         << divideNumbers(numberOne, numberTwo) << endl;
                }
                break;

            case 5:
                if((int)numberTwo == 0)
                {
                    cout << "Error: Cannot use zero as modulus.\n";
                }
                else
                {
                    cout << "Result: " << (int)numberOne << " % "
                         << (int)numberTwo << " = "
                         << findModulus((int)numberOne, (int)numberTwo)
                         << endl;
                }
                break;

            case 6:
                cout << "Result: " << numberOne << " ^ "
                     << (int)numberTwo << " = "
                     << calculatePower(numberOne, (int)numberTwo)
                     << endl;
                break;
        }

    } while(option != 7);

    return 0;
}

