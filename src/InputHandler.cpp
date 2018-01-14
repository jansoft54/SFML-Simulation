#include "InputHandler.h"
#include <iostream>
InputHandler::InputHandler()
{
    //ctor
}

InputHandler::~InputHandler()
{
    //dtor
}

void InputHandler::addEventListener(Listener& listener,sf::Event::EventType event)
{
    listeners.push_back(listener);
    events.push_back(event);
}
void InputHandler::handleEvents(sf::Event::EventType type)
{

    for(unsigned i = 0; i < listeners.size();++i)
    {
        if(type == events[i]){
            listeners[i].get().onHandle();
        }
    }
}
