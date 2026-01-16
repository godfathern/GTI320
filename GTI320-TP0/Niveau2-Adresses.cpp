/**
 * @file Niveau2-Adresses.cpp
 *
 * @brief Petit exercice sur la notion d'adresse, de pointeur et de référence.
 *
 *
 */


#include <iostream>


void uneFct(int x, int& y, int* p)
{
    // Le paramètre x illustre un « passage par copie ».
    std::cout << "[uneFct] La variable x contient " << x << " et elle est située à l'adresse : " << &x << "\n";
    x += 1;

    // Le paramètre y illustre un « passage par référence ». La variable locale y
    // est en fait la variable y définie dans le main.
    std::cout << "[uneFct] La variable y contient " << y << " et elle est située à l'adresse : " << &y << "\n";
    y += 100;

    // Le paramètre *p est une copie du pointeur p de la fonction main, c'est une
    // variable différente mais elle pointe au même endroit.
    std::cout << "[uneFct] La variable p contient " << p << " et elle est située à l'adresse : " << &p << "\n"
              << std::endl;
    *p += 1000000;
}


int main()
{
    int x = 0;
    int y = 1;

    std::cout << "[main] La variable x contient " << x << " et elle est située à l'adresse : " << &x << "\n";
    std::cout << "[main] La variable y contient " << y << " et elle est située à l'adresse : " << &y << "\n";

    // L'astérisque * désigne un pointeur. Un pointeur contient une adresse mémoire.
    int* p = &x;
    std::cout << "[main] La variable p contient " << p << " et elle est située à l'adresse : " << &p << "\n"
              << std::endl;

    // p pointe vers la mémoire où est située x. On peut ainsi modifier x en
    // passant par p. La syntaxe *p signifie « ce qui est pointé par p ».
    *p = 320;
    std::cout << "Après avoir affecté 320 dans *p, on voit que p n'est pas modifiée mais x oui.\n";
    std::cout << "[main] La variable p contient " << p << " et elle est située à l'adresse : " << &p << "\n";
    std::cout << "[main] La variable x contient " << x << " et elle est située à l'adresse : " << &x << "\n"
              << std::endl;

    // Exercice : essayer de prédire ce qui sera affiché lorsque la fonction 'uneFct' est exécuté.
    // uneFct(x, y, p);


    std::cout << "[main] La variable x contient " << x << " et elle est située à l'adresse : " << &x << "\n";
    std::cout << "[main] La variable y contient " << y << " et elle est située à l'adresse : " << &y << "\n";
    std::cout << "[main] La variable p contient " << p << " et elle est située à l'adresse : " << &p << "\n";
}
