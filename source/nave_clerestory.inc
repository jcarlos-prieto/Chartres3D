//----- CONSTRUCTION OF THE NAVE CLERESTORY

#ifndef(clerestory_step)
	#include "clerestory_step.inc" 
#end

#macro nave_clerestory()
	union {
		#local i=-1;
		#while (i<2)
			#if (i=-1) #declare q="r"; #else #declare q="l"; #end
			object {clerestory_step(6.5,2.2,concat("vNaveClerestory_",q,"1")) rotate 90*i*y translate <7.7*i,0,-3.25>}
			#local j=0;
			#while (j<5)
				object {clerestory_step(7.18,2.2,concat("vNaveClerestory_",q,str(j+2,1,0))) rotate 90*i*y translate <7.7*i,0,3.59+7.18*j>}
				#local j=j+1;
			#end
			object {clerestory_step(6.71,2.2,concat("vNaveClerestory_",q,"7")) rotate 90*i*y translate <7.7*i,0,39.255>}
			#local i=i+2;
		#end		
	}
#end