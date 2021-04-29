#include "carte.hpp"
#include "carte.h"

void showCard(Carte carte)
{
    const float LARGEUR_CARTE = 192.3;
    const float HAUTEUR_CARTE = 279.2;
    const float LARGEUR_FENETRE = 500;
    const float HAUTEUR_FENETRE = 500;
    const float START_POSITION_X = 200;
    const float START_POSITION_Y = 100;
    float ratioLargeur = LARGEUR_CARTE / LARGEUR_FENETRE;
    float ratioHauteur = HAUTEUR_CARTE / HAUTEUR_FENETRE;
    float ratioStartX = START_POSITION_X / LARGEUR_FENETRE;
    float ratioStartY = START_POSITION_Y / HAUTEUR_FENETRE;
    float new_x_carte;
    float new_y_carte;
    float new_start_x;
    float new_start_y;
    sf::RenderWindow window(sf::VideoMode(LARGEUR_FENETRE, HAUTEUR_FENETRE), "Jeu de cartes");
    while (window.isOpen())
    {
        CartePosition position = readPosition(carte);
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Resized)
            {
                new_x_carte = event.size.width * ratioLargeur;
                new_y_carte = event.size.height * ratioHauteur;
                new_start_x = event.size.width * ratioStartX;
                new_start_y = event.size.height * ratioStartY;
            }
            if (event.type == sf::Event::MouseButtonPressed)
            {
                if (event.mouseButton.button == sf::Mouse::Left)
                {
                    sf::Vector2i localPosition = sf::Mouse::getPosition(window);
                    if (localPosition.x >= new_start_x && localPosition.x <= (new_start_x + new_x_carte) && localPosition.y >= new_start_y && localPosition.y <= (new_start_y + new_y_carte))
                    {
                        returnCarte(&carte);
                    }
                }
            }
            if (event.type == sf::Event::Closed)
                window.close();
        }

        window.clear(sf::Color::White);

        //Comment afficher une carte graphiquement
        //Charger la texture contenant toutes les cartes
        sf::Texture textureCartes;
        if (!textureCartes.loadFromFile("jeu-carte.png"))
        {
            std::cout << "impossible d'ouvrir le fichier jeu-carte.png" << std::endl;
            exit(1);
        }
        //-----------------------------------------------------------------------

        //---------Ceci est à faire pour chaque affichage de carte---------------
        //Définir un sprite pour notre carte
        sf::Sprite spriteCarte;
        spriteCarte.setTexture(textureCartes);
        //définir le rectangle correspondant à la carte dans la textureCartes
        //paramètres de IntRect dans l'ordre : gauche, haut, largeur, hauteur
        //  gauche : coordonnée du bord gauche du rectangle
        //  haut :  coordonnée du bord haut du rectangle
        //  largeur : largeur du rectangle
        //  hauteur : hauteur du rectangle
        spriteCarte.setTextureRect(sf::IntRect(position.x * LARGEUR_CARTE, position.y * HAUTEUR_CARTE, LARGEUR_CARTE, HAUTEUR_CARTE));
        spriteCarte.setPosition(START_POSITION_X, START_POSITION_Y); //position de la carte dans la fenetre
        //Il ne reste plus qu'à dessiner le sprite
        window.draw(spriteCarte);
        //----------------------------------------------------------------------

        window.display();
    }
}

Carte readCart()
{
    Carte carte;
    bool inputRang = true;
    bool inputCouleur = true;
    bool inputVisible = true;
    int input;
    std::cout << "Saisissez une carte :" << std::endl
              << std::endl;
    while (inputRang)
    {
        std::cout << "1- Ace -- ";
        std::cout << "2- Deux -- ";
        std::cout << "3- Trois -- ";
        std::cout << "4- Quatre -- ";
        std::cout << "5- Cinq -- ";
        std::cout << "6- Six -- ";
        std::cout << "7- Sept -- ";
        std::cout << "8- Huit -- ";
        std::cout << "9- Neuf -- ";
        std::cout << "10- Dix -- ";
        std::cout << "11- Valet -- ";
        std::cout << "12- Dame -- ";
        std::cout << "13- Roi" << std::endl;
        std::cin >> input;
        if (input < 1 || input > 13)
        {
            std::cout << "Saisie invalide" << std::endl;
        }
        else
        {
            carte.rang = input;
            inputRang = !inputRang;
        }
    }
    std::cout << "Saisissez la couleur :" << std::endl
              << std::endl;
    while (inputCouleur)
    {
        std::cout << "0- Trèfle -- ";
        std::cout << "1- Carreau -- ";
        std::cout << "2- Coeur -- ";
        std::cout << "3- Pique" << std::endl;
        std::cin >> input;
        if (input < 0 || input > 3)
        {
            std::cout << "Saisie invalide" << std::endl;
        }
        else
        {
            carte.couleur = input;
            inputCouleur = !inputCouleur;
        }
    }
    std::cout << "La carte est elle visible ou non ?" << std::endl
              << std::endl;
    while (inputVisible)
    {
        std::cout << "0- Non -- ";
        std::cout << "1- Oui" << std::endl;
        std::cin >> input;
        if (input < 0 || input > 1)
        {
            std::cout << "Saisie invalide" << std::endl;
        }
        else
        {
            carte.visible = input;
            inputVisible = !inputVisible;
        }
    }
    return carte;
}

CartePosition readPosition(Carte carte)
{
    CartePosition position = {2, 4};
    if (!carte.visible)
    {
        return position;
    }
    else
    {
        position.x = carte.rang - 1;
        position.y = carte.couleur;
        return position;
    }
}

void returnCarte(Carte *pcarte)
{
    (*pcarte).visible = !(*pcarte).visible;
}

Liste create_liste(void)
{
    Liste liste = NULL;
    return liste;
}

bool isEmpty(Liste L)
{
    return L == NULL;
}

void visualise_liste(Liste L)
{
    Liste temp = L;
    while (!isEmpty(temp))
    {
        showCard(temp->carte);
        if(temp->suivant == NULL)
        {
            std::cout << std::endl;
            return;
        }
        temp = temp->suivant;
        if(temp->suivant == L)
        {
            std::cout << std::endl;
            return;
        }
    }
}

Liste addHead(Carte carte, Liste L)
{
    Liste tete = new maillon;
    tete->carte = carte;
    tete->suivant = L;
    return tete;
}

Liste deleteHead(Liste L)
{
    Liste temp = L->suivant;
    delete L;
    return temp;
}

Liste ajout_queue(Carte carte, Liste L)
{
    if(L == NULL)
    {
        return addHead(carte, L);
    }
    Liste liste = new maillon;
    Liste temp;
    liste->carte = carte;
    liste->suivant = NULL;
    if(L->suivant == NULL) {
        L->suivant = liste;
        return L;
    }
    temp = L;
    while(temp->suivant != NULL)
    {
        temp = temp->suivant;
    }
    temp->suivant = liste;
    return L;
}

Liste supprimen(int n, Liste L)
{
    if(n == 0)
    {
        return deleteHead(L);
    }
    Liste temp = L;
    for(int i=0;i<n-1;i++) 
    {
        if(temp->suivant == NULL)
        {
            return L;
        }
        temp = temp->suivant;
    }
    if(temp->suivant->suivant == NULL)
    {
        temp->suivant = NULL;
        return L;
    }
    temp->suivant = temp->suivant->suivant;
    return L;
}