#pragma once
#include <SFML/Graphics.hpp>

class Vec3 {
public:
	double x;
	double y;
	double z;
	
	Vec3() = default;

	Vec3(double x, double y, double z);

	Vec3(sf::Color colour);

	operator sf::Color();

	Vec3 operator=(const Vec3& v);
	Vec3 operator+=(const Vec3& v);
	Vec3 operator-=(const Vec3& v);
	Vec3 operator*=(const double s);
	Vec3 operator/=(const double s);
	Vec3 operator-() const;
};

using Colour = Vec3;

Vec3 operator+(const Vec3& v, const Vec3& u);
Vec3 operator-(const Vec3& v, const Vec3& u);
Vec3 operator*(const Vec3& v, double s);
Vec3 operator/(const Vec3& v, double s);
Vec3 operator*(double s, const Vec3& v);
Vec3 operator*(const Vec3& v, const Vec3& u);

Vec3 normalise(Vec3 v);
double dot(Vec3 v, Vec3 u);
Vec3 cross(Vec3 v, Vec3 u);
double distance(Vec3 v, Vec3 u);
Vec3 interpolate(const Vec3& v, const Vec3& u, double a);
