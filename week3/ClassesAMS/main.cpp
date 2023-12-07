#include <iostream>
#include <string>
#include <fstream>
#include <limits>

class Asset {
public:
    Asset(const std::string& assetName, const std::string& assetEntryDate, const std::string& location,
          const std::string& description, const std::string& quantity, const std::string& assetAssignment)
        : m_assetName(assetName), m_assetEntryDate(assetEntryDate), m_location(location),
          m_description(description), m_quantity(quantity), m_assetAssignment(assetAssignment) {}

    void readAsset() {
        // Implement the function if needed
    }

    void updateAsset() {
        // Implement the function if needed
    }

    void deleteAsset() {
        // Implement the function if needed
    }

    void displayAssets() {
        std::cout << "Asset Name: " << m_assetName << std::endl;
        std::cout << "Asset Location: " << m_location << std::endl;
        std::cout << "Asset Expiry Date: " << m_assetEntryDate << std::endl;
        std::cout << "Asset Description: " << m_description << std::endl;
        std::cout << "Asset Quantity: " << m_quantity << std::endl;
        std::cout << "Assigned to: " << m_assetAssignment << std::endl;
        // Add display for asset assignment if needed
    }

private:
    std::string m_assetName;
    std::string m_assetEntryDate;
    std::string m_location;
    std::string m_description;
    std::string m_quantity;
    std::string m_assetAssignment;
};

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
    std::cout << "Enter the end date of the drug: " << std::endl;
    std::cin >> entryDate;
    std::cin.ignore();
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

    std::ofstream output("Asset.txt", std::ios::app);
    if (output.is_open()) {
        output << "Asset Name: " << assetName << std::endl;
        output << "Asset Entry Date: " << entryDate << std::endl;
        output << "Asset Location: " << location << std::endl;
        output << "Asset Description: " << description << std::endl;
        output << "Asset is Assigned to: " << assetAssignment << std::endl;
        output << std::endl;
        output.close();
        std::cout << "Information stored!\n";
    }
    return Asset(assetName, entryDate, location, description, quantity, assetAssignment);
}

int main() {
    Asset userAsset = createAsset();
    userAsset.displayAssets();

    return 0;
}
