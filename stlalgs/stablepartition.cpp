#include <string>
#include <algorithm>
#include<iostream>
#include<vector>
//stable partition takes a vector range (v.begin(), v.end) and applies a predicate over that range
//All values including begin, not including end, are organized within the vector based on the predicate
//stable partition moves the values around the vector so that all values or which the predicate return true
//are placed before all values for which the predicate returns false
//stable partition returns a std::vector<T>::iterator which points to the position at which the vector is split.
bool isOdd(int i) {return i%2 == 1;}
bool isLetter(char c) {return (c-'0')>10;} //could cause problems
int main()
{
	std::vector<int> v;
	for(int i = 0; i<10; i++)
		v.push_back(i);
	
	std::vector<int>::iterator bound;
	bound = std::stable_partition(v.begin(), v.end(), isOdd);
	for(int i = 0; i<10; i++)
	{
		std::cout<<v[i]<<std::endl;
	}
	
	std::string s = "p1lea2se5hir6e7me";
	std::string::iterator b;
	b = std::stable_partition(s.begin(), s.end(), isLetter);
	std::cout<<s<<std::endl;
	return 0;
}
