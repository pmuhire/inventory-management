#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <algorithm>
#include <inventory.h>
#include <commands.h>

int main() {
    std::string command;

    std::cout << "--------------------------------------------------" << std::endl;
    std::cout << "*              Inventory Management System       *" << std::endl;
    std::cout << "--------------------------------------------------" << std::endl;
    help();

    while (true) {
        std::cout << "\nEnter a command: ";
        std::cin >> command;

        // Convert the command to lowercase
        std::transform(command.begin(), command.end(), command.begin(), ::tolower);

        if (command == "itemadd") {
            std::string item_id, item_name, item_quantity, item_registration_date;
            std::cin >> item_id >> item_name >> item_quantity >> item_registration_date;
            addItem(item_id, item_name, item_quantity, item_registration_date);
        } else if (command == "itemslist") {
            listItems();
        } else if (command == "help") {
            help();
        } else if (command == "exit") {
            break;
        } else {
            std::cout << "--------------------------------------------------" << std::endl;
            std::cout << "*        Invalid command. Please try again.       *" << std::endl;
            std::cout << "--------------------------------------------------" << std::endl;
        }
    }

    return 0;
}
