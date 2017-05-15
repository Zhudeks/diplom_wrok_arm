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


set f_in1 [open "Makefile" "r"]
set f_in [read $f_in1]
set input_list [split $f_in '\n']
close $f_in1

set target [list]
set dependencies [list]
set command [list]

set i 0
foreach el $input_list {
	#puts $i
	if {![regexp {^$} $el]} {
		if {[regexp {^[\s]} $el] | [regexp {^[\t]} $el] | [regexp {^[\n]} $el] | [regexp {^[\r]} $el] | [regexp {^$} $el]} {
			#puts "this line started with space"
			if {[regexp {\s*((([a-z]+)[+]*)\s+(\-?[a-z]*)\s+(([a-z]+\.?[a-z]+\s?)+))} $el -> com]} {
				lappend command $com
				#puts $com
				#set ob ob
				#dict set objects ob $i command "$com"
				#[set ob[set i]] set_command $com
			}
		incr i 1
		} else {
			#set ob ob
			#dict set objects $ob $i [makefile new]
			#set ob$i [makefile new]
			
			#puts "this line not started with space"
			if {[regexp {(^[a-z]+\.?[a-z]?)\s:(\s(([a-z]+\.?[a-z]+\s?)+)\s?)?} $el -> tar dep_ dep dep__]} {
				lappend target $tar
				#puts $target
				#dict set objects ob $i target "$tar"
				#[set ob[set i]] set_target $tar
				
				lappend dependencies $dep
				#puts $dependencies
				#set ob ob
				#dict set objects ob $i dependencies "$dep"
				#[set ob[set i]] set_dependencies $dep
			}
		}
	}
}




# for {set j 0} {$j<$i} {incr j} {
	# puts [[set ob[set j]] get_target]
	# puts [[set ob[set j]] get_dependencies]
	# puts [[set ob[set j]] get_command]
# }


