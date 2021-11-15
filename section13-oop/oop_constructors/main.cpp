#include "Book.h"
#include <iostream>
#include <string>
#include <vector>

int main() {
    Book *my_book {new Book {"None", "Personal", "ZH"}};
    Book another_book;

    my_book->set_name("Diary");
    std::cout << my_book->get_name() << std::endl;
    std::cout << my_book->get_publisher() << std::endl;
    std::cout << my_book->get_total_pages() << std::endl;
    my_book->set_total_pages(960);

    std::cout << my_book->get_total_pages() << std::endl;

    my_book->add_more_pages(40);

    std::cout << my_book->get_total_pages() << std::endl;

    delete my_book;

    Book some_book {"Book's name"};

    std::cout << some_book.get_name() << std::endl;
    std::cout << some_book.get_publisher() << std::endl;
    std::cout << some_book.get_total_pages() << std::endl;

    Book yet_another_book {some_book};

    std::cout << yet_another_book.get_name() << std::endl;

    yet_another_book.set_publisher("New publisher");

    std::cout << some_book.get_publisher() << std::endl;

    Book *new_ptr_book {my_book};

    // will produce error -> my_book references a deleted (null) object
    std::cout << new_ptr_book->get_publisher() << std::endl;
}