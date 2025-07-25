//----- CONSTRUCTION OF THE FLOOR OF THE NAVE AND ITS AISLES

#ifndef(labyrinth)
	#include "labyrinth.inc" 
#end

#macro nave_floor()
	#local w1 = 0.4;											// Width of the lateral steps
	#local h1 = 0.09;											// Height of the lateral steps
	#local l1 = sqrt(pow(0.5,2)+pow(35.88,2));		// Length of the central floor
	#local a1 = degrees(atan(0.5/35.88));				// Angle of the central floor

	union {
		object {sBlock_squ(35.16,6.2,0.5,0.7,0.3,0.3,Floor) rotate 90*x translate <0,-0.25,1>}
		object {sBlock_squ(9.58,35.7,0.5,0.7,0.3,0.3,Floor) rotate 90*x translate <12.79,-0.25,7.2>}
		object {sBlock_squ(9.58,35.7,0.5,0.7,0.3,0.3,Floor) rotate 90*x translate <-12.79,-0.25,7.2>}
		union {
			object {sBlock_squ(16,7.5,0.5,0.7,0.3,0.3,Floor)}
			object {sBlock_squ(16,l1-21.3,0.5,0.7,0.3,0.3,Floor) translate 21.3*y}
			object {labyrinth() translate 14.4*y}
			rotate 90*x translate -0.23*y rotate a1*x translate 7.2*z
		}
		#local i=0;
		#while (i<3)
			object {nBlock_squ(2*w1,0.5,1,Floor) translate <8-2*w1,-0.5-2*h1,21.54+7.2*i>}
			object {nBlock_squ(2*w1,0.5,1,Floor) translate <-8+2*w1,-0.5-2*h1,21.44+7.2*i>}
			#local i=i+1;
		#end
		#local i=0;
		#while (i<3)
			object {sBlock_squ(35.9,0.5,w1,0.5,0.3,0.5,Floor) rotate 90*y translate <8-w1*(0.5+i),-0.5-h1*(i+1),25.13>}
			object {sBlock_squ(35.9,0.5,w1,0.5,0.3,0.5,Floor) rotate 90*y translate <-8+w1*(0.5+i),-0.5-h1*(i+1),25.13>}
			#local i=i+1;
		#end
	}
#end
