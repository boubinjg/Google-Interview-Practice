#include<iostream>
#include<vector>
struct point{
	int x;
	int y;
};
struct line{
	int m;
	int b;
};
line getline(point p1, point p2)
{
	
}
bool passesThrough(line l, point p)
{

}
line findMaxLine(std::vector<point> graph)
{
	std::cout<<graph[0].x<<std::endl;
}
int main()
{
	point p1, p2, p3, p4;
	p1.x = 0;
	p2.x = 0;
	p3.x = 0;
	p4.x = 5;
	p1.y = 0;
	p2.y = 3;
	p3.y = 6;
	p4.y = 2;

	std::vector<point> graph;
	graph.push_back(p1);
	graph.push_back(p2);
	graph.push_back(p3);
	graph.push_back(p4);

	line l = findMaxLine(graph);
	return 0;
}
