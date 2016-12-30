#include<vector>
#include<string>
#include<iostream>
#include<algorithm>
void printBoard(std::vector<std::string> s)
{
	for(int i = 0; i<s.size(); i++)
		std::cout<<s[i]<<std::endl;
}
int findNQueens(std::vector<std::string> board)
{
	while(board[7] != "QQQQQQQQ")
	{
		for(int i = 0; i<8; i++)
		{
			
		}
	}
}
int main()
{
	std::vector<std::string> board;
	board.push_back("QQQQQQQQ");
	for(int i = 0; i<7; i++)
	{
		board.push_back("EEEEEEEE");
	}
	printBoard(board);
}
