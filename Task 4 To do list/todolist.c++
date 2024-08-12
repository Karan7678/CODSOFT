                                                        //TASK 4: TO-DO-LIST    

#include <iostream>
#include <string>
#include <limits>  // For std::numeric_limits
#include <cstdlib> // For system("cls")

using namespace std;

void showTask(const string task[], int taskCount)
{
    cout << "Task To Do : " << endl;
    cout << "-----------------------------------" << endl;
    for (int i = 0; i < taskCount; i++)
    {
        cout << "Task " << i << " : " << task[i] << endl;
    }
    cout << "------------------------------------\n\n";
}

int main()
{
    const int MAX_TASKS = 20;
    string task[MAX_TASKS];
    int taskCount = 0;
    int option = -1;

    while (option != 0)
    {
        system("cls"); // Used to Update the console screen
        cout << "-----TO DO LIST----- " << endl;
        cout << "1 @ To Create New Task " << endl;
        cout << "2 @ To Show Task " << endl;
        cout << "3 @ To Delete A Task " << endl;
        cout << "0 @ To Exit from the To Do List \n\n"
             << endl;
        cin >> option;

        // Check for invalid input
        if (cin.fail())
        {
            cin.clear();                                         // Clear the error flag
            cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Discard invalid input
            option = -1;
            cout << "!!!!Invalid input!!!! NOW !! Press 5 key to continue " << endl;
            cin.ignore(); // Allow to read the message
            cin.get();    // Wait for user to press enter
            continue;
        }

        switch (option)
        {
        case 1:
            if (taskCount >= MAX_TASKS)
            {
                cout << "STOP !!! The Task list is full " << endl;
            }
            else
            {
                cout << "Please Enter your Task : ";
                cin.ignore(); // Ignore leftover newline character
                getline(cin, task[taskCount]);
                taskCount++;
            }
            break;

        case 2:
            system("cls");
            showTask(task, taskCount);
            cout << "Press ENTER to return to menu ";
            cin.ignore(); // Ignore leftover newline character
            cin.get();    // Wait for user to press enter
            break;

        case 3:
            system("cls");
            showTask(task, taskCount);
            int delTask;
            cout << "Enter the index of the task you want to delete: ";
            cin >> delTask;

            // Check for invalid input
            if (cin.fail())
            {
                cin.clear();                                         // Clear the error flag
                cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Discard invalid input
                cout << "!!!!Invalid input!!!! NOW !! Press 5 key to continue" << endl;
                cin.ignore(); // Pause to allow user to read the message
                cin.get();    // Wait for user to press enter
                break;
            }

            if (delTask < 0 || delTask >= taskCount)
            {
                cout << "You entered an Invalid task index." << endl;
            }
            else
            {
                for (int i = delTask; i < taskCount - 1; i++)
                {
                    task[i] = task[i + 1];
                }
                taskCount--;
                cout << "Task deleted successfully " << endl;
            }
            cout << "Press ENTER to return to menu ";
            cin.ignore(); // Ignore leftover newline character
            cin.get();    // Wait for user to press enter
            break;

        case 0:
            cout << "You are now successfully EXIT from the Task Manager " << endl;
            break;

        default:
            cout << "!!!!Invalid input!!!! NOW !! Press 5 key to continue " << endl;
            cin.ignore(); // Ignore leftover newline character
            cin.get();    // Wait for user to press enter
        }
    }

    return 0;
}
