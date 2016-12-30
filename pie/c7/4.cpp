#include<iostream>
#include<string>
#include<vector>
std::string alph = "abcdefghijklmnoprstuvwxy";
char getKey(int num, int place)
{
	return (alph[3*(num-1) + place-1]);
}
void getAllWords(std::string num, std::vector<std::string> v)
{
	if(num == "")
	{
		for(auto it = v.begin(); it<v.end(); it++)
			std::cout<<(*it)<<std::endl;
	}
	else if(v.empty())
	{
		std::string s;
		for(int i = 1; i<=3; i++)
		{
			s = "";
			s.push_back(getKey(num[0]-'0', i));
			v.push_back(s);
			std::cout<<s<<std::endl;
		}
		num.erase(num.begin());
		getAllWords(num, v);
	}
	else
	{
		std::vector<std::string> nv;
		for(int i = 1; i<=3; i++)
		{
			for(auto it = v.begin(); it<v.end(); it++)
			{
				nv.push_back((*it) + getKey(num[0]-'0', i));
			}			
		}	
		num.erase(num.begin());
		getAllWords(num, nv);
	}
}
int main()
{
	std::vector<std::string> s;
	getAllWords("8234567", s);
}
