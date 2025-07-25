//----- END WALL OF THE NAVE AISLE
//	     c: Type. 1-Nave;  2-Transept

#macro aisle_endwall(c)
	#switch (c)
	#case (1)
		object {sBlock_squ(9.04,15.88,0.4,0.8,0.8,0.4,Wall) translate 0.2*z}
		#break
	#case (2)
		union {
			difference {
				object {sBlock_squ(7.18,15.6,1.18,0.8,0.8,0.4,Wall)}
				union {
					box {<-2.4,-1,-2> <2.4,6,2>}
					object {gothic_arch(2.4,1.5,3) translate (6-dd)*y}
					texture {T_Block(Wall,NoMortar)}
				}
			}
			object {sBlock_squ(4.3,3,0.38,0.8,0.8,0.4,Wall) translate <0,5,0.45>}
			object {gothic_rin(2.4,2.4,0.4,1.5,1.18,0,0.8,Wall) translate 6*y}
			object {gothic_rin(2.8,2.8,0.8,1.5,0.88,0,0.8,Wall) translate <0,5.4,0.15>}
			object {gothic_rin(2.8,2.8,0.8,1.5,0.58,0,0.8,Wall) translate <0,4.8,0.3>}
			#local i=-1;
			#while (i<2)
				object {sBlock_squ(0.4,6,1.18,0.4,0.4,0.4,Wall) translate 2.2*i*x}
				object {nBlock_pyr(1.69,1.28,1.59,1.18,0.1,Wall) translate <2.795*i,0.2,0>}
				object {sBlock_squ(1.69,0.2,1.28,0.8,0.8,0.2,Wall) translate <2.795*i,0,0>}
				#local i=i+2;
			#end			
			//--- Door
			object {nBlock_squ(0.2,5,0.38,Door) translate 0.45*z}
			object {sBlock_squ2(5,4.4,0.3,0.2,Door) translate -2.2*y rotate 90*z translate <0,2.5,0.49>}
		}
		#break
	#end		
#end
