#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <algorithm>
#include <random>

class DataLoader
{
public:
    // Constructor
    DataLoader(const std::string &filename, int numWords)
    {
        std::ifstream file(filename);

        // Do this when you open a file to make sure it opened correctly
        if (!file.is_open())
        {
            std::cerr << "Failed to open file: " << filename << std::endl;
            return;
        }

        // Read in all the words and store them in a vector
        std::string word;
        while (file >> word)
        {
            words_.push_back(word);
        }

        // Shuffle the words. Start by creating a random number generator object, initialize
        // it with a random seed, and then use the generator to shuffle the words.
        std::random_device rd;
        std::mt19937 g(rd());
        std::shuffle(words_.begin(), words_.end(), g);

        // Store the original words in a separate vector
        allWords_ = words_;

        // Resize the vector to the number of words requested
        numWords_ = std::min(numWords, static_cast<int>(words_.size()));
        words_.resize(numWords_);
    }

    // We use & here to return a reference to the vector. This is more efficient than returning
    // a copy of the vector.

    const std::vector<std::string> &getWords() const
    {
        return words_;
    }

    const std::vector<std::string> &getAllWords() const
    {
        return allWords_;
    }

private:
    std::vector<std::string> words_;
    std::vector<std::string> allWords_;
    int numWords_;
};
