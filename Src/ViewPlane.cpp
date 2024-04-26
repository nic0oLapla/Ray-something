#include "ViewPlane.h"

ViewPlane::ViewPlane(Vec2 dim, const Vec3& centre, const Vec3& origin, const Vec3& xVec, const Vec3& yVec)
	: dim(dim), centre(centre), origin(origin), horizontal_basis(xVec), vertical_basis(yVec)
{}