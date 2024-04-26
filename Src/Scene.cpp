#include "Scene.h"
#include <iostream>

Scene::Scene() {}

void Scene::addEntity(std::shared_ptr<Entity> entity) {
	titties.push_back(entity);
}

Colour cast(const Ray& ray, const Scene& world) {
	
	Record rec = Record();

	bool hit_any = false;

	for (std::shared_ptr<Entity> entity : world.titties) {
		if (entity->test(ray, rec))
			hit_any = true;
	}

	if (hit_any) {
		if (ray.depth > 2)
			return rec.colour;

		//Ray reflected = rec.material->reflect(ray, rec.normal, rec.hit_point);
		//return rec.colour * cast(reflected, world) * dot(rec.normal, -ray.dir);

		switch (rec.material->type()) {
		case 0:
		{
			Vec3 direction = normalise(ray.dir - 2 * dot(ray.dir, rec.normal) * rec.normal);
			Ray reflected(rec.hit_point, direction);
			reflected.depth = ray.depth + 1;
			return rec.colour * cast(reflected, world) * dot(rec.normal, -ray.dir);
			break;
		}
		case 1:
		{
			Vec3 direction = normalise(Vec3(rand(), rand(), rand()));
			if (dot(direction, rec.normal) < 0)
				direction = -direction;
			Ray reflected(rec.hit_point, direction);
			reflected.depth = ray.depth + 1;
			return rec.colour * cast(reflected, world) * dot(rec.normal, -ray.dir);
			break;
		}
		case 2:
		{
			return rec.colour;
			break;
		}
		}

	}

	//LERP: (1 - a)* startValue + a * endValue;
	double a = (1 + ray.dir.y) / 2;
	Colour white(0.9, 0.9, 0.9);
	Colour blue(0.5, 0.7, 1);
	return interpolate(white, blue, a);
}