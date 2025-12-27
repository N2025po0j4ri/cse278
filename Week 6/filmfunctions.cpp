
#include <string>
#include <cstring>
#include <iostream>

#include "./film.h"
void menu() {
            std::cout << "-----------------------------------------" << std::endl;
            std::cout << "A Query Application for Film Database"<< std::endl;
            std::cout << std::endl;
            std::cout << "A. Find the film that ";
            std::cout << "starts with a letter."<< std::endl;
            std::cout << "B. Lookup film for which ";
            std::cout << "the rental cost is minimum."<< std::endl;
            std::cout << "C. Exit"<< std::endl;
            std::cout << "-----------------------------------------" << std::endl;
            std::cout << "Enter a choice: " ;
}