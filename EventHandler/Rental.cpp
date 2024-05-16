#pragma once
#include "Movie.cpp";

class Rental
{
public:
	Rental(Movie& movie, int days_rented)
		: movie(movie),
		daysRented(days_rented)
	{
	}

	Movie getMovie()
	{
		return movie;
	}

	double getCharge() {
		return movie.getChargeFor(daysRented);
	}

	int getFrequentRenterPoints() {
		return movie.getFrequentRenterPointsFor(daysRented);
	}

	string getStatement() {
		return "\t" + movie.getTitle() + "\t" + to_string_with_short_precision(getCharge()) + "\n";
	}

private:
	Movie movie;
	int daysRented;

	string to_string_with_short_precision(double tar)
	{
		char buf[20] = { 0 };
		sprintf_s(buf, sizeof(buf), "%.1f", tar);
		return string(buf);
	}
};