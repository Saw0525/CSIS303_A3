#include <iostream>
#include <vector>
#include "question2.h"
using namespace std;


int main() {
    vector<int> items = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    int target = 10;
    
    cout << "Elements in the vector: ", display(items);
    
    int result = find_last_occurrence(items, target);
    if (result != -1) 
        cout << "Last occurrence of " << target << " is at index: " << result << endl;
    else 
        cout << "Target not found" << endl;

//my .exe file was closing immediately after the program execution. So, I added this code to keep the console window open.
    int exitCode;
    cout << " " << endl;
    cout << "Press 0 to Exit from the program: ";
    cin >> exitCode;
    while (exitCode != 0) {
        cout << "Invalid input. Please press 0 to close the program: ";
        cin >> exitCode;
    }
    return 0;

    
}
