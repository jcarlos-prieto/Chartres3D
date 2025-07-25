//----- CONSTRUCTION OF THE FLOOR OF THE CHOIR AND ITS AISLES

#macro choir_floor()
	union {
		object {sBlock_squ(50.54,20.76,0.5,0.7,0.3,0.3,Floor) rotate 90*x translate <0,-0.25,1>}
		object {ssBlock_rin(8.2,0.4,0.5,180,0.5,0.3,Floor) translate <0,-0.25,21.76>}
		difference {
			object {nBlock_cyl(0.4,0.5,Floor)}
			box {<-1,-1,-1> <1,1,> texture {T_Block(Floor,NoMortar)}}
			translate <0,-0.5,21.76>
		}
	}
#end