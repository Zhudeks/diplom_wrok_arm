#include"HelperFunctions.h"
template class __declspec(dllexport) std::vector<Form>;



extern "C"
{
	__declspec(dllexport)  std::vector<Form> GetList(const std::string &PathMAkeFile)
	{
		std::ifstream makefile(PathMAkeFile);
		std::string line;
		std::string prevline;

		OutFile target;
		std::vector<InputFile> dependecies;
		std::vector<Form> list;



		while (std::getline(makefile, line))
		{
			if (line.empty())
				continue;

			if (IsThereFullstop(line))
			{
				prevline = line;
				target = GetOutFile(line);
				dependecies = GetDependecies(line);
			}
			else
			{
				if (IsThereFullstop(prevline))
				{
					target.SetCommand(line);
					list.push_back(Form(target, dependecies));
				}
				prevline = line;
			}
		}



		return list;
	}
}