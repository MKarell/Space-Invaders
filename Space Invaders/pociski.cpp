#include "pociski.h"

using namespace std;

void dodajPociskBohatera(Pocisk* aktualny, int h, int w)
{
    while (aktualny->nastepny != 0)
        aktualny = aktualny->nastepny;

    Pocisk* nowy = new Pocisk;
    nowy->h = h - 1;
    nowy->w = w;
    nowy->nastepny = 0;
    aktualny->nastepny = nowy;
}

void dodajPociskWroga(Pocisk* aktualny, int h, int w)
{

    while (aktualny->nastepny != 0)
        aktualny = aktualny->nastepny;

    Pocisk* nowy = new Pocisk;
    nowy->h = h + 1;
    nowy->w = w;
    nowy->speed = 0;
    nowy->nastepny = 0;
    aktualny->nastepny = nowy;
}

void usunPocisk(Pocisk* aktualny)
{
    Pocisk* dousun = aktualny->nastepny;
    if (dousun != 0)
    {
        aktualny->nastepny = dousun->nastepny;
        delete dousun;
    }
}

void przesunPociskBohatera(Pocisk* aktualny)
{
    aktualny = aktualny->nastepny;
    while (aktualny != 0)
    {
        aktualny->h--;
        aktualny = aktualny->nastepny;
    }
}

void przesunPociskWroga(Pocisk* aktualny, int poz)
{

    if (aktualny->nastepny != 0)
    {
        aktualny = aktualny->nastepny;
        while (aktualny != 0)
        {
            if (aktualny->speed % (4 - poz) == 0)
                aktualny->h++;
            aktualny->speed++;
            aktualny = aktualny->nastepny;
        }
    }
}

bool wyswietlPociski(Pocisk* aktualny, int h, int w)
{
    if (aktualny->nastepny == 0)
        return 0;
    aktualny = aktualny->nastepny;
    while (aktualny != 0)
    {
        if (aktualny->h == h && aktualny->w == w)
            return 1;
        aktualny = aktualny->nastepny;
    }
    return 0;
}
