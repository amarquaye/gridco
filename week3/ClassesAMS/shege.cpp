#include <iostream>
#include <fstream>
#include <string>
#include <vector>
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

    // Getter for the asset name
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

Asset createAsset() {
    std::string name;
    std::string colour;
    std::string location;
    std::string description;
    std::string quantity;
    std::string assigned;
    std::string assignment;

    // Clear the newline character from the buffer
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

        // Clear the newline character from the buffer
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

        std::cout << "Is the file to be assigned? (yes/no)" << std::endl;
        std::cin >> assigned;

        // Clear the newline character from the buffer
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
    std::getline(inputFile, line); // Read header line

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
    std::getline(inputFile, line); // Read header line

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
        outputFile.open(fileName, std::ios::app); // Append to existing file
    } else {
        outputFile.open(fileName); // Truncate existing file
    }

    if (!outputFile.is_open()) {
        std::cout << "Error: Unable to open file for writing.\n";
        return;
    }

    // Write header if it's a new file
    if (!append) {
        outputFile << "Name,Colour,Location,Description,Quantity,Assignment\n";
    }

    // Write asset
    outputFile << asset.writeAssetToCSV() << '\n';

    outputFile.close();
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
    std::getline(inputFile, line); // Read header line
    tempFile << line << '\n'; // Write header to temp file

    while (std::getline(inputFile, line)) {
        size_t pos = line.find(',');
        std::string currentAssetName = line.substr(0, pos);

        if (currentAssetName == assetName) {
            // Replace the line with the updated asset
            tempFile << updatedAsset.writeAssetToCSV() << '\n';
        } else {
            tempFile << line << '\n'; // Write unchanged line to temp file
        }
    }

    inputFile.close();
    tempFile.close();

    // Replace the original file with the temp file
    std::remove(fileName.c_str());
    std::rename("temp.csv", fileName.c_str());
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
    std::getline(inputFile, line); // Read header line
    tempFile << line << '\n'; // Write header to temp file

    while (std::getline(inputFile, line)) {
        size_t pos = line.find(',');
        std::string currentAssetName = line.substr(0, pos);

        if (currentAssetName != assetName) {
            tempFile << line << '\n'; // Write unchanged line to temp file
        }
    }

    inputFile.close();
    tempFile.close();

    // Replace the original file with the temp file
    std::remove(fileName.c_str());
    std::rename("temp.csv", fileName.c_str());
}

int main() {
    std::string userInput;
    std::cout << "================= Welcome to Shege Technologies ==================\n";

    do {
        printInstructionText();
        std::cin >> userInput;

        if (userInput == "c") {
            Asset userAsset = createAsset();
            saveAssetToFile("Asset.csv", userAsset, true);
        } else if (userInput == "r") {
            std::cout << "Enter the name of the Asset to read: ";
            std::string assetName;
            std::cin >> assetName;

            std::vector<std::string> matchingLines = readAssetFromFile("Asset.csv", assetName);
            printMatchingLines(matchingLines);
        } else if (userInput == "u") {
            std::cout << "Enter the name of the Asset to update: ";
            std::string assetName;
            std::cin >> assetName;

            std::vector<std::string> matchingLines = readAssetFromFile("Asset.csv", assetName);

            if (!matchingLines.empty()) {
                // Assuming there's only one asset with the given name
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

                updateAssetInFile("Asset.csv", assetName, updatedAsset);
                std::cout << "Asset updated successfully!\n";
            } else {
                std::cout << "Asset not found.\n";
            }
        } else if (userInput == "d") {
            std::cout << "Enter the name of the Asset to delete: ";
            std::string assetName;
            std::cin >> assetName;

            deleteAssetFromFile("Asset.csv", assetName);
            std::cout << "Asset deleted successfully!\n";
        } else if (userInput == "s") {
            showAllAssetsFromFile("Asset.csv");
        } else if (userInput != "x") {
            std::cout << "Enter a valid response!\n";
        }
    } while (userInput != "x");

    return 0;
}
