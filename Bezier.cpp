#include "stdafx.h"
#include "Bezier.h"

Bezier::Bezier(const Vector2& p0, const Vector2& p1, const Vector2& p2, const Vector2& p3)
	: p0(p0), p1(p1), p2(p2), p3(p3)
{
}

void Bezier::draw(SDL_Renderer *renderer) const
{
	Vector2 newParamB;
	Vector2 oldParamB = p0;

	

	for (size_t i = 0; i < 20; i++)
	{
		float t = (i + 1.0f) / 20.0f;
		float tt = (1.0f - t);

		newParamB.x = pow(tt, 3) * p0.x + 3 * pow(tt, 2) * t * p1.x + 3 * tt *
			pow(t, 2) * p2.x + pow(t, 3) * p3.x;
		newParamB.y = pow(tt, 3) * p0.y + 3 * pow(tt, 2) * t * p1.y + 3 * tt * 
			pow(t, 2) * p2.y + pow(t, 3) * p3.y;
		
		SDL_RenderDrawLine(renderer, newParamB.x, newParamB.y,oldParamB.x, oldParamB.y);

		oldParamB = newParamB;
	}
}
