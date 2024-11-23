#include <iostream>

constexpr int N_ELEMENTS = 100;

int main()
{
    // HIBA: A "NELEMENTS" helyett "N_ELEMENTS" kellene, mivel a v�ltoz� neve m�shogy van defini�lva.
    int *b = new int[NELEMENTS]; // Jav�t�s: int *b = new int[N_ELEMENTS];

    // HIBA: Az aposztr�f (') helyett id�z�jel (") kell a stringhez.
    std::cout << '1-100 ertekek duplazasa' // Jav�t�s: std::cout << "1-100 ertekek duplazasa";

    // HIBA: A for-ciklus felt�tele hib�s. A felt�tel hi�nyzik, �s az inicializ�l� szakasz nem megfelel�.
    for (int i = 0;) // Jav�t�s: for (int i = 0; i < N_ELEMENTS; i++)
    {
        b[i] = i * 2; // Ez rendben van.
    }

    // HIBA: A m�sodik for-ciklus felt�tel�nek �rt�ke mindig hamis (i; helyett i < N_ELEMENTS kell).
    for (int i = 0; i; i++) // Jav�t�s: for (int i = 0; i < N_ELEMENTS; i++)
    {
        // HIBA: Hi�nyzik a pontosvessz� (;) a "std::cout" v�g�r�l.
        std::cout << "Ertek:"; // Jav�t�s: std::cout << "Ertek:" << b[i] << std::endl;
    }

    // HIBA: Hi�nyzik az int inicializ�l�sa. Az "atlag" v�ltoz� nem inicializ�lt, ami hib�s sz�m�t�sokat okoz.
    std::cout << "Atlag szamitasa: " << std::endl;
    int atlag = 0; // Jav�t�s: adjunk neki kezdeti �rt�ket, p�ld�ul 0.
    for (int i = 0; i < N_ELEMENTS, i++) // HIBA: A vessz� (,) helyett pontosvessz� (;) kell.
    {
        // HIBA: Hi�nyzik a pontosvessz� (;) a sor v�g�r�l.
        atlag += b[i] // Jav�t�s: atlag += b[i];
    }

    // HIBA: Ha eg�sz sz�m oszt eg�sz sz�mot, az eredm�ny lev�gott (int). Ez helyes, ha eg�sz �tlagot szeretn�nk.
    atlag /= N_ELEMENTS;
    std::cout << "Atlag: " << atlag << std::endl;

    // HIBA: A "delete" nem ker�lt megh�v�sra a dinamikusan lefoglalt mem�ria felszabad�t�s�ra.
    delete[] b; // Jav�t�s: adjuk hozz� a mem�ria felszabad�t�s�t.

    return 0;
}

