#ifndef _dependecygraph
#define _dependecygraph
#include"ARM.h"
#include <sys/stat.h>
#include<iostream>
#include<list>
#include<dlfcn.h>
#include<stdlib.h>

typedef std::vector<Form> (*FPointer)(const std::string&);


class node
{
public:
	node(File *file) : m_file(file) {}
	node(std::vector<Form>::iterator &iterator)
	{
		m_file = &(iterator->m_target);

		for (auto it = iterator->m_inputs.begin(); it != iterator->m_inputs.end(); ++it)
			m_dependecies.push_back(new node(&(*it)));

	}
	~node()
	{
		for (auto it = m_dependecies.begin(); it != m_dependecies.end(); ++it)
			delete  (*it);
	}


	File *m_file;
	std::list<node*> m_dependecies;
};



class DAG
{
public:
	DAG()  {}
	~DAG()
	{
		for (auto it = m_roots.begin(); it != m_roots.end(); ++it)
			delete (*it);
	}

	void create(std::vector<Form>&);
	void update();


private:
	void create_helper(std::vector<Form>::iterator&);
	void DFS(node *&);
	std::list<node*> m_roots;
};

#endif