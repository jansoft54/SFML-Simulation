#pragma once
#include <SFML/Graphics.hpp>
#include "QuadController.h"
#include "InputHandler.h"
class App
{
    public:
        App(int,int);
       ~App();
        App(const App& other);
        App& operator=(const App& other) = delete;

    public:
        void run();

    private:
        const unsigned WIDTH,HEIGHT;

        sf::RenderWindow m_window;
        sf::Font m_font;
        sf::Text m_fpstxt;
        sf::Clock clock;
        InputHandler handler;

        QuadController& quads;


};

