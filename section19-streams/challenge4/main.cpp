#include <iostream>
#include <fstream>
#include <iomanip>
#include <string>

std::string read_file(const std::string filename);
void write_file(std::string filename);

int main(void) {
    std::ifstream poem_in {"romeoandjuliet"};
    if (!poem_in) return 1;

    std::ofstream poem_out {"romeoandjuliet_lines"};
    if (!poem_out) return 1;

    std::string in_line;
    size_t line_number {};

    while (std::getline(poem_in, in_line)) {
        ++line_number;
        poem_out << std::setw(6) << std::left 
            << std::to_string(line_number)+":" << in_line;
    }
    
    poem_in.close();
    poem_out.close();
    
    int value {};
    std::string input;
    std::cout << "Enter an integer: ";
    std::cin >> input;
    
    std::istringstream iss {input};
    if (iss >> value)
        std::cout << "ok"<< std::endl;
    else
        std::cerr << "invalid input" << std::endl;
  
    return 0;
}
