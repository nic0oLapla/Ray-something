#pragma once
#include "Ray.h"
#include "Record.h"
#include "Materials.h"

struct Entity {
	virtual ~Entity() = default;

	virtual bool test(const Ray& ray, Record& record) = 0;
};

