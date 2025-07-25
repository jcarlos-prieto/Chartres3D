//----- STEP 3 OF THE CHOIR COLUMN

#macro column3_cho()
	union {
	
		//--- Body
		object {sBlock_cyl(0.1,14.4,0.8,Column) translate -0.74*z}	
		object {sBlock_cyl(0.08,14.4,0.8,Column) translate <-0.2,0,-0.62>}	
		object {sBlock_cyl(0.08,14.4,0.8,Column) translate <0.2,0,-0.62>}	
		
		//--- Lower ornament
		object {sBlock_cyl(0.16,0.32,0.32,Column) translate -0.74*z}
		object {sBlock_squ2(0.22,0.32,0.22,0.32,Column) rotate 45*y translate <-0.2,0,-0.62>}
		object {sBlock_squ2(0.22,0.32,0.22,0.32,Column) rotate 45*y translate <0.2,0,-0.62>}
		union {
			object {nBlock_tor(0.16,0.04,360,Column) translate <0,0.28,-0.74>}
			object {nBlock_tor(0.1,0.02,360,Column) translate <0,0.38,-0.74>}
			#local i=-1;
			#while (i<2)
				object {nBlock_tor(0.08,0.02,360,Column) translate <0.2*i,0.38,-0.62>}
				union {
					#local j=0;
					#while (j<4)
						intersection {
							object {nBlock_cyl(0.04,2,Column) translate -y rotate 90*z translate <0,0.28,-0.11>}
							box {<0,0,0> <1,1,-1> texture {T_Block(Column,NoMortar)} rotate 45*y}
							rotate 90*j*y
						}				
						#local j=j+1;
					#end
					rotate -45*i*y
					translate <0.2*i,0,-0.62>
				}
				#local i=i+2;
			#end
		}
		
		//--- Mid-lower ornament		
		object {nBlock_cyl(0.18,0.08,Column) translate <0,5.86,-0.74>}	
		object {nBlock_cyl(0.12,0.04,Column) translate <0,5.82,-0.74>}	
		object {nBlock_cyl(0.16,0.08,Column) translate <-0.2,5.86,-0.62>}	
		object {nBlock_cyl(0.1,0.04,Column) translate <-0.2,5.82,-0.62>}	
		object {nBlock_cyl(0.16,0.08,Column) translate <0.2,5.86,-0.62>}	
		object {nBlock_cyl(0.1,0.04,Column) translate <0.2,5.82,-0.62>}	
	
		//--- Mid-upper ornament		
		object {nBlock_cyl(0.18,0.08,Column) translate <0,10.45,-0.74>}	
		object {nBlock_cyl(0.12,0.04,Column) translate <0,10.41,-0.74>}	
		object {nBlock_cyl(0.16,0.08,Column) translate <-0.2,10.45,-0.62>}	
		object {nBlock_cyl(0.1,0.04,Column) translate <-0.2,10.41,-0.62>}	
		object {nBlock_cyl(0.16,0.08,Column) translate <0.2,10.45,-0.62>}	
		object {nBlock_cyl(0.1,0.04Column) translate <0.2,10.41,-0.62>}	
		
		//--- Upper ornament
		object {nBlock_squ(0.4,0.05,0.4,Column) translate <0,14.43,-0.74>}
		object {nBlock_squ(0.35,0.08,0.35,Column) translate <0,14.35,-0.74>}
		object {nBlock_squ(0.3,0.05,0.3,Column) translate <0,14.3,-0.74>}
		object {nBlock_tor(0.1,0.02,360,Column) translate <0,14.08,-0.74>}
	
		//--- Leaves
		#if (show_ornaments)
			#local i=0;
			#while (i<2)
				object {leaf_curve2 scale <0.45,0.6,0.45> translate <0.1,14.08,0> rotate (45+90*i)*y translate -0.74*z}
				#local i=i+1;
			#end
		#end
	}
#end