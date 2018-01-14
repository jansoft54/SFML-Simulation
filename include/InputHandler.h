#pragma once
#include <SFML/Graphics.hpp>
#include <vector>
#include "Listener.h"
#include <functional>
class InputHandler
{
    public:
        InputHandler();
        virtual ~InputHandler();
        void addEventListener(Listener&,sf::Event::EventType);
        void handleEvents(sf::Event::EventType);

    private:
        std::vector<std::reference_wrapper<Listener>> listeners;
        std::vector<sf::Event::EventType> events;

};

