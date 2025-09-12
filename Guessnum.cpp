#include <iostream>
#include <cstdlib> // For rand() and srand()
#include <ctime> // For time()

using namespace std;

int main() {
    srand(time(0)); // Initialize random seed

    int level = 1;
    const int maxLevel = 5;
    int chances[] = {10, 8, 6, 4, 2};

    cout << "Welcome to the Number Guessing Game!" << endl;
    cout << "You have 5 levels to complete. Each level has a different number of chances." << endl;

    while (level <= maxLevel) {
        int numberToGuess = rand() % 100 + 1; // Random number between 1 and 100
        int attempts = chances[level - 1];
        bool hasGuessedCorrectly = false;

        cout << "\nLevel " << level << ": You have " << attempts << " chances to guess the number between 1 and 100." << endl;

        while (attempts > 0) {
            cout << "Enter your guess: ";
            int userGuess;
            cin >> userGuess;

            if (userGuess < 1 || userGuess > 100) {
                cout << "Please guess a number between 1 and 100." << endl;
                continue;
            }

            if (userGuess == numberToGuess) {
                cout << "Congratulations! You've guessed the correct number." << endl;
                hasGuessedCorrectly = true;
                break;
            } else if (userGuess < numberToGuess) {
                cout << "Too low! Try again." << endl;
            } else {
                cout << "Too high! Try again." << endl;
            }

            attempts--;
            cout << "You have " << attempts << " chances left." << endl;
        }

        if (!hasGuessedCorrectly) {
            cout << "Sorry, you've run out of chances. The correct number was: " << numberToGuess << endl;
            cout << "Game Over!" << endl;
            break;
        }

        if (level == maxLevel) {
            cout << "Congratulations! You've completed all levels!" << endl;
        } else {
            cout << "Great job! Moving on to the next level." << endl;
        }

        level++;
    }

    return 0;
}
