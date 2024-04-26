#pragma once
#include "Entity.h"

struct Sphere : public Entity {
	Vec3 centre;
	double radius;
	Colour colour;
	Material* material;

	Sphere(const Vec3& centre, double radius, const Colour& colour, Material* material);

	bool test(const Ray& ray, Record& record) override;
};