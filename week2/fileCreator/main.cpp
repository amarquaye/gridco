#include <iostream>
#include <fstream>

int main(){
    std::cout << "Please enter the name of the file you want to create." << std::endl;
    std::string filename;
    std::cin >> filename;
    filename += ".txt";

    std::ofstream output(filename);

    if(output.is_open()){
        output <<  "Hello world\n";
        output << "I am writing to this file\n";
        output << "Printing to a file from C++\n";
        output << "This is a doc file\n";
        output.close();
    }
    else{
        std::cout << "Failed to write to file\n";
    }
}