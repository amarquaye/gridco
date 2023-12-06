#include <iostream>
#include <string>
#include <fstream>

class Asset {
public:
    Asset(const std::string& assetName, const std::string& assetExpiryDate, const std::string& location, const std::string& description, const std::string& quantity){
        m_assetName = assetName;
        m_assetExpiryDate = assetExpiryDate;
        m_location = location;
        m_description = description;
        m_quantity = quantity;
    }

    void readAsset(){

    }

    void updateAsset(){

    }

    void deleteAsset(){

    }

    void displayAssets(){
        std::cout << "Asset Name: " << m_assetName << std::endl;
        std::cout << "Asset Location: " << m_location << std::endl;
        std::cout << "Asset Expiry Date: " << m_assetExpiryDate << std::endl;
        std::cout << "Asset Description: " << m_description << std::endl;
        std::cout << "Asset Quantity: " << m_quantity << std::endl;
    }

private:
    std::string m_assetName;
    std::string m_assetExpiryDate;
    std::string m_location;
    std::string m_description;
    std::string m_quantity;
};


Asset createAsset(){
    std::string assetName;
    std::string expDate;
    std::string location;
    std::string description;
    std::string quantity; 

    std::cout << "Enter the name of the drug you want to add: " << std::endl;
    std::getline(std::cin, assetName);
    std::cout << "Enter the end date of the drug: " << std::endl;
    std::cin >> expDate;
    std::cin.ignore();
    std::cout << "Enter where the drug is being stored: " << std::endl;
    std::getline(std::cin, location);
    std::cout << "Enter the description of the drug: " << std::endl;
    std::getline(std::cin , description);
    std::cout << "Enter the quantity of the drug being stored: " << std::endl;
    std::cin >> quantity;

    std::ofstream output("ASset.csv");

    return Asset(assetName, expDate, location, description, quantity);    
}

int main(){
   Asset userAsset = createAsset();
   userAsset.displayAssets();
} 