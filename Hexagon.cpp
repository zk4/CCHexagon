#include "Hexagon.h"
#include <cmath>
using namespace std;

Hexagon Hexagon::directions[Hexagon::eDirection::COUNT] =
{
    { 0, 0 }, { 1, 0 }, { 1, -1 }, { 0, -1 },
    { -1, 0 }, { -1, +1 }, { 0, 1 }
};


float Hexagon::Distance(Hexagon& h)
{
    return max (max (abs (q - h.q), abs (r - h.r)), abs (y() - h.y()));
}

Hexagon::Hexagon(float q_ /*= 0*/, float r_ /*= 0 */, ccColor4F color_ /*= ccc4f(1, 1, 1, 1)*/) :q(q_), r(r_), color(color_)
{
   
}

Hexagon::Hexagon (const Hexagon& h)
{
    *this = h;
}

Hexagon::eDirection Hexagon::Towards (const Hexagon& target) const
{
	Hexagon dir = target - *this;
	dir.Round();
	dir.Normalize();
    for (int i = 0; i < eDirection::COUNT; ++i)
    {
        if (dir == directions[i])
            return eDirection (i);
    }

}

Hexagon& Hexagon::Move (eDirection dir, int times)
{
    *this += (directions[dir] * times);
    return *this;
}
void Hexagon::draw(int length, CCPoint center)
{
	for (int i = 0; i < 6; ++i)
	{
		float start_radian = M_PI / 3 * i + (M_PI / 6);
		float end_radian = start_radian + M_PI / 3;
 
		ccDrawColor4F(color.r, color.g, color.b, color.a);
		ccDrawLine(
			ccpAdd(ccp(cos(start_radian)*length, sin(start_radian)*length), center),
			ccpAdd(ccp(cos(end_radian)*length, sin(end_radian)*length), center)

			);
	}
}

 

Hexagon Hexagon::Round( )
{
	//DDA algorith
	float rx = std::round(q);
	float ry = std::round(y());
	float rz = std::round(r);

	float x_diff = abs(rx - q);
	float y_diff = abs(ry - y());
	float z_diff = abs(rz - r);

	if ((x_diff > y_diff) && (x_diff > z_diff))
		rx = -ry - rz;
	else if (y_diff > z_diff)
		ry = -rx - rz;
	else
		rz = -rx - ry;

	return Hexagon(rx, rz);
}

void Hexagon::Integerilze()
{
	 q = std::round(q);
	 r = std::round(r);

}

void Hexagon::Normalize()
{
	if (q!=0)
	q /= abs(q);
	if (r!=0)
	r /= abs(r);
}

