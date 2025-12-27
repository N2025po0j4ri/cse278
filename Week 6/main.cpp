/*
* Helps user find information about each actor/actress in film database.
* It connects to a MySQL database, executes a SELECT SQL statement and displays a
single result.
* Author: N. Poojari 2023
*/
#define MYSQLPP_MYSQL_HEADERS_BURIED
#include <mysql++/mysql++.h>
#include <string>
#include <cstring>
#include <iostream>
int main(int argc, char* argv[]) {
    // Connect to database with: database, server, userID, password
    mysqlpp::Connection myDB;
    if (myDB.connect("cse278TA2022", "localhost", "cse278TA2022",
    "s3ltzerWater")) {
    // Create a query object
    mysqlpp::Query query = myDB.query();
        // Displays query application menu
        std::string menuchoice;
        do {
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
            std::cin >> menuchoice;
            if (menuchoice =="A") {         // Choice A
                std::cout << "Enter a letter between A and Z.";
                std::string movietitle;
                std::cin >> movietitle;
                query << "SELECT title, rating, release_year "
                    << "FROM film "
                    << "WHERE title LIKE \"" << movietitle << "%\""
                    << "ORDER BY title;";
                query.parse();
                    mysqlpp::StoreQueryResult result = query.store();
                    // Always check for errors for sql statement
                        if(result) {
                            std::cout << "title\trating\trelease_year" << std::endl;
                            for (const auto& row : result) {
                                for(const auto& col : row) {
                                    std::cout << col << "\t";
                                }
                            std::cout << std::endl;
                            }

                        } else {
                        std::cerr << "Query failed: " << query.error() << std::endl;
                        }
                } else if (menuchoice == "B") {         // Choice B
                
                std::cout << "Select film title for which the rental ";
                std::cout << "rate is minimum and rated PG-13'. " << std::endl;
                //std::cout << "Enter rating G, PG, PG-13, R, NC-17: " << std::endl;
               // std::string movierating;
                //std::cin >> movierating;
                query << "SELECT title, MIN(rental_rate) "
                    << "FROM film; ";
                query.parse();
                    mysqlpp::StoreQueryResult result = query.store();
                    // Always check for errors for sql statement
                        if(result) {
                           std::cout << "title\tMIN(rental_rate)\trating" << std::endl;
                          //std::cout << "title\tMIN(rental_rate)\trelease_year" << std::endl;
                            for (const auto& row : result) {
                                for(const auto& col : row) {
                                    std::cout << col << "\t";
                                }
                            std::cout << std::endl;
                            }
                        } else {
                        std::cerr << "Query failed: " << query.error() << std::endl;
                        }
                }
            }while( !(menuchoice == "C"));
    } else {
    std::cerr << "Connection failed: " << myDB.error() << std::endl;
    return 1;
    }
return 0;

}

