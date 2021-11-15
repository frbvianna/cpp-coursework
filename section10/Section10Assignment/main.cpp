#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main()
{
    string inputStr;
    
    cout << "Enter a string with no spaces: ";
    getline(cin, inputStr);
    cout << endl;
    
    string leftStr;
    string rightStr;

    size_t spaceNumber {};
    
    for (size_t i {0}; i < inputStr.length(); ++i) 
    {
        spaceNumber = inputStr.length()-i-1;
        string spaceStr (spaceNumber, ' ');
        
        leftStr = leftStr + inputStr.at(i);
        
        cout << spaceStr << leftStr << rightStr << endl;
        
        rightStr = inputStr.at(i) + rightStr;
    }

    cout << endl;
    return 0;
}
