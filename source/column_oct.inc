//----- COLUMN (OCTOGONAL TYPE)
//      h0: Lower ornament elevation

#ifndef(column0)
	#include "column0.inc"
#end
#ifndef(column1_oct)
	#include "column1_oct.inc"
#end
#ifndef(column2)
	#include "column2.inc"
#end
#ifndef(column3_oct)
	#include "column3_oct.inc"
#end

#macro column_oct(h0)
	union {
		object {column0() translate h0*y}
		object {column1_oct(h0) translate 0.28*y}
		object {column2() translate 9.08*y}
		object {column3_oct() translate 9.28*y}
	}
#end