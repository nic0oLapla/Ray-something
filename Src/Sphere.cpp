#include "Sphere.h"

Sphere::Sphere(const Vec3& centre, double radius, const Colour& colour, std::shared_ptr<Material> material)
	: centre(centre), radius(radius), colour(colour), material(material)
{}

//Colour Sphere::getColour() { return colour; }
//std::shared_ptr<Material> Sphere::getMaterial() { return material; }

bool Sphere::test(const Ray& ray, Record& record) {
	double a = dot(ray.dir, ray.dir);
	double b = 0 - dot(centre - ray.origin, ray.dir);
	double c = dot(centre - ray.origin, centre - ray.origin) - radius * radius;
	double det = b * b - a * c;
	if (det >= 0) {
		double t_plus = (-b + std::sqrt(det)) / a;
		double t_minus = (-b - std::sqrt(det)) / a;

		double t;
		if (t_plus <= t_minus)
			t = t_plus;
		else
			t = t_minus;

		if (t > 0 && (t < record.t || record.t == 0)) {
			record.t = t;
			record.hit_point = ray.origin + record.t * ray.dir;
			record.normal = normalise(record.hit_point - centre);
			record.colour = colour;
			record.material = material;
			return true;
		}
		
	}
	return false;
}