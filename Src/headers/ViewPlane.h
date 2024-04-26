#pragma once
#include "Vec2.h"
#include "Vec3.h"

struct ViewPlane {
	Vec2 dim;
	Vec3 centre;
	Vec3 origin;
	Vec3 horizontal_basis;
	Vec3 vertical_basis;
	

	ViewPlane(Vec2 dim, const Vec3& centre, const Vec3& origin, const Vec3& xVec, const Vec3& yVec);
};

