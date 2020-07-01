// main.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "core.h"
#include "helper.h"
#include "MathLib/vector2.h"
#include "painter.h"
#include <iostream>
#include <vector>


Painter painter;
bool Update(float dt)
{
    bool quit = false;
    quit = Core::Input::IsPressed(Core::Input::KEY_ESCAPE);

    painter.Update(dt);

    return quit;
}

void Draw(Core::Graphics& graphics)
{

    graphics.SetColor(RGB(rand() % 255, rand() % 255, rand() % 255));

 //   if (painter.empty())
  //  {
   //     for (size_t i = 0; i < points.size() - 1; i++)
        //{
          //  graphics.DrawLine(points[i].x, points[i].y, points[i + 1].x, points[i + 1].y);

            painter.Draw(graphics);
        //}
   // }

    //graphics.DrawLine(0,0,point.x,point.y);
}



int main()
{
    painter.Load("picture.txt");
    char name[] = "Dalton";
    Core::Init(name, 800, 600);
    Core::RegisterUpdateFn(Update);
    Core::RegisterDrawFn(Draw);
    Core::GameLoop();
    Core::Shutdown();

  
    painter.Save("picture.txt");
}
