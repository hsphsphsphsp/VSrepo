#pragma once

#include <vector>
#include "Movie.cpp"
#include "Rental.cpp"

using std::string;
using std::vector;
class Customer {

private:
    string name;
    vector<Rental> rentals;

    string to_string_with_short_precision(double tar)
    {
        char buf[20] = { 0 };
        sprintf_s(buf, sizeof(buf), "%.1f", tar);
        return string(buf);
    }

public:
    Customer(const string& name) : name(name) {}

    void addRental(Rental arg)
    {
        rentals.push_back(arg);
    }

    string getName() {
        return name;
    }

    string statement()
    {
        double totalAmount = 0;
        int frequentRenterPoints = 0;
        string result = "Rental Record for " + getName() + "\n";

        for (Rental aRental : rentals) {
            // add frequent renter points
            frequentRenterPoints += aRental.getFrequentRenterPoints();
            totalAmount += aRental.getCharge();

            // show figures for this rental
            result += aRental.getStatement();
        }

        // add footer lines
        result += "Amount owed is " + to_string_with_short_precision(totalAmount) + "\n";
        result += "You earned " + std::to_string(frequentRenterPoints) + " frequent renter points";

        return result;
    }
};