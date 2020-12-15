# include <iostream>
# include <ctime>

void PrintIntroduction(int Difficulty)
{
// Initial story layout printed to console
    std::cout << "\n++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++\n";
    std::cout << "|  You are a hacker tasked with breaking into a level " << Difficulty << " secure server room.  |\n";
    std::cout << "|        Enter the correct code to proceed to the next security door.        |\n";
    std::cout << "++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++\n\n";

}

bool PlayGame(int Difficulty)
{
    PrintIntroduction(Difficulty);

    const int CodeA = rand() % Difficulty + Difficulty;
    const int CodeB = rand() % Difficulty + Difficulty;
    const int CodeC = rand() % Difficulty + Difficulty;

    const int CodeSum = CodeA + CodeB + CodeC;
    const int CodeProd = CodeA * CodeB * CodeC;

    // Print out the sum and product
    std::cout << "+ There are 3 numbers in the code\n";
    std::cout << "+ The codes add up to: " << CodeSum;
    std::cout << "\n+ The codes multiplied by each other are: " << CodeProd << "\n\n";

    // Store Player Guesses
    int GuessA, GuessB, GuessC;
    std::cout << "Enter the code: ";
    std::cin >> GuessA >> GuessB >> GuessC;

    int GuessSum = GuessA + GuessB + GuessC;
    int GuessProd = GuessA * GuessB * GuessC;

    // Check if the player's guesses are correct
    if (GuessSum == CodeSum && GuessProd == CodeProd)
    {
        std::cout << "\nYou have passed the level " << Difficulty << " security door!";
        if (Difficulty < 5)
        {
            std::cout << "\nPlease proceed to the next door.";
        }
        
        return true;
    }
    else
    {
        std::cout << "\nYou entered the wrong code. Please try again.\n";
        return false;
    }
}

int main()
{
    srand(time(NULL));
    
    int LevelDifficulty = 1;
    int MaxLevel = 5;

    while (LevelDifficulty <= MaxLevel)
    {
        bool bLevelComplete = PlayGame(LevelDifficulty);
        std::cin.clear(); // Clears any errors
        std::cin.ignore(); // Discards the input buffer

        if (bLevelComplete)
        {
            ++LevelDifficulty;
        }
        
    }
    std::cout << "\n\nCongratulations! You WIN!! You have broken into the secure server room!\n\n"; 
   
    return 0;
}