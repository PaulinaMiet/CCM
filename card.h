#pragma once

#include <string>

class Card

{

private:

    std::string card_number;

    std::string expiration_date;

    std::string card_brand;

public:

    Card(std::string &number, std::string &expire, std::string &brand);

    bool verify();

    std::string getBrand();

    std::string getNumber();

    std::string getExpiry();

};
