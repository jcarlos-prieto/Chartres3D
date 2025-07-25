//----- WALL AND ARCH BETWEEN TWO ADJACENT COLUMNS
//		  L: Length
//		 th: Thickness

#macro arcade_step(L,th)

	#local n = 1.3; 
	#local h = 5-(L/2-0.45)*sqrt(2*n-1);
	#local a=degrees(acos(1-1/n));

	union {
		//--- Wall
		difference {
			union {
				object {sBlock_squ(L,5.6,1.18,0.8,0.8,0.4,Wall)}
				object {sBlock_squ(L,0.8,0.4,0.8,0.8,0.4,Wall) translate <0,5.6,-0.39>}
			}
			union {					
				box {<-L/2+0.45,-2*dd,-1> <L/2-0.45,h,1>}
				object {gothic_arch(L/2-0.45,n,2) translate (h-dd)*y}
				texture {T_Block(Wall,NoMortar)}
			}
		}
		object {sBlock_squ(L,0.08,0.08,0.8,0.8,0.08,Column) translate -0.04*y rotate -90*x translate <0,5.9,-0.63>}
		object {sBlock_squ(L,0.04,0.04,0.8,0.8,0.04,Column) translate -0.02*y rotate -90*x translate <0,5.84,-0.61>}
		object {sBlock_cyl(0.04,L,0.8,Column) rotate 90*z translate <L/2,5.9,-0.67>}
		object {sBlock_cyl(0.02,L,0.8,Column) rotate 90*z translate <L/2,5.84,-0.63>}

		//--- Arch ornaments
		object {arch(L/2-0.45,h+(L/2-0.45)*sqrt(2*n-1),0.08,n,2,0.35,0.65,1.18,0,0.15,th,0.2,0,0,Column)} 
	}
#end