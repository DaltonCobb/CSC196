// Game.cpp : This file contains the 'main' function. Program execution begins and ends there.

#include "core.h"
#include "Math/Math.h"
#include "Math/Random.h"
#include "Math/Vector2.h"
#include "Math/Color.h"
#include "Graphics/Shape.h"
#include <iostream>
#include <string>


nc::Shape ship;

nc::Vector2 position{ 400.0f, 300.0f };
float scale = 5.0f;
float angle = 0.0f;

float speed = 300.0f;

float frameTime;
float roundTime{ 0 };
bool gameOver{ false };
DWORD prevTime;
DWORD deltaTime;

bool Update(float dt)
{
	frameTime = dt;
	roundTime += dt;
	if (roundTime >= 5) gameOver = true;


	if (gameOver) dt = 0;
	// get delta time
	DWORD time = GetTickCount();
	deltaTime = time - prevTime;
	prevTime = time;


	bool quit = Core::Input::IsPressed(Core::Input::KEY_ESCAPE);

	int x, y;
	Core::Input::GetMousePos(x, y);

	//nc::Vector2 target = nc::Vector2{ x,y };
	//nc::Vector2 direction = target - position;

//	direction.Normalize();

	//if (direction.Length() < 50.0f)
	
	//	position = position + (-direction * speed);
	nc::Vector2 force;
	if (Core::Input::IsPressed('W')) { force = nc::Vector2::forward * speed; }
	nc::Vector2 direction = force * dt;
	direction = nc::Vector2::Rotate(direction, angle);

	position = position + direction;

	if (position.x > 800.0f) position.x = 0;
	if (position.x < 0) position.x = 800;
	if (position.y > 600.0f) position.y = 0;
	if (position.y < 0) position.y = 600;

	//if (Core::Input::IsPressed('A')) position += nc::Vector2::left * (speed * dt);
	//if (Core::Input::IsPressed('D')) position += nc::Vector2::right * (speed * dt);

	if (Core::Input::IsPressed('A')) angle -= dt * nc::TWO_PI;
	if (Core::Input::IsPressed('D')) angle += dt * nc::TWO_PI;

	return quit;
}



void Draw(Core::Graphics& graphics)
{
	graphics.DrawString(10, 10, std::to_string(frameTime).c_str());
	graphics.DrawString(10, 20, std::to_string(1.0f/ frameTime).c_str());
	graphics.DrawString(10, 30, std::to_string(deltaTime / 1000.0f).c_str());

	if (gameOver)graphics.DrawString(400, 300, "GameOver!");
	//graphics.SetColor(color);


	//graphics.DrawLine(static_cast<float>(rand() % 800), static_cast<float>(rand() % 600),

	ship.Draw(graphics, position, scale, angle);
}



int main()
{
	DWORD time = GetTickCount();
	std::cout << time / 1000/ 60 / 60 / 24 << std::endl;

	ship.Load("ship.txt");
	ship.SetColor({ 1,1,1 });

	char name[] = "CSC196";
	Core::Init(name, 800, 600); 
	Core::RegisterUpdateFn(Update);
	Core::RegisterDrawFn(Draw);
	
	Core::GameLoop();
	Core::Shutdown();
}

