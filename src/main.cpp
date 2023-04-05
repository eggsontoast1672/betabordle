#include <iostream>
#include <stdlib.h>
#include <time.h>

int main() {
    srand(time(nullptr));

    std::cout << "Keybordle!" << std::endl;
    std::cout << "The goal is simple, find the secret keybordle by guessing" << std::endl;
    std::cout << "Just enter a string of appropriate lengthand the computer will tell you if the letter in the alphabet is:" << std::endl;
    std::cout << "After the letter you entered(1)" << std::endl;
    std::cout << "Before the letter you entered(0)" << std::endl;
    std::cout << "The same(the letter)" << std::endl;
    std::cout << "How many letters?" << std::endl;

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
    
    auto guessNum = 0;

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
        } else {
            bool success = true;
            std::string answer;
            for (int i = 0; i < alphalen; i++) {
                if (guess.substr(i, 1) == keybordle.substr(i, 1)) {
                    alpha.find_first_of(keybordle.substr(i, 1));
                    answer += keybordle.substr(i, 1);
                } else if (alpha.find_first_of(guess.substr(i, 1)) > alpha.find_first_of(keybordle.substr(i, 1))) {
                    answer += "0";
                    success = false;
                } else {
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
    } else {
        std::cout << "You lose!";
    }

    std::cin.get();
}