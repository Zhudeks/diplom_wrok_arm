#include "DependecyGraph.h"


void DAG::create(std::vector<Form> &list)
{
	for (auto it = list.begin(); it != list.end(); ++it)
		create_helper(it);
}

void DAG::create_helper(std::vector<Form>::iterator&iterator)
{
	bool flag = true;
	for (auto it = m_roots.begin(); it != m_roots.end(); ++it)
	{
		for (auto it1 = (*it)->m_dependecies.begin(); it1 != (*it)->m_dependecies.end(); ++it1)
			if (iterator->m_target.GetName() == (*it1)->m_file->GetName())
			{
				(*it1)->m_file = &(iterator->m_target);
				for (auto iter = iterator->m_inputs.begin(); iter != iterator->m_inputs.end(); ++iter)
					(*it1)->m_dependecies.push_back(new node(&(*iter)));

				flag = false;
				break;
			}
	}

	if (flag)
		m_roots.push_back(new node(iterator));
}

void DAG::update()
{
	for (auto it = m_roots.begin(); it != m_roots.end(); ++it)
		DFS((*it));
}

void DAG::DFS(node *& newroot)
{
	for (auto it = newroot->m_dependecies.begin(); it != newroot->m_dependecies.end(); ++it)
	{
		DFS(*it);

		OutFile * ptr = dynamic_cast<OutFile*> (newroot->m_file);
		struct stat inputfileInfo;
		struct stat targetfileInfo;

		if (stat((newroot->m_file->GetPath()).c_str(), &targetfileInfo) == 0)
		{
			stat((*it)->m_file->GetPath().c_str(), &inputfileInfo);
			if (inputfileInfo.st_mtime - targetfileInfo.st_mtime > 0)
				ptr->SetFlag(true);
		}
		else
			ptr->SetFlag(true);
	}



	if (newroot->m_dependecies.size() != 0)
	{
		OutFile * ptr = dynamic_cast<OutFile*> (newroot->m_file);
		if (ptr->GetFlag())
		{
			std::cout << ptr->GetCommand() << '\n';
			system(ptr->GetCommand().c_str());
		}
	}
}