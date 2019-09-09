#include "Cow.h"
#include "main.h"

int main()
{
	Cow Cow1;
	Cow1.ShowCow();
	Cow Cow2 = Cow("2ºÅ", "À­Êº", 80);
	Cow2.ShowCow();
	Cow Cow3("3ºÅ", "³Ô", 70);
	Cow3.ShowCow();
	Cow Cow4 = Cow3;
	Cow4.ShowCow();
	Cow* Cow5 = new Cow(Cow3);
	Cow5->ShowCow();
	Cow1 = Cow2;
	Cow1.ShowCow();

	return 0;
}