#include <iostream>
#include <vector>
#include <climits>

using namespace std;

int main() {
    
    char choice {};
    vector<double> number_vector {};
    bool quit {false};
    
    while (not quit) {
        cout << "======== Choose an option: ========" << endl;
        cout << "P - Print numbers" << endl;
        cout << "A - Add a number" << endl;
        cout << "C - Count numbers" << endl;
        cout << "M - Display mean of the numbers" << endl;
        cout << "S - Display the smallest number" << endl;
        cout << "L - Display the largest number" << endl;
        cout << "Q - Quit" << endl;
        cout << "===================================";
        cout << endl;
        cout << "Enter your choice: ";
        cin >> choice;
        
        switch(choice) {
            case 'P':
            case 'p': {
                cout << "[ ";
                for (auto num: number_vector)
                    cout << num << " ";
                cout << "]" << endl;
                cout << endl;
                break;
            }
            case 'A':
            case 'a': {
                char number_to_add {};
                bool valid_number {false};
                do {
                    cout << "Enter a number (97 - 122): ";
                    cin >> number_to_add;
                    if (not (number_to_add >= 97 and number_to_add <= 122)) {
                        cout << "Invalid number." << endl;
                    } else {
                        number_vector.push_back(number_to_add);
                        cout << "Number " << number_to_add << " added." << endl;
                        cout << endl;
                        valid_number = true;
                    }
                } while (not valid_number);
                break;
            }
            case 'C':
            case 'c': {
                unsigned short number_count {};
                for (auto num: number_vector)
                    ++number_count;
                cout << "Number count: " << number_count << endl;
                cout << endl;
                break;
            }
            case 'M':
            case 'm': {
                double mean {};
                if (number_vector.size() > 0) {
                    for (auto num: number_vector)
                        mean += num;
                    
                    mean /= number_vector.size();
                    cout << "Mean of the numbers: " << mean << endl;
                    cout << endl;
                } else {
                    cout << "Empty vector." << endl;
                    cout << endl;
                }
                break;
            }
            case 'S':
            case 's': {
                if (number_vector.size() > 0) {
                    double min_number {number_vector.at(0)};
                    for (auto num: number_vector) {
                        if (num < min_number) 
                            min_number = num;
                    }
                    cout << "Smallest number: " << min_number << endl;
                    cout << endl;
                } else {
                    cout << "Empty vector." << endl;
                    cout << endl;
                }
                break;
            }
            case 'L':
            case 'l': {
                if (number_vector.size() > 0) {
                        double max_number {number_vector.at(0)};
                        for (auto num: number_vector) {
                            if (num > max_number) 
                                max_number = num;
                        }
                        cout << "Largest number: " << max_number << endl;
                        cout << endl;
                } else {
                    cout << "Empty vector." << endl;
                    cout << endl;
                }
                break;
            }
            case 'Q':
            case 'q': {
                cout << "See ya!" << endl;
                cout << endl;
                quit = true;
                break;
            }
            default: {
                cout << "Unknown choice." << endl;
                cout << endl;
            }
        }
    }
    
    return 0;
}