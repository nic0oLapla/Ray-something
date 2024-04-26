#pragma once
#include <SFML/Graphics.hpp>

class Vec2 {
public:
	double x;
	double y;

	Vec2(double x, double y);

	Vec2(sf::Vector2f vector2f);
	Vec2(sf::Vector2u vector2u);

	operator sf::Vector2f();
	operator sf::Vector2u();

	Vec2 operator+=(const Vec2& v);
	Vec2 operator-=(const Vec2& v);
	Vec2 operator*=(const double s);
	Vec2 operator/=(const double s);
};

Vec2 operator+(const Vec2& v, const Vec2& u);
Vec2 operator-(const Vec2& v, const Vec2& u);
Vec2 operator*(const Vec2& v, double s);
Vec2 operator/(const Vec2& v, double s);
Vec2 operator*(double s, const Vec2& v);
Vec2 normalise(Vec2 v);
double dot(Vec2 v, Vec2 u);
double distance(Vec2 v, Vec2 u);
