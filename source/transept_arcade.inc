//----- CONSTRUCTION OF THE ARCADE OF THE TRANSEPT

#ifndef(arcade_step)
	#include "arcade_step.inc"
#end

#macro transept_arcade()
	union {
		object {arcade_step(7.61,0.4) rotate 180*y translate <-12.775,0,-7.18>}
		object {arcade_step(8.29,0.4) rotate 180*y translate <-20.725,0,-7.18>}
		object {arcade_step(8.29,0.4) rotate 180*y translate <-29.015,0,-7.18>}
		object {arcade_step(7.61,0.4) rotate 180*y translate <12.775,0,-7.18>}
		object {arcade_step(8.29,0.4) rotate 180*y translate <20.725,0,-7.18>}
		object {arcade_step(8.29,0.4) rotate 180*y translate <29.015,0,-7.18>}
		object {arcade_step(7.61,0.4) translate <-12.775,0,7.18>}
		object {arcade_step(8.29,0.4) translate <-20.725,0,7.18>}
		object {arcade_step(8.29,0.4) translate <-29.015,0,7.18>}
		object {arcade_step(7.61,0.4) translate <12.775,0,7.18>}
		object {arcade_step(8.29,0.4) translate <20.725,0,7.18>}
		object {arcade_step(8.29,0.4) translate <29.015,0,7.18>}
	}
#end