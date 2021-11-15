#include <iostream>
#include <cstring>
#include <string>
#include <vector>
#include <cstdlib>

using namespace std;

int main() {
    
    string alphabet {"ABCDEFGHIJKLMNOPQRSTUVXWYZabcdefghijklmnopqrstuvxwyz1234567890 "};
    string encrypted_alphabet {alphabet};
    string message;
    string encrypted_message;
    string decrypted_message;
    char aux {};
    
    for (unsigned short i {0}; i < encrypted_alphabet.length(); ++i) {
        unsigned short random_index {rand() % encrypted_alphabet.length()};
        aux = encrypted_alphabet.at(i); 
        encrypted_alphabet.at(i) = encrypted_alphabet.at(random_index);
        encrypted_alphabet.at(random_index) = aux;
    }

    cout << "Enter your message: ";
    getline(cin, message);
    cout << endl;
    
    cout << "Encrypting message..." << endl;
    cout << endl;
    
    for (unsigned short i {0}; i < message.length(); ++i) {
        if (alphabet.find(message.at(i)) == string::npos) {
            encrypted_message += message.at(i);
        } else
            encrypted_message += encrypted_alphabet.at(alphabet.find(message.at(i)));
    }
    
    cout << "Encrypted message: " << encrypted_message << endl;
    cout << endl;
    
    cout << "Decrypting message..." << endl;
    cout << endl;
    
    for (unsigned short i {0}; i < encrypted_message.length(); ++i) {
        if (encrypted_alphabet.find(encrypted_message.at(i)) == string::npos) {
            decrypted_message += encrypted_message.at(i);
        } else
            decrypted_message += alphabet.at(encrypted_alphabet.find(encrypted_message.at(i)));
    }
    
    cout << "Decrypted message: " << decrypted_message << endl;
    cout << endl;
    
    return 0;
}