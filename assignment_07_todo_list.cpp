// =============================================================================
// PROGRAMMING FUNDAMENTALS — Assignment 7
// =============================================================================
//
// TASK: Console-Based To-Do List Application
//
// Build a simple to-do list program that runs entirely in the console and
// allows the user to manage their tasks interactively using a menu.
//
// -----------------------------------------------------------------------------
// FEATURES YOUR PROGRAM MUST SUPPORT
// -----------------------------------------------------------------------------
//
//   1. Add a Task
//      - Prompt the user to type a task description.
//      - Add it to the list and confirm it was added.
//
//   2. View All Tasks
//      - Display all tasks currently in the list, numbered from 1.
//      - If the list is empty, print a friendly message saying so.
//
//   3. Delete a Task
//      - Show the list of tasks with their numbers.
//      - Ask the user which task number they want to remove.
//      - Remove the task and confirm the deletion.
//      - If the task number is invalid, print an error message.
//
//   4. Quit
//      - End the program with a farewell message.
//
// -----------------------------------------------------------------------------
// HOW THE MENU SHOULD LOOK
// -----------------------------------------------------------------------------
//
//   ============================
//        TO-DO LIST MENU
//   ============================
//   1. Add task
//   2. View tasks
//   3. Delete task
//   4. Quit
//   Enter your choice (1-4):
//
// -----------------------------------------------------------------------------
// EXPECTED INTERACTION EXAMPLE
// -----------------------------------------------------------------------------
//
//   Enter your choice (1-4): 1
//   Enter task: Buy groceries
//   Task added: "Buy groceries"
//
//   Enter your choice (1-4): 2
//   Your Tasks:
//   1. Buy groceries
//   2. Study for exams
//
//   Enter your choice (1-4): 3
//   Enter task number to delete: 1
//   Task "Buy groceries" has been removed.
//
//   Enter your choice (1-4): 4
//   Goodbye!
//
// -----------------------------------------------------------------------------
// REQUIREMENTS
// -----------------------------------------------------------------------------
// - Store tasks in a vector<string> (a dynamic list of text).
// - Use a loop to keep the menu running until the user chooses to quit.
// - Each feature MUST be implemented in its own function (see scaffold below).
// - Handle invalid menu choices gracefully (print an error, do not crash).
//

//
// =============================================================================
// YOUR CODE BELOW — remove the // symbols from the scaffold and fill it in
// =============================================================================


#include <iostream>
#include <vector>
#include <string>
using namespace std;

void menu();
void addTask(vector<string>& tasks);
void showTasks(const vector<string>& tasks);
void removeTask(vector<string>& tasks);

int main()
{
    vector<string> tasks = {
        "Study for upcoming exams",
        "Buy an item",
        "Complete an assignment",
        "Exercise for 30 minutes",
        "Visit the doctor",
        "Watch a movie"
    };

    int choice;

    do
    {
        menu();

        cout << "Please select (1-4): ";
        cin >> choice;
        cin.ignore();

        if (choice == 1)
        {
            addTask(tasks);
        }
        else if (choice == 2)
        {
            showTasks(tasks);
        }
        else if (choice == 3)
        {
            removeTask(tasks);
        }
        else if (choice == 4)
        {
            cout << "Goodbye!" << endl;
        }
        else
        {
            cout << "Invalid choice." << endl;
        }

    } while (choice != 4);

    return 0;
}

void menu()
{
    cout << endl;
    cout << "TO-DO LIST MENU" << endl;
    cout << "1. Add task" << endl;
    cout << "2. View tasks" << endl;
    cout << "3. Delete task" << endl;
    cout << "4. Quit" << endl;
}

void addTask(vector<string>& tasks)
{
    string task;

    cout << "Enter task: ";
    getline(cin, task);

    tasks.push_back(task);

    cout << "Task added: \"" << task << "\"" << endl;
}

void showTasks(const vector<string>& tasks)
{
    if (tasks.size() == 0)
    {
        cout << "You have no tasks." << endl;
    }
    else
    {
        cout << "Your Tasks:" << endl;

        for (int i = 0; i < tasks.size(); i++)
        {
            cout << i + 1 << ". " << tasks[i] << endl;
        }
    }
}

void removeTask(vector<string>& tasks)
{
    if (tasks.size() == 0)
    {
        cout << "You have no tasks to delete." << endl;
        return;
    }

    showTasks(tasks);

    int number;
    cout << "Enter task number to delete: ";
    cin >> number;
    cin.ignore();

    if (number >= 1 && number <= tasks.size())
    {
        cout << "Task \"" << tasks[number - 1] << "\" has been removed." << endl;
        tasks.erase(tasks.begin() + number - 1);
    }
    else
    {
        cout << "Invalid task number." << endl;
    }
}
