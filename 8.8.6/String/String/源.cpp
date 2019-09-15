/* µÚ8ÕÂ ±à³ÌÁ·Ï° 6. */

#include <iostream>
#include <cctype>
#include <string>

using namespace std;

template<class T>

T maxn(T num[], int i);
char* maxn(char* num[], int xC);

int main()
{
	int x[6] = { 564, 24, 67, 3, 6, 5 };
	double y[6] = { 564.5, 245.4, 67.55, 3.54, 6.45, 5.0 };
	char a[] = "sgdf";
	char b[] = "sdfsdfsdfsdfsdfs";
	char c[] = "sdfsdfsdfsdf";
	char d[] = "sdfsdfsdfsdaadfs";
	char e[] = "g";

	char* xc[5];
	xc[0] = a;
	xc[1] = b;
	xc[2] = c;
	xc[3] = d;
	xc[4] = e;

	cout << "int max is:" << maxn(x, 6) << endl;
	cout << "double max is:" << maxn(y, 6) << endl;
	cout << "double max is:" << maxn(xc, 5) << endl;
}

template<class T>
T maxn(T num[], int xC)
{
	decltype(num[0]) max = num[0];

	for (int i = 1; i < xC; i++)
	{
		max = num[i] > max ? num[i] : max;
	}

	return max;
}

char* maxn(char* num[], int xC)
{
	char* max = num[0];

	for (int i = 1; i < xC; i++)
	{
		if (strlen(num[i]) > strlen(max))
		{
			max = num[i];
		}
	}

	return max;
}
