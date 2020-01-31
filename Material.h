#pragma once
#include "Hitable.h"
#include "Ray.h"

class Material {
public:
	virtual bool scatter(const Ray& r_in, const hit_record& rec, Vec3& attenuation, Ray& scattered) const = 0;
};

