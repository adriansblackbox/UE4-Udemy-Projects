#include <iostream>
#include <ctime>

void PlayGameAtDifficulty(int difficulty)
{
    // Introduction to the game
    std::cout << "You're a secret agent breaking into LEVEL " << difficulty << "server room\n";
    std::cout << "Your SuperHacker 2000 tells you the following information...\n";

    srand(time(NULL));
    // Create constant variables that will be used for the "code" meant to be deciphered
    // They are a radome number based off the difficulty that was passed through.
    const int KeyA = rand() % difficulty + difficulty;
    const int KeyB = rand() % difficulty + difficulty;
    const int KeyC = rand() % difficulty + difficulty;
    // Both the sum and product of the variables above will be used to test the player
    const int sum = KeyA + KeyB + KeyC;
    const int product = KeyA * KeyB * KeyC;
    // Prints the questions
    std::cout << std::endl;
    std::cout << "+ There are three numbers in the code\n";
    std::cout << "+ The codes multiply to give " << product << std::endl;
    std::cout << "+ The codes add-up to " << sum << std::endl;
    std::cout << std::endl;
    std::cout << "Enter the three code numbers followed by x\n";
    std::cout << std::endl;
    // Variables to hold the player's answers
    int answer;
    int trialSum = 0;
    int trialProduct = 1;
    // Player inserts their answers with Std In
    while (std::cin >> answer)
    {
        trialSum += answer;
        trialProduct *= answer;
    }
    // Depending on whether or not the answers are correct, different lines are printed
    std::cout << std::endl;
    if (trialSum == sum && trialProduct == product)
    {
        // Success
        std::cout << "CONGRATS, YOU'RE IN. Now hurry before anyone finds you.\n";
        std::cout << "=======================================================\n";
    }
    else
    {
        // Failure
        std::cout << "BOOM!!!!!! You are TOAST.\n";
    }
    std::cout << std::endl;

}

int main()
{
    // Starting the games difficulty at 2, and ending at 10 (8 rounds)
    int difficulty = 2;
    int maxDifficulty = 10;
    while(difficulty <= maxDifficulty)
    {
        PlayGameAtDifficulty(difficulty);
        // After play game function is executed, reset Std Cin, and increase difficulty.
        std::cin.clear();
        std::cin.ignore();
        ++difficulty;
    }
    // The end of the game (8 rounds completed)
    std::cout << "That's all the code we've got for you agent. Hope you aren't too hurt...\n";
    return 0;
}