#pragma once
#include "shape.h"
#include "MathLib/vector2.h"

class Box : public Shape
{
public:

	virtual bool Update(float dt) override;
	virtual void Draw(Core::Graphics& graphics) override;
	virtual eType Type() override { return eType::BOX; }
	virtual void Load(std::ifstream& stream) override;
	virtual void Save(std::ofstream& stream) override;


private:
	float _size{ 40 };
	nc::vector2 m_center;
	static const nc::vector2 s_points[];
};
