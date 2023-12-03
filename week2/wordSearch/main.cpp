#include <iostream>
#include <string>

int main() {
    std::string sentence = "this is a word search program\n A program to take the user's word\n Find the word and return the number of times that word appears\n";
    std::string word;

    std::cout << "Enter a word you're looking for\n";
    std::getline(std::cin, word);

    int counter = 0;
    size_t pos = sentence.find(word);  // Find the first occurrence of the word

    while (pos != std::string::npos) {
        counter++;  // Increment the counter for each occurrence
        pos = sentence.find(word, pos + 1);  // Find the next occurrence of the word
    }

    std::cout << "The word \"" << word << "\" appears " << counter << " times." << std::endl;

    return 0;
}