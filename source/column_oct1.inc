//----- COLUMN (OCTOGONAL TYPE) - SMALL
//      h0: Lower ornament elevation

#ifndef(column0)
	#include "column0.inc"
#end
#ifndef(column1_oct)
	#include "column1_oct.inc"
#end
#ifndef(column2a)
	#include "column2a.inc"
#end

#macro column_oct1(h0)
	union {
		object {column0() translate h0*y}
		object {column1_oct(h0) translate 0.28*y}
		object {column2a() translate 9.08*y}
	}
#end