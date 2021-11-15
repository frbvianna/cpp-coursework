#ifndef __MOVIE__H__
#define __MOVIE__H__
#include <iostream>
#include <string>

class Movie {
private:
    std::string name;
    std::string rating;
    int times_watched;
public:
    // Constructors
    Movie();
    Movie(std::string);
    Movie(std::string, std::string);
    Movie(std::string, std::string, int);
    
    // Copier
    Movie(const Movie&);

    // Destructor
    ~Movie();

    // Getters
    std::string get_name() const;
    std::string get_rating() const;
    int get_times_watched() const;

    // Setters
    void set_name(const std::string&);
    void set_rating(const std::string&);
    void set_times_watched(const int&);

    // Increment movie watch count
    void increment_times_watched();
};

#endif  //!__MOVIE__H__