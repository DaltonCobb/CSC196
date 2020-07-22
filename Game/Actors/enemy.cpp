#include "enemy.h"
#include "Math/Math.h"
#include "Graphics/ParticalSystem.h"

bool Enemy::Load(const std::string& filename)
{
	bool success = false;
	
	std::ifstream stream(filename);
	if (stream.is_open())
	{
		success = true;

		Actor::Load(stream);

		std::string line;
		std::getline(stream, line);
		m_speed = stof(line);


		stream.close();
	}
	return success;
}


void Enemy::Update(float dt)
{
	nc::Vector2 direction = m_target->GetTransform().position - m_transform.position;
	direction.Normalize();
	nc::Vector2 velocity = direction * m_speed;
	//m_transform.position =m_transform.position + (velocity * dt);
	m_transform.angle = std::atan2(direction.y, direction.x) + nc::DegresToRadians(90.0f);

	m_transform.Update();
}

void Enemy::OnCollision(Actor* actor)
{
	if (actor->GetType() == eType::PROJECTILE)
	{
		m_destroy = true;

		nc::Color colors[] = { nc::Color::white, nc::Color::red,nc::Color::green, nc::Color::blue };
		nc::Color color = colors[rand() % 4];
		g_particleSystem.Create(m_transform.position , 0, 180, 30, 1, color, 100, 200);
	}
}
