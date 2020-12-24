#pragma once

#include <list>

class Hash
{
	int BUCKET;

	std::list<int>* table;

public:
	Hash(int);

	void insert(int);

	void remove(int);

	int hash(int);

	void displayHash();
};

