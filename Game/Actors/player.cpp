#include "player.h"
#include "Math/Math.h"
#include <fstream>
#include "Projectile.h"
#include "..\Engine\Object\Scene.h"

namespace nc
{

	bool Player::Load(const std::string& filename)
	{

		bool success = false;

		std::ifstream stream(filename);
		if (stream.is_open())
		{
			success = true;

			Actor::Load(stream);

			std::string line;

			std::getline(stream, line);
			m_thrust = stof(line);

			std::getline(stream, line);
			m_ratation = stof(line);


			stream.close();
		}
		return success;
	}


	void Player::Update(float dt)
	{
		m_fireTimer += dt;
		if (Core::Input::IsPressed(VK_SPACE) && m_fireTimer >= m_fireRate)
		{
			m_fireTimer = 0;

			Projectile* projectile = new Projectile;
			projectile->Load("projectile.txt");
			projectile->GetTransform().position = m_transform.position;
			projectile->GetTransform().angle = m_transform.angle;
			m_scene->AddActor(projectile);
		}
		//Player
		//	position = position + (-direction * speed);
		nc::Vector2 force;
		if (Core::Input::IsPressed('W')) { force = nc::Vector2::forward * m_thrust; }
		//point force in direction of ship
		force = nc::Vector2::Rotate(force, m_transform.angle);

		m_velocity = m_velocity + (force * dt);
		m_velocity = m_velocity * 0.98f;

		//set position with velocity
		m_transform.position = m_transform.position + (m_velocity * dt);


		if (m_transform.position.x > 800.0f) m_transform.position.x = 0;
		if (m_transform.position.x < 0) m_transform.position.x = 800;
		if (m_transform.position.y > 600.0f) m_transform.position.y = 0;
		if (m_transform.position.y < 0) m_transform.position.y = 600;


		if (Core::Input::IsPressed('A')) { m_transform.angle = m_transform.angle - (nc::DegresToRadians(m_ratation) * dt); }
		if (Core::Input::IsPressed('D')) { m_transform.angle = m_transform.angle + (nc::DegresToRadians(m_ratation) * dt); }

		m_transform.Update();
	}
}