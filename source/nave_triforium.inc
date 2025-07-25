//----- CONSTRUCTION OF THE NAVE TRIFORIUM

#ifndef(triforium_step)
	#include "triforium_step.inc"
#end

#macro nave_triforium()
	union {
		#local i=-1;
		#while (i<2)
			object {triforium_step(4,6.5) rotate 90*i*y translate <7.9*i,0,-3.25>}
			#local j=0;
			#while (j<5)
				object {triforium_step(4,7.18) rotate 90*i*y translate <7.9*i,0,3.59+7.18*j>}
				#local j=j+1;
			#end
			object {triforium_step(3,6.71) rotate 90*i*y translate <7.9*i,0,39.255>}
			#local i=i+2;
		#end
	}
#end