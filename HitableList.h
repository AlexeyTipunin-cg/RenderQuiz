#ifndef HITABLELISTH
#define HITABLELISTH

#include "Hitable.h"

class HitableList : public Hitable {
public:
	HitableList(){}
	HitableList(Hitable **l, int n) {
		list = l;
		listSize = n;
	}
	virtual bool hit(const Ray& r, float tmin, float tmax, hit_record& rec) const;
	Hitable **list;
	int listSize;
};

bool HitableList::hit(const Ray& r, float t_min, float t_max, hit_record& rec) const {
	hit_record temp_rec;
	bool hit_anything = false;
	double closest_so_far = t_max;
	for (int i = 0; i < listSize; i++)
	{
		if (list[i]->hit(r, t_min, closest_so_far, temp_rec))
		{
			hit_anything = true;
			closest_so_far = temp_rec.t;
			rec = temp_rec;
		}
	}
	return hit_anything;
}

#endif // !HITABLELISTH

