//----- CONSTRUCTION OF THE TRIFORIUM OF THE TRANSEPT

#ifndef(triforium_step)
	#include "triforium_step.inc"
#end

#macro transept_triforium()
	union {
		object {triforium_step(5,7.61) rotate 180*y translate <-12.775,0,-6.79>}
		object {triforium_step(5,8.29) rotate 180*y translate <-20.725,0,-6.79>}
		object {triforium_step(5,8.29) rotate 180*y translate <-29.015,0,-6.79>}
		object {triforium_step(5,7.61) rotate 180*y translate <12.775,0,-6.79>}
		object {triforium_step(5,8.29) rotate 180*y translate <20.725,0,-6.79>}
		object {triforium_step(5,8.29) rotate 180*y translate <29.015,0,-6.79>}
		object {triforium_step(5,7.61) translate <-12.775,0,6.79>}
		object {triforium_step(5,8.29) translate <-20.725,0,6.79>}
		object {triforium_step(5,8.29) translate <-29.015,0,6.79>}
		object {triforium_step(5,7.61) translate <12.775,0,6.79>}
		object {triforium_step(5,8.29) translate <20.725,0,6.79>}
		object {triforium_step(5,8.29) translate <29.015,0,6.79>}
	}
#end