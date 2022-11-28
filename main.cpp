#include <iostream>
#include "utils.h"
int main() {
    std::string str = file_to_string("data.txt");
    std::cout << str << std::endl;
}