//----- CONSTRUCTION OF THE FLOOR OF THE AMBULATORY

#macro ambulatory_floor()
	union {
		object {ssBlock_rin(16.3,8.2,0.5,180,0.5,0.3,Floor) translate <0,-0.25,21.54>}
		object {ssBlock_rin(22.25,16.25,0.4,180,0.5,0.3,Floor) translate <0,0.2,21.54>}
		object {ssBlock_rin(16.25,15.85,0.2,180,0.5,0.4,Floor) translate <0,0.1,21.54>}
		object {sBlock_squ(8.7,0.4,1.02,1,1,0.4,Floor) translate <20.6,0,21.03>}
		object {sBlock_squ(9.1,0.2,0.88,1,1,0.2,Floor) translate <20.4,0,20.53>}
		object {sBlock_squ(8.7,0.4,1.02,1,1,0.4,Floor) translate <-20.6,0,21.03>}
		object {sBlock_squ(9.1,0.2,0.88,1,1,0.2,Floor) translate <-20.4,0,20.53>}
	}
#end