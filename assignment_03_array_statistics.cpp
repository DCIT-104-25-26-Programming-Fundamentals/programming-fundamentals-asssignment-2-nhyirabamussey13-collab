// =============================================================================
// PROGRAMMING FUNDAMENTALS — Assignment 3
// =============================================================================
//
// TASK: Array Statistics Calculator
//
// Write a C++ program that reads a collection of numbers from the user
// and computes key statistical values using separate functions.
//
// -----------------------------------------------------------------------------
// EXPECTED INPUT / OUTPUT EXAMPLE
// -----------------------------------------------------------------------------
//
//   How many numbers? 5
//   Enter number 1: 4
//   Enter number 2: 7
//   Enter number 3: 2
//   Enter number 4: 9
//   Enter number 5: 1
//
//   Results:
//   Sum:     23
//   Average: 4.6
//   Maximum: 9
//   Minimum: 1
//
// -----------------------------------------------------------------------------
// REQUIREMENTS
// -----------------------------------------------------------------------------
// - You MUST implement each calculation in its own function (see scaffold).
// - You may NOT use any standard library functions like accumulate(), max(),
//   or min(). Implement the logic yourself using loops.
// - N must be a positive integer. If the user enters 0 or a negative number,
//   print an error message and stop.
//

//
// =============================================================================
// YOUR CODE BELOW — remove the // symbols from the scaffold and fill it in
// =============================================================================

#include <iostream>
using namespace std;

int findsum(int thing[], int number) {
    int sum = 0;
    for (int integer = 0; integer < number; integer++) {
        sum = sum + thing[integer];
    }
    return sum;
}

double average(int sum, int integer) {
    return (double)sum / integer;
}

double Max(int thing[], int number) {
    double maximum = thing[0];
    for (int integer = 1; integer < number; integer++) {
        if (thing[integer] > maximum)
            maximum = thing[integer];
    }
    return maximum;
}

double min(int thing[], int number) {
    double minimum = thing[0];
    for (int integer = 1; integer < number; integer++) {
        if (thing[integer] < minimum)
            minimum = thing[integer];
    }
    return minimum;
}

int main() {
    int number;
    std::cout << "How many numbers? ";
    std::cin >> number;

    if (number <= 0) {
        std::cout << "Error: Number of values must be positive.";
        return 0;
    }

    int thing[number];
    for (int integer = 0; integer < number; integer++) {
        std::cout << "Enter number " << integer + 1 << ": ";
        std::cin >> thing[integer];
    }

    std::cout << "\nResults:" << std::endl;
    std::cout << "Sum: " << findsum(thing, number) << std::endl;
    std::cout << "Average: " << average(findsum(thing, number), number) << std::endl;
    std::cout << "Maximum: " << Max(thing, number) << std::endl;
    std::cout << "Minimum: " << min(thing, number) << std::endl;

    return 0;
}
