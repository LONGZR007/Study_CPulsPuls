/* µÚ8ÕÂ ±à³ÌÁ·Ï° 6. */

#include <iostream>
#include <cctype>
#include <string>

using namespace std;

template<class T>

T maxn(T num, int i);

int main()
{
	int x[6] = {564, 24, 67, 3, 6, 5};
	double y[6] = { 564.5, 245.4, 67.55, 3.54, 6.45, 5.0 };

	cout << "int max is:" << maxn(x, 6) << endl;
	cout << "double max is:" << maxn(y, 6) << endl;
}

template<class T>
T maxn(T num[], int xC);
{
	decltype(num[0]) maxn = num[0];

	for ( i = 1; i < xC; i++)
	{
		maxn = num[i] > maxn ? num[i] : maxn;
	}

	return axn;
}
