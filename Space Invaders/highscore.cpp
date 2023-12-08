#include "highscore.h"

Lista* pobierzScory(Lista* poczatek, int poz)
{
    string poziom;
    if (poz == 1)
        poziom = "Latwy.txt";
    else if (poz == 2)
        poziom = "Sredni.txt";
    else if (poz == 3)
        poziom = "Trudny.txt";
    ifstream plik;
    plik.open(poziom.c_str());
    Lista* aktualny = 0;
    if (ifstream(poziom.c_str(), ios::ate).tellg())
    {
        while (!plik.eof())
        {
            string napis;
            plik >> napis;
            if (napis != "")
            {
                if (poczatek == 0)
                {

                    poczatek = new Lista;
                    poczatek->imie = napis;
                    plik >> poczatek->wynik;
                    poczatek->nastepny = 0;
                    aktualny = poczatek;
                }
                else
                {
                    Lista* nowy = new Lista;
                    nowy->nastepny = 0;
                    nowy->imie = napis;
                    plik >> nowy->wynik;
                    aktualny->nastepny = nowy;
                    aktualny = nowy;
                }
            }
        }
    }
    plik.close();
    return poczatek;
}

void dodajWynik(int w, Lista*& poczatek)
{
    Lista* aktualny = poczatek;
    Lista* poprzedni;
    if (poczatek == 0)
    {
        poczatek = new Lista;
        poczatek->wynik = w;
        poczatek->nastepny = 0;
        cout << "Podaj imie: ";
        cin >> poczatek->imie;
        return;
    }
    else if (w >= aktualny->wynik)
    {
        Lista* nowy = new Lista;
        nowy->wynik = w;
        nowy->nastepny = aktualny;
        cout << "Podaj imie: ";
        cin >> nowy->imie;
        poczatek = nowy;
        return;
    }

    while (aktualny->nastepny != 0)
    {
        poprzedni = aktualny;
        aktualny = aktualny->nastepny;
        if (w >= aktualny->wynik)
        {
            Lista* nowy = new Lista;
            nowy->wynik = w;
            poprzedni->nastepny = nowy;
            nowy->nastepny = aktualny;
            cout << "Podaj imie: ";
            cin >> nowy->imie;
            return;
        }
    }
    Lista* nowy = new Lista;
    nowy->wynik = w;
    nowy->nastepny = 0;
    aktualny->nastepny = nowy;
    cout << "Podaj imie: ";
    cin >> nowy->imie;
}

void usunOstatni(Lista* aktualny)
{
    int ile = 0;
    Lista* poprzedni = 0;
    while (aktualny->nastepny != 0)
    {
        poprzedni = aktualny;
        aktualny = aktualny->nastepny;
        ile++;
    }
    if (ile >= 10)
    {
        poprzedni->nastepny = 0;
        delete aktualny;
    }
}

void wypiszScory(Lista* aktualny)
{
    wypiszS("Ranking");
    while (aktualny != 0)
    {
        cout << aktualny->imie << " " << aktualny->wynik << endl;
        aktualny = aktualny->nastepny;
    }
}

void wpiszScory(Lista* aktualny, int poz)
{
    string poziom;
    if (poz == 1)
        poziom = "Latwy.txt";
    else if (poz == 2)
        poziom = "Sredni.txt";
    else if (poz == 3)
        poziom = "Trudny.txt";
    ofstream plik;
    plik.open(poziom.c_str());
    while (aktualny != 0)
    {
        plik << aktualny->imie << " " << aktualny->wynik << endl;
        aktualny = aktualny->nastepny;
    }
    plik.close();
}
