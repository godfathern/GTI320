/**
 * @file Niveau4-Templates.cpp
 *
 * @brief Exemple simplissime d'utilisation de templates.
 *
 */


#include <assert.h>
#include <iostream>


// definition d'un constante (préprocesseur)
#define N 100

/**
 * La classe MinExtractor implémente un conteneur muni de trois primitives :
 *
 * isEmpty : retourne vrai s'il est vide, faux sinon.
 *
 * add : ajoute un élément dans le conteneur.
 *
 * extractMin : retire l'élément minimum du conteneur.
 */
template<typename T>
class MinExtractor {
    // Le type T désigne un type de donné générique qui sera choisi plus tard.

private:
    T m_data[N]; // tampon où les éléments sont stockées
    int m_count; // nombre d'éléments dans le tampon

public:
    // Constructeur par défaut
    MinExtractor() :
        m_count(0)
    {
    }

    // Destructeur
    ~MinExtractor()
    {
        // Rien à faire car aucune allocation dynamique... pour l'instant !
    }

    bool isEmpty() const // le mot clé «const» signifie ici que l'exécution de cette fonction ne modifie pas l'objet
    {
        return (m_count == 0);
    }

    void add(const T& t)
    {
        assert(m_count < N); // une assertion est un test réalisé à l'exécution. Si
                             // la test est faux, une exception est levée.
                             // Des options de compilation permettent de désactiver
                             // les assertion de manière à ne par ralentir le
                             // programme lorsqu'on est certain que le code est
                             // bon.
        m_data[m_count++] = t;
    }

    T extractMin()
    {
        assert(m_count > 0);
        int pos_min = 0;
        // Recherche du min
        for (int i = 1; i < m_count; ++i) {
            if (m_data[i] < m_data[pos_min]) {
                pos_min = i;
            }
        }
        T min_element = m_data[pos_min];
        // Copie du dernier élément du tableau dans la position du min.
        m_data[pos_min] = m_data[m_count - 1];
        --m_count; // Il y a maintenant un élément de moins.
        return min_element;
    }
};

int main()
{
    std::cout << "Démo d'un MinExtractor contenant des données de type double :\n";
    MinExtractor<double> me_d;
    me_d.add(5.5);
    me_d.add(2.2);
    me_d.add(1.1);
    me_d.add(3.3);
    me_d.add(4.4);
    while (!me_d.isEmpty()) {
        double d = me_d.extractMin();
        std::cout << "Élément retiré : " << d << "\n";
    }


    std::cout << "Démo d'un MinExtractor contenant des données de type char :\n";
    MinExtractor<char> me_c;
    me_c.add('E');
    me_c.add('C');
    me_c.add('A');
    me_c.add('B');
    me_c.add('D');
    while (!me_c.isEmpty()) {
        char c = me_c.extractMin();
        std::cout << "Élément retiré : " << c << "\n";
    }
    return 0;
}

// Exercice 1
// Lire le code, l'exécuter et comprendre pourquoi ça fonctionne.
//
//
//
//
// Exercice 2
//
// On décide que l'extraction du min doit être très rapide.
//
// Modifiez le code de la classe MinExtractor de sorte que l'insertion maitienne
// le tableau trié en ordre décroissant.
//
// Modifiez alors la fonction d'extraction, l'élément minimum est toujours dans
// la dernière case du tableau, il n'y a pas besoin de faire une recherche.
//
//
// Exercice 3*
//
// Modifiez la classe MinExtractor pour que le tampon soit implémenté à l'aide
// d'un tableau alloué dyniquement. Lorsqu'une insertion est effectuée dans un
// tableau plein, on alloue un nouveau tableau 2 fois plus grand et toutes les
// données doivent être recopiées dans ce nouveau tableau.
//
// Vous devrez écrire une fonction qui ressemble à ceci :
//
// void doubleBuffersSize()
// {
//   size = 2*size;
//   T* newBuffer = new T[ size ];
//   // copie des valeurs
//   delete[] oldBuffer; //
//   oldBuffer = newBuffer; // copie du pointeur
// }
//
//
//
// Exercice 4**
//
// (À faire seulement si vous avez le temps et que ça vous amuse)
//
// Maintenir le tableau trié est inutilement coûteux (O(n)), utilisez une
// structure de tas (aussi appelé 'monceau' ou 'heap' en anglais) de manière à
// ce que l'insertion et l'extraction se fassent toutes les deux en O(log(n)).
//
