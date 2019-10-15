#include "stdafx.h"
#include "Bezier.h"

Bezier::Bezier(const Vector2& p0, const Vector2& p1, const Vector2& p2, const Vector2& p3)
	: p0(p0), p1(p1), p2(p2), p3(p3)
{
}

void Bezier::draw(SDL_Renderer *renderer) const
{
	Vector2 newParamB;

	

	for (size_t i = 0; i < 20; i++)
	{
		float t = i / 20;

		float tt = (1 - t);
		newParamB.x = pow(tt, 3) * p0.x + 3 * (tt, 2) * t * p1.x + 3 * tt * (t, 2) * p2.x + (t, 3) * p3.x;
		newParamB.y = pow(tt, 3) * p0.y + 3 * (tt, 2) * t * p1.y + 3 * tt * (t, 2) * p2.y + (t, 3) * p3.y;
		
		SDL_RenderDrawLine(renderer, p0.x + newParamB.x, p0.y + newParamB.y, p1.x + newParamB.x, p1.y + newParamB.y);
		SDL_RenderDrawLine(renderer, p1.x + newParamB.x, p1.y + newParamB.y, p2.x + newParamB.x, p2.y + newParamB.y);
		SDL_RenderDrawLine(renderer, p2.x + newParamB.x, p2.y + newParamB.y, p3.x + newParamB.x, p3.y + newParamB.y); 
		//DL_RenderDrawLine(renderer, p0.x , p0.y, p1.x, p1.y);
		/*SDL_RenderDrawLine(renderer, p1.x, p1.y, p2.x, p2.y);
		SDL_RenderDrawLine(renderer, p2.x, p2.y, p3.x, p3.y);*/
	}
}
