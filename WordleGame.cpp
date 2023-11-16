#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <algorithm>
#include <random>
#include <filesystem>
// Include the data loader and guesschecker classes here
#include "DataLoader.cpp"
#include "GuessChecker.cpp"

class WordleGame
{
public:
    WordleGame(int attempts, int numWords, std::string sourceFileName, std::string targetFileName)
    {
        attempts_ = attempts;
        numWords_ = numWords;
        sourceFileName_ = sourceFileName;
        targetFileName_ = targetFileName;
    }

    void Play()
    {
        // Get the words from the data loader
        DataLoader dataLoader(sourceFileName_, numWords_);
        std::vector<std::string> words = dataLoader.getWords();
        std::vector<std::string> allWords = dataLoader.getAllWords();

        std::string wordGuess;

        // Pick a random word from the vector
        std::random_device rd;
        std::mt19937 g(rd());
        std::shuffle(words.begin(), words.end(), g);
        std::string wordToGuess = words[0];

        // Print the number of blanks in the word to guess
        std::string result;
        for (int i = 0; i < wordToGuess.length(); i++)
        {
            result += '_';
        }
        std::cout << "The word to guess is " << result << " and the number of letters in the word are : " << result.length() << std::endl;

        // Play the game
        while (attempts_ > 0)
        {
            std::cout << "Guess a word: ";
            std::cin >> wordGuess;

            if (GuessChecker::CheckGuess(wordGuess, wordToGuess))
            {
                // Write the result to results.csv
                std::ofstream file(targetFileName_, std::ios_base::app);
                file << wordToGuess << "," << attempts_ << std::endl;
                break;
            }

            attempts_--;
        }

        if (attempts_ == 0)
        {
            std::cout << "You ran out of attempts! The word was: " << wordToGuess << std::endl;
        }
    }

private:
    int attempts_;
    int numWords_;
    std::string sourceFileName_;
    std::string targetFileName_;
};
