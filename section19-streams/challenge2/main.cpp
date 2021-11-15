#include <iostream>
#include <string>
#include <fstream>
#include <iomanip>
#include <vector>
#include <numeric>

#define RESULTS "ABCDE"

int main(void) {

    std::ifstream grades_file;
    std::string grades_filename;

    std::cout << "Inform the grades filename: ";
    std::cin >> grades_filename;
    std::cout << std::endl;

    grades_file.open(grades_filename);
    if (!grades_file) {
        std::cerr << "Grades file not opened." << std::endl;
        exit(1);
    }

    std::cout << std::setw(15) << std::left << "Student" << "Score" << std::endl;
    std::cout << "--------------------" << std::endl;
    std::string name;
    std::string answers;
    std::vector<short> grades;
    while(grades_file >> answers >> name) {
        short grade {0};
        for (size_t i {0}; i < answers.size(); ++i) {
            if (answers[i] == RESULTS[i]) {
                grade++;
            }
        }
        grades.push_back(grade);
        std::cout << std::setw(15) << std::left << name << grade << "/5" << std::endl;
    }
    std::cout << "--------------------" << std::endl;
    double avg_grade {std::accumulate(grades.begin(), grades.end(), 0.0)/grades.size()};
    std::cout << std::setw(15) << std::left << "Average score" << avg_grade << "/5" << std::endl;

    grades_file.close();
    return 0;
}