#include <iostream>
#include <fstream>
#include <string>
#include <limits>
#include <filesystem>
#include <ctime> 

namespace fs = std::filesystem;

// Function to write log entry
void logActivity(const std::string& activity) {
    std::ofstream logFile("activity_log.txt", std::ios::app);
    if (logFile.is_open()) {
        // Get current timestamp
        std::time_t t = std::time(nullptr);
        std::tm* timestamp = std::localtime(&t);

        // Write timestamp and activity to the log file
        logFile << "[" << std::put_time(timestamp, "%Y-%m-%d %H:%M:%S") << "] " << activity << std::endl;

        logFile.close();
    } else {
        std::cerr << "Error opening the log file for writing." << std::endl;
    }
}

void createFile() {
    std::string fileName;
    std::cout << "Enter the name of the file you want to create: ";
    std::cin >> fileName;
    fileName += ".txt";

    std::ofstream output(fileName);
    std::cout << "File " << fileName << " created\n";

    if (output.is_open()) {
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // Clear the input buffer
        std::string message;
        std::cout << "Enter the information you want to keep: ";
        std::getline(std::cin, message);
        output << message;
        output.close();
        std::cout << "Information stored!\n";

        // Log the activity
        logActivity("Created file: " + fileName);
    }
}

void readFile() {
    std::string fileName;
    std::cout << "Enter the name of the file you want to read from: ";
    std::cin >> fileName;
    fileName += ".txt";

    std::string line;
    std::ifstream input(fileName);
    if (input.is_open()) {
        std::cout << "File found\n";
        while (std::getline(input, line)) {
            std::cout << line << std::endl;
        }

        // Log the activity
        logActivity("Read from file: " + fileName);
    } else {
        std::cout << "File not found\n";
    }
}

void updateFile() {
    std::string fileName;
    std::cout << "Enter the name of the file you want to update: ";
    std::cin >> fileName;
    fileName += ".txt";

    std::string message;
    std::ifstream inputFile(fileName);
    if (inputFile.is_open()) {
        std::cout << "File found\n";
        std::ofstream output(fileName, std::ios::app); // Open the file in append mode
        if (output.is_open()) {
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            std::cout << "\n What do you want to update in this file: ";
            std::getline(std::cin, message);
            output << "\n" << message;
            output.close();
            std::cout << "File " << fileName << " has been updated\n";

            // Log the activity
            logActivity("Updated file: " + fileName);
        } else {
            std::cout << "Unable to open the file for updating.\n";
        }
    } else {
        std::cout << "File not found. Create a new file.\n";
    }
}

void deleteFile() {
    std::string fileName;
    std::cout << "Enter the name of the file you want to delete: ";
    std::cin >> fileName;
    fileName += ".txt";

    int result = std::remove(fileName.c_str());
    if (result == 0) {
        std::cout << "File " << fileName << " has been deleted\n";

        // Log the activity
        logActivity("Deleted file: " + fileName);
    } else {
        std::cout << "Error deleting the file\n";
    }
}

void showAllFiles() {
    std::cout << "=== All .txt Files and Information ===\n";
    for (const auto& entry : fs::directory_iterator(".")) {
        if (entry.is_regular_file() && entry.path().extension() == ".txt") {
            std::cout << "File: " << entry.path().filename() << std::endl;
            std::ifstream input(entry.path());
            std::string line;
            while (std::getline(input, line)) {
                std::cout << "Information: " << line << std::endl;
            }
            std::cout << "===============================\n";
        }
    }

    // Log the activity
    logActivity("Viewed all files");
}

bool createFolderInSameDirectory() {
    std::string archived = "Archived";
    try {
        // Get the current working directory
        fs::path currentPath = fs::current_path();

 
        fs::path folderPath = currentPath / archived;

        // Check if the folder already exists
        if (!fs::exists(folderPath)) {
            // Create the folder
            fs::create_directory(folderPath);
            //std::cout << "Folder created successfully: " << folderPath << std::endl;
            return true;
        } else {
            //std::cerr << "Folder already exists: " << folderPath << std::endl;
            return true;
        }
    } catch (const std::exception& e) {
        //std::cerr << "Error creating folder: " << e.what() << std::endl;
        return false;
    }
}

void archiveFile() {
    std::string fileName;
    std::cout << "Enter the name of the file you want to archive: ";
    std::cin >> fileName;
    fileName += ".txt";

    // Check if the file exists
    if (fs::exists(fileName)) {
        // Create the "Archived" folder if it doesn't exist
        if (createFolderInSameDirectory()) {
            // Construct the destination path in the "Archived" folder
            fs::path destinationPath = fs::current_path() / "Archived" / fileName;

            // Move the file to the "Archived" folder
            fs::rename(fileName, destinationPath);

            std::cout << "File " << fileName << " archived successfully to: " << destinationPath << std::endl;

            // Log the activity
            logActivity("Archived file: " + fileName);
        } else {
            std::cerr << "Error creating the 'Archived' folder.\n";
        }
    } else {
        std::cout << "File not found\n";
    }
}

void closeApplication() {
    std::cout << "Closing Application.......\n";

    // Log the activity
    logActivity("Closed application");
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
            createFile();
        } else if (userInput == "r") {
            readFile();
        } else if (userInput == "u") {
            updateFile();
        } else if (userInput == "d") {
            deleteFile();
        } else if (userInput == "s") {
            showAllFiles();
        } 
        else if(userInput == "a"){
            createFolderInSameDirectory();
            archiveFile();
        }
        else if (userInput != "x") {
            std::cout << "Enter a valid response!\n";
        }
    } while (userInput != "x");

    closeApplication();

    return 0;
}
