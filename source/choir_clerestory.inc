//----- CONSTRUCTION OF THE CHOIR CLERESTORY

#ifndef(clerestory_step)
	#include "clerestory_step.inc" 
#end
#ifndef(clerestory2_step)
	#include "clerestory2_step.inc" 
#end

#macro choir_clerestory()
	union {
		#local i=-1;
		#while (i<2)
			#if (i=-1) #declare q="l"; #else #declare q="r"; #end
			object {clerestory_step(6.5,2.2,concat("vChoirClerestory_",q,"1")) rotate 90*i*y translate <7.7*i,0,-3.25>}
			#local j=0;
			#while (j<3)
				object {clerestory_step(7.18,2.2,concat("vChoirClerestory_",q,str(j+2,1,0))) rotate 90*i*y translate <7.7*i,0,3.59+7.18*j>}
				#local j=j+1;
			#end
			#local i=i+2;
		#end
      
      union {
			#local i=0;
			#while (i<7)
				object {clerestory2_step(3.7,concat("vChoirClerestory_c",str(i+1,1,0))) rotate -90*y translate -7.55*x rotate 180/7*(i+0.5)*y}
				#local i=i+1;
			#end
			translate 21.76*z
		}
	}
#end