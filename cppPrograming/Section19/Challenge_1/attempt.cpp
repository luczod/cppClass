// Section 19
// Challenge 1
// Formatting output
#include "tour.h"

#include <iomanip>
#include <iostream>
#include <string>

/*void columns()
{
    std::cout << "\n123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789"
                 "01234567890"
              << std::endl;
}*/

const std::string columns{
    "12345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890"
};

void attempt()
{
    Tours tours{ "Tour Ticket Prices from Miami",
                 {
                     {
                         "Colombia",
                         { { "Bogota", 8778000, 400.98 },
                           { "Cali", 2401000, 424.12 },
                           { "Medellin", 2464000, 350.98 },
                           { "Cartagena", 972000, 345.34 } },
                     },
                     {
                         "Brazil",
                         { { "Rio De Janiero", 13500000, 567.45 },
                           { "Sao Paulo", 11310000, 975.45 },
                           { "Salvador", 18234000, 855.99 } },
                     },
                     {
                         "Chile",
                         { { "Valdivia", 260000, 569.12 }, { "Santiago", 7040000, 520.00 } },
                     },
                     { "Argentina", { { "Buenos Aires", 3010000, 723.77 } } },
                 } };

    // Unformatted display so you can see how to access the vector elements
    std::cout << columns << std::endl;
    std::cout << "\n" << std::left << std::setw(columns.length() / 3) << " " << tours.title << "\n" << std::endl;

    std::cout << "Country" << std::setw(columns.length() / 4) << std::setfill(' ') << " " << "City"
              << std::setw(columns.length() / 4) << std::setfill(' ') << " " << "Population"
              << std::setw(columns.length() / 4) << std::setfill(' ') << " " << "Price" << std::endl;

    std::cout << "\n" << std::setw(columns.length()) << std::left << std::setfill('-') << " " << std::endl;

    for(auto country : tours.countries) { // loop through the countries
        std::cout << country.name;

        for(auto city : country.cities) { // loop through the cities for each country
            std::cout << std::setw(columns.length() / 4) << std::setfill(' ') << " " << city.name
                      << std::setw(columns.length() / 4) << std::setfill(' ') << " " << city.population
                      << std::setw(columns.length() / 4) << std::setfill(' ') << " " << city.cost << std::endl;
        }
    }

    std::cout << std::endl << std::endl;
}