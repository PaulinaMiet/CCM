#include "base.h"

#include "card.h"

#include <fstream>

void CardBase::readFromFile(std::string name)
{

    std::ifstream in(name);

    std::string number, expire;

    while (in >> number >> expire)

    {

        Card new_card(number, expire);

        // if(new_card.verify()){

        addCard(new_card);

        //}
    }

    in.close();
}

void CardBase::saveToFile(std::string name)
{

    std::ofstream out(name);

    for (Card card : cards)
    {

        out << card.card_number << " " << card.expiration_date << std::endl;
    }

    out.close();
}

void CardBase::addCard(Card card)
{

    cards.push_back(card);
}

Card CardBase::getCard(int index)
{

    return cards[index];
}