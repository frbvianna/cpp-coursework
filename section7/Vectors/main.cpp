#include <iostream>
#include <vector>

using namespace std;

int main() {
//    vector <char> vowels;       // Não roda
//    vector <char> vowels (5);
    vector <char> vowels {'a', 'e', 'i', 'o', 'u'};

    cout << vowels.at(0) << endl;
    cout << vowels.at(8) << endl;
    
    return 0;
}