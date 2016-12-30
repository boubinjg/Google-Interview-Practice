#include<iostream>
#include<string>
#include<unordered_map>
std::unordered_map<std::string, bool> pmap;
void fperm(std::string rem, std::string perm)
{
	if(rem == "")
	{
		std::cout<<perm<<std::endl;
	}
	for(int i = 0; i<rem.size(); i++)
	{
		std::string nperm = perm+rem[i];
		std::string nrem = rem.substr(0,i) + rem.substr(i+1);
		if(!pmap[nperm])
		{
			pmap[nperm] = true;
			fperm(nrem, nperm);
		}
	}
}
void fpermnm(std::string chars, std::unordered_map<char, int> map, std::string perm)
{;
	int count = 0, total = 0;
	char last;
	for(auto it = chars.begin(); it<chars.end(); it++)
	{
		if(map[*it])
		{
			last = *it;
			count++;
		}
	}
	if(count == 1)
	{
		count--;
		for(int i = map[last]; i>0; i--);
			perm+=last;
	}
	if(count == 0)
		std::cout<<perm<<std::endl;
	else
	 for(auto it = chars.begin(); it<chars.end(); it++)
	 {
		if(map[*it])
		{
			map[*it]--;
			std::string nperm = perm+*it;
			fpermnm(chars, map, nperm);
		}
	 }
}
int main()
{
	std::string s = "aaaaaaaaaac";
	//fperm(s, "");
	std::unordered_map<char, int> map;
	for(auto it = s.begin(); it<s.end(); it++)
		map[*it]++;
	fpermnm("ac", map, "");
}
