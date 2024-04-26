#include "Materials.h"

Ray Specular::reflect(const Ray& incident, const Vec3& point, const Vec3& normal) const {
	Vec3 direction = normalise(incident.dir - 2 * dot(incident.dir, normal) * normal);
	Ray reflected(point, direction);
	reflected.depth = incident.depth + 1;
	return reflected;
}

Ray Diffuse::reflect(const Ray& incident, const Vec3& point, const Vec3& normal) const {
	Vec3 direction = normalise(Vec3(rand(), rand(), rand()));
	if (dot(direction, normal) < 0)
		direction = -direction;
	Ray reflected(point, direction);
	reflected.depth = incident.depth + 1;
	return reflected;
}

Ray Glow::reflect(const Ray& incident, const Vec3& point, const Vec3& normal) const {
	Ray emitted(point, Vec3());
	emitted.depth = 100;
	return emitted;
}