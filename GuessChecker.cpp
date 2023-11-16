#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <algorithm>
#include <random>

class GuessChecker
{
public:
    static bool CheckGuess(std::string wordGuess_, std::string wordToGuess_)
    {
        std::string result_;

        for (int i = 0; i < wordToGuess_.length(); i++)
        {
            result_ += '_';
        }

        if (wordGuess_ == wordToGuess_)
        {
            std::cout << "You guessed the word!" << std::endl;
            return true;
        }

        else
        {
            for (int i = 0; i < wordGuess_.length(); i++)
            {
                for (int j = 0; j < wordToGuess_.length(); j++)
                {
                    if (i != j && wordGuess_[i] == wordToGuess_[j])
                    {
                        result_[i] = '#';
                        break;
                    }

                    else if (i == j && wordGuess_[i] == wordToGuess_[j])
                    {
                        result_[i] = '!';
                        break;
                    }

                    else
                    {
                        result_[i] = '_';
                    }
                }
            }
            std::cout << "You guessed " << result_ << std::endl;
            return false;
        }
    }
};
