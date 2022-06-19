#include "base.h"

#include "card.h"

#include <fstream>

#include <iostream>

void CardBase::readFromFile(std::string name)
{

    std::ifstream in(name);

    std::string number, expire, brand;

    int check = 1;


    while (in >> number >> expire >> brand)

    {

        Card new_card(number, expire, brand);

        if (new_card.verify())
        {

            addCard(new_card);
        }
        else
        {
            std::cout << "Wystapil blad przy odczytywaniu karty numer " << check << "\n";
        }
        check ++;
    }

    in.close();
}

void CardBase::saveToFile(std::string name)
{

    std::ofstream out(name);

    for (Card card : cards)
    {

        out << card.getNumber() << " " << card.getExpiry() << card.getBrand() << " " << std::endl;
    }

    out.close();
}

void CardBase::addCard(Card card)
{

    cards.push_back(card);
}

void CardBase::deleteCard(int index)
{
    cards.erase(cards.begin() + index - 1);
}

Card CardBase::getCard(int index)
{

    return cards[index];
}

size_t CardBase::getBaseSize()
{

    return cards.size();
}