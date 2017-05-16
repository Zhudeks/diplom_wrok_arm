#ifndef _ARM
#define _ARM
#include"IntermediateView.h"
#include<fstream>




class ARM
{
public:
	ARM() {}
	ARM(std::vector<Form> list) : m_list(list) {}


	void SortList();
	void CountDependecies();
	std::vector<Form>& GetList();




private:
	std::vector<Form> m_list;
	
	bool Find(std::vector<InputFile>&, OutFile &);
	bool AlreadyExist(std::vector<Form>&, OutFile&);
	bool IsIncluded(std::vector<InputFile> &, std::string&);


};



#endif