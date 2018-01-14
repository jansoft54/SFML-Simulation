#include <iostream>
#include "App.h"



App::App(int width, int height)
 : WIDTH(width),HEIGHT(height)
 , m_window({WIDTH , HEIGHT},"BISQWIT RENDER ART")
 , quads(QuadController::getInstance(WIDTH / 4 , HEIGHT/4))
{

   if(!m_font.loadFromFile("fonts/arial.ttf"))
    std::cout << "ERROR LOADING FONT" << '\n';

   m_fpstxt.setFont(m_font);
   m_fpstxt.setString("FPS: 0");
   m_fpstxt.setCharacterSize(15);
   m_fpstxt.setFillColor(sf::Color::White);

   handler.addEventListener(quads,sf::Event::KeyPressed);

}

void App::run()
{

    sf::Clock clock;
    float elapsed = 0;
    unsigned fps_count = 0;


    while(m_window.isOpen()){

        elapsed = clock.getElapsedTime().asSeconds();
      // m_window.setFramerateLimit(10);
        if(elapsed >= 1){clock.restart(); elapsed = 0; m_fpstxt.setString("FPS: " + std::to_string(fps_count)); fps_count = 0;}

        sf::Event event;

        while(m_window.pollEvent(event))
        {
            if(event.type == sf::Event::Closed)
                m_window.close();

        handler.handleEvents(event.type);
        }

        m_window.clear(sf::Color::Black);

        quads.update();
        quads.render(m_window);

        m_window.draw(m_fpstxt);
        m_window.display();

        ++fps_count;
    }
}

App::App(const App& other):WIDTH(2),HEIGHT(2), quads(QuadController::getInstance(WIDTH / 4 , HEIGHT/4)){
 std::cout << "COPY" << '\n';
}
App::~App()
{
   std::cout << "DESTRUCTOR" << '\n';
}

