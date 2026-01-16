/**
 * @file Niveau3-Heritage.cpp
 *
 * @brief Petit exercice sur la notion d'héritage en C++. Illustre une différence majeur avec le langage Java.
 *
 */

#include <iostream>

class A {
protected:
    int m_x;

public:
    // Constructeur par défaut
    A() :
        m_x(65) // initialise m_x à 21
    {
    }

    // Constructeur à partir d'un int
    A(int _x) :
        m_x(_x)
    {
    }

    void displaySelf()
    {
        std::cout << "Object de la classe A avec x=" << m_x << "\n";
    }
};


// La classe B hérite de la classe A
class B : public A {
public:
    // Constructeur par défaut, le constructeur A(int _x) est utilisé pour
    // initialisé le classe parent.
    B() :
        A(66)
    {
    }

    void displaySelf()
    {
        std::cout << "Object de la classe B avec x=" << m_x << "\n";
    }
};

int main()
{
    //
    // Lisez le code suivant, exécutez le et observez ce qui est affiché.

    A a1; // constructeur par défaut
    std::cout << "Affichage de 'a1' : ";
    a1.displaySelf();

    A a2(97); // construteur avec un paramètre int
    std::cout << "Affichage de 'a2' : ";
    a2.displaySelf();

    B b;
    std::cout << "Affichage de 'b' : ";
    b.displaySelf();

    A* ptr = &a1;
    std::cout << "Affichage (1) de ce qui est pointé par 'ptr' : ";
    ptr->displaySelf();
    // Note la syntaxe 'pts->' est équivalent à '(*pts).' Autrement dit, on
    // exécute la fonction 'displaySelf' de l'objet pointé par le pointeur ptr.

    ptr = &a2;
    std::cout << "Affichage (2) de ce qui est pointé par 'ptr' : ";
    ptr->displaySelf();

    ptr = &b; // valide car B hérite de A.
    std::cout << "Affichage (3) de ce qui est pointé par 'ptr' : ";
    ptr->displaySelf();

    // Exercice : pourquoi est-ce que l'objet pointé par ptr est affiché comme
    // étant de la classe A alors qu'en fait il est de la classe B ?
    //
    // TODO modifiez le code de la classe A de sorte que l'instruction
    // 'ptr->displaySelf()'
    // utilise la fonction displaySelf de la classe B.
    //
    // Aide : il faut ajouter un mot clé au bon endroit. Rien de plus. Peut-être
    // une petite recherche sur internet sera nécessaire.
}
