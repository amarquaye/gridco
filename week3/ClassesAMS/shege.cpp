#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <ctime>
#include <limits>

class Asset {
public:
    Asset(const std::string& name, const std::string& colour, const std::string& location,
          const std::string& description, const std::string& quantity, const std::string& assigned)
        : name(name), colour(colour), location(location), description(description),
          quantity(quantity), assigned(assigned) {}

    std::string writeAssetToCSV() const {
        return name + "," + colour + "," + location + "," + description + "," + quantity + "," + assigned;
    }

    const std::string& getName() const {
        return name;
    }

private:
    std::string name;
    std::string colour;
    std::string location;
    std::string description;
    std::string quantity;
    std::string assigned;
};

bool isValidAsset(const std::string& name, const std::string& colour,
                   const std::string& location, const std::string& description,
                   const std::string& quantity, const std::string& assigned) {
    return !name.empty() && !colour.empty() && !location.empty() &&
           !description.empty() && !quantity.empty() && (assigned == "yes" || assigned == "no");
}

std::string getCurrentDateTime() {
    time_t now = time(0);
    tm* localTime = localtime(&now);
    char buffer[80];
    strftime(buffer, 80, "%Y-%m-%d %H:%M:%S", localTime);
    return buffer;
}

void logEntry(const std::string& fileName, const std::string& entry) {
    std::ofstream logFile(fileName, std::ios::app);

    if (!logFile.is_open()) {
        std::cerr << "Error: Unable to open log file for writing.\n";
        return;
    }

    logFile << getCurrentDateTime() << " - " << entry << '\n';

    logFile.close();
}

bool fileExists(const std::string& fileName) {
    std::ifstream file(fileName);
    return file.good();
}

void createAssetFile(const std::string& fileName) {
    std::ofstream outputFile(fileName);

    if (!outputFile.is_open()) {
        std::cerr << "Error: Unable to create file for writing.\n";
        return;
    }

    outputFile << "Name,Colour,Location,Description,Quantity,Assignment\n";

    outputFile.close();

    logEntry("log.txt", "File 'Asset.csv' created with header.");
}

Asset createAsset() {
    std::string name;
    std::string colour;
    std::string location;
    std::string description;
    std::string quantity;
    std::string assigned;
    std::string assignment;

    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

    do {
        std::cout << "Enter the name of the Asset: " << std::endl;
        std::getline(std::cin, name);
        std::cout << "Enter the colour of the Asset: " << std::endl;
        std::getline(std::cin, colour);
        std::cout << "Enter where the Asset is being stored: " << std::endl;
        std::getline(std::cin, location);
        std::cout << "Enter the description of the Asset: " << std::endl;
        std::getline(std::cin, description);
        std::cout << "Enter the quantity of the Asset: " << std::endl;
        std::cin >> quantity;

        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

        std::cout << "Is the file to be assigned? (yes/no)" << std::endl;
        std::cin >> assigned;

        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

        if (assigned == "yes") {
            std::cout << "Who is it being assigned to?" << std::endl;
            std::getline(std::cin, assignment);
        } else if (assigned == "no") {
            std::cout << "Ok!" << std::endl;
            assignment = "Not Assigned.";
        } else {
            std::cerr << "Please enter the appropriate answer." << std::endl;
        }

        if (isValidAsset(name, colour, location, description, quantity, assigned)) {
            break;
        } else {
            std::cout << "Invalid or incomplete input. Please fill in all the required fields!\n";
        }

    } while (true);

    Asset newAsset(name, colour, location, description, quantity, assignment);
    return newAsset;
}

std::vector<std::string> readAssetFromFile(const std::string& fileName, const std::string& assetName) {
    std::ifstream inputFile(fileName);

    if (!inputFile.is_open()) {
        std::cerr << "Error: Unable to open file for reading.\n";
        return {};
    }

    std::vector<std::string> matchingLines;
    std::string line;
    std::getline(inputFile, line);

    while (std::getline(inputFile, line)) {
        size_t pos = line.find(',');
        std::string currentAssetName = line.substr(0, pos);

        if (currentAssetName == assetName) {
            matchingLines.push_back(line);
        }
    }

    inputFile.close();
    return matchingLines;
}

void printMatchingLines(const std::vector<std::string>& lines) {
    if (lines.empty()) {
        std::cout << "Asset not found.\n";
    } else {
        std::cout << "Matching Assets:\n";
        for (const std::string& line : lines) {
            std::cout << line << '\n';
        }
    }
}

void showAllAssetsFromFile(const std::string& fileName) {
    std::ifstream inputFile(fileName);

    if (!inputFile.is_open()) {
        std::cerr << "Error: Unable to open file for reading.\n";
        return;
    }

    std::string line;
    std::getline(inputFile, line);

    std::cout << "All Assets:\n";
    while (std::getline(inputFile, line)) {
        std::cout << line << '\n';
    }

    inputFile.close();
}

void printInstructionText() {
    std::cout << "What do you want to do?\n";
    std::cout << "c(Create), r(Read), u(Update), d(Delete), s(Show All), x(Close Program)\n";
}

