#pragma once

#include "Vector2.h"

class Bezier
{
public:
	Bezier(const Vector2& p0, const Vector2& p1, const Vector2& p2, const Vector2& p3);

	void draw(SDL_Renderer *renderer) const;
	Vector2 BezierCalulation(float t) const;

	const int static BezierPrecision = 20;
	Vector2 newParamB; //the new calculated parm 
	Vector2 BSegments[BezierPrecision + 1];
	Vector2 oldParamB = p0; //setted to a new position at the end of every iteration

private:
	Vector2 p0, p1, p2, p3;
};
