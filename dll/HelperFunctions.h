#ifndef _HelperFunctions
#define _HelperFunctions
#include"IntermediateView.h"
#include<fstream>


bool IsThereFullstop(const std::string&);
OutFile GetOutFile(const std::string&);
std::vector<InputFile> GetDependecies(const std::string &);


#endif