#ifndef __MOVIES__H__
#define __MOVIES__H__
#include "Movie.h"
#include <iostream>
#include <vector>
#include <string>

class Movies {
private:
    std::vector<Movie> movies;
public:
    // Constructors
    Movies();
    Movies(std::vector<Movie>);

    // Copier
    Movies(const Movies&);

    // Destructor
    ~Movies();

    // Getters
    std::vector<Movie> get_movies() const;

    // Setters
    void set_movies(std::vector<Movie>);

    // Add new movie to the collection
    void add_movie(std::string name, std::string rating, 
                    int times_watched);

    // Increment watch count for a movie
    void increment_times_watched(const std::string&);

    // Display all movies in collection
    void display_all_movies() const;
};

#endif  //!__MOVIES__H__