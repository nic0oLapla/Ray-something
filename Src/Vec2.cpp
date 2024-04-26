#include "Vec2.h"

Vec2::Vec2(double x, double y)
	: x(x), y(y)
{}

Vec2::Vec2(sf::Vector2u vector2u)
	: x(vector2u.x), y(vector2u.y)
{}
Vec2::Vec2(sf::Vector2f vector2f)
	: x(vector2f.x), y(vector2f.y)
{}

Vec2::operator sf::Vector2u(){
	return sf::Vector2u(x, y);
}
Vec2::operator sf::Vector2f() {
	return sf::Vector2f(x, y);
}
	
Vec2 Vec2::operator+=(const Vec2& v) { x += v.x; y += v.y; return *this; }
Vec2 Vec2::operator-=(const Vec2& v) { x -= v.x; y -= v.y; return *this; }
Vec2 Vec2::operator*=(const double s) { x *= s; y *= s; return *this; }
Vec2 Vec2::operator/=(const double s) { x /= s; y /= s; return *this; }

Vec2 operator+(const Vec2& v, const Vec2& u) { return Vec2(v.x + u.x, v.y + u.y); }
Vec2 operator-(const Vec2& v, const Vec2& u) { return Vec2(v.x - u.x, v.y - u.y); }
Vec2 operator*(const Vec2& v, double s) { return Vec2(v.x * s, v.y * s); }
Vec2 operator/(const Vec2& v, double s) { return Vec2(v.x / s, v.y / s); }
Vec2 operator*(double s, const Vec2& v) { return Vec2(v.x * s, v.y * s); }

Vec2 normalise(Vec2 v) {
	return v / std::sqrt(dot(v, v));
}

double dot(Vec2 v, Vec2 u) {
	return v.x * u.x
		 + v.y * u.y;
}

double distance(Vec2 v, Vec2 u) {
	return sqrt(
		  (v.x - u.x) * (v.x - u.x)
		+ (v.y - u.y) * (v.y - u.y)
	);
}