#include "Vec3.h"

Vec3::Vec3(double x, double y, double z)
	: x(x), y(y), z(z)
{}

Vec3::Vec3(sf::Color colour)
	: x(colour.r / 255.0), y(colour.g / 255.0), z(colour.b / 255.0)
{}

Vec3::operator sf::Color(){
	return sf::Color(x * 255, y * 255, z * 255, 255);
}

Vec3 Vec3::operator=(const Vec3& v) { x = v.x; y = v.y; z = v.z; return *this; }
Vec3 Vec3::operator+=(const Vec3& v) { x += v.x; y += v.y; z += v.z; return *this; }
Vec3 Vec3::operator-=(const Vec3& v) { x -= v.x; y -= v.y; z -= v.z; return *this; }
Vec3 Vec3::operator*=(const double s) { x *= s; y *= s; z *= s; return *this; }
Vec3 Vec3::operator/=(const double s) { x /= s; y /= s; z /= s; return *this; }
Vec3 Vec3::operator-() const { return Vec3(-x, -y, -z); }

Vec3 operator+(const Vec3& v, const Vec3& u) { return Vec3(v.x + u.x, v.y + u.y, v.z + u.z); }
Vec3 operator-(const Vec3& v, const Vec3& u) { return Vec3(v.x - u.x, v.y - u.y, v.z - u.z); }
Vec3 operator*(const Vec3& v, double s) { return Vec3(v.x * s, v.y * s, v.z * s); }
Vec3 operator/(const Vec3& v, double s) { return Vec3(v.x / s, v.y / s, v.z / s); }
Vec3 operator*(double s, const Vec3& v) { return Vec3(v.x * s, v.y * s, v.z * s); }
Vec3 operator*(const Vec3& v, const Vec3& u) { return Vec3(v.x * u.x, v.y * u.y, v.z * u.z); }

Vec3 normalise(Vec3 v) {
	return v / std::sqrt(dot(v, v));
}

double dot(Vec3 v, Vec3 u) {
	return v.x * u.x
		 + v.y * u.y
		 + v.z * u.z;
}

Vec3 cross(Vec3 v, Vec3 u) {
	return Vec3(
		v.y * u.z - v.z * u.y,
		v.x * u.z - v.z * u.x,
		v.x * u.y - v.y * u.x
	);
}

double distance(Vec3 v, Vec3 u) {
	return sqrt(
		  (v.x - u.x) * (v.x - u.x)
		+ (v.y - u.y) * (v.y - u.y)
		+ (v.z - u.z) * (v.z - u.z)
	);
}

Vec3 interpolate(const Vec3& v, const Vec3& u, double a)
{
	return (1 - a) * v + a * u;
}