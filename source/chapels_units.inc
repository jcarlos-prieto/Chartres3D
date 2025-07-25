//----- DISTRIBUTION OF EACH CHAPEL

#ifndef(chapel)
	#include "chapel.inc" 
#end

#macro chapels_units()
	union {
		object {chapel(1,2) translate 21.1*z rotate -74.12*y}
		object {chapel(2,3) translate 24.44*z rotate -45.48*y}
		object {chapel(3,1) translate 19.93*z rotate -22.39*y}
		object {chapel(4,3) translate 24.43*z}
		object {chapel(5,1) translate 19.93*z rotate 22.39*y}
		object {chapel(6,3) translate 24.44*z rotate 45.48*y}
		object {chapel(7,2) translate 21.1*z rotate 74.12*y}
	}
#end