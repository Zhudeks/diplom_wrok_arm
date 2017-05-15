#include <stdlib.h>
#include <tcl.h>
#include <iostream>
#include <string>
#include <list>

using namespace std;

Tcl_Interp *interp;
int ExtendTcl (Tcl_Interp *interp) {
    /*
    Create Tcl Commands, etc.
    */
    return TCL_OK;
}

class makefile {

	private:
		string target;
		string dependencies;
		string command;
	
	public:
		void set_target (string value) {
			target=value;
		}
		
		void set_dependencies (string value) {
			dependencies=value;
		}
		
		void set_command (string value) {
			command=value;
		}

		string get_target () {
			return target;
		}
		
		string get_dependencies () {
			return dependencies;
		}
		
		string get_command () {
			return command;
		}
	
};

int main (int argc ,char *argv[]) {
    Tcl_FindExecutable(argv[0]);
    interp = Tcl_CreateInterp();
    if (Tcl_Init(interp) != TCL_OK) {
        return EXIT_FAILURE;
    }
    if (ExtendTcl(interp) != TCL_OK) {
        fprintf(stderr ,"Tcl_Init error: %s\n" ,Tcl_GetStringResult(interp));
        exit(EXIT_FAILURE);
    }
    /*
    do stuff
    */
	
	Tcl_EvalFile(interp,"Armfile_parser.tcl");
	
	list <makefile> list;

	Tcl_Obj *theList_target = Tcl_GetVar2Ex(interp, string("target").c_str(), NULL, TCL_LEAVE_ERR_MSG);
	if (theList_target == NULL) {
		// Was an error; message in interpreter result...
	}
	
	int objc_target;
	Tcl_Obj **objv_target;
	if (Tcl_ListObjGetElements(interp, theList_target, &objc_target, &objv_target) == TCL_ERROR) {
		// Not a list! error message in interpreter result...
	}
		
	Tcl_Obj *theList_dependencies = Tcl_GetVar2Ex(interp, string("dependencies").c_str(), NULL, TCL_LEAVE_ERR_MSG);
	if (theList_dependencies == NULL) {
		// Was an error; message in interpreter result...
	}
	
	int objc_dependencies;
	Tcl_Obj **objv_dependencies;
	if (Tcl_ListObjGetElements(interp, theList_dependencies, &objc_dependencies, &objv_dependencies) == TCL_ERROR) {
		// Not a list! error message in interpreter result...
	}
		
	Tcl_Obj *theList_command = Tcl_GetVar2Ex(interp, string("command").c_str(), NULL, TCL_LEAVE_ERR_MSG);
	if (theList_command == NULL) {
		// Was an error; message in interpreter result...
	}
	
	int objc_command;
	Tcl_Obj **objv_command;
	if (Tcl_ListObjGetElements(interp, theList_command, &objc_command, &objv_command) == TCL_ERROR) {
		// Not a list! error message in interpreter result...
	}
	
	for (int i=0 ; i<objc_command ; i++) {
		string value_target = Tcl_GetString(objv_target[i]);
		string value_dependencies = Tcl_GetString(objv_dependencies[i]);
		string value_command = Tcl_GetString(objv_command[i]);
		
		makefile ob;
		
		ob.set_target(value_target);
		ob.set_dependencies(value_dependencies);
		ob.set_command(value_command);
		
		list.push_back(ob);
	}
	
	for (std::list<makefile>::iterator it = list.begin(); it != list.end(); it++) {
		std::cout << it->get_target()<<std::endl;
		std::cout << it->get_dependencies()<<std::endl;
		std::cout << it->get_command()<<std::endl;
		std::cout<<std::endl;
	}
	
	
	

	
	Tcl_Finalize();
    return EXIT_SUCCESS;
}
