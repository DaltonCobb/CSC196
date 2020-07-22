#include "..\Game\Actors\Projectile.h"
#include "Math/Math.h"
#include "Graphics/ParticalSystem.h"

void Projectile::OnCollision(Actor* actor)
{
	if (actor->GetType() == eType::ENEMY)
	{
		m_destroy = true;
	}
}

bool Projectile::Load(const std::string& filename)
{
	bool success = false;
	
	std::ifstream stream(filename);
	if (stream.is_open())
	{
		success = true;

		Actor::Load(stream);

		std::string shapename;
		std::getline(stream, shapename);
		m_speed = Load(shapename);

		stream.close();
	}
	return success;
}


void Projectile::Update(float dt)
{
	m_lifeTime -= dt;
	if (m_lifeTime <= 0)
	{
		m_destroy = true;
	}


	nc::Vector2 direction = nc::Vector2::Rotate(nc::Vector2::forward, m_transform.angle);
	nc::Vector2 velocity = direction * 300.0f;
	m_transform.position = m_transform.position + (velocity * dt);
	
	g_particleSystem.Create(m_transform.position, m_transform.angle + nc::PI, 10, 1, 0.5f, nc::Color{ 1,1,1 }, 100, 200);


	m_transform.Update();
}
