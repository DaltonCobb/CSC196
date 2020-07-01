#pragma once
#include "shape.h"
#include "MathLib/vector2.h"



class Line : public Shape
{
public:
	Line() {}

	virtual bool Update(float dt) override;
	virtual void Draw(Core::Graphics& graphics) override;
	virtual eType Type() override { return eType::LINE; }

	virtual void Load(std::ifstream& stream) override;
	virtual void Save(std::ofstream& stream) override;

private:
	nc::vector2 m_start;
	nc::vector2 m_end;
	bool m_started{ false };
};

