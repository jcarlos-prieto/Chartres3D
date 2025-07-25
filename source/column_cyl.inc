//----- COLUMN (CYLINDRICAL TYPE)
//      h0: Lower ornament elevation

#ifndef(column0)
	#include "column0.inc"
#end
#ifndef(column1_cyl)
	#include "column1_cyl.inc"
#end
#ifndef(column2)
	#include "column2.inc"
#end
#ifndef(column3_cyl)
	#include "column3_cyl.inc"
#end

#macro column_cyl(h0)
	union {
		object {column0() translate h0*y}
		object {column1_cyl(h0) translate 0.28*y}
		object {column2() translate 9.08*y}
		object {column3_cyl() translate 9.28*y}
	}
#end