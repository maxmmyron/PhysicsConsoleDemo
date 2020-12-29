#include "File.h"

#include <iostream>
#include <fstream>

/*************************
	Constructors
*************************/
File::File(const char* fileName, std::ios_base::openmode flags)
{
	file.open(fileName, flags);
	File::IsOpen = file.is_open();
}

/*************************
	File Management
*************************/
void File::Close()
{
	file.close();
}

/*************************
	File IO
*************************/

//File::Write is not here due to Linker Errors (LNK 2019) because of the template variable :/

/*************************
	Getters & Setters
*************************/
const char* File::GetFileName()
{
	return fileName;
}