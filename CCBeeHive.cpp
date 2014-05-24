#include "CCBeeHive.h"

void CCBeeHive::MakeHexagons (int r, const Hexagon& center, vector<Hexagon>& hexagons, ccColor4F color)
{

    for (int x = r; x >= -r; --x)
    {
        for (int y = -r; y <= r; ++y)
        {
            if (abs (x - y) <= r)
                hexagons.push_back (Hexagon (x, y, color) += center);
        }
    }

}

void CCBeeHive::MakeRing (int r, const Hexagon& center, vector<Hexagon>& ring, ccColor4F color)
{

    for (int x = r; x >= -r; --x)
    {
        for (int y = -r; y <= r; ++y)
        {
            int z = x - y;
            if (abs (x) == r || abs (y) == r || abs (z) == r)
            {
                if (abs (x - y) <= r)
                    ring.push_back (Hexagon (x, y, color) += center);
            }
        }
    }

}

void CCBeeHive::MakeRings (int inner, int outter, const Hexagon& center, vector<Hexagon>& rings, ccColor4F color)
{
    for (int i=inner; i<=outter; ++i)
    {
        MakeRing (i, center, rings, color);
    }
}



void CCBeeHive::MakeCross (int r, const Hexagon& center, vector<Hexagon>& cross, ccColor4F color)
{

    for (int x = r; x >= -r; --x)
    {
        for (int y = -r; y <= r; ++y)
        {
            int z = x - y;
            if (abs (x) == 0 || abs (y) == 0 || abs (z) == 0)
            {
                if (abs (x - y) <= r)
                    cross.push_back (Hexagon (x, y, color) += center);
            }
        }
    }

}

void CCBeeHive::MakeLine2 (Hexagon& start, Hexagon& end, vector<Hexagon>& line, ccColor4F color)
{
	 
	line.push_back(start);
 
	while ((line.end()-1)->distance(end) > 0)
	{
		Hexagon a = end - *(line.end() - 1);
		if (abs(a.q)>abs(a.r))
				
		line.push_back(a);
	 
	}


}

void CCBeeHive::InterSect (vector<Hexagon>& des, vector<Hexagon>& src, vector<Hexagon>& out, ccColor4F color)
{
    for (auto & dd : des)
    {
        for (auto &ss : src)
        {
            if (dd == ss)
                out.push_back (dd);
        }
    }
}

bool CCBeeHive::Find (const vector<Hexagon>& src, const Hexagon& target)
{
    for (auto & s: src)
    {
        if (s == target)
            return true;
    }
    return false;
}

void CCBeeHive::MakeIntersectRange (int r, const Hexagon& center, vector<Hexagon>& des, vector<Hexagon>& range, ccColor4F color)
{





}

void CCBeeHive::MakeLine(Hexagon& start, Hexagon& end, vector<Hexagon>& line, ccColor4F color /*= ccc4f(1, 1, 1, 1)*/)
{
	int N = start.distance(end);

	for (int i = 0; i <= N; ++i)
	{
		Hexagon h = (start * (1.0f - float(i) / N) + (end * float(i) / N));
		h.color = color;
		line.push_back(h);
	}
}



