//Baza kart kredytowych Paulina Miętkiewska

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

             << "3. Usun karte\n"

             << "4. Odczytaj z pliku\n"

             << "5. Zapisz do pliku\n"

             << "6. Wyjdz\n"

             << "=========================================\n";

        int numer;

        cin >> numer;

        switch (numer)
        {

        case 1:
        {

            string c_numer, expiry, brand;


            while (1)
            {

                cout << "Podaj numer, date wygasniecia i wydawce karty" << endl;
                cin >> c_numer >> expiry >> brand;

                Card new_card(c_numer, expiry, brand);

                if (new_card.verify())
                {

                    base.addCard(new_card);
                    break;
                }
                else
                {
                    cout << "Podano niepoprawny numer karty lub date wygasniecia. Sprobowac ponownie? T/N\n";
                    char YESNO;
                    cin >> YESNO;

                    if (YESNO == 'T' || YESNO == 't')
                    {
                        continue;
                    }
                    else if (YESNO == 'N' || YESNO == 'n')
                    {
                        break;
                    }
                    else
                    {
                        cout << "Wpisano niepoprawna instrukcje.\n";
                        break;
                    }
                }
            }

            break;
        }

        case 2:
        {

            int index;
            size_t basesize;

            basesize = base.getBaseSize();

            if (basesize > 0)
            {
                cout << "Podaj indeks karty do odczytania (od 1 do " << (basesize) << ")" << endl; // rozmiar wektora??

                cin >> index;

                if (index <= basesize && index > 0)
                {

                Card card = base.getCard(index - 1);

                cout << card.getNumber() << " " << card.getExpiry() << " " << card.getBrand() << endl;
                }

                else
                {
                    cout << "Podano niepoprawny indeks karty. \n";
                }
            }
            else
            {
                cout << "Baza danych jest pusta.\n";
            }

            break;
        }

        case 3:
        {
            int index;

            if (base.getBaseSize() > 0)
            {
                cout << "Podaj indeks karty do usuniecia (od 1 do " << (base.getBaseSize()) << ")" << endl; // rozmiar wektora??

                cin >> index;

                if(index <= base.getBaseSize() && index > 0)
                {
                base.deleteCard(index);
                }
                else
                {
                    cout << "Podano niepoprawny indeks.\n";
                }
            }
            else
            {
                cout << "Baza danych jest pusta.\n";
            }
            break;
        }

        case 4:
        {

            string name;

            cout << "Podaj nazwe pliku" << endl;

            cin >> name;

            base.readFromFile(name);

            break;
        }

        case 5:
        {

            string name;

            cout << "Podaj nazwe pliku" << endl;

            cin >> name;

            base.saveToFile(name);

            break;
        }

        case 6:
        {

            return 0;
        }

        default:
        {
            cout << "Podano niepoprawny numer polecenia.";
            break;
        }
        }
    }
}