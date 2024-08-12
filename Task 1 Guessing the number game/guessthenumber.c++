                                                //Task 1: Number Guessing Game

#include <iostream>
#include <cstdlib>
#include <ctime>
#include <limits> // Use limit for the sureing the number is valid or not

using namespace std;

int main()
{
    cout << "\n\t\t\t\t\tWelcome to the Guessing The Number Game " << endl;
    cout << "Let's start the game !!! " << endl;
    cout << "Now guess the number between 1 to 100 " << endl;
    cout << "Press 0 to end the game! \n"
         << endl;

    srand(time(0)); // Generate the random number

    while (true)
    {
        int random = 1 + (rand() % 100);
        int playerchoice;
        int remainingchance = 5;

        for (int i = 1; i <= 5; i++)
        {
            cout << "\n\nEnter the number: ";
            cin >> playerchoice;

            if (cin.fail())
            {
                cin.clear();                                         // Clear the error flag
                cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Ignore invalid input
                cout << "Please enter a valid number!" << endl;
                i--; // Decrement i to not count this invalid attempt
                continue;
            }

            if (playerchoice == 0)
            {
                cout << "You chose to end the game. Goodbye!" << endl;
                return 0;
            }

            if (playerchoice == random)
            {
                cout << "AWESOME ^_^ You guessed the right number !!! " << endl;
                cout << "Play again with us " << endl;
                break;
            }
            else
            {
                cout << "Nope, " << endl;
                if (playerchoice > random)
                {
                    cout << "The Secret Number is smaller than the number you have chosen " << endl;
                }
                else
                {
                    cout << "The Secret Number is greater than the number you have chosen " << endl;
                }
                cout << "Please try again !!! " << endl;

                remainingchance--;
                cout << remainingchance << " choices left " << endl;

                if (remainingchance == 0)
                {
                    cout << "Your lifeline is over! The number was " << random << ". YOU LOSE THE GAME @@ \n";
                    cout << "Play the game again to win this game " << endl;
                }
            }
        }
    }

    return 0;
}
