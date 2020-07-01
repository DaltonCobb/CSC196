#pragma once
#include "core.h"
#include "shape.h"
#include <vector>

class Painter
{
public:
	Painter() {}
	~Painter();

	void Update(float dt);
	void Draw(Core::Graphics& graphics);
	void Load(const std::string& filename);
	void Save(const std::string& filename);

private:
	Shape::eType m_shapetype = Shape::eType::LINE;

	Shape* m_shape{ nullptr };

	std::vector<Shape*>m_shapes;

};