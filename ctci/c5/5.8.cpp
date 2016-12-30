#include<iostream>
bool getbit(unsigned char byte, int i)
{
	return (((1<<i) & byte) != 0);
}
void printBoard(unsigned char* screen, int width)
{
		int height = 216/width;
		for(int i = 0; i<height; i++)
		{
			for(int j = 0; j<width; j++)
			{
				for(int k = 0; k<8; k++)
				{
					std::cout<<getbit(screen[width*i + j], k);
				}
			}
			std::cout<<std::endl;
		}
		
}
void drawLine(unsigned char* screen, int width, int x1, int x2, int y)
{
		int height = 216/width;
		for(int i = x1; i<=x2; i++)
		{
			int charPos = width*y + (i/8);
			unsigned char c = screen[charPos];
			int bitSet = i%8;
			c = ((1<<bitSet) | c);
			screen[charPos] = c;
			std::cout<<charPos<<std::endl;
		}
		printBoard(screen, width);
}
int main()
{
	unsigned char c[216]; 
	for(int i = 0; i<216; i++)
	{
		c[i] = 0;
	}
	drawLine(c, 9, 20, 30, 10);
}
