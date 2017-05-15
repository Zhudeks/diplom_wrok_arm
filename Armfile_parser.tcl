#!C:\Tcl\bin\tclsh

set f_in1 [open "Armfile" "r"]
set f_in [read $f_in1]
set input_list [split $f_in '\n']
close $f_in1

set target [list]
set dependencies [list]
set command [list]

set i 0
foreach el $input_list {
	if {[regexp {^OUT\s*\((([^)])+)\)\s*:\s*IN\s*\((([^)])+)\)} $el -> p1 p2 p3 p4 p5]} {
		#puts "$p1"
		#puts "$p3"
		lappend target $p1
		lappend dependencies $p3
	}
	
	if {[regexp {^CMD\s*\((([^)])+)\)} $el -> c1 c2 c3]} {
		#puts $c1
		lappend command $c1
	}
}
