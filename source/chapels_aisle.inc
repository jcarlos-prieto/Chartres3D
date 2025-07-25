//----- CONSTRUCTION OF THE AISLE BETWEEN THE CHAPELS AND THE AMBULATORY

#ifndef(aisle_wall3_step)
	#include "aisle_wall3_step.inc" 
#end

#macro chapels_aisle()
	union {
		object {aisle_wall3_step(1,0,3.14,1,0) translate 22.35*z rotate 90*y translate -0.22*z}
		object {aisle_wall3_step(2,1.9,2.5,0,1) translate 22.35*z rotate 60.56*y}
		object {aisle_wall3_step(1,1.6,1.3,1,0) translate 22.35*z rotate 32.65*y}
		object {aisle_wall3_step(2,1.1,1.5,0,1) translate 22.35*z rotate 12.59*y}
		object {aisle_wall3_step(2,1.5,1.1,1,0) translate 22.35*z rotate -12.59*y}
		object {aisle_wall3_step(1,1.3,1.6,0,1) translate 22.35*z rotate -32.65*y}
		object {aisle_wall3_step(2,2.5,1.9,1,1) translate 22.35*z rotate -60.56*y}
		object {aisle_wall3_step(1,3.14,0,1,1) translate 22.35*z rotate -90*y translate -0.22*z}
	}
#end