#pragma once
#include "Ray.h"

struct Material {
	virtual Ray scatter(const Ray& incident, const Vec3& point, const Vec3& normal) const = 0;

	virtual int type() = 0;
};

struct Specular : public Material {
	Ray scatter(const Ray& incident, const Vec3& point, const Vec3& normal) const override;

	int type() override { return 0; }
};

struct Diffuse : public Material {
	Ray scatter(const Ray& incident, const Vec3& point, const Vec3& normal) const override;

	int type() override { return 1; }
};

struct Lambertian : public Material {
	Ray scatter(const Ray& incident, const Vec3& point, const Vec3& normal) const override;

	int type() override { return 2; }
};
