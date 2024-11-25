#include "Scene.h"
#include <iostream>

Scene::Scene() {}

void Scene::addEntity(std::shared_ptr<Entity> entity) {
	entities.push_back(entity);
}

Colour cast(const Ray& ray, const Scene& world) {
	
	Record rec = Record();

	bool hit_any = false;

	for (std::shared_ptr<Entity> entity : world.entities) {
		if (entity->test(ray, rec))
			hit_any = true;
	}

	if (hit_any) {
		//if (ray.depth > 2)
			//return 0.1 * rec.colour;

		Ray reflected = rec.material->scatter(ray, rec.hit_point, rec.normal);
		return rec.colour * cast(reflected, world) * std::max(0.0, dot(rec.normal, -ray.dir)) * 0.9;


	}

	//LERP: (1 - a)* startValue + a * endValue;
	double a = (1 + ray.dir.y) / 2;
	Colour white(0.9, 0.9, 0.9);
	Colour blue(0.5, 0.7, 1);
	return interpolate(white, blue, a);
}