#include <iostream>
#include <fstream>

int main() {
    std::fstream in_file_fstream {"some_file.txt", std::ios::in};

    std::ifstream in_file_ifstream {"some_file.txt"};

    if (!in_file_ifstream) {
        std::cerr << "could not open file";
    }

    std::ifstream in_file_ifstream_nofilename;
    std::string filename;
    std::cin >> filename;

    in_file_ifstream_nofilename.open(filename);

    std::string line;
    while (!in_file_ifstream_nofilename.eof()) {
        std::getline(in_file_ifstream_nofilename, line);
        std::cout << line << std::endl;
    }

    in_file_fstream.close();
    in_file_ifstream.close();
    in_file_ifstream_nofilename.close();

    return 0;
}