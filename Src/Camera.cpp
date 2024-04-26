#include "Camera.h"

#define PI 3.14159265

Camera::Camera(const double& view_plane_width, const int& samples_per_pixel, const double& fov, Vec2 dim, const Vec3& cPos, const Vec3& cDir)
:	view_plane_width(view_plane_width), 
	samples_per_pixel(samples_per_pixel), 
	fov(fov), 
	window_dim(dim), 
	camera_pos(cPos),
	camera_dir(normalise(cDir)),
	view_plane(makeViewPlane())
{
	vertices = sf::VertexArray(sf::Points, window_dim.x * window_dim.y);
	for (int i = 0; i < window_dim.y; i++) {
		for (int j = 0; j < window_dim.x; j++) {
			int index = i * window_dim.x + j;
			vertices[index].position = Vec2(j, i);
			vertices[index].color = Colour(0, 0, 0);
		}
	}
}

sf::VertexArray Camera::render(const Scene& world, int frame) {

	//For each horizontal scanline
	for (int i = 0; i < window_dim.y; i++) {

		//For each pixel
		for (int j = 0; j < window_dim.x; j++) {
			
			//Begin at black
			Colour pixel = Colour(0, 0, 0);

			//For each sample
			for (int k = 0; k < samples_per_pixel; k++) {
				
				//Randomise target within pixel
				Vec2 target = Vec2(
					j + ((std::rand() / (RAND_MAX + 1.0))),
					i + ((std::rand() / (RAND_MAX + 1.0)))
				);

				//Send white ray out through target))
				Ray ray(camera_pos, rayDir(target));
				pixel += cast(ray, world) / samples_per_pixel;
			}
			int index = i * window_dim.x + j;

			//Redraw pixel each frame
			//vertices[index].color = pixel;

			//Average pixel with previous frames
			vertices[index].color = vertices[index].color * ((frame - 1.0) / frame) + pixel * (1.0 / frame);
			//vertices[index].color = interpolate(vertices[index].color, pixel, 0.5);
		}
	}
	return vertices;
}

ViewPlane Camera::makeViewPlane() const {
	Vec2 view_plane_dim(view_plane_width, view_plane_width * window_dim.y / window_dim.x);

	float d = view_plane_dim.x / (2.0 * tan(fov * (PI / (2.0 * 180.0))));
	Vec3 centre = camera_pos + d * camera_dir;

	Vec3 horizontal_basis = normalise(Vec3(1.0, 0.0, -camera_dir.x / camera_dir.z));
	if (cross(camera_dir, horizontal_basis).y > 0.0)
		horizontal_basis = normalise(Vec3(-1.0, 0.0, -camera_dir.x / camera_dir.z));
	Vec3 vertical_basis = normalise(cross(camera_dir, horizontal_basis));

	Vec3 origin = centre - (view_plane_dim.x / 2.0) * horizontal_basis - (view_plane_dim.y / 2.0) * vertical_basis;

	return ViewPlane(view_plane_dim, centre, origin, horizontal_basis, vertical_basis);
}

Vec3 Camera::rayDir(Vec2 target_window) {
	Vec2 target_view_plane = target_window * (view_plane_width / window_dim.x);

	Vec3 target_world = view_plane.origin 
						+ target_view_plane.x * view_plane.horizontal_basis 
						+ target_view_plane.y * view_plane.vertical_basis;

	return normalise(target_world - camera_pos);
}
