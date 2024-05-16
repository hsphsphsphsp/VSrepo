#pragma once
#include <string>

using std::string;

class priceAlgo {
public:
	virtual double calcPrice(int daysRented) = 0;
	virtual int getPoint(int daysRented) = 0;
};

class childrenPrice : public priceAlgo {
	double calcPrice(int daysRented) {
		return 1.5 + (daysRented > 3 ? (daysRented - 3) * 1.5 : 0);
	}

	int getPoint(int daysRented) {
		return 1;
	}
};

class newReleasePrice : public priceAlgo {
	double calcPrice(int daysRented) {
		return daysRented * 3;
	}

	int getPoint(int daysRented) {
		return daysRented > 1 ? 2 : 1;
	}
};

class regularPrice : public priceAlgo {
	double calcPrice(int daysRented) {
		return 2 + (daysRented > 2 ? (daysRented - 2) * 1.5 : 0);
	}

	int getPoint(int daysRented) {
		return 1;
	}
};

class Movie
{
public:
	static const int CHILDRENS = 2;
	static const int NEW_RELEASE = 1;
	static const int REGULAR = 0;

	Movie(const string& title, int price_code)
		: title(title),
		priceCode(price_code)
	{
		switch (priceCode)
		{
		case REGULAR:
			setPriceCode(new regularPrice());
			break;
		case NEW_RELEASE:
			setPriceCode(new newReleasePrice());
			break;
		case CHILDRENS:
			setPriceCode(new childrenPrice());
			break;
		}
	}

	string getTitle()
	{
		return title;
	}

	void setPriceCode(priceAlgo *algo) {
		mAlgo = algo;
	}

	double getChargeFor(int daysRented) {
		return mAlgo->calcPrice(daysRented);
	}

	int getFrequentRenterPointsFor(int daysRented) {
		return mAlgo->getPoint(daysRented);
	}

private:
	string title;
	int priceCode;
	priceAlgo *mAlgo;
};

class ChildrenMovie : public Movie {

};