#include<iostream>
#include<algorithm>
bool waterDivis(int x, int y, int z, int res)
{
	if(res == 0)
		return true;
	else if(res < 0)
		return false;
	bool ret = false;
	
	ret = ret || waterDivis(x,y,z,res-x) || waterDivis(x,y,z,res-y) || waterDivis(x,y,z,res-z);
	
	return ret;
}
bool water(int x, int y, int z)
{
	return !(z%y) || !(z%x) || !(z%(abs(x-y))) ||  waterDivis(x,y,abs(x-y),z);
}
int main()
{
	std::cout<<water(3,5,4)<<" "<<water(2,6,5)<<" "<<water(2,4,6)<<std::endl;
}
