#include <iostream>
#include <ctime>

void PlayGameAtDifficulty(int difficulty)
{
    std::cout << "You're a secret agent breaking into LEVEL " << difficulty << "server room\n";
    std::cout << "Your SuperHacker 2000 tells you the following information...\n";

    srand(time(NULL));
    const int KeyA = rand() % difficulty + difficulty;
    const int KeyB = rand() % difficulty + difficulty;
    const int KeyC = rand() % difficulty + difficulty;

    const int sum = KeyA + KeyB + KeyC;
    const int product = KeyA * KeyB * KeyC;

    std::cout << std::endl;
    std::cout << "+ There are three numbers in the code\n";
    std::cout << "+ The codes multiply to give " << product << std::endl;
    std::cout << "+ The codes add-up to " << sum << std::endl;

    std::cout << std::endl;
    std::cout << "Enter the three code numbers followed by x\n";
    std::cout << std::endl;

    int answer;
    int trialSum = 0;
    int trialProduct = 1;

    while (std::cin >> answer)
    {
        trialSum += answer;
        trialProduct *= answer;
    }

    std::cout << std::endl;
    if (trialSum == sum && trialProduct == product)
    {
        std::cout << "CONGRATS, YOU'RE IN. Now hurry before anyone finds you.\n";
        std::cout << "=======================================================\n";
    }
    else
    {
        std::cout << "BOOM!!!!!! You are TOAST.\n";
    }
    std::cout << std::endl;

}

int main()
{
    int difficulty = 2;
    int maxDifficulty = 10;
    while(difficulty <= maxDifficulty)
    {
        PlayGameAtDifficulty(difficulty);
        std::cin.clear();
        std::cin.ignore();
        ++difficulty;
    }
    std::cout << "WOW - You're a master hacker!\n";
    return 0;
}