#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <algorithm>
#include <random>
#include <filesystem>
#include "WordleGame.cpp"

int main()
{
    std::cout << "You are now playing Wordle" << std::endl;
    std::cout << "How many attempts would you like?" << std::endl;
    int attempts;
    std::cin >> attempts;

    std::cout << "Prepare to play" << std::endl;

    WordleGame game(attempts, 10, "words.txt", "results.csv");

    game.Play();
}