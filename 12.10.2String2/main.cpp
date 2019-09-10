#include "string2.h"               // includes <iostream>

int main(void)
{
	using namespace std;

	String s1(" and I am C++ student.");
	String s2 = "Please enter yuor name:";
	String s3;
s2 =  s1;
	cout << s2;
	cin >> s3;
	s2 = "My name is" + s3;
	cout << s2 << ".\n";
	
	s2.stringup();
	cout << "The string \n" << s2 << "\ncontains " << s2.has('A')
		<< "'a' characters in it.\n";
	s1 = "red";

	String rgb[3] = {(s1), ("green"), ("blue")};
	cout << "Enter the name of a primary color for mixiang lighr:";

	String ans;
	bool success = false;
	while (cin >> ans)
	{
		ans.stringlow();
		for (int i = 0; i < 3; i++)
		{
			if (ans == rgb[i])
			{
				cout << "That's righr!\n";
				success = true;
				break;
			}
		}
		if (success)
			break;
		else
			cout << "Try ahain!\n";

		cout << "Bye\n";

	}

	return 0;
}