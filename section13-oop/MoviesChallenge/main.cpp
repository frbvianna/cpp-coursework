#include <iostream>
#include <string>
#include "Movies.h"

void display_menu();
char get_choice();
bool handle_choice(const char&, Movies*);

int main() {
    Movies *movies {new Movies};

    char opt {};
    bool quit {false};
    
    do {
        display_menu();
        opt = get_choice();
        quit = handle_choice(opt, movies);

    } while (not quit);

    delete movies;

    std::cout << "Exiting movie collection..." << std::endl;

    return 0;
}

void display_menu() {
    const std::string h_bar (80, '=');
    std::cout << std::endl;
    std::cout << h_bar << std::endl;
    std::cout << "Movie Collection Menu" << std::endl;
    std::cout << h_bar << std::endl;
    std::cout << "[A]\tAdd a movie given its name, rating and times watched";
    std::cout << std::endl;
    std::cout << "[I]\tIncrement a movie watch count provided its name";
    std::cout << std::endl;
    std::cout << "[D]\tDisplay all movies in collection";
    std::cout << std::endl;
    std::cout << "[Q]\tQuit Movie Collection";
    std::cout << std::endl;
    std::cout << h_bar << std::endl;
    std::cout << std::endl;
}

char get_choice() {
    char opt {};
    std::cout << "Choose an option: ";
    std::cin >> opt;
    return opt;
}

bool handle_choice(const char &opt, Movies *movies) {
    switch (opt)
    {
    case 'A':
    case 'a': {
        std::string name;
        std::string rating;
        int times_watched {};

        std::cout << "What's the movie's name? ";
        std::cin >> name;

        std::cout << "Inform the movie rating: ";
        std::cin >> rating;
        
        std::cout << "How many times have you watched it? ";
        std::cin >> times_watched;

        std::cout << std::endl;

        movies->add_movie(name, rating, times_watched);
        break;
    }
    case 'I':
    case 'i': {
        std::string name;

        std::cout << "What's the movie's name? ";
        std::cin >> name;
        std::cout << std::endl;

        movies->increment_times_watched(name);
        break;
    }
    case 'D':
    case 'd': {
        movies->display_all_movies();
        break;
    }
    case 'Q':
    case 'q':
        return true;
    default: 
        std::cout << "Invalid option " << opt << std::endl;
    }
    return false;
}
