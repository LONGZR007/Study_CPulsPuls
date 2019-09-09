#pragma warning(disable : 4996)
#include "Cow.h"
#include <cstring>

Cow::Cow()
{
	name[0] = '\0';
	hobby = new char[1];
	*hobby = '\0';
	weight = 0;
}

Cow::Cow(const char* nm, const char* ho, double wt)
{
	std::strcpy(name, nm);
	hobby = new char[strlen(ho) + 1];
	std::strcpy(hobby, ho);
	weight = wt;

}

Cow::Cow(const Cow &c)
{
	std::strcpy(name, c.name);
	hobby = new char[strlen(c.hobby) + 1];
	strcpy(hobby, c.hobby);
	weight = c.weight;
}

Cow::~Cow()
{
	delete[] hobby;
}

Cow& Cow::operator=(const Cow& c)
{
	std::strcpy(name, c.name);
	delete[] hobby;
	hobby = new char[strlen(c.hobby) + 1];
	std::strcpy(hobby, c.hobby);
	weight = c.weight;

	return *this;
}

void Cow::ShowCow() const
{
	std::cout << "name:" << name << ".    hobby:" << hobby << ".    weight:" << weight << std::endl;
}