#ifndef INVENTORY_H
#define INVENTORY_H

#include <string>
#include <vector>

struct Item {
    std::string id;
    std::string name;
    std::string quantity;
    std::string registration_date;
};
bool isItemExist(const std::string& item_id);
std::vector<std::string> split(const std::string& str, char delimiter);
bool compareItems(const Item& item1, const Item& item2);
void createEmptyFile(const std::string& filename);
void addItem(std::string& item_id, std::string& item_name, const std::string& item_quantity, const std::string& item_registration_date);
void listItems();

#endif  // INVENTORY_H
