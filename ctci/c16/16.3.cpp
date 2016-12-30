#include<iostream>
struct point{
	double x;
	double y;
};
struct line{
	point p1;
	point p2;
};
bool intersect(line l1, line l2)
{
	
	double m1 = (l1.p1.y - l1.p2.y)/(l1.p1.x-l1.p2.x);			
	double m2 = (l2.p1.y - l2.p2.y)/(l2.p1.x-l2.p2.x);
	std::cout<<m1<<" "<<m2<<std::endl;

	double b1 = l1.p1.y -(m1 * (l1.p1.x));
	double b2 = l2.p1.y -(m2 * (l2.p1.x));
	std::cout<<b1<<" "<<b2<<std::endl;

	double interX = m1-m2;
	double interY;
	if(!interX)
	{
		if(b1 == b2)
			return true;
		else
			return false;
	}
	interX = (b2-b1)/interX;
	interY = m1*interX + b1;
	std::cout<<interX<<" "<<interY<<std::endl;
	
	if((l1.p1.x < interX && interX < l1.p2.x || l1.p1.x > interX && interX > l1.p2.x) &&
	   (l1.p1.y < interY && interY < l1.p2.y || l1.p1.y > interY && interY > l1.p2.y) )
		return true;
	return false;
	     	
}
int main()
{
	point p1;
	p1.x = 0;
	p1.y = 0;
	point p2;
	p2.x = 2;	
	p2.y = 2;

	point p3;
	p3.x = 0;
	p3.y = 10;
	point p4;
	p4.x = 10;
	p4.y = 3;

	line l1;
	l1.p1 = p1;
	l1.p2 = p2;

	line l2;
	l2.p1 = p3;
	l2.p2 = p4;

	std::cout<<intersect(l1, l2)<<std::endl;
	
	return 0;
}
