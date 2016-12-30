#include<iostream>
#include<unordered_map>
#include<algorithm>
void perm(std::unordered_map<std::string, bool>& s, std::string prefix, std::string rest)
{
	if(rest == "" && !s[prefix])
	{
		s[prefix] = true;
		std::cout<<prefix<<std::endl;
	}
	else
	{
		for(int i = 0; i<rest.length(); i++)
		{
			std::string next = prefix+rest[i];
			std::string remaining = rest.substr(0,i) + rest.substr(i+1);
			perm(s, next, remaining);
		}
	}
}
void permDupesEff(std::string perm, std::string left, std::unordered_map<char, int> count)
{
	std::cout<<perm<<" "<<left<<std::endl;
	if(left == "")
		std::cout<<perm<<std::endl;
	else
	{
		for(int i = 0; i<left.length(); i++)
		{
			std::string next = perm+left[i]; 
			std::string remaining = left;
			count[left[i]]--;
			if(count[left[i]] == 0)
				remaining = remaining.substr(0,i) + remaining.substr(i+1);
			permDupesEff(next, remaining, count);
		}	
	}	
}
int main()
{
	std::unordered_map<std::string, bool> s;
	//perm(s, "","abcda");
	std::unordered_map<char, int> sc;
	std::string str = "abcdaba";
	for(int i = 0; i<str.size(); i++)
	{
		sc[str[i]]++;
	}
	permDupesEff("","abc",sc);
}
