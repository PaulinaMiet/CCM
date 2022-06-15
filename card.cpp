#include "card.h"
#include <iostream>

Card::Card(std::string &number, std::string &expire)
    : card_number(number), expiration_date(expire)
{
}

bool Card::verify()
{

    // kod weryfikujący
    // numer to będzie 16 znaków - cyfr, np. 9890909809848409
    // data to będzie 5 znaków, np. 06/23

    // sprawdzanie rozmiaru

    if (card_number.length() != 16)
        return false;

    if (expiration_date.length() != 5)
        return false;


    // sprawdzanie daty - po lewej stronie dwie cyfry, musi to być miesiąc, więc sprawdzamy czy jest poprawny

    if (expiration_date[0] == 0)
    {

        if (!('0' < expiration_date[1] && expiration_date[1] <= '9'))
        {

            return false;
        }
    }

    else if (expiration_date[0] == 1)
    {

        if (!('0' <= expiration_date[1] && expiration_date[1] <= '2'))
        {

            return false;
        }
    }

    else
    {

        return false;
    }

    // po środku musi być ukośnik

    if (expiration_date[2] != '/')
    {

        return false;
    }

    // nie robimy żadnych założeń co do roku, więc tylko sprawdazamy czy są to cyfry

    if ((!isdigit(expiration_date[3])) || (!isdigit(expiration_date[4])))
    {

        return false;
    }

    //  numer karty

    // sprawdźmy czy to na pewno cyfry

    for (auto i : card_number)
    {

        if (!isdigit(i))
        {

            return false;
        }
    }

    // algorytm luhna

    // Dla każdej pozycji cyfry określone zostają mnożniki. Użyję 2 dla pozycji nieparzystych, 1 dla parzystych.
    // Każdą cyfrę liczby mnoży się przez odpowiadającą jej wagę od prawej do lewej. Ostatnia cyfra - nieparzysta

    int sum = 0;

    for (int i = 0; i < 16; i++)
    {
        int a;

        a = card_number[16 - i]*((i+1)%2 + 1);

        if (a >= 10)
        {
            sum += (a%10+1);
        }
        else
        {
            sum += a;
        }
    }
    
    if (sum%10 != 0)
    {
        return false;
    }

    // jeśli wszystko dobrze to na końcu

    return true;
}