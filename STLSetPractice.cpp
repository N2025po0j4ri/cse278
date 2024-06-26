

#include <iostream>
#include <set>
using namespace std;
 /*
int main()
{
    set<int> s1; // default ascending order
    //set<int, greater<int> > s1; // set descending order
    s1.insert(10);
    s1.insert(5);
    s1.insert(12);
    s1.insert(4);
    s1.insert(12);

    for (auto i : s1) {
        cout << i << ' ';
    }
    return 0;
}
*/
/*
 Sets are a type of associative container in which each element has to be unique because the value of the element identifies it. The values are stored in a specific sorted order i.e. either ascending or descending.

The std::set class is the part of C++ Standard Template Library (STL) and it is defined inside the <set> header file.

Syntax:

std::set <data_type> set_name;
Datatype: Set can take any data type depending on the values, e.g. int, char, float, etc.

Ex:
set<int> val; // defining an empty set
set<int> val = {6, 10, 5, 1}; // defining a set with values
*/


 
int main()
{
   // std::set<char> a; // default ascending order
    set<char, greater<char> > a; // set descending order
    a.insert('G');
    a.insert('F');
    a.insert('G');
    a.insert('A');
    a.insert('G');
    a.insert('B');


    for (auto& str : a) {
        std::cout << str << ' ';
    }
    std::cout << '\n';
    return 0;
} 

/*
 Time complexity: O(N) // N is the size of the set.

Auxiliary Space: O(N)

The reason it printed only F and G is that set does not take multiple same values it only accepts a unique value. We can use Multiset if we want to store multiple same values.

Set Sorted in Descending Order
By default, the std::set is sorted in ascending order. However, we have the option to change the sorting order by using the following syntax.

std::set <data_type, greater<data_type>> set_name;


*/
