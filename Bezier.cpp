#include "stdafx.h"
#include "Bezier.h"

Bezier::Bezier(const Vector2& p0, const Vector2& p1, const Vector2& p2, const Vector2& p3)
	: p0(p0), p1(p1), p2(p2), p3(p3)
{
	for (size_t i = 0; i < BezierPrecision + 1; i++)
	{
		BSegments[i] = BezierCalulation(float(i) / 20.0f);
		
	}
	
}


//draw a track using a cubic Bezier curve

void Bezier::draw(SDL_Renderer *renderer) const
{
	//draw the track. 
	for (size_t i = 0; i < BezierPrecision; i++)
	{
		SDL_RenderDrawLine(renderer, BSegments[i].x, BSegments[i].y, BSegments[i+1].x, BSegments[i+1].y);

	}
	
}

Vector2 Bezier::BezierCalulation(float t)const
{
	Vector2 newParamB = Vector2 (); //the new calculated parm 
	Vector2 oldParamB = p0; //setted to a new position at the end of every iteration

		float tReduct = (1.0f - t); //tt is the reduction operator
		float powT = t * t; // pt is t by the power of 2 
		float pow3T = powT * t; //ppt is t by the power of 3 
		float powTT = tReduct * tReduct; //ppt is tt by the power of 2
		float pow3TT = powTT * tReduct; //pptt is tt by the power of 3 
		//repeat this operation this number of times in order to render it a full track


		//Cubic Bezier formula 
		newParamB.x = pow3TT * p0.x + 3 * powTT * t * p1.x + 3 * tReduct * powT * p2.x + pow3T * p3.x;
		newParamB.y = pow3TT * p0.y + 3 * powTT * t * p1.y + 3 * tReduct * powT * p2.y + pow3T * p3.y;

		

		//set the old param with the new param so new it
			//begins with the new iteration at the spot were the last one ended


		oldParamB = newParamB;

	return newParamB;
}
