// Keybordle.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <stdlib.h>
#include <time.h>

int main()
{
    //clearly unoptomized
    //abcdefghijklm|nopqrstuvwxyz
    //abcdef g hijklm|nopqrs t uvwxyz
    //abc|def g hij|klm|nop|qrs t uvw|xyz
    //abcdefg
    std::cout << "Keybordle!\n";
    std::cout << "The goal is simple, find the secret keybordle by guessing \nJust enter a string of appropriate length and the computer will tell you if the letter in the alphabet is:\nAfter the letter you entered(1)\nBefore the letter you entered(0)\nThe same(the letter)\n";
    std::cout << "How many letters?\n";
    int alphalen;
    std::cin >> alphalen;
    if (alphalen > 26) {
        alphalen = 26;
    }
    else if (alphalen < 2) {
        alphalen = 2;
    }
    std::cout << "How long of a game?\n";
    int len;
    std::cin >> len;
    std::string bet = "abcdefghijklmnopqrstuvwxyz";
    std::string alpha = "abcdefghijklmnopqrstuvwxyz";
    std::string keybordle = "";
    std::string pointless;
    auto guessNum = 0;
    srand(time(0));
    bool pass = false;
    bet.substr(0, alphalen);
    
    for (int i = 0; i < alphalen; i++) {
        int letter = rand() % (alphalen - i);
        keybordle += bet.substr(letter, 1);
        bet.erase(letter, 1);
    }

    while (guessNum < len) {
        std::cout << "Enter your guess!\n";
        std::string guess;
        std::cin >> guess;
        //keybordle was: psyeiuxdwbnjzkcqmvholtgafr
        if (guess.length() != alphalen) {
            std::cout << "Oops, wrong length!" << std::endl;
        }
        else {
            bool success = true;
            std::string answer;
            for (int i = 0; i < alphalen; i++) {
                if (guess.substr(i, 1) == keybordle.substr(i, 1)) {
                    alpha.find_first_of(keybordle.substr(i, 1));
                    answer += keybordle.substr(i, 1);
                }
                else if (alpha.find_first_of(guess.substr(i, 1)) > alpha.find_first_of(keybordle.substr(i, 1))) {
                    answer += "0";
                    success = false;
                }
                else {
                    answer += "1";
                    success = false;
                }
            }
            std::cout << std::endl << answer << "\n";
            if (success) {
                std::cout << "You win\n";
                pass = true;
                break;
            }
        }
        guessNum++;
    }
    if (pass) {
        std::cout << "Consider Playing again!";
        std::cin >> pointless;
    }
    else {
        std::cout << "You lose!";
        std::cin >> pointless;
    }
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
