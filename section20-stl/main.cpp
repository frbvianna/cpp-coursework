#include <iostream>
#include <array>
#include <map>
#include <string>
#include <algorithm>

int main(void) 
{
    std::array<int, 10> arr;

    std::map<std::string, std::pair<std::string, int>> person;
    person["Felipe"] = std::pair<std::string, int>{"Idade", 22};
    person["Alguem"] = std::pair<std::string, int>{"Idade", 53};

    std::cout << person["Felipe"].second << std::endl;

    auto p_it = person.begin();
    while ( p_it != person.end() ) 
    {
        std::cout << p_it->second.second << std::endl;
        p_it++;
    }

    return EXIT_SUCCESS;
}