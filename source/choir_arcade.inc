//----- CONSTRUCTION OF THE ARCADE

#ifndef(arcade_step)
	#include "arcade_step.inc"
#end

#macro choir_arcade()
	union {		
		#local i=-1;
		#while (i<2)
			object {arcade_step(6.5,0.4) rotate 90*i*y translate <8.29*i,0,-3.25>}
			#local j=0;
			#while (j<3)
				object {arcade_step(7.18,0.4) rotate 90*i*y translate <8.29*i,0,3.59+7.18*j>}
				#local j=j+1;
			#end
			#local i=i+2;
		#end
      
      union {
			#local i=0;
			#while (i<7)
				object {arcade_step(4.15,0.25) rotate -90*y translate -8.15*x rotate 180/7*(i+0.5)*y}
				#local i=i+1;
			#end
			translate 21.76*z
		}
	}
#end