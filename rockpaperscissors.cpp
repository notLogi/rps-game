#include <iostream>
#include <cstdlib>
#include <ctime>

enum Choice {
    ROCK,
    PAPER,
    SCISSORS
};

// Function to get the computer's choice
Choice getComputerChoice() {
    int randomNum = std::rand() % 3;
    return static_cast<Choice>(randomNum);
}

// Function to determine the winner
void determineWinner(Choice userChoice, Choice computerChoice) {
    std::cout << "Your choice: ";
    switch (userChoice) {
        case ROCK:
            std::cout << "Rock\n";
            break;
        case PAPER:
            std::cout << "Paper\n";
            break;
        case SCISSORS:
            std::cout << "Scissors\n";
            break;
    }

    std::cout << "Computer's choice: ";
    switch (computerChoice) {
        case ROCK:
            std::cout << "Rock\n";
            break;
        case PAPER:
            std::cout << "Paper\n";
            break;
        case SCISSORS:
            std::cout << "Scissors\n";
            break;
    }

    if (userChoice == computerChoice) {
        std::cout << "It's a tie!\n";
    } else if ((userChoice == ROCK && computerChoice == SCISSORS) ||
               (userChoice == PAPER && computerChoice == ROCK) ||
               (userChoice == SCISSORS && computerChoice == PAPER)) {
        std::cout << "You win!\n";
    } else {
        std::cout << "Computer wins!\n";
    }
}

int main() {
    // Seed the random number generator
    std::srand(static_cast<unsigned int>(std::time(nullptr)));

    while (true) {
        std::cout << "Rock, Paper, Scissors Game\n";
        std::cout << "1. Rock\n";
        std::cout << "2. Paper\n";
        std::cout << "3. Scissors\n";
        std::cout << "4. Quit\n";
        std::cout << "Enter your choice: ";

        int choice;
        std::cin >> choice;

        if (choice < 1 || choice > 4) {
            std::cout << "Invalid choice. Please enter a number between 1 and 4.\n";
            continue;
        }

        if (choice == 4) {
            std::cout << "Thanks for playing. Goodbye!\n";
            break;
        }

        Choice userChoice = static_cast<Choice>(choice - 1);
        Choice computerChoice = getComputerChoice();

        determineWinner(userChoice, computerChoice);
    }

    return 0;
}
