#!C:\Tcl\bin\tclsh

oo::class create makefile {
	method set_target {value} {
		my variable target
		set target $value
	}
	
	method set_dependencies {value} {
		my variable dependencies
		set dependencies $value
	}
	
	method set_command {value} {
		my variable command
		set command $value
	}

	method get_target {} {
		my variable target
		return $target
	}
	
	method get_dependencies {} {
		my variable dependencies
		return $dependencies
	}
	
	method get_command {} {
		my variable command
		return $command
	}
}

set target_list {edit}
set dependencies_list {main.o kbd.o command.o display.o}
set command_list {g++ -o edit main.o kbd.o command.o display.o}

set a1 [makefile new]
$a1 set_target $target_list
$a1 set_dependencies $dependencies_list
$a1 set_command $command_list

puts [$a1 get_target]
puts [$a1 get_dependencies]
puts [$a1 get_command]