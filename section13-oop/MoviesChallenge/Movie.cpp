#include "Movie.h"

/*
 * Builders
 */
Movie::Movie() : 
    Movie("Undefined", "Undefined", 1) {
        //std::cout << "Default Movie constructor called" << std::endl;
}

Movie::Movie(std::string name) : 
    Movie(name, "Undefined", 1) {
        //std::cout << "Movie Constructor #1 called" << std::endl;
}

Movie::Movie(std::string name, std::string rating) :
    Movie(name, rating, 1) {
        //std::cout << "Movie constructor #2 called" << std::endl;
}

Movie::Movie(std::string name, std::string rating, int times_watched) :
    name{name}, rating{rating}, times_watched{times_watched} {
        //std::cout << "Main Movie constructor called" << std::endl;
}

/*
 * Copier
 */
Movie::Movie(const Movie &src) :
    Movie(src.name, src.rating, src.times_watched) {
        //std::cout << "Movie copier called" << std::endl;
}

/*
 * Destructor
 */
Movie::~Movie() {
    //std::cout << "Movie destructor called" << std::endl;
}

/*
 * Getters
 */
std::string Movie::get_name() const {
    return name;
}

std::string Movie::get_rating() const {
    return rating;
}

int Movie::get_times_watched() const {
    return times_watched;
}

/* 
 * Setters
 */
void Movie::set_name(const std::string &name) {
    this->name = name;
}

void Movie::set_rating(const std::string &rating) {
    this->rating = rating;
}

void Movie::set_times_watched(const int &times_watched) {
    this->times_watched = times_watched;
}

/*
 * Other methods
 */
void Movie::increment_times_watched() {
    times_watched++;
}