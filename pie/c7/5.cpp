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
	

	std::string s;
	for(int i = 1; i<=3; i++)
	{
		s = "";
		s.push_back(getKey(num[0]-'0', i));
		v.push_back(s);
		std::cout<<s<<std::endl;
	}

	while(num != "")
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
		v=nv;
	}
	
	if(num == "")
	{
		for(auto it = v.begin(); it<v.end(); it++)
			std::cout<<(*it)<<std::endl;
	}
}
int main()
{
	std::vector<std::string> s;
	getAllWords("8234567", s);
}
