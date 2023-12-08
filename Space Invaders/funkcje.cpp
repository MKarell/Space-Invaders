#include "funkcje.h"

using namespace std;

void czyscEkran()
{
    COORD cur = { 0,0 };
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), cur);
}

void usunWroga(Statek* aktWrog, Pocisk* aktPocisk, int& points)
{
    Pocisk* poczatekP = aktPocisk;
    Statek* poprzedniS = NULL;
    Pocisk* poprzedniP = NULL;
    while (aktWrog->nastepny != NULL)
    {
        poprzedniS = aktWrog;
        aktWrog = aktWrog->nastepny;
        while (aktPocisk->nastepny != NULL)
        {
            poprzedniP = aktPocisk;
            aktPocisk = aktPocisk->nastepny;
            if (aktWrog->height == aktPocisk->h && aktWrog->width == aktPocisk->w)
            {
                aktWrog->hp--;
                if (aktWrog->hp == 0)
                {
                    Statek* dousunS = aktWrog;
                    poprzedniS->nastepny = aktWrog->nastepny;
                    delete dousunS;
                    aktWrog = poprzedniS;
                }
                usunPocisk(aktPocisk);
                points++;
            }
        }
        aktPocisk = poczatekP;
    }
}

void czyTrafBohater(Statek& bohater, Pocisk* aktualny)
{
    Pocisk* poprzedni;
    while (aktualny->nastepny != NULL)
    {
        poprzedni = aktualny;
        aktualny = aktualny->nastepny;

        if (bohater.height == aktualny->h && bohater.width == aktualny->w)
        {
            bohater.hp--;
            usunPocisk(poprzedni);

            break;
        }
    }
}

void wczytaj(Statek& bohater, Pocisk* pociskiBohatera, Statek* listaWrogow, Pocisk* pociskiWroga, int& punkty, int& poz)
{
    int znak;
    ifstream plik;
    plik.open("save.txt");
    plik >> bohater.tab >> bohater.hp >> bohater.height >> bohater.width;
    plik >> znak;
    Pocisk* aktualnyP = pociskiBohatera;
    while (znak != 0)
    {
        Pocisk* nowy = new Pocisk;
        nowy->nastepny = NULL;
        nowy->speed = znak;
        plik >> nowy->h >> nowy->w;
        aktualnyP->nastepny = nowy;
        aktualnyP = nowy;
        plik >> znak;
    }
    Statek* aktualnyS = listaWrogow;
    plik >> znak;
    while (znak != 0)
    {
        Statek* nowy = new Statek;
        nowy->nastepny = NULL;
        nowy->hp = znak;
        plik >> nowy->tab >> nowy->height >> nowy->width;
        aktualnyS->nastepny = nowy;
        aktualnyS = nowy;
        plik >> znak;
    }
    aktualnyP = pociskiWroga;
    plik >> znak;
    while (znak != 0)
    {
        Pocisk* nowy = new Pocisk;
        nowy->nastepny = NULL;
        nowy->speed = znak;
        plik >> nowy->h >> nowy->w;
        aktualnyP->nastepny = nowy;
        aktualnyP = nowy;
        plik >> znak;
    }
    plik >> punkty >> poz;
}

void zapisz(Statek& bohater, Pocisk* pociskiBohatera, Statek* listaWrogow, Pocisk* pociskiWroga, int& punkty, int poz)
{
    ofstream plik;
    plik.open("save.txt");
    plik << bohater.tab << " " << bohater.hp << " " << bohater.height << " " << bohater.width << endl;
    while (pociskiBohatera->nastepny != 0)
    {
        pociskiBohatera = pociskiBohatera->nastepny;
        plik << pociskiBohatera->speed << " " << pociskiBohatera->h << " " << pociskiBohatera->w << " ";
    }
    plik << " 0" << endl;
    while (listaWrogow->nastepny != 0)
    {
        listaWrogow = listaWrogow->nastepny;
        plik << listaWrogow->hp << " " << listaWrogow->tab << " " << listaWrogow->height << " " << listaWrogow->width << " ";
    }
    plik << " 0" << endl;
    while (pociskiWroga->nastepny != 0)
    {
        pociskiWroga = pociskiWroga->nastepny;
        plik << pociskiWroga->speed << " " << pociskiWroga->h << " " << pociskiWroga->w << " ";
    }
    plik << " 0" << endl;
    plik << punkty << " " << poz;
}

void dodajPociskBossa(Boss* aktualnyW, Pocisk* glpocisk)
{
    Pocisk* aktpocisk = glpocisk;
    while (aktpocisk->nastepny != 0)
        aktpocisk = aktpocisk->nastepny;
    Wspol* aktwspol = aktualnyW->wspol;
    if (aktualnyW->wspol->nast == 0)
    {
        dodajPociskBossa(aktualnyW->lewy, glpocisk);
        dodajPociskBossa(aktualnyW->prawy, glpocisk);
    }
    else
    {
        while (aktwspol->nast != 0)
        {
            aktwspol = aktwspol->nast;
            if (aktwspol->t == 'T' && rand() % 10 == 0)
            {
                Pocisk* nowy = new Pocisk;
                nowy->h = aktwspol->h + 1;
                nowy->w = aktwspol->w;
                aktpocisk->nastepny = nowy;
                aktpocisk = nowy;
            }
        }
    }
}
