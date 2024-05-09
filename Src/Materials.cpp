#include "Materials.h"

Ray Specular::scatter(const Ray& incident, const Vec3& point, const Vec3& normal) const {
	Vec3 direction = normalise(incident.dir - 2 * dot(incident.dir, normal) * normal);

	Ray reflected(point, direction);
	reflected.depth = incident.depth + 1;
	return reflected;
}

Ray Diffuse::scatter(const Ray& incident, const Vec3& point, const Vec3& normal) const {
	Vec3 direction = normalise(Vec3(rand(), rand(), rand()));
	if (dot(direction, normal) < 0)
		direction = -direction;

	Ray reflected(point, direction);
	reflected.depth = incident.depth + 1;
	return reflected;
}
Ray Lambertian::scatter(const Ray& incident, const Vec3& point, const Vec3& normal) const {
	double theta = 360 * (rand() / (double)RAND_MAX);
	Vec3 sphere_centre = point + normal;
	Vec3 sphere_point = sphere_centre + normalise(Vec3(rand(), rand(), rand()));
	Vec3 direction = normalise(sphere_point - point);

	Ray reflected(point, direction);
	reflected.depth = incident.depth + 1;
	return reflected;
}