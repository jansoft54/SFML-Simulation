#pragma once
#include <SFML/Graphics.hpp>
#include "SRandom.h"
#include "Listener.h"
#include <vector>

class QuadController: public Listener{
    public:
        QuadController(const QuadController&) = delete;
        QuadController& operator=(const QuadController&) = delete;
       ~QuadController() = default;
        QuadController(int,int);


        static QuadController& getInstance(int,int);
        void update();
        void bufferRect();
        void render(sf::RenderWindow&);
        void addQuad(std::vector<sf::Vertex>&,int,int,int,int) ;
        void onHandle();




    private:
        std::vector<sf::Vertex> vertices;

        const int WIDTH,HEIGHT,QUAD_SIZE;
        int** quads ;
        int* s = new int[4];

        void addCircle(int,int,int,char);
        void moveMouse(sf::RenderWindow&);





};

