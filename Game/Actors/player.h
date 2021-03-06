#pragma once
#include "Object/Actor.h"

namespace nc
{
	class Player : public nc::Actor
	{
	public:
		Player() {}
		virtual ~Player() {}

		virtual eType GetType()override { return eType::PLAYER; }

		virtual bool Load(const std::string& filename) override;
	

		virtual void Update(float dt) override;

	protected:
		float m_thrust{ 300.0f };
		float m_ratation{ 360.0f };

		float m_fireRate{ 0.2f };
		float m_fireTimer{ 0 };
		nc::Vector2 m_velocity;
	};
}