// Game.cpp : This file contains the 'main' function. Program execution begins and ends there.

#include "core.h"
#include "Math/Math.h"
#include "Math/Random.h"
#include "Graphics/Shape.h"
#include "Math/Transform.h"
#include "Object/Actor.h"
#include "Actors/player.h"
#include "Actors/enemy.h"
#include "Graphics/ParticalSystem.h"
#include <iostream>
#include <string>
#include <list>
#include <Object\Scene.h>


//Enemy enemy;
nc::Scene scene;
nc::ParticleSystem particleSystem;


float frameTime;
float spawnTimer{ 0 };

float t{ 0 };

DWORD prevTime;
DWORD deltaTime;

bool Update(float dt)
{
	frameTime = dt;


	bool quit = Core::Input::IsPressed(Core::Input::KEY_ESCAPE);
	
	t = t + (dt * 2.0f);

	// get delta time
	DWORD time = GetTickCount();
	deltaTime = time - prevTime;
	prevTime = time;
	spawnTimer += dt;
	if (spawnTimer >= 3.0f)
	{
		spawnTimer = 0;

	

		Enemy* enemey = new Enemy;
		enemey->Load("enemy.txt");
		enemey->SetTarget(scene.GetActor<nc::Player>());
		enemey->SetSpeed(nc::random(50, 100));
		enemey->GetTransform().position = nc::Vector2{ nc::random(0, 800), nc::random(0 , 600) };
		scene.AddActor(enemey);

	}


	nc::Player* player = scene.GetActor<nc::Player>();
	particleSystem.Create(player->GetTransform().position, player->GetTransform().angle + nc::PI , 10, 1, 1, nc::Color{ 1,1,1 }, 100, 200);

	int x, y;
	Core::Input::GetMousePos(x, y);
	if (Core::Input::IsPressed(Core::Input::BUTTON_LEFT))
	{
		nc::Color colors[] = { nc::Color::white, nc::Color::red,nc::Color::green, nc::Color::blue };
		nc::Color color = colors[rand() % 4];
		particleSystem.Create({ x,y }, 0, 180, 30, 1, color, 100, 200);
	}



	particleSystem.Update(dt);
	scene.Update(dt);

	return quit;
}



void Draw(Core::Graphics& graphics)
{
	graphics.SetColor(nc::Color{ 1, 1, 1 });
	graphics.DrawString(10, 10, std::to_string(frameTime).c_str());
	graphics.DrawString(10, 20, std::to_string(1.0f/ frameTime).c_str());

	
	//enemy.Draw(graphics);

	particleSystem.Draw(graphics);
	scene.Draw(graphics);
}



int main()
{
	scene.Startup();
	particleSystem.Startup();

	nc::Actor* player = new nc::Player;
	player->Load("player.txt");
	scene.AddActor(player);

	
	//enemy.Load("enemy.txt");
	//enemy.SetTarget(player);

	for (size_t i = 0; i < 3; i++)
	{
	nc::Actor* actor = new Enemy;
	actor->Load("enemy.txt");
	dynamic_cast<Enemy*>(actor)->SetTarget(player);
	dynamic_cast<Enemy*>(actor)->SetSpeed(nc::random(50, 100));
	actor->GetTransform().position = nc::Vector2{ nc::random(0, 800), nc::random(0 , 600) };
	scene.AddActor(actor);

	}

	char name[] = "CSC196";
	Core::Init(name, 800, 600); 
	Core::RegisterUpdateFn(Update);
	Core::RegisterDrawFn(Draw);
	
	Core::GameLoop();
	Core::Shutdown();

	particleSystem.Shutdown();
	scene.Shutdown();

}
