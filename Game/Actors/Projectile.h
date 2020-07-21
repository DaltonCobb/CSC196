#pragma once
#include "..\Engine\Object\Actor.h"

class Projectile : public nc::Actor
{
public:
	Projectile() {}

	virtual eType GetType()override { return eType::PROJECTILE; }


	virtual void OnCollision(Actor* actor) override;

	virtual bool Load(const std::string& filename) override ;
	virtual void Update(float dt) override;

	void SetSpeed(float speed) { m_speed = speed; }

protected:
	float m_speed{ 300.0f };

};

