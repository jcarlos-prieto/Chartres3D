//----- CONSTRUCTION OF THE CHOIR TRIFORIUM

#ifndef(triforium_step)
	#include "triforium_step.inc"
#end

#macro choir_triforium()
	union {		
		//--- Right side
		#local i=-1;
		#while (i<2)
			object {triforium_step(4,6.5) rotate 90*i*y translate <7.9*i,0,-3.25>}
			#local j=0;
			#while (j<3)
				object {triforium_step(5,7.18) rotate 90*i*y translate <7.9*i,0,3.59+7.18*j>}
				#local j=j+1;
			#end
			#local i=i+2;
		#end
      
      union {
			#local i=0;
			#while (i<7)
				object {triforium_step(2,4.15) rotate -90*y translate -7.76*x rotate 180/7*(i+0.5)*y}
				#local i=i+1;
			#end
			translate 21.76*z
		}
	}
#end