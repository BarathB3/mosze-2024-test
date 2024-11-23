#include <iostream>

constexpr int N_ELEMENTS = 100;

int main()
{
    // HIBA: A "NELEMENTS" helyett "N_ELEMENTS" kellene, mivel a változó neve máshogy van definiálva.
    int *b = new int[NELEMENTS]; // Javítás: int *b = new int[N_ELEMENTS];

    // HIBA: Az aposztróf (') helyett idézõjel (") kell a stringhez.
    std::cout << '1-100 ertekek duplazasa' // Javítás: std::cout << "1-100 ertekek duplazasa";

    // HIBA: A for-ciklus feltétele hibás. A feltétel hiányzik, és az inicializáló szakasz nem megfelelõ.
    for (int i = 0;) // Javítás: for (int i = 0; i < N_ELEMENTS; i++)
    {
        b[i] = i * 2; // Ez rendben van.
    }

    // HIBA: A második for-ciklus feltételének értéke mindig hamis (i; helyett i < N_ELEMENTS kell).
    for (int i = 0; i; i++) // Javítás: for (int i = 0; i < N_ELEMENTS; i++)
    {
        // HIBA: Hiányzik a pontosvesszõ (;) a "std::cout" végérõl.
        std::cout << "Ertek:"; // Javítás: std::cout << "Ertek:" << b[i] << std::endl;
    }

    // HIBA: Hiányzik az int inicializálása. Az "atlag" változó nem inicializált, ami hibás számításokat okoz.
    std::cout << "Atlag szamitasa: " << std::endl;
    int atlag = 0; // Javítás: adjunk neki kezdeti értéket, például 0.
    for (int i = 0; i < N_ELEMENTS, i++) // HIBA: A vesszõ (,) helyett pontosvesszõ (;) kell.
    {
        // HIBA: Hiányzik a pontosvesszõ (;) a sor végérõl.
        atlag += b[i] // Javítás: atlag += b[i];
    }

    // HIBA: Ha egész szám oszt egész számot, az eredmény levágott (int). Ez helyes, ha egész átlagot szeretnénk.
    atlag /= N_ELEMENTS;
    std::cout << "Atlag: " << atlag << std::endl;

    // HIBA: A "delete" nem került meghívásra a dinamikusan lefoglalt memória felszabadítására.
    delete[] b; // Javítás: adjuk hozzá a memória felszabadítását.

    return 0;
}

