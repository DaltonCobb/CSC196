#pragma once
#include <fstream>

namespace nc
{
	struct vector2
	{
		float x, y;

	public:
		vector2() : x{ 0 }, y{ 0 } {}
		vector2(float x, float y) : x{ x }, y{ y } {}
		vector2(int x, int y) : x{ static_cast<float>(x) }, y{ static_cast<float>(y) } {}

		vector2 operator + (const vector2& v) { return vector2{ x + v.x, y + v.y }; }
		vector2 operator * (float s) { return vector2{ x * s, y * s }; }

		friend std::ofstream& operator << (std::ofstream& stream, const vector2& v)
		{
			stream << v.x << ' ' << v.y;
			return stream;
		}
		friend std::ifstream& operator >> (std::ifstream& stream, vector2& v)
		{
			stream >> v.x >> v.y;
			return stream;
		}

	};
}