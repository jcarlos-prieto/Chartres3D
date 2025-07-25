//----- CONSTRUCTION OF THE CHOIR COLUMN

#ifndef(column_oct)
	#include "column_oct.inc" 
#end
#ifndef(column_cyl)
	#include "column_cyl.inc" 
#end
#ifndef(column_oct3)
	#include "column_oct3.inc" 
#end
#ifndef(column_cho)
	#include "column_cho.inc" 
#end

//----- CONSTRUCTION OF THE COLUMN ROWS
#macro choir_columns()
	union {
		#local i=-1;
		#while (i<2)
			object {column_cyl(0) rotate 90*i*y translate <8.29*i,0,0>}
			object {column_oct(0) rotate 90*i*y translate <8.29*i,0,7.18>}
			object {column_cyl(0) rotate 90*i*y translate <8.29*i,0,14.36>}
			object {column_oct3(0,-i) rotate 90*i*y translate <8.29*i,0,21.54>}
			#local i=i+2;
		#end
		union {
			#local i=0;
			#while (i<6)
				object {column_cho() rotate -90*y translate -8.29*x rotate 180/7*(i+1)*y}
				#local i=i+1;
			#end
			translate 21.76*z
		}
	}
#end