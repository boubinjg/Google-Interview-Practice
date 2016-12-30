#include<string>
#include<iostream>
#include<algorithm>
#include<unordered_map>
void perm(std::string prefix, std::string rest, std::unordered_map<char, int> m)
{
	
	if(rest == "")
	{
		std::cout<<prefix<<std::endl;
	}
	else
	{
		std::string nPrefix, nRest;
		if(rest.length() == 1)
		{
			for(int i = 0; i<m[rest[0]]; i++)
				prefix += rest;
			perm(prefix, "", m);
		}
		else
		{
			for(int i = 0; i<rest.length(); i++)
			{
				nPrefix = prefix + rest[i];
				m[rest[i]]--;
				if(m[rest[i]] <= 0)
					nRest = rest.substr(0,i) + rest.substr(i+1);
				else
					nRest = rest;
				perm(nPrefix, nRest, m);
			}
		}
	}
}
int main()
{
	std::string input = "aabbcc";
	std::unordered_map<char,int> m;
	for(int i = 0; i<input.size(); i++)
	{
		m[input[i]]++;
	}
	perm("","abc", m);
}
