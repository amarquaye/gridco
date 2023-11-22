#include <iostream>
#include <fstream>
#include <string>
#include <cstdio>

void createFile(){ // Creates and names the file based on the users input 
    std::string fileName;
    std::cout << "Enter the name of the file you want to create: \n";
    std::cin >> fileName;
    fileName += ".txt";
    std::ofstream output(fileName);

    if (output.is_open()) {
        std::cout << "Enter the information you want kept: \n";
        std::string message;
        std::cin >> message;
        output << message;
        output.close();
    }
}

void readFile(){ // Reads the content of the file
    std::string fileName;
    std::cout << "Enter the name of the file you want to read from: \n";
    std::cin >> fileName;
    fileName += ".txt";

    std::string message;
    std::ifstream output(fileName);
    if(output.is_open()){
        while(output){
            message = output.get();
            std::cout << message;
        }
    }
}

void updateFile(){ // Edits the content of the file
    std::string fileName;
    std::cout << "Enter the name of the file you want to update too: \n";
    std::cin >> fileName;
    fileName += ".txt";

    std::string message;
    std::ofstream output(fileName);
    if (output.is_open()) {
         std::cout << "What do you want to Update to this file?\n";
        std::string message;
        std::cin >> message;
        output << message;
        output.close();
    }
    else {
        std::cout << "This file does not exist. Create a new file.\n";
    }
}

void deleteFile(){ // finds the file being looked for and deletes it
    std::string fileName;
    std::cout << "Enter the name of the file you want to delete: \n";
    std::cin >> fileName;
    fileName += ".txt";
    int result  = std::remove(fileName.c_str());
    std::cout << result << std::endl;
}

void closeApplication(){ // Self explanatory
    std::cout << "Closing Application.......\n";
}

void printInstructionText(){ //Prints the placeholder text
    std::cout << "What do you want to do?\n";
    std::cout << "c(Create) ,  r(Search and Read) ,  u(Update) ,  d(delete) ,  x(Close Program)\n";
}

int main(){
    std::string userInput;
    std::cout << "================= Welcome to Shege Pharmacy ==================\n";
    printInstructionText();
    std::cin >> userInput;

    while(userInput != "x"){
        if(userInput == "c"){
            createFile();  //Creates the file
            printInstructionText();
            std::cin >> userInput;
        }
        else if(userInput == "r"){
            readFile(); //Searches and reads from file
            printInstructionText();
            std::cin >> userInput;
        }
        else if(userInput == "u"){
            updateFile(); //Updates the file of choice
            printInstructionText();
            std::cin >> userInput;
        }
        else if(userInput == "d"){
            deleteFile(); //Deletes the file
            printInstructionText();
            std::cin >> userInput;
        }
        else if(userInput == "x"){
            closeApplication();
        }
        else{
            std::cout << "Enter a valid response!\n";
            printInstructionText();
            std::cin >> userInput;
        }
    }
}