#include "statki.h"

using namespace std;

Statek* dodajWroga1(int i, int j)
{
    Statek* nowy = new Statek;
    nowy->tab = 'Y';
    nowy->height = i;
    nowy->width = j;
    nowy->hp = 1;
    nowy->nastepny = 0;
    return nowy;
}

Statek* dodajWroga2(int i, int j)
{
    Statek* nowy = new Statek;
    nowy->tab = 'W';
    nowy->height = i;
    nowy->width = j;
    nowy->hp = 3;
    nowy->nastepny = 0;
    return nowy;
}

Statek stworzBohatera(int h, int w)
{
    Statek bohater;
    bohater.tab = 'X';
    bohater.height = h - 2;
    bohater.width = w / 2;
    bohater.hp = 3;
    return bohater;
}

char czyWyswietl(Statek* aktualny, int h, int w)
{
    if (aktualny->nastepny == 0)
        return 0;
    aktualny = aktualny->nastepny;
    while (aktualny != 0)
    {
        if (aktualny->height == h && aktualny->width == w)
        {
            return aktualny->tab;
        }
        aktualny = aktualny->nastepny;
    }
    return 0;
}

void przesunWrogow(Statek* aktualny, bool& kierunek, int w)
{
    if (aktualny->nastepny == 0)
        return;
    Statek* poczatek = aktualny->nastepny;
    int min = poczatek->width;
    int max = poczatek->width;

    while (aktualny->nastepny != 0)
    {
        aktualny = aktualny->nastepny;
        if (aktualny->width < min)
            min = aktualny->width;
        if (aktualny->width > max)
            max = aktualny->width;

    }
    aktualny = poczatek;
    if (rand() % 9 == 0)
    {
        while (aktualny != 0)
        {
            if (max == w - 2)
                kierunek = 0;
            if (min == 1)
                kierunek = 1;
            if (kierunek)
                aktualny->width++;
            else
                aktualny->width--;

            aktualny = aktualny->nastepny;
        }
    }

}

void nowaFala(Statek* aktualny, int w, int poz)
{
    for (int i = 2; i < 7; i += 2)
    {
        for (int j = 4; j < w - 4; j += 2)
        {
            if (rand() % (12 / poz) == 0)
                aktualny->nastepny = dodajWroga2(i, j);
            else
                aktualny->nastepny = dodajWroga1(i, j);

            aktualny = aktualny->nastepny;
        }
    }
}
