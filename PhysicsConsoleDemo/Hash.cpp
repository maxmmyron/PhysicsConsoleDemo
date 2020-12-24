#include "Hash.h"

#include <list>
#include <iostream>
#include <iterator>

Hash::Hash(int b) 
{
	this->BUCKET = b;
	table = new std::list<int>[BUCKET];
}

void Hash::insert(int key)
{
	int index = hash(key);
	table[index].push_back(key);
}

void Hash::remove(int key) 
{
	int index = hash(key);

	std::list<int> :: iterator i;
	for (i = table[index].begin(); i != table[index].end(); i++)
	{
		if (*i == key)
		{
			break;
		}
	}

	if (i != table[index].end())
	{
		table[index].erase(i);
	}
}

void Hash::displayHash()
{
	for (int i = 0; i < BUCKET; i++)
	{
		std::cout << i;
		for (auto x : table[i])
		{
			std::cout << " --> " << x;
		}
		std::cout << std::endl;
	}
}
