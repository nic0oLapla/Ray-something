#pragma once
#include "Entity.h"

struct Scene {
	std::vector<std::shared_ptr<Entity>> titties;

	Scene();

	void addEntity(std::shared_ptr<Entity> entity);
};

Colour cast(const Ray& ray, const Scene& scene);