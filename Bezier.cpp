#include "stdafx.h"
#include "Bezier.h"

Bezier::Bezier(const Vector2& p0, const Vector2& p1, const Vector2& p2, const Vector2& p3)
	: p0(p0), p1(p1), p2(p2), p3(p3)
{
}

//draw a track using a cubic Bezier curve

void Bezier::draw(SDL_Renderer *renderer) const
{
	Vector2 newParamB; //the new calculated parm 
	Vector2 oldParamB = p0; //setted to a new position at the end of every iteration

	
	for (size_t i = 0; i < 20; i++)
	{
		float t = (i + 1.0f) / 20.0f; //t is the floating parameter that affects the curve
		float tt = (1.0f - t); //tt is the reduction operator
		float pt = t * t; // pt is t by the power of 2 
		float ppt = pt * t; //ppt is t by the power of 3 
		float ptt = tt * tt; //ppt is tt by the power of 2
		float pptt = ptt * tt; //pptt is tt by the power of 3 
		//repeat this operation this number of times in order to render it a full track


		//Cubic Bezier formula 
		newParamB.x = pptt * p0.x + 3 * ptt * t * p1.x + 3 * tt * pt * p2.x + ppt * p3.x;
		newParamB.y = pptt * p0.y + 3 * ptt * t * p1.y + 3 * tt * pt * p2.y + ppt * p3.y;
		
		//draw the track. 
		SDL_RenderDrawLine(renderer, newParamB.x, newParamB.y, oldParamB.x, oldParamB.y);

		//set the old param with the new param so new it
			//begins with the new iteration at the spot were the last one ended
		oldParamB = newParamB;
	}

	
}
