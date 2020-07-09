
#include "box.h"
#include "MathLib/vector2.h"

const nc::vector2 Box::s_points[] = { {-1,-1}, {1,-1},{1,1},{-1,1},{-1,-1} };


bool Box::Update(float dt)
{
	int x, y;
	Core::Input::GetMousePos(x, y);
	nc::vector2 point{ x, y };
	m_center = point;
	

	bool place = !Core::Input::IsPressed(Core::Input::BUTTON_LEFT);

	return place;

}


void Box::Draw(Core::Graphics& graphics)
{
	for (size_t i = 0; i < 4; i++)
	{
		nc::vector2 p1 = (m_center + s_points[i]) * _size;
		nc::vector2 p2 = (m_center + s_points[i + 1]) * _size;
		graphics.DrawLine(p1.x, p1.y, p2.x, p2.y);
	}
}

void Box::Load(std::ifstream& stream)
{
	Shape::Load(stream);

	stream >> m_center;
	stream >> _size;
}

void Box::Save(std::ofstream& stream)
{
	Shape::Save(stream);

	stream << m_center << ' ';
	stream << _size << std::endl;
}
