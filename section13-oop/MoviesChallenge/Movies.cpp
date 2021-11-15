#include "Movies.h"

/*
 * Constructors
 */
Movies::Movies() {
    //std::cout << "Default Movies constructor called" << std::endl;
}

Movies::Movies(std::vector<Movie> movies) :
    movies{movies} {
        //std::cout << "Main Movies constructor called" << std::endl;
}

/* 
 * Copier
 */
Movies::Movies(const Movies& src) :
    Movies(src.movies) {
        //std::cout << "Movies copier called" << std::endl;
}

/*
 * Destructor
 */
Movies::~Movies() {
    //std::cout << "Movies destructor called" << std::endl;
}

/*
 * Getters
 */
std::vector<Movie> Movies::get_movies() const {
    return movies;
}

/*
 * Setters
 */
void Movies::set_movies(std::vector<Movie> movies) {
    this->movies = movies;
}

/*
 * Other methods
 */
void Movies::add_movie(std::string name, std::string rating,
                        int times_watched) {
    Movie movie {name, rating, times_watched};
    movies.push_back(movie);
    std::cout << "Added movie " << movie.get_name() << std::endl;
}

void Movies::increment_times_watched(const std::string &movie_name) {
    for (Movie &m : movies) {
        if (m.get_name() == movie_name) {
            m.increment_times_watched();         

            std::cout << "Watched " << m.get_name() <<
            " movie " << m.get_times_watched() << " times";
            std::cout << std::endl;

            return;
        }
    }
    std::cout << "Movie " << movie_name << " not in collection."; 
    std::cout << std::endl;
}

void Movies::display_all_movies() const {
    std::cout << "Movies list";
    std::cout << std::endl;
    std::cout << "Name" << '\t' << 
                "Rating" << '\t' <<
                "Count";
    std::cout << std::endl;

    for (const Movie &m : movies) {
        std::cout << m.get_name() << '\t' <<
                    m.get_rating() << '\t' <<
                    m.get_times_watched() << '\t';
        std::cout << std::endl; 
    }
}