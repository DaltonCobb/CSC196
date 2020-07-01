#include "painter.h"
#include "MathLib/vector2.h"


Painter::~Painter()
{
	for (Shape* shape : m_shapes)
	{
		delete shape;
	}
	m_shapes.clear();
}

void Painter::Update(float dt)
{
	if (Core::Input::IsPressed(Core::Input::KEY_LEFT))
	{
		if (m_shape)
		{
			delete m_shape;
			m_shape = nullptr;
		}
		m_shapetype = Shape::eType::LINE;
	}
	if (Core::Input::IsPressed(Core::Input::KEY_RIGHT))
	{
		if (m_shape)
		{
			delete m_shape;
			m_shape = nullptr;
		}
		m_shapetype = Shape::eType::BOX;
	}
	
	if (m_shape == nullptr && Core::Input::IsPressed(Core::Input::BUTTON_LEFT))
	{
		m_shape = Shape::CreateShape(m_shapetype);
	}
	if (m_shape)
	{
		bool place = m_shape->Update(dt);
		if (place)
		{
			m_shapes.push_back(m_shape);
			m_shape = nullptr;
		}
	}
	}

void Painter::Draw(Core::Graphics& graphics)
{
	graphics.DrawString(10, 10, Shape::GetShapeName(m_shapetype));

	if (m_shape)
	{
		m_shape->Draw(graphics);
	}
	if (!m_shapes.empty())
	{
	for (Shape* shape : m_shapes)
	{
		shape->Draw(graphics);

	}
	}
}

void Painter::Load(const std::string& filename)
{
	std::ifstream stream;
	stream.open(filename);
	if (stream.is_open())
	{
		while (!stream.eof())
		{
			int itype;
			stream >> itype;

			if (stream.eof()) break;

			Shape::eType type = static_cast<Shape::eType>(itype);
			Shape* shape = Shape::CreateShape(type);
			shape->Load(stream);

			m_shapes.push_back(shape);
		}
	}
}

void Painter::Save(const std::string& filename)
{
	std::ofstream stream;
	stream.open(filename);
	if (stream.is_open())
	{
		for (Shape* shape : m_shapes)
		{
			shape->Save(stream);
		}
	}
}