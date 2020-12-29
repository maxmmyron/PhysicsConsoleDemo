#pragma once

#include <iostream>
#include <fstream>

class File
{
public:
	/*************************
		Constructors
	*************************/
	File() = default;
	File(const char*, std::ios_base::openmode flags = std::ios_base::in | std::ios_base::out);

	/*************************
		File Management
	*************************/
	void Close();
	bool IsOpen;

	/*************************
		File IO
	*************************/
	template <typename T>
	void Write(T contents, bool newLine = true)
	{
		if (newLine)
		{
			file << contents << "\n";
		}
		else
		{
			file << contents;
		}
		
	}

	/*************************
		Getters & Setters
	*************************/
	const char* GetFileName();

private:
	std::fstream file;
	const char* fileName{};
};

