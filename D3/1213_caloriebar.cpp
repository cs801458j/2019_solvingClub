#include <iostream>
using namespace std;

int T;
char f[11];
char str[1001];
int main()
{
	
	for (int t = 1; t <= 10; t++)
	{
		cin >> T;
		cin >> f;
		cin >> str;
		int f_l,s_l;
		

		for (int i = 0; i < 11; i++)
		{
			if (f[i] == '\0')
			{
				f_l = i;
				break;
			}
		}
		for (int i = 0; i < 1001; i++)
		{
			if (str[i] == '\0')
			{
				s_l = i;
				break;
			}
		}
		int answer = 0;
		for (int i = 0; i < s_l;)
		{
			
			if (str[i] == f[0])
			{
				bool find = true;
				for (int j = 0; j < f_l; j++)
				{
					if (str[i + j] != f[j])
					{
						find = false;
						break;
					}
				}
				if (find)
				{
					answer++;
					i += f_l;
				}
				else
					i++;
			}
			else
				i++;
		}
		printf("#%d %d\n",t,answer);
	}
	return 0;
}