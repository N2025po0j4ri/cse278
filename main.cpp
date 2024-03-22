// Purpose:
// Copyright
// Trails notes
// Attempt #1 :
#include <iostream>
#include <fstream>
#include <vector>
#include <string>

using namespace std;

void nurses(vector<string>& nurseName, vector<string>& weekShift, string day) {
    string shift = "";
    string nurse = "";
    int count = 0;
    for (int i = 0; i < weekShift.size(); ++i) {
        string shift = weekShift.at(i);
        if (day == "SATURDAY") {
            if (shift[0] == '1') {
                cout << nurseName.at(i) << endl;
                count++;
            }
        }
        else if (day == "SUNDAY") {
            if (shift[6] == '1') {
                cout << nurseName.at(i) << endl;
                count++;
            }
        }
        else if (day == "MONDAY") {
            if (shift[5] == '1') {
                cout << nurseName.at(i) << endl;
                count++;
            }
        }
        else if (day == "TUESDAY") {
            if (shift[4] == '1') {
                cout << nurseName.at(i) << endl;
                count++;
            }
        }
        else if (day == "WEDNESDAY") {
            if (shift[3] == '1') {
                cout << nurseName.at(i) << endl;
                count++;
            }
        }
        else if (day == "THURSDAY") {
            if (shift[2] == '1') {
                cout << nurseName.at(i) << endl;
                count++;
            }
        }
        else if (day == "FRIDAY") {
            if (shift[1] == '1') {
                cout << nurseName.at(i) << endl;
                count++;
            }
        }
    }
    cout << "---- Nurses ----" << endl;
    cout << count << " nurse(s) work(s) on " << day;
}

int main() {

    ifstream inFS;     // Input file stream
    vector<string> nurseName;
    vector<string> weekShift;
    //string fileName;
    
    cout << ">> Enter the file name with its extension: ";
    // cin >> fileName;
    
    cout << endl;
    inFS.open("NurseShift3.txt");
    if (!inFS.is_open()) {
        cout << "!!! Could not open the input file : " << "NurseShift3.txt" << endl;
        return 1; // 1 indicates error
    }
    else {
        string name;
        string shift;
        while (inFS >> name) {
            
                nurseName.push_back(name);
                inFS >> shift;
                weekShift.push_back(shift);
        }
        string day = "";
        cout << "\n----------------------------------" << endl;
        cout << "The Nurse Shift Query Application" << endl;
        cout << "----------------------------------" << endl;
        do {
            
            cout << ">> Enter a day of the week(to quit, type exit) : " << endl;
            //getline(cin, day);
            cin >> day;
            for (int i = 0; i < day.length(); i++) {
                if (day[i] >= 'a' && day[i] <= 'z') {
                    day[i] -= 32;
                }
            }
            if (day == "MONDAY" || day == "TUESDAY" || day == "WEDNESDAY" 
                      || day == "THURSDAY" || day == "FRIDAY" || day == "SATURDAY" 
                      || day == "SUNDAY") {
                nurses(nurseName, weekShift, day);
            }
          
        } while (day != "EXIT");
    }

    inFS.close();

    return 0;
}