#pragma once
#include "Materials.h"

struct Record {
	double t;
	Vec3 hit_point;
	Vec3 normal;
	Colour colour;
	std::shared_ptr<Material> material;
};