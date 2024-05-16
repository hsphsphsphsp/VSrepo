#include "pch.h"
#include "../EventHandler/Customer.cpp"
#include "../EventHandler/Rental.cpp"
#include "../EventHandler/Movie.cpp"

using std::string;
/*
TEST(TestCaseName, TestName) {
    Customer customer = Customer(string("Bob"));
    customer.addRental(Rental(Movie(string("Jaws"), Movie::REGULAR), 2));
    customer.addRental(Rental(Movie(string("Golden Eye"), Movie::REGULAR), 3));
    customer.addRental(Rental(Movie(string("Short New"), Movie::NEW_RELEASE), 1));
    customer.addRental(Rental(Movie(string("Long New"), Movie::NEW_RELEASE), 2));
    customer.addRental(Rental(Movie(string("Bambi"), Movie::CHILDRENS), 3));
    customer.addRental(Rental(Movie(string("Toy Story"), Movie::CHILDRENS), 4));

    string expected = "" +
        string("Rental Record for Bob\n") +
        string("\tJaws\t2.0\n") +
        string("\tGolden Eye\t3.5\n") +
        string("\tShort New\t3.0\n") +
        string("\tLong New\t6.0\n") +
        string("\tBambi\t1.5\n") +
        string("\tToy Story\t3.0\n") +
        string("Amount owed is 19.0\n") +
        string("You earned 7 frequent renter points");

    EXPECT_EQ(expected, customer.statement());
}*/

TEST(CustomerTest, StatementForNoRental) {
    Customer customer = Customer(string("NAME_NOT_IMPORTANT"));

    string statement = customer.statement();

    EXPECT_EQ(statement, string("Rental Record for NAME_NOT_IMPORTANT\n")
        + string("Amount owed is 0.0\n")
        + string("You earned 0 frequent renter points"));
}

TEST(CustomerTest, StatementForRegularMovieRentalForLessThan3Days) {
    Customer customer = Customer(string("NAME_NOT_IMPORTANT"));
    Movie movie = Movie(string("TITLE_NOT_IMPORTANT"), Movie::REGULAR);
    int dayRented = 2;
    Rental rental = Rental(movie, dayRented);
    customer.addRental(rental);

    string statement = customer.statement();

    EXPECT_EQ(statement, string("Rental Record for NAME_NOT_IMPORTANT\n")
        + string("\tTITLE_NOT_IMPORTANT\t2.0\n")
        + string("Amount owed is 2.0\n")
        + string("You earned 1 frequent renter points"));
}

TEST(CustomerTest, StatementForRegularMovieRentalForMoreThan2Days) {
    Customer customer = Customer(string("NAME_NOT_IMPORTANT"));
    Movie movie = Movie(string("TITLE_NOT_IMPORTANT"), Movie::REGULAR);
    int dayRented = 3;
    Rental rental = Rental(movie, dayRented);
    customer.addRental(rental);

    string statement = customer.statement();

    EXPECT_EQ(statement, string("Rental Record for NAME_NOT_IMPORTANT\n")
        + string("\tTITLE_NOT_IMPORTANT\t3.5\n")
        + string("Amount owed is 3.5\n")
        + string("You earned 1 frequent renter points"));
}

TEST(CustomerTest, StatementForNewReleaseMovie) {
    Customer customer = Customer(string("NAME_NOT_IMPORTANT"));
    Movie movie = Movie(string("TITLE_NOT_IMPORTANT"), Movie::NEW_RELEASE);
    int dayRented = 1;
    Rental rental = Rental(movie, dayRented);
    customer.addRental(rental);

    string statement = customer.statement();

    EXPECT_EQ(statement, string("Rental Record for NAME_NOT_IMPORTANT\n")
        + string("\tTITLE_NOT_IMPORTANT\t3.0\n")
        + string("Amount owed is 3.0\n")
        + string("You earned 1 frequent renter points"));
}

TEST(CustomerTest, StatementForChildrenMovieRentalMoreThan3Days) {
    Customer customer = Customer(string("NAME_NOT_IMPORTANT"));
    Movie movie = Movie(string("TITLE_NOT_IMPORTANT"), Movie::CHILDRENS);
    int dayRented = 4;
    Rental rental = Rental(movie, dayRented);
    customer.addRental(rental);

    string statement = customer.statement();

    EXPECT_EQ(statement, string("Rental Record for NAME_NOT_IMPORTANT\n")
        + string("\tTITLE_NOT_IMPORTANT\t3.0\n")
        + string("Amount owed is 3.0\n")
        + string("You earned 1 frequent renter points"));
}

TEST(CustomerTest, StatementForChildrenMovieRentalMoreThan4Days) {
    Customer customer = Customer(string("NAME_NOT_IMPORTANT"));
    Movie movie = Movie(string("TITLE_NOT_IMPORTANT"), Movie::CHILDRENS);
    int dayRented = 3;
    Rental rental = Rental(movie, dayRented);
    customer.addRental(rental);

    string statement = customer.statement();

    EXPECT_EQ(statement, string("Rental Record for NAME_NOT_IMPORTANT\n")
        + string("\tTITLE_NOT_IMPORTANT\t1.5\n")
        + string("Amount owed is 1.5\n")
        + string("You earned 1 frequent renter points"));
}

TEST(CustomerTest, StatementForNewReleaseMovieRentalMoreThan1Day) {
    Customer customer = Customer(string("NAME_NOT_IMPORTANT"));
    Movie movie = Movie(string("TITLE_NOT_IMPORTANT"), Movie::NEW_RELEASE);
    int dayRented = 2;
    Rental rental = Rental(movie, dayRented);
    customer.addRental(rental);

    string statement = customer.statement();

    EXPECT_EQ(statement, string("Rental Record for NAME_NOT_IMPORTANT\n")
        + string("\tTITLE_NOT_IMPORTANT\t6.0\n")
        + string("Amount owed is 6.0\n")
        + string("You earned 2 frequent renter points"));
}

TEST(CustomerTest, StatementForFewMovieRental) {
    Customer customer = Customer(string("NAME_NOT_IMPORTANT"));
    Movie regularMovie = Movie(string("TITLE_NOT_IMPORTANT"), Movie::REGULAR);
    Movie newReleaseMovie = Movie(string("TITLE_NOT_IMPORTANT"), Movie::NEW_RELEASE);
    Movie childrensMovie = Movie(string("TITLE_NOT_IMPORTANT"), Movie::CHILDRENS);
  
    customer.addRental(Rental(regularMovie, 1));
    customer.addRental(Rental(newReleaseMovie, 4));
    customer.addRental(Rental(childrensMovie, 4));

    string statement = customer.statement();

    EXPECT_EQ(statement, string("Rental Record for NAME_NOT_IMPORTANT\n")
        + string("\tTITLE_NOT_IMPORTANT\t2.0\n")
        + string("\tTITLE_NOT_IMPORTANT\t12.0\n")
        + string("\tTITLE_NOT_IMPORTANT\t3.0\n")
        + string("Amount owed is 17.0\n")
        + string("You earned 4 frequent renter points"));
}