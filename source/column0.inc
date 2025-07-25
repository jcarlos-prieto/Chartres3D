//----- STEP 0 OF THE COLUMN

#macro column0()
	union {
		#local l1 = 0.875*sqrt(2)+2*s[Column];
		#local w1 = l1/2+s[Column];
		#local i=0;
		#while (i<2)
			object {sBlock_squ(0.7,0.5,2.45,0.35,0.35,0.5,Column) translate -0.3*y rotate 90*i*y}
			#local i=i+1;
		#end
		#local i=0;
		#while (i<4)
			union {
				//??? ¿Se puede sustituir por un superBlock ?
				object {nBlock_squ(w1,0.5,l1/2,Column) translate 0.25*l1*z}
				object {nBlock_squ(w1,0.5,l1/2,Column) translate -0.25*l1*z}
				translate <-w1/2+s[Column],-0.3,l1/2-s[Column]> rotate 45*y translate <0.35-s[Column],0,-1.225+s[Column]> rotate 90*i*y
			}
			#local i=i+1;
		#end
		object {nBlock_squ(1.64,0.18,1.64,Column) translate 0.2*y rotate 45*y}
		#local i=0;
		#while (i<2)
			object {nBlock_squ(2.45,0.18,0.7,Column) translate 0.2*y rotate 90*i*y}
			#local i=i+1;
		#end
		object {nBlock_pyr(1.64,1.64,1.44,1.44,0.1,Column) translate 0.38*y rotate 45*y}
		#local i=0;
		#while (i<2)
			object {nBlock_pyr(2.45,0.7,2.25,0.5,0.1,Column) translate 0.38*y rotate 90*i*y}
			#local i=i+1;
		#end
		#local i=0;
		#while (i<2)
			object {nBlock_squ(2.25,0.2,0.5,Column) translate 0.48*y rotate 90*i*y}
			#local i=i+1;
		#end
	}
#end