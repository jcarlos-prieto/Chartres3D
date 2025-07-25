//----- CONSTRUCTION OF THE CIRCULAR COLUMN ROWS IN THE AMBULATORY

#ifndef(column_cyl2)
	#include "column_cyl2.inc" 
#end
#ifndef(column_oct2)
	#include "column_oct2.inc" 
#end

#macro ambulatory_columns()
	union {
		object {column_cyl2(0) translate 16.58*z rotate 12.59*y}
		object {column_cyl2(0) translate 16.58*z rotate 32.65*y}
		object {column_cyl2(0) translate 16.58*z rotate 60.56*y}
		object {column_cyl2(0) translate 16.58*z rotate -12.59*y}
		object {column_cyl2(0) translate 16.58*z rotate -32.65*y}
		object {column_cyl2(0) translate 16.58*z rotate -60.56*y}
	}
#end