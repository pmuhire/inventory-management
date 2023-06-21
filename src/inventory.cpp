#include <iostream>
#include <fstream>
#include <sstream>
#include <algorithm>
#include <inventory.h>
#include <iomanip>

std::vector<std::string> split(const std::string &str, char delimiter)
{
    std::vector<std::string> tokens;
    std::string token;
    std::istringstream tokenStream(str);
    while (getline(tokenStream, token, delimiter))
    {
        tokens.push_back(token);
    }
    return tokens;
}
bool isItemExist(const std::string &item_id, const std::string &item_name)
{
    std::ifstream inventoryFile("inventory.csv");
    if (!inventoryFile)
    {
        std::cerr << "Error opening file." << std::endl;
        return false;
    }

    std::string line;
    while (std::getline(inventoryFile, line))
    {
        std::stringstream ss(line);
        std::string currentItemId;
        std::string currentItemName;

        // Extract the item ID and item name from the line
        std::getline(ss, currentItemId, ',');
        std::getline(ss, currentItemName, ',');

        // Trim leading and trailing whitespaces from the extracted values
        currentItemId.erase(currentItemId.find_last_not_of(" \n\r\t") + 1);
        currentItemName.erase(currentItemName.find_last_not_of(" \n\r\t") + 1);

        // Check if either item ID or item name matches
        if (currentItemId == item_id || currentItemName == item_name)
        {
            inventoryFile.close();
            return true;
        }
    }

    inventoryFile.close();
    return false;
}

bool compareItems(const Item &item1, const Item &item2)
{
    return item1.name < item2.name;
}

void createEmptyFile(const std::string &filename)
{
    std::ofstream file(filename);
    if (!file)
    {
        std::cerr << "Error creating file: " << filename << std::endl;
        return;
    }
    file.close();
}

void addItem(std::string &item_id, std::string &item_name, const std::string &item_quantity, const std::string &item_registration_date)
{
    // Convert the item_id and item_name to lowercase
    std::transform(item_id.begin(), item_id.end(), item_id.begin(), ::tolower);
    std::transform(item_name.begin(), item_name.end(), item_name.begin(), ::tolower);

    // CHECK IF ITEM EXIST
    if (isItemExist(item_id, item_name))
    {
        std::cout << "Item with either ID: " << item_id << " or Name: " << item_name << " already exists." << std::endl;
        return;
    }

    std::ofstream inventoryFile("inventory.csv", std::ios::app);
    if (!inventoryFile)
    {
        std::cerr << "Error opening file." << std::endl;
        return;
    }

    inventoryFile << item_id << ',' << item_name << ',' << item_quantity << ',' << item_registration_date << std::endl;

    inventoryFile.close();

    std::cout << "Item added successfully!" << std::endl;
}

void listItems()
{
    std::ifstream inventoryFile("inventory.csv");
    if (!inventoryFile)
    {
        createEmptyFile("inventory.csv");

        inventoryFile.open("inventory.csv");
        if (!inventoryFile)
        {
            std::cerr << "Error opening file." << std::endl;
            return;
        }
    }

    std::string line;
    std::vector<Item> items;

    // Read items from the file into the vector
    while (getline(inventoryFile, line))
    {
        std::vector<std::string> tokens = split(line, ',');
        if (tokens.size() == 4)
        {
            Item item;
            item.id = tokens[0];
            item.name = tokens[1];
            item.quantity = tokens[2];
            item.registration_date = tokens[3];
            items.push_back(item);
        }
    }

    inventoryFile.close();

    if (items.empty())
    {
        std::cout << "The inventory is empty." << std::endl;
        return;
    }

    // Sort the items alphabetically by name
    std::sort(items.begin(), items.end(), compareItems);

    // Display the sorted items
    for (const auto &item : items)
    {
        std::cout << std::setw(5) << "Item ID: "<< std::setw(5)  << item.id
              << std::setw(20) << "Item Name: "<< std::setw(5)  << item.name
              << std::setw(12) << "Quantity: " << std::setw(5) << item.quantity
              << std::setw(15) << "Reg Date: " << item.registration_date << std::endl;
    }
}