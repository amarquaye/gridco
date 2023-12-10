#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>
#include <limits>
#include <ctime>

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
}

void logEntry(const std::string& logFileName, const std::string& activity, const std::string& assetName) {
    std::ofstream logFile(logFileName, std::ios::app);

    if (!logFile.is_open()) {
        std::cerr << "Error: Unable to open log file for writing.\n";
        return;
    }

    std::time_t currentTime = std::time(nullptr);
    std::string timestamp = std::asctime(std::localtime(&currentTime));
    timestamp.erase(std::remove(timestamp.begin(), timestamp.end(), '\n'), timestamp.end());

    logFile << timestamp << " - " << activity << " for asset: " << assetName << '\n';

    logFile.close();
}

Asset createAsset(const std::vector<Asset>& existingAssets, const std::string& logFileName) {
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

        auto it = std::find_if(existingAssets.begin(), existingAssets.end(),
                               [&](const Asset& asset) { return asset.getName() == name; });

        if (it != existingAssets.end()) {
            std::cerr << "Asset with the name '" << name << "' already exists. Please enter a different name.\n";
            continue;
        }

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

    // Log the create activity
    logEntry(logFileName, "Create", newAsset.getName());

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
    std::cout << "Select Operation\n";
    std::cout << "c(Create), r(Read), u(Update), d(Delete), s(Show All), x(Close Program)\n";
}

void saveAssetToFile(const std::string& fileName, const Asset& asset, bool append, const std::string& logFileName) {
    std::ofstream outputFile;
    if (append) {
        outputFile.open(fileName, std::ios::app);
    } else {
        outputFile.open(fileName);
        outputFile << "Name,Colour,Location,Description,Quantity,Assignment\n";
    }

    if (!outputFile.is_open()) {
        std::cout << "Error: Unable to open file for writing.\n";
        return;
    }

    outputFile << asset.writeAssetToCSV() << '\n';

    outputFile.close();

    // Log the save activity
    logEntry(logFileName, "Save", asset.getName());
}

void updateAssetInFile(const std::string& fileName, const std::string& assetName, const Asset& updatedAsset, const std::string& logFileName) {
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

    // Log the update activity
    logEntry(logFileName, "Update", assetName);
}

void deleteAssetFromFile(const std::string& fileName, const std::string& assetName, const std::string& logFileName) {
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

    // Log the delete activity
    logEntry(logFileName, "Delete", assetName);
}


int main() {
    std::string fileName = "Asset.csv";
    std::string logFileName = "log.txt";

    if (!fileExists(fileName)) {
        createAssetFile(fileName);
    }

    std::string userInput;
    std::vector<Asset> assets;

    std::cout << "================= Asset Management System ==================\n";
    std::cout << "================= Version 1.1 ==================\n";
    std::cout << "================= Developed by Shege Technologies ==================\n";

    do {
        printInstructionText();
        std::cin >> userInput;

        if (userInput == "c" && "C") {
            Asset userAsset = createAsset(assets, logFileName);
            assets.push_back(userAsset);
            saveAssetToFile("Asset.csv", userAsset, true, logFileName);
        } else if (userInput == "r" && "R") {
            std::cout << "Enter the name of the Asset to read: ";
            std::string assetName;
            std::cin >> assetName;

            std::vector<std::string> matchingLines = readAssetFromFile("Asset.csv", assetName);
            printMatchingLines(matchingLines);
        } else if (userInput == "u" && "U") {
            std::cout << "Enter the name of the Asset to update: ";
            std::string assetName;
            std::cin >> assetName;

            std::vector<std::string> matchingLines = readAssetFromFile("Asset.csv", assetName);

            if (!matchingLines.empty()) {
                std::string updatedAssetName;
                std::string updatedAssetColour;
                std::string updatedAssetLocation;
                std::string updatedAssetDescription;
                std::string updatedAssetQuantity;
                std::string updatedAssetAssigned;
                std::string assigned;

                std::cout << "Enter the updated information:\n";

                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

                std::cout << "Enter the name of the Asset: ";
                std::getline(std::cin, updatedAssetName);
                std::cout << "Enter the colour of the Asset: ";
                std::getline(std::cin, updatedAssetColour);
                std::cout << "Enter where the Asset is being stored: ";
                std::getline(std::cin, updatedAssetLocation);
                std::cout << "Enter the description of the Asset: ";
                std::getline(std::cin, updatedAssetDescription);
                std::cout << "Enter the quantity of the Asset: ";
                std::getline(std::cin, updatedAssetQuantity);
                std::cout << "Is the file to be assigned? (yes/no): ";
                std::cin >> assigned;

                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

                if (assigned == "yes" && "YES" && "Yes") {
                    std::cout << "Who is it being assigned to?" << std::endl;
                    std::getline(std::cin, updatedAssetAssigned);
                } else if (assigned == "no" && "NO" && "No") {
                    std::cout << "Ok!" << std::endl;
                    updatedAssetAssigned = "Not Assigned.";
                } else {
                    std::cerr << "Please enter the appropriate answer." << std::endl;
                }

                Asset updatedAsset(updatedAssetName, updatedAssetColour, updatedAssetLocation,
                                    updatedAssetDescription, updatedAssetQuantity, updatedAssetAssigned);

                updateAssetInFile("Asset.csv", assetName, updatedAsset, logFileName);
                std::cout << "Asset updated successfully!\n";
            } else {
                std::cout << "Asset not found.\n";
            }
        } else if (userInput == "d" && "D") {
            std::cout << "Enter the name of the Asset to delete: ";
            std::string assetName;
            std::cin >> assetName;

            deleteAssetFromFile("Asset.csv", assetName, logFileName);
            std::cout << "Asset deleted successfully!\n";
        } else if (userInput == "s" && "S") {
            showAllAssetsFromFile("Asset.csv");

            logEntry(logFileName, "Show All", "N/A");
        } else if (userInput != "x" && "X") {
            std::cout << "Enter a valid response!\n";
        }
    } while (userInput != "x");

    return 0;
}
