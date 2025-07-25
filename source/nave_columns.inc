//----- CONSTRUCTION OF THE NAVE COLUMN

#ifndef(column_oct)
	#include "column_oct.inc" 
#end
#ifndef(column_cyl)
	#include "column_cyl.inc" 
#end
#ifndef(column_squ2)
	#include "column_squ2.inc" 
#end

#macro nave_columns()
	union {
		#local i=-1;
		#while (i<2)
			#local j=0;
			#while (j<6)
				object {column_oct(0) rotate 90*i*y translate <8.29*i,0,7.18*j>}
				#local j=j+2;
			#end
			#local j=1;
			#while (j<6)
				object {column_cyl(0) rotate 90*i*y translate <8.29*i,0,7.18*j>}
				#local j=j+2;
			#end
			object {column_squ2(-i,1) translate <8.29*i,0,43.08>}
			#declare i=i+2;
		#end
	}
#end