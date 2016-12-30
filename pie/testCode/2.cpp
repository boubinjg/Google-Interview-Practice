#include<iostream>
template <class T>
struct test{
	T thing;
};
int main()
{
	test<int> t;
	t.thing = 0;
	std::cout<<t.thing<<std::endl;
	return 0;
}
