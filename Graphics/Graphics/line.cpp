#include "line.h"


bool Line::Update(float dt)
{
	int x, y;
	Core::Input::GetMousePos(x, y);
	nc::vector2 point{ x, y };


	if (m_started == false)
	{
		m_started = true;
		m_start = point;
	}

	m_end = point;

	bool place = !Core::Input::IsPressed(Core::Input::BUTTON_LEFT);

	return place;
}

void Line::Draw(Core::Graphics& graphics)
{
	graphics.DrawLine(m_start.x, m_start.y, m_end.x, m_end.y);
}

void Line::Load(std::ifstream& stream)
{
	Shape::Load(stream);

	stream >> m_start;
	stream >> m_end;
}

void Line::Save(std::ofstream& stream)
{
	Shape::Save(stream);

	stream << m_start << ' ';
	stream << m_end << std::endl;
}