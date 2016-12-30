#include<iostream>
#include<string>
#include<vector>
void superset(std::string s, std::vector<std::string> v)
{
	if(s == "")
	{
		for(int i = 0; i<v.size() ; i++)
		{
			std::cout<<v[i]<<std::endl;
		}
	}
	else
	{
		std::vector<std::string> nv;
		std::string ns;
		ns.push_back(s[0]);
		nv.push_back(ns);
		for(int i = 0; i<v.size(); i++)
		{
			nv.push_back(v[i]);
			v[i]+=ns;
			nv.push_back(v[i]);
		}
		s.erase(s.begin());
		superset(s, nv);
	}
}
int main()
{
	std::string s = "12345";
	std::vector<std::string> v;
	superset(s, v);
}
