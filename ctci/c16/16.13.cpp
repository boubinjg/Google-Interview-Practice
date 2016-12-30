#include<iostream>
struct square{
	double bottomx, bottomy, sideLength;
};
struct line{
	double m, b;
};
line getBisectingLine(square one, square two)
{
	line bl;
	bl.m = ((one.bottomy+one.sideLength/2) - (two.bottomy+two.sideLength/2))/
	       ((one.bottomx+one.sideLength/2) - (two.bottomx+two.sideLength/2));
	bl.b = (one.bottomx+one.sideLength/2)*-bl.m + one.sideLength/2;
	return bl;
}
int main()
{
	square one, two;
	one.bottomx = 0;
	one.bottomy = 0;
	one.sideLength = 2;
	two.bottomx = 4;
	two.bottomy = 4; 
	two.sideLength = 2;
	line l = getBisectingLine(one, two);
	std::cout<<"y = "<<l.m<<"x + "<<l.b<<std::endl;
	return 0;
}
