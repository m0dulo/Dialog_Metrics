#ifndef PRINT_H
#define PRINT_H

#include <string>
#include <vector>
#include <iostream>

using namespace std;

void print(const vector<string> &words) {
    for (const string &w : words) {
        cout << w << " ";
    }
    cout << endl;
}


#endif // PRINT_H
