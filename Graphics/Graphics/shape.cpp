#include "shape.h"
#include "line.h"
#include "box.h"

void Shape::Load(std::ifstream& stream)
{
	//
}

void Shape::Save(std::ofstream& stream)
{
	stream << static_cast<int>(Type()) << ' ';

}

Shape* Shape::CreateShape(eType type)
{
	Shape* shape = nullptr;
	switch (type)
	{
	case Shape::eType::LINE:
		shape = new Line;
		break;
	case Shape::eType::BOX:
		shape = new Box;
		break;
	default:
		break;
	}
	return shape;
}

const char* Shape::GetShapeName(eType type)
{
	switch (type)
	{
	case Shape::eType::LINE:
		return "Line";
		break;
	case Shape::eType::BOX:
		return "Box";
		break;
	default:
		break;
	}
	return " ";
}