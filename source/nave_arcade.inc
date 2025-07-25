//----- CONSTRUCTION OF THE NAVE ARCADE

#ifndef(arcade_step)
	#include "arcade_step.inc"
#end

#macro nave_arcade()
	union {		
		#local i=-1;
		#while (i<2)
			object {arcade_step(6.5,0.4) rotate 90*i*y translate <8.29*i,0,-3.25>}
			#local j=0;
			#while (j<5)
				object {arcade_step(7.18,0.4) rotate 90*i*y translate <8.29*i,0,3.59+7.18*j>}
				#local j=j+1;
			#end
			object {arcade_step(6.71,0.4) rotate 90*i*y translate <8.29*i,0,39.255>}
			#local i=i+2;
		#end
	}
#end