#ifndef _TOUR_H_
#define _TOUR_H_
#include <string>
#include <vector>

struct City {
    std::string name;
    long population;
    double cost;
};

// Assume each country has at least 1 city
struct Country {
    std::string name;
    std::vector<City> cities;
};

struct Tours {
    std::string title;
    std::vector<Country> countries;
};

void attempt();
void solution();

#endif // _TOUR_H_