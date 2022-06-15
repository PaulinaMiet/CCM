#pragma once

#include <string>

struct Card

{

    const std::string card_number;

    const std::string expiration_date;

    Card(std::string &number, std::string &expire);

    bool verify();
};