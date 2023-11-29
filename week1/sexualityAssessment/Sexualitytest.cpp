//Sexuality assessment test program written by Jeffery Hodo
// Industrial attachment at Ghana Grid Company
// Week 1 assignment 
// 21st November 2023


#include <iostream>
#include <string>

int main() {
    std::string name, gender;
    int a1, a2, a3;

    std::cout << "Sexual Assessment Program" << "\n";
    std::cout << "Answer the following questions to determine your sexuality" << "\n";

    // Get user input
    std::cout << "Enter your name:" << "\n";
    std::cin >> name;

    std::cout << "Gender? (M/F)" << "\n";
    std::cin >> gender;

    std::cout << "Are you attracted to males?" << "\n";
    std::cout << "1- Yes  2- No" << "\n";
    std::cin >> a1;

    std::cout << "Are you attracted to females?" << "\n";
    std::cout << "1- Yes  2- No" << "\n";
    std::cin >> a2;

    std::cout << "Are you attracted to inanimate objects?" << "\n";
    std::cout << "1- Yes  2- No" << "\n";
    std::cin >> a3;

    // Using if-else statements to determine sexuality based on user inputs

    if ((gender == "M" || gender == "m") && a1 == 1 && a2 == 2 && a3 == 2) {
        std::cout << "Dear " << name << " " << "you are gay";
    } else if ((gender == "M" || gender == "m") && a1 == 2 && a2 == 1 && a3 == 2) {
        std::cout << "Dear " << name << " " << "you are straight";
    } else if ((gender == "M" || gender == "m" || gender == "F" || gender == "f") && a1 == 1 && a2 == 1 && a3 == 2) {
        std::cout << "Dear " << name << " " << "you are bisexual";
    }

    return 0;
}

