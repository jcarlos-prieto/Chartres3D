//----- CONSTRUCTION OF THE TRANSEPT COLUMN

#ifndef(column_oct)
	#include "column_oct.inc" 
#end
#ifndef(column_cyl)
	#include "column_cyl.inc" 
#end
#ifndef(column_squ1)
	#include "column_squ1.inc" 
#end
#ifndef(column_squ3)
	#include "column_squ3.inc" 
#end

#macro transept_columns()
	union {
		//--- Four square columns in the center
		object {column_squ1(1,1) translate <-8.29,0,-7.18>}
		object {column_squ1(-1,1) translate <8.29,0,-7.18>}
		object {column_squ1(1,-1) translate <-8.29,0,7.18>}
		object {column_squ1(-1,-1) translate <8.29,0,7.18>}
	
		//--- Four square columns at both sides
		object {column_squ3(1,1) translate <-33.63,0,-7.18>}
		object {column_squ3(-1,1) translate <33.63,0,-7.18>}
		object {column_squ3(1,-1) translate <-33.63,0,7.18>}
		object {column_squ3(-1,-1) translate <33.63,0,7.18>}

		//--- Columns between aisle and main part of the transept	
		object {column_oct(0) rotate 180*y translate <-16.58,0,-7.18>}
		object {column_cyl(0) rotate 180*y translate <-24.87,0,-7.18>}
		object {column_oct(0) rotate 180*y translate <16.58,0,-7.18>}
		object {column_cyl(0) rotate 180*y translate <24.87,0,-7.18>}
		object {column_oct(0) translate <-16.58,0,7.18>}
		object {column_cyl(0) translate <-24.87,0,7.18>}
		object {column_oct(0) translate <16.58,0,7.18>}
		object {column_cyl(0) translate <24.87,0,7.18>}	
	}
#end