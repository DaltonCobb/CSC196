#include "Game.h"
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


void Game::Initialize()
{
	m_scene.Startup();
	g_particleSystem.Startup();

	nc::Actor* player = new nc::Player;
	player->Load("player.txt");
	m_scene.AddActor(player);


	for (size_t i = 0; i < 3; i++)
	{
		nc::Actor* actor = new Enemy;
		actor->Load("enemy.txt");
		dynamic_cast<Enemy*>(actor)->SetTarget(player);
		dynamic_cast<Enemy*>(actor)->SetSpeed(nc::random(50, 100));
		actor->GetTransform().position = nc::Vector2{ nc::random(0, 800), nc::random(0 , 600) };
		m_scene.AddActor(actor);

	}


}

bool Game::Update(float dt)
{
	frameTime = dt;


	bool quit = Core::Input::IsPressed(Core::Input::KEY_ESCAPE);


	spawnTimer += dt;
	if (spawnTimer >= 3.0f)
	{
		spawnTimer = 0;

		Enemy* enemey = new Enemy;
		enemey->Load("enemy.txt");
		enemey->SetTarget(m_scene.GetActor<nc::Player>());
		enemey->GetTransform().position = nc::Vector2{ nc::random(0, 800), nc::random(0 , 600) };
		m_scene.AddActor(enemey);

		int x, y;
		Core::Input::GetMousePos(x, y);
		if (Core::Input::IsPressed(Core::Input::BUTTON_LEFT))
		{
			nc::Color colors[] = { nc::Color::white, nc::Color::red,nc::Color::green, nc::Color::blue };
			nc::Color color = colors[rand() % 4];
			g_particleSystem.Create({ x,y }, 0, 180, 30, 1, color, 100, 200);
		}


	}
	g_particleSystem.Update(dt);
	m_scene.Update(dt);

	return quit;
}

void Game::Draw(Core::Graphics& graphics)
{
	graphics.SetColor(nc::Color{ 1, 1, 1 });
	graphics.DrawString(10, 10, std::to_string(frameTime).c_str());
	graphics.DrawString(10, 20, std::to_string(1.0f / frameTime).c_str());


	g_particleSystem.Draw(graphics);
	m_scene.Draw(graphics);
}
