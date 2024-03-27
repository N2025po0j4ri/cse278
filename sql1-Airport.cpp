/*
* It connects to a MySQL database, executes a SELECT SQL statement and displays a
single result.
* Author: N. Poojari 2023
*/
#define MYSQLPP_MYSQL_HEADERS_BURIED
#include <mysql++/mysql++.h>
#include <string>
#include <iostream>
int main(int argc, char* argv[]) {
// Connect to database with: database, server, userID, password
mysqlpp::Connection myDB;
if (myDB.connect("cse278TA2022", "localhost", "cse278TA2022",
"s3ltzerWater")) {
// Create a query object
mysqlpp::Query query = myDB.query();
// Add a query statement to the query object
query << "SELECT name, code, city, country "
<< "FROM Airports "
<< "WHERE code LIKE \"AT%\"";
query.parse();
mysqlpp::StoreQueryResult result = query.store();
// Always check for errors for sql statement
if(result) {
std::cout << std::left <<std::setw(70) << "Name"
<< std::setw(5)<< "Code"
<< std::setw(30)<<"City"
<< std::setw(20)<<"Country"
<< std::endl;
std::string line(125,'-');
std::cout << line <<std::endl;
for (const auto & row : result) {
std::cout <<std::left<<std::setw(70)<< row[0].c_str()
<< std::setw(5) << row[1]
<< std::setw(30) << row[2].c_str()
<<std::setw(20)<<row[3].c_str()
<< std::endl;
} // done printing results
}
else {
std::cerr << "Query failed: " << query.error() << std::endl;
}
} else {
std::cerr << "Connection failed: " << myDB.error() << std::endl;
return 1;
}
return 0;
}
