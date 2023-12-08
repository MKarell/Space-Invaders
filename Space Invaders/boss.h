#ifndef BOSS_H
#define BOSS_H

struct Wspol
{
    char t;
    int h;
    int w;
    Wspol* nast;
};

struct Boss
{
    int hp;
    Wspol* wspol;
    Boss* lewy;
    Boss* prawy;
};

void dodajElem1(Boss* glowa);

Boss* stworzBossa();

void dodajElem2(Boss* aktualnyW, int h, int w);

char wyswietlBossa(Boss* aktualnyG, int i, int j);

void przesunBossa(Boss* aktualny);

#endif // BOSS_H

