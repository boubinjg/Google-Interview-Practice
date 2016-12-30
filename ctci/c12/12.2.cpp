#include<iostream>
void reverse(char* str)
{
	int len = 0;
	while(str[len] != '\0')
		len++;

	for(int i = 0; i<len/2; i++)
	{
		char ctmp = str[i];
		str[i] = str[len-i-1];
		str[len-i-1] = ctmp;
	}
}
int main()
{
	char s[] = {'a','b','c','d','\0'};
	reverse(s);
	printf("%s\n", s);
}
