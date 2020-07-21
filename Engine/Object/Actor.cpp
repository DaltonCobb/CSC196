#include "pch.h"
#include "Actor.h"

namespace nc
{

void Actor::Load(std::istream& stream)
{
	stream >> m_transform;

	std::string shapename;
	std::getline(stream, shapename);

	m_shape.Load(shapename);
}
bool Actor::Load(const std::string& filename)
{
	bool success = false;

	std::ifstream stream(filename);
	if (stream.is_open())
	{
		success = true;

		Load(stream);


		stream.close();
	}
	return success;
}


	void Actor::Update(float dt)
{
	//nothing
}

	void Actor::Draw(Core::Graphics& graphics)
	{
		m_shape.Draw(graphics, m_transform);

	}


}
