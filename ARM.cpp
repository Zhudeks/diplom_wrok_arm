#include "arm.h"


void ARM::SortList()
{
	std::vector<Form> list_1;
	std::vector<Form> list_2;
	std::vector<Form> sortlist;



	for (auto it = m_list.begin(); it != m_list.end(); ++it)
	{
		bool flag = true;
		for (auto it1 = m_list.begin(); it1 != m_list.end(); ++it1)
			if (Find(it1->m_inputs, it->m_target))
			{
				flag = false;
				break;
			}

		if (flag)
			sortlist.push_back(*it);
	}



	for (auto it = sortlist.begin(); it != sortlist.end(); ++it)
	{
		for (auto it1 = m_list.begin(); it1 != m_list.end(); ++it1)
			if (Find(it->m_inputs, it1->m_target) && !AlreadyExist(list_1, it1->m_target))
				list_1.push_back(*it1);
	}



	for (auto it = list_1.begin(); it != list_1.end(); ++it)
	{
		for (auto it1 = m_list.begin(); it1 != m_list.end(); ++it1)
			if (Find(it->m_inputs, it1->m_target) && !AlreadyExist(list_2, it1->m_target))
				list_2.push_back(*it1);
	}


	for (auto it = list_1.begin(); it != list_1.end(); ++it)
		sortlist.push_back(*it);


	for (auto it = list_2.begin(); it != list_2.end(); ++it)
		sortlist.push_back(*it);

	m_list = sortlist;
}

void ARM::CountDependecies()
{
	for (auto it = m_list.begin(); it != m_list.end(); ++it)
	{
		for (auto it1 = it->m_inputs.begin(); it1 != it->m_inputs.end(); ++it1)
		{
			if ((it1->GetName().find(".h")) != std::string::npos || (it1->GetName().find(".cpp")) != std::string::npos)
			{
				std::ifstream file(it1->GetPath());
				std::string line;

				while (std::getline(file, line))
				{
					if (line.empty())
						continue;

					if (line.find("#include\"") != std::string::npos && !IsIncluded(it->m_inputs, line))
						it->m_inputs.push_back(InputFile(it1->GetAddress(), line));
				}
			}
		}
	}
}

std::vector<Form>& ARM::GetList()
{
	SortList();
	CountDependecies();


	return m_list;
}




//helper functions
bool ARM::Find(std::vector<InputFile>& inputs, OutFile &target)
{
	for (auto it = inputs.begin(); it != inputs.end(); ++it)
		if (target.GetName() == it->GetName())
			return true;

	return false;
}

bool ARM::AlreadyExist(std::vector<Form>& list, OutFile &target)
{
	for (auto it = list.begin(); it != list.end(); ++it)
		if (target.GetName() == it->m_target.GetName())
			return true;

	return false;
}

bool ARM::IsIncluded(std::vector<InputFile>& dependecies, std::string &line)
{
	std::string str("#include");
	line.replace(line.find(str), str.length(), "");
	line.replace(line.find('"'), 1, "");
	line.replace(line.find('"'), 1, "");


	for (auto it = dependecies.begin(); it != dependecies.end(); ++it)
		if (it->GetName() == line)
			return true;

	return false;
}