//----- CONSTRUCTION OF THE FLOOR OF THE CHAPELS

#macro chapels_floor()
	union {
		object {ssBlock_rin(24.96,21.96,0.2,180,0.5,0.3,Floor) translate 0.5*y}
		object {ssBlock_rin(28.56,24.96,0.2,20,0.5,0.3,Floor) rotate 80*y translate 0.5*y}
		object {ssBlock_rin(28.56,24.96,0.2,20,0.5,0.3,Floor) rotate 125.48*y translate 0.5*y}
		object {ssBlock_rin(28.56,24.96,0.2,20,0.5,0.3,Floor) rotate 34.52*y translate 0.5*y}
		object {ssBlock_rin(28.56,24.96,0.2,20,0.5,0.3,Floor) rotate 154.12*y translate 0.5*y}
		object {ssBlock_rin(28.56,24.96,0.2,20,0.5,0.3,Floor) rotate 5.88*y translate 0.5*y}
	}
#end