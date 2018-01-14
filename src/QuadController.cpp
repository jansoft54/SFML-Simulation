#include "QuadController.h"
#include <iostream>
#include "SRandom.h"
#include  <math.h>

QuadController::QuadController(int width, int height)
 :  WIDTH(width)
 ,  HEIGHT(height)
 ,  QUAD_SIZE(4)
 ,  quads(new int*[200])

{
    SRandom srand = SRandom::getRandom();
    for(int i = 0 ; i < 200; ++i)
        quads[i] = new int[WIDTH];

    for(int y = 0; y < HEIGHT; y++)
    for(int x = 0; x < WIDTH; x++)
    {
    quads[y][x] = 0;
     if(srand.nextInt(0,10) >9)
        quads[y][x] = 1;
    }

}


QuadController& QuadController::getInstance(int w,int h)
{
    static QuadController singleController(w,h);
    return singleController;
}

void QuadController::addQuad(std::vector<sf::Vertex>& vec,int x,int y, int lengthX = 4,int lengthY = 4)
{


    sf::Vertex bottomLeft(sf::Vector2f(x, y),sf::Color::Green);
    sf::Vertex bottomRight(sf::Vector2f(x + lengthX, y),sf::Color::Green);
    sf::Vertex topLeft(sf::Vector2f(x, y + lengthY),sf::Color::Green);
    sf::Vertex topRight(sf::Vector2f(x+lengthX, y + lengthY),sf::Color::Green);


    //SFML need the Vertecies to be supplied clockwise
    vec.push_back(bottomLeft);
    vec.push_back(topLeft);
    vec.push_back(topRight);
    vec.push_back(bottomRight);
}
void QuadController::bufferRect(){
    int contigRects = 0;
    int XRange = 4;
    int posX = 0;


    for(int y  = 0; y < HEIGHT; ++y){
        for(int x = 0; x < WIDTH; ++x){
               // std::cout << x << " " << y << " "<<XRange << " " << quads[y][x]<<'\n';
            if(quads[y][x])
            {
                if(!contigRects){
                 ++contigRects;
                 posX = x * QUAD_SIZE;
                }else{
                     XRange += QUAD_SIZE;
                }
            }else{
                if(contigRects){
                    addQuad(vertices,posX,y * QUAD_SIZE,XRange);
                    contigRects = 0;
                    XRange = 4;
                }
            }
        }
        if(contigRects != 0)
            addQuad(vertices,posX,y * QUAD_SIZE,XRange);
        contigRects = 0;
        XRange = 4;
        posX = 0;
    }
}


void QuadController::render(sf::RenderWindow& window)
{
    vertices.clear();
    vertices.reserve(HEIGHT * WIDTH * 4);

      bufferRect();

window.draw(&vertices[0],vertices.size(),sf::Quads);
}

void QuadController::update()
{

    for(int y = HEIGHT - 1; y >= 0; y--)
    for(int x = 0; x < WIDTH; x++)
    {

        if(y > 0 && quads[y][x] == 0 && quads[y - 1][x] != 0 )
        {

          int temp = quads[y][x];
          quads[y][x] = quads[y-1][x];
          quads[y-1][x] = temp;
        }
    }

}

void QuadController::onHandle()
{
    addCircle(SRandom::getRandom().nextOddInt(9,25),SRandom::getRandom().nextInt(50,200),20,1);
    addCircle(SRandom::getRandom().nextOddInt(9,25),SRandom::getRandom().nextInt(50,200),SRandom::getRandom().nextInt(100,120),0);
}


void QuadController::addCircle(int radius,int screenx,int screeny,char flag = 1)
{
     if(radius % 2 == 0 || (flag != 1 && flag != 0))
        return ;

    int circle[radius*2][radius*2];
    for (int i = 0; i < radius * 2; i++)
        for (int j = 0; j < radius * 2; j++)
        circle[i][j] = flag == 1 ? 0 : 1;

    int posx = 0,sign = 1;
    for(int j = 0; j < 2 ; ++j)
    {
     for(int i = 0; i < radius + 1 ; ++i)
     {
       int blocks = sqrt(radius*radius - i*i);
       for(int z = 0; z < (blocks * 2) ; z++)
           circle[ radius - blocks + z ][radius + sign*posx] = flag;
       ++posx;
     }
    posx = 0;
    sign = -1;
    }
    for(int y = 0; y < radius * 2; y++)
    for(int x = 0; x < radius * 2; x++)
    {
    if(circle[y][x] != flag == 1 ? 0 : 1)
     quads[screeny+ y][screenx + x] = circle[y][x];
    }

}