void saveAssetToFile(const std::string& fileName, const Asset& asset, bool append) {
    std::ofstream outputFile;

    if (append) {
        outputFile.open(fileName, std::ios::app);
    } else {
        outputFile.open(fileName);

        if (!outputFile.is_open()) {
            std::cout << "Error: Unable to open file for writing.\n";
            return;
        }

        outputFile << "Name,Colour,Location,Description,Quantity,Assignment\n";
    }

    if (!outputFile.is_open()) {
        std::cout << "Error: Unable to open file for writing.\n";
        return;
    }

    outputFile << asset.writeAssetToCSV() << '\n';

    outputFile.close();

    logEntry("log.txt", "Asset added: " + asset.getName());
}

void updateAssetInFile(const std::string& fileName, const std::string& assetName, const Asset& updatedAsset) {
    std::ifstream inputFile(fileName);
    std::ofstream tempFile("temp.csv");

    if (!inputFile.is_open()) {
        std::cerr << "Error: Unable to open file for reading.\n";
        return;
    }

    if (!tempFile.is_open()) {
        std::cerr << "Error: Unable to open temp file for writing.\n";
        return;
    }

    std::string line;
    std::getline(inputFile, line);
    tempFile << line << '\n';

    while (std::getline(inputFile, line)) {
        size_t pos = line.find(',');
        std::string currentAssetName = line.substr(0, pos);

        if (currentAssetName == assetName) {
            tempFile << updatedAsset.writeAssetToCSV() << '\n';
        } else {
            tempFile << line << '\n';
        }
    }

    inputFile.close();
    tempFile.close();

    std::remove(fileName.c_str());
    std::rename("temp.csv", fileName.c_str());

    logEntry("log.txt", "Asset updated: " + assetName);
}

void deleteAssetFromFile(const std::string& fileName, const std::string& assetName) {
    std::ifstream inputFile(fileName);
    std::ofstream tempFile("temp.csv");

    if (!inputFile.is_open()) {
        std::cerr << "Error: Unable to open file for reading.\n";
        return;
    }

    if (!tempFile.is_open()) {
        std::cerr << "Error: Unable to open temp file for writing.\n";
        return;
    }

    std::string line;
    std::getline(inputFile, line);
    tempFile << line << '\n';

    while (std::getline(inputFile, line)) {
        size_t pos = line.find(',');
        std::string currentAssetName = line.substr(0, pos);

        if (currentAssetName != assetName) {
            tempFile << line << '\n';
        }
    }

    inputFile.close();
    tempFile.close();

    std::remove(fileName.c_str());
    std::rename("temp.csv", fileName.c_str());

    logEntry("log.txt", "Asset deleted: " + assetName);
}

int main() {
    std::string fileName = "Asset.csv";

    if (!fileExists(fileName)) {
        createAssetFile(fileName);
    }

    std::string userInput;
    std::cout << "================= Welcome to Shege Technologies ==================\n";

    do {
        printInstructionText();
        std::cin >> userInput;

        if (userInput == "c") {
            Asset userAsset = createAsset();
            saveAssetToFile(fileName, userAsset, true);
            logEntry("log.txt", "User created an Asset");
        } else if (userInput == "r") {
            std::cout << "Enter the name of the Asset to read: ";
            std::string assetName;
            std::cin >> assetName;

            std::vector<std::string> matchingLines = readAssetFromFile(fileName, assetName);
            printMatchingLines(matchingLines);
            logEntry("log.txt", "User read Asset: " + assetName);
        } else if (userInput == "u") {
            std::cout << "Enter the name of the Asset to update: ";
            std::string assetName;
            std::cin >> assetName;

            std::vector<std::string> matchingLines = readAssetFromFile(fileName, assetName);

            if (!matchingLines.empty()) {
                std::string updatedAssetName;
                std::string updatedAssetColour;
                std::string updatedAssetLocation;
                std::string updatedAssetDescription;
                std::string updatedAssetQuantity;
                std::string updatedAssetAssigned;

                std::cout << "Enter the updated information:\n";
                std::cout << "Enter the name of the Asset: ";
                std::cin >> updatedAssetName;
                std::cout << "Enter the colour of the Asset: ";
                std::cin >> updatedAssetColour;
                std::cout << "Enter where the Asset is being stored: ";
                std::cin >> updatedAssetLocation;
                std::cout << "Enter the description of the Asset: ";
                std::cin >> updatedAssetDescription;
                std::cout << "Enter the quantity of the Asset: ";
                std::cin >> updatedAssetQuantity;
                std::cout << "Is the file to be assigned? (yes/no): ";
                std::cin >> updatedAssetAssigned;

                Asset updatedAsset(updatedAssetName, updatedAssetColour, updatedAssetLocation,
                                    updatedAssetDescription, updatedAssetQuantity, updatedAssetAssigned);

                updateAssetInFile(fileName, assetName, updatedAsset);
                std::cout << "Asset updated successfully!\n";
                logEntry("log.txt", "User Updated Asset: " + updatedAssetName);
            } else {
                std::cout << "Asset not found.\n";
            }
        } else if (userInput == "d") {
            std::cout << "Enter the name of the Asset to delete: ";
            std::string assetName;
            std::cin >> assetName;

            deleteAssetFromFile(fileName, assetName);
            std::cout << "Asset deleted successfully!\n";
            logEntry("log.txt", "User Deleted Asset: " + assetName);
        } else if (userInput == "s") {
            showAllAssetsFromFile(fileName);
            logEntry("log.txt", "User has viewed all Assets");
        } else if (userInput != "x") {
            std::cout << "Enter a valid response!\n";
        }
    } while (userInput != "x");

    return 0;
}
