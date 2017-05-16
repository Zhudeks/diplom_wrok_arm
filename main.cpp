#include"DependecyGraph.h"



int main(int argc, char* argv[])
{
	if (argc != 2)
	{
		std::cout<<"Error\n";
		return 0;
	}
	
	void *handle ;
	if (argv[1][8] == '\0')	
		handle = dlopen("E:\\folder\\ParseMakeFile.so", RTLD_LAZY);
	else
	{
		std::cout<<"Such .so fiile is not found\n";
		return 0;
	}
		

	
	
	
	if (!handle)
	{
		std::cout<<"Such .so file doesn't exist\n";
		return 0;
	}
	
	FPointer GetList = (FPointer)dlsym(handle,"GetList");
	if (!GetList)
	{
		std::cout<<"Such function  doesn't exist\n";
		return 0;
	}
	
	
	ARM ob(GetList("E:\\dir\\MakeFile.txt"));
	DAG graph;
	graph.create(ob.GetList());
	graph.update();
	
	
	dlclose(handle);
	
	return 0;
}
