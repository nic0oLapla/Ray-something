#pragma once
#include "Vec2.h"
#include "Vec3.h"
#include "Scene.h"
#include "ViewPlane.h"
#include <iostream>

class Camera {
	ViewPlane makeViewPlane() const;
	Vec3 rayDir(Vec2 target);
	
public:
	double view_plane_width = 3.0;
	const int samples_per_pixel = 1;
	const double fov;
	Vec2 window_dim;
	Vec3 camera_pos;
	Vec3 camera_dir;
	ViewPlane view_plane;
	sf::VertexArray vertices;

	Camera(const double& view_plane_width, const int& samples_per_pixel, const double& fov, Vec2 dim, const Vec3& cPos, const Vec3& cDir);
	sf::VertexArray render(const Scene& world, int frame);
	 
};