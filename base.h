#pragma once

#include <string>

#include <vector>

#include "card.h"

class CardBase

{

private:
    std::vector<Card> cards;

public:
    void readFromFile(std::string name);

    void saveToFile(std::string name);

    void addCard(Card card);

    Card getCard(int index);
};