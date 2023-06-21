#include <iostream>
#include <commands.h>

void help() {
    std::cout << "--------------------------------------------------" << std::endl;
    std::cout << "*              Commands syntaxes                 *" << std::endl;
    std::cout << "--------------------------------------------------" << std::endl;
    std::cout << "- itemadd <item_id> <item_name> <item_quantity> <item_registration_date>: Add a new item" << std::endl;
    std::cout << "- itemslist: List all items" << std::endl;
    std::cout << "- help: Display help information" << std::endl;
    std::cout << "- exit: Exit the program" << std::endl;
    std::cout << "--------------------------------------------------" << std::endl;
    std::cout << "--------------------------------------------------" << std::endl;
    std::cout <<std::endl;
}
