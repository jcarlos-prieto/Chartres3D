//----- CONSTRUCTION OF THE FLOOR OF THE MAIN ENTRANCE HALL

#macro main_facade_floor()
	#local a1 = degrees(atan(0.5/35.88));				// Angle of the central nave floor
	object {sBlock_squ(17.8,14.1,0.5,0.7,0.3,0.3,Floor) rotate 90*x translate -0.75*y rotate a1*x}
#end