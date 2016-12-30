#include<vector>
#include<string>
#include<algorithm>
#include<iostream>
#include<deque>
class Deck{
private:
	std::deque<std::string> cards;
public:
	Deck()
	{
		for(int i = 0; i<4; i++)
		{
			for(int j = 1; j<=13; j++)
			{
				std::string s = "";
				switch(j)
				{
					case 1:
						s+="A";
						break;
					case 11:
						s+="J";
						break;
					case 12:
						s+="Q";
						break;
					case 13:
						s+="K";
						break;
					default:
						s+= std::to_string(j);
						break;
				}	
				switch(i)
				{
					case 0:
						s+="H";
						break;
					case 1: 
						s+="S";
						break;
					case 2:
						s+="C";
						break;
					case 3:
						s+="D";
						break;
				}
				cards.push_back(s);
			}
		}
	}
	std::string takeCard()
	{
		std::string ret = cards.front();
		cards.pop_front();
		cards.push_back(ret);
		return ret;
	}
	void shuffle()
	{
		std::random_shuffle(cards.begin(), cards.end());	
	}
};
int main()
{
	Deck d;
	d.shuffle();
	for(int i = 0; i<1000; i++)
	{
		std::cout<<d.takeCard()<<std::endl;
	}
}
