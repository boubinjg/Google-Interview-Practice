#include<iostream>
#include<string>
#include<vector>

int explorePond(std::vector<std::string>& bits, int i, int j)
{
	if(i < 0 || j < 0 || i >= bits.size() || j >= bits[i].size())
	{
		return 0;
	}
	if(bits[i][j] == '0')
	{
		
		bits[i][j] = '1';
		int size = 0;
		return 1 + explorePond(bits, i-1, j) + explorePond(bits, i+1, j) +
	       	       explorePond(bits, i, j-1) + explorePond(bits, i, j+1);
	}
	else 
		return 0;
}
std::vector<int> findPonds(std::vector<std::string> bits)
{
	std::vector<int> ret;
	for(int i = 0; i<bits.size(); i++)
	{
		for(int j = 0; j<bits[i].size(); j++)
		{
			if(bits[i][j] == '0')
			{
				int size = explorePond(bits, i, j);
				ret.push_back(size);	
			}
		}
	}
	return ret;
}
int main()
{
	std::vector<std::string> bits;
	bits.push_back("001111");
	bits.push_back("001111");
	bits.push_back("111001");
	bits.push_back("110001");
	bits.push_back("110111");
	bits.push_back("111110");
	std::vector<int> pondSizes = findPonds(bits);
	for(int i = 0; i<pondSizes.size(); i++)
		std::cout<<pondSizes[i]<<std::endl;
	return 0;
}
