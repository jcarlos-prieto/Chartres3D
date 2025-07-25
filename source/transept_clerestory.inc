//----- CONSTRUCTION OF THE CLERESTORY OF THE TRANSEPT

#ifndef(clerestory_step)
	#include "clerestory_step.inc" 
#end

#macro transept_clerestory()
	union {
		object {clerestory_step(7.61,2.5,"vTranseptClerestory_lb1") rotate 180*y translate <-12.775,0,-6.59>}
		object {clerestory_step(8.29,2.5,"vTranseptClerestory_lb2") rotate 180*y translate <-20.725,0,-6.59>}
		object {clerestory_step(8.29,2.5,"vTranseptClerestory_lb3") rotate 180*y translate <-29.015,0,-6.59>}
		object {clerestory_step(7.61,2.5,"vTranseptClerestory_rb1") rotate 180*y translate <12.775,0,-6.59>}
		object {clerestory_step(8.29,2.5,"vTranseptClerestory_rb2") rotate 180*y translate <20.725,0,-6.59>}
		object {clerestory_step(8.29,2.5,"vTranseptClerestory_rb3") rotate 180*y translate <29.015,0,-6.59>}
		object {clerestory_step(7.61,2.5,"vTranseptClerestory_lf1") translate <-12.775,0,6.59>}
		object {clerestory_step(8.29,2.5,"vTranseptClerestory_lf2") translate <-20.725,0,6.59>}
		object {clerestory_step(8.29,2.5,"vTranseptClerestory_lf3") translate <-29.015,0,6.59>}
		object {clerestory_step(7.61,2.5,"vTranseptClerestory_rf1") translate <12.775,0,6.59>}
		object {clerestory_step(8.29,2.5,"vTranseptClerestory_rf2") translate <20.725,0,6.59>}
		object {clerestory_step(8.29,2.5,"vTranseptClerestory_rf3") translate <29.015,0,6.59>}
	}
#end