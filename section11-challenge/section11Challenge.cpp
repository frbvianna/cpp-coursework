#include "section11Challenge.h"

int main() {
    
    char choice {};
    vector<double> number_vector {};
    bool quit {false};
    
    playing_with_number_vectors(choice, number_vector, quit);

    return 0;
}

/*
 * Asks for user choices and builds a vector of numbers interactively, thus adding new numbers, printing them out, 
 * finding the smallest or largest of them, counting how many numbers there are, etc.
 */
void playing_with_number_vectors(char &option, vector<double> &vector_of_numbers, bool quit) {
    do {
        display_options();
        option = input_choice();
        quit = execute_chosen(option, vector_of_numbers);
    } while (not quit);

    return;
}

/*
 * Displays options menu to the user.
 */
void display_options() {
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
}

/*
 * Asks the user to input a character choice.
 */
char input_choice() {
    char choice {};
    cout << "Enter your choice: ";
    cin >> choice;
    return choice;
}

/*
 * Executes whatever option was chosen.
 */
bool execute_chosen(char choice, vector<double> &number_vector) {
    /*
     * Switch statement to parse options chosen.
     */
    switch(choice) {
        /*
         * Option to print the numbers in vector.
         */
        case 'P':
        case 'p': {
            cout << "[ ";
            for (auto num: number_vector)
                cout << num << " ";
            cout << "]" << endl;
            cout << endl;
            break;
        }
        /*
         * Option to add numbers to vector.
         */
        case 'A':
        case 'a': {
            double number_to_add {};
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
        /*
         * Option to count numbers in vector.
         */
        case 'C':
        case 'c': {
            unsigned short number_count {};
            for (auto num: number_vector)
                ++number_count;
            cout << "Number count: " << number_count << endl;
            cout << endl;
            break;
        }
        /*
         * Option to find mean of the numbers in vector.
         */
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
        /*
         * Option to find the smallest number in vector.
         */
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
        /*
         * Option to find the largest number in vector.
         */
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
        /*
         * Option to quit the program.
         */
        case 'Q':
        case 'q': {
            cout << "See ya!" << endl;
            cout << endl;
            return true;
        }
        /*
         * Default option for other invalid choices.
         */
        default: {
            cout << "Unknown choice." << endl;
            cout << endl;
        }
    }
    return false;
}