//----- COLUMN (CHOIR TYPE)

#ifndef(column_cyl2)
	#include "column_cyl2.inc"
#end
#ifndef(column3_cho)
	#include "column3_cho.inc"
#end


#macro column_cho()
	union {
		object {column_cyl2(0)}
		object {column3_cho() translate 9.28*y}
	}
#end