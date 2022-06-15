#include <iostream>

#include "card.h"

#include "base.h"

using namespace std;

int main(int, char **)
{

    CardBase base;

    while (true)

    {

        cout << "=========================================\n"

             << "Wpisz numer polecenia:\n"

             << "1. Dodaj karte\n"

             << "2. Odczytaj karte\n"

             << "3. Odczytaj z pliku\n"

             << "4. Zapisz do pliku\n"

             << "5. Wyjdz\n"

             << "=========================================\n";

        int numer;

        cin >> numer;

        switch (numer)
        {

        case 1:
        {

            string c_numer, expiry;

            cout << "Podaj numer i date wygasniecia" << endl;

            cin >> c_numer >> expiry;

            Card new_card(c_numer, expiry);

            // if(new_card.verify()){

            base.addCard(new_card);

            //}

            break;
        }

        case 2:
        {

            int index;

            cout << "Podaj indeks (od 0 do " << endl; // rozmiar wektora??

            cin >> index;

            Card card = base.getCard(index);

            cout << card.card_number << " " << card.expiration_date << endl;

            break;
        }

        case 3:
        {

            string name;

            cout << "Podaj nazwe pliku" << endl;

            cin >> name;

            base.readFromFile(name);

            break;
        }

        case 4:
        {

            string name;

            cout << "Podaj nazwe pliku" << endl;

            cin >> name;

            base.saveToFile(name);

            break;
        }

        case 5:
        {

            return 0;
        }
        }
    }
}