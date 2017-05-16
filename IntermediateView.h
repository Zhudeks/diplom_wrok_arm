#ifndef _IntermediateView
#define _IntermediateView
#include"file.h"
#include<vector>



class Form
{
public:
	Form() {}
	Form(OutFile target, std::vector<InputFile> inputs) : m_target(target), m_inputs(inputs) {}

	
	
	OutFile m_target;
	std::vector<InputFile> m_inputs;
};


#endif