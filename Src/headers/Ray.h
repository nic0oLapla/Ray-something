#pragma once
#include "Vec3.h"

struct Ray {
	int depth;
	Vec3 origin;
	Vec3 dir;

	Ray(const Vec3& origin, const Vec3& dir);
};


