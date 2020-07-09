#pragma once
#include "core.h"
#include <fstream>

class Shape
{
public:
	enum class eType
	{
		LINE,
		BOX
	};
public:
	Shape() {}

	virtual bool Update(float dt) = 0;
	virtual void Draw(Core::Graphics& graphics) = 0;
	virtual eType Type() = 0;

	virtual void Load(std::ifstream& stream);
	virtual void Save(std::ofstream& stream);

	static Shape* CreateShape(eType type);
	static const char* GetShapeName(eType type);
};


