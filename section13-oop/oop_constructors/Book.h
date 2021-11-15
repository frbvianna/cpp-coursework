#ifndef __BOOK__H__
#define __BOOK__H__
#include <string>
#include <iostream>
class Book {
private:
    std::string name;
    std::string publisher;
    std::string theme;
    int total_pages {};
public:
    // Constructors
    Book() :
        Book("None", "None", "None", 0) {
            std::cout << "Using default constructor" << std::endl;
        }
    Book(std::string name_value) : 
        Book(name_value, "None", "None", 0) {
            std::cout << "Using constructor w/ custom Book name" << std::endl;
        }
    Book(std::string name_value, std::string publisher_value) :
        Book(name_value, publisher_value, "None", 0) {
            std::cout << "Using constructor w/ custom Book name and \
            Book publisher" << std::endl;
        }
    Book(std::string name_value, std::string publisher_value, 
        std::string theme_value ) :
        Book(name_value, publisher_value, theme_value, 0) {
            std::cout << "Using constructor w/ custom Book name and \
            Book publisher and Book theme" << std::endl;
        }
    Book(std::string name_value, std::string publisher_value,
        std::string theme_value, int total_pages_value)
        : name{name_value}, publisher{publisher_value},
        theme{theme_value}, total_pages{total_pages_value} {
                std::cout << "Using custom constructor" << std::endl;
        }

    // Copier
    Book(const Book &source) : 
        Book(source.name, source.publisher, source.theme, source.total_pages) {
            std::cout << "Using custom copier" << std::endl;
        }

    // Destructor
    ~Book() {
        std::cout << "Using custom destructor" << std::endl;
    }

    // Setter methods
    void set_name(std::string book_name) {name = book_name;};
    void set_publisher(std::string book_publisher) {publisher = book_publisher;};
    void set_theme(std::string book_theme) {theme = book_theme;};
    void set_total_pages(int page_num) {total_pages = page_num;};

    // Getter methods
    std::string get_name() {return name;};
    std::string get_publisher() {return publisher;};
    std::string get_theme() {return theme;};
    int get_total_pages() {return total_pages;};

    // Other methods
    void add_more_pages(int page_num);
};
#endif  //!__BOOK__H__
