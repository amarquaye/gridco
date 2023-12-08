#include <iostream>
#include <string>
#include <fstream>
#include <chrono>
#include <ctime>

class Asset {
public:
    Asset(const std::string& assetName, const std::string& assetEntryDate, const std::string& location,
          const std::string& description, const std::string& quantity, const std::string& assetAssignment)
        : m_assetName(assetName), m_assetEntryDate(assetEntryDate), m_location(location),
          m_description(description), m_quantity(quantity), m_assetAssignment(assetAssignment) {}

    std::string displayAssets() const {
        return m_assetName + "," + m_assetEntryDate + "," + m_location + "," +
               m_description + "," + m_quantity + "," + m_assetAssignment;
    }

private:
    std::string m_assetName;
    std::string m_assetEntryDate;
    std::string m_location;
    std::string m_description;
    std::string m_quantity;
    std::string m_assetAssignment;
};

std::string getCurrentDate() {
    auto now = std::chrono::system_clock::to_time_t(std::chrono::system_clock::now());
    std::string date = std::ctime(&now);
    date.pop_back(); // Remove the trailing newline character
    return date;
}

bool isFileEmpty(const std::string& filename) {
    std::ifstream file(filename);
    return file.peek() == std::ifstream::traits_type::eof();
}

void writeToCSV(const Asset& asset) {
    const std::string filename = "Asset.csv";

    std::ofstream output(filename, std::ios::app);

    if (output.is_open()) {
        // Check if the file is empty, and if so, print the header
        if (isFileEmpty(filename)) {
            output << "Name,Entry Date,Location,Description,Quantity,Assigned" << std::endl;
        }

        output << asset.displayAssets() << std::endl;
        output.close();
        std::cout << "Information stored!\n";
    } else {
        std::cerr << "Error: Unable to open the file." << std::endl;
    }
}

Asset createAsset() {
    std::string assetName;
    std::string entryDate;
    std::string location;
    std::string description;
    std::string quantity;
    std::string assetAssignment;

    std::string assigned;

    std::cout << "Enter the name of the drug you want to add: " << std::endl;
    std::getline(std::cin, assetName);
    entryDate = getCurrentDate(); // Automate the entry date
    std::cout << "Enter where the drug is being stored: " << std::endl;
    std::getline(std::cin, location);
    std::cout << "Enter the description of the drug: " << std::endl;
    std::getline(std::cin, description);
    std::cout << "Enter the quantity of the drug being stored: " << std::endl;
    std::cin >> quantity;
    std::cout << "Is the file to be assigned?" << std::endl;
    std::cin >> assigned;

    while (assigned != "yes" && assigned != "no") {
        std::cout << "Didn't enter a valid response!!" << std::endl;
        std::cin >> assigned;
    }

    if (assigned == "yes") {
        std::cout << "Who is it to be assigned to? " << std::endl;
        std::cin.ignore(); // Ignore the newline character left in the buffer
        std::getline(std::cin, assetAssignment);
    } else if (assigned == "no") {
        std::cout << "Ok. The file will be left unassigned." << std::endl;
        assetAssignment = "Not assigned";
    }

    Asset newAsset(assetName, entryDate, location, description, quantity, assetAssignment);
    writeToCSV(newAsset);

    return newAsset;
}

void closeApplication() {
    std::cout << "Closing Application.......\n";
}

void printInstructionText() {
    std::cout << "What do you want to do?\n";
    std::cout << "c(Create), r(Read), u(Update), d(Delete), s(Show All), x(Close Program)\n";
}

int main() {
    std::string userInput;
    std::cout << "================= Welcome to Shege Technologies ==================\n";

    do {
        printInstructionText();
        std::cin >> userInput;

        if (userInput == "c") {
            //createFile();
        } else if (userInput == "r") {
            //readFile();
        } else if (userInput == "u") {
            //updateFile();
        } else if (userInput == "d") {
            //deleteFile();
        } else if (userInput == "s") {
            //showAllFiles();
        } 
        else if (userInput != "x") {
            std::cout << "Enter a valid response!\n";
        }
    } while (userInput != "x");

    closeApplication();

    return 0;
}
