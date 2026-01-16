// @file Niveau1-NamespacesEtTableaux.cpp
//
// Quelques exercices pour se familiariser avec les namespaces et les bases de
// la manipulation de tableaux.
//

#include <assert.h>
#include <iostream>
#include <string.h>

double* merge(double* tab1, int size1, double* tab2, int size2);


namespace Foo {
    int x = 12;

    void f()
    {
        std::cout << "Exécution de la fonction f(x) du namespace Foo\n";
    }
} // namespace Foo

namespace Bar {
    double x = 3.1415;

    void f()
    {
        std::cout << "Exécution de la fonction f(x) du namespace Bar\n";
    }
} // namespace Bar


int main()
{
    // Les 'namespace' évitent les conflits de nom. On accède aux éléments d'un namespace en le préfixant du nom du namespace et de l'opérateur ::

    Foo::f(); // exécute la fonction f du namespace Foo
    Bar::f(); // exécute la fonction f du namespace Bar

    // Exercice 1(a) Modifier et afficher la variable x du namespace Foo

    // TODO (exercice 1(a) ici)

    // Exercice 1(b) Modifier et afficher la variable x du namespace Bar

    // TODO (exercice 1(b) ici)

    return 0; // retirer cette ligne lorsque vous avez terminé l'exercice 1


    // Exercice 2

    // Déclaration d'un tableau statique (la taille ne peut jamais être modifiée)
    int myArray[4];
    myArray[0] = 10;
    myArray[1] = 11;
    myArray[2] = 12;
    myArray[3] = 13;
    for (int i = 0; i < 4; ++i) {
        std::cout << "myArray[" << i << "] = " << myArray[i] << "\n";
    }
    std::cout << "C++ ne vérifie pas les bornes des tableaux.\n";
    for (int i = -2; i < 6; ++i) {
        std::cout << "myArray[" << i << "] = " << myArray[i] << "\n";
    }


    // Allocation dynamique d'un tableau.
    int* p = new int[5]; // p pointe vers un tableau de taille 5 alloué dynamiquement.
    p[0] = 100;
    p[1] = 101;
    p[2] = 102;
    p[3] = 103;
    p[4] = 104;


    // Lancez le programme avec le débogueur (F5). Vous devriez obtenir une
    // erreur 'bad_alloc' la boucle ci-dessous.
    //
    // En C++ il n'y a pas de "ramasse miettes" (garbadge collector). C'est à vous de libérer la mémoire
    // lorsqu'on en a plus besoin.
    //
    // Règle : chaque "new" doit avoir son "delete[]" pour libérer la mémoire
    // allouée.

    // Ajouter un appel à delete[] dans la boucle ci-dessous afin de libérer la
    // mémoire au fur et à mesure. Le but est de faire en sorte que les 1000
    // appels à 'new' s'exéctuent sans erreur.
    for (int i = 0; i < 100; ++i) {
        // TODO corrigez
        std::cout << i << "\n";
        p = new int[10000000]; // p est un nouveau tableau de taille 100000000
    }

    return 0; // retirer cette ligne lorsque vous avez terminé l'exercice 2


    // Exercice 3
    // Écrivez la fonction merge ci-dessous.
    double arrayA[4] = { 1.0, 2.0, 4.0, 8.0 };
    double arrayB[5] = { 16.0, 32.0, 64.0, 128.0, 256.0 };
    double* arrayAB = merge(arrayA, 4, arrayB, 5);

    // Test le merge
    double a = 1.0;
    for (int i = 0; i < 9; ++i) {
        assert(arrayAB[i] == a);
        a *= 2.0;
    }
    delete[] arrayAB;


    // Exercice 4*
    // Afin d'améliorer les performances de votre code, réécrivez la fonction
    // 'merge' en utilisant adéquatement la commande 'memcpy'.
    //
    // Aide : le nombre d'octets occupés par un tableau de N doubles est : N*sizeof(double)


    return 0;
}


/*
La fonction merge reçoit en paramètre deux tableaux tab1 de taille size1 et tab2 de taille size2.

La fonction effectue le travaille suivant :
1. Allouer un nouveau tableau de double de taille size1+size2
2. Copier le contenu de tab1 dans les size1 premières cases du nouveau tableau
3. Copier le contenu de tab2 dans les size2 dernières cases du nouveau tableau
4. Retourner l'adresse de ce nouveau tableau

Ex : merge( {a,b,c}, {d,e} ) ---> {a,b,c,d,e}
*/
double* merge(double* tab1, int size1, double* tab2, int size2)
{
    return NULL; // Retirez cette ligne
}
