#include"HelperFunctions.h"

bool IsThereFullstop(const std::string &line)
{
	for (int i = 0; i < line.size(); ++i)
		if (line[i] == ':' && line[i - 1] == ' ')
			return true;

	return false;
}


OutFile GetOutFile(const std::string &line)
{
	std::string name;

	for (int i = 0; line[i] != ':' && line[i] != ' '; ++i)
		name.push_back(line[i]);

	return OutFile("E:\\dir", name);
}
std::vector<InputFile> GetDependecies(const std::string &line)
{
	std::vector<InputFile> dependecies;
	int index;

	for (index = 0; index < line.size(); ++index)
		if (line[index] == ' ' && line[index + 1] == ':')
			break;


	for (int i = index + 2; i < line.size(); ++i)
	{
		std::string name;
		for (; i < line.size() && line[i] == ' '; ++i);

		if (i == line.size())
			break;

		for (; i < line.size() && line[i] != ' '; ++i)
			name.push_back(line[i]);

		dependecies.push_back(InputFile("E:\\dir", name));
	}

	return dependecies;
}