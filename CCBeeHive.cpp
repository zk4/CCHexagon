#include "CCBeeHive.h"

void CCBeeHive::MakeHexagons (int radius, const Hexagon& center, vector<Hexagon>& hexagons, ccColor4F color)
{

    for (int q = radius; q >= -radius; --q)
    {
        for (int r = -radius; r <= radius; ++r)
        {
			if (abs(r) <= radius && abs(q) <= radius && abs(-q-r) <= radius)
                hexagons.push_back (Hexagon (q, r, color) += center);
        }
    }

}

void CCBeeHive::MakeRing (int radius, const Hexagon& center, vector<Hexagon>& ring, ccColor4F color)
{

    for (int q = -radius; q <= radius; ++q)
    {
        for (int r = -radius; r <= radius; ++r)
        {
           
			if (max(max(abs(q), abs(r)), abs(-q - r)) == radius)
            {
                
                    ring.push_back (Hexagon (q, r, color) += center);
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



void CCBeeHive::MakeCross (int radius, const Hexagon& center, vector<Hexagon>& cross, ccColor4F color)
{

	cross.push_back( center);
	for (int i = -radius; i <= radius; ++i)
	{
		if (i == 0)continue;
		int x = i;
		int z = -i;
		int y = -x - z;

		cross.push_back(Hexagon(x,y, color) += center);
		cross.push_back(Hexagon(y, z, color) += center);
		cross.push_back(Hexagon(x, z, color) += center);
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
	line.push_back(start);
	line.push_back(end);
	float N = start.distance(end);
	
	for (int i = 0; i <= N; ++i)
	{
		Hexagon h1 = start * (1 - i / N);
		Hexagon h2 = end * i / N;
		Hexagon  h = (h1 +h2 ).round();
	h.color = color;
	line.push_back(h);
	}
}



