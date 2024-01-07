#pragma once

#include <DynamicBody.hpp>

class Projectile : public DynamicBody {
public:

	Projectile(Vecf pos, Vecf vel, Image* i = nullptr, BodyRectangle* br = nullptr);
};