#include <iostream>
#include <string>

int main(){
    std::string sentence = "this is a word search program\n A program to take the user's input\n Find the word and return the number of times that word appears\n";
    std::string word;

    std::cout << "Enter a word you're looking for\n";
    //std::cin >> word;
    std::getline(std::cin, word);
    std::cout << word;
}