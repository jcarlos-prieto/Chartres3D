//----- STEP 3 OF THE COLUMN (CYLINDRICAL)

#macro column3_cyl()
	union {
	
		//--- Body
		object {sBlock_oct(0.16,14.4,0.8,Column) translate <0,0,-0.87>}	
		object {sBlock_cyl(0.1,14.4,0.8,Column) translate <-0.22,0,-0.74>}	
		object {sBlock_cyl(0.1,14.4,0.8,Column) translate <0.22,0,-0.74>}	
		object {sBlock_cyl(0.08,14.4,0.8,Column) translate <-0.42,0,-0.62>}	
		object {sBlock_cyl(0.08,14.4,0.8,Column) translate <0.42,0,-0.62>}	
		
		//--- Lower ornament
		object {sBlock_oct(0.22,0.32,0.32,Column) translate -0.87*z}
		object {sBlock_squ(0.35,0.32,0.5,0.5,0.48,0.32,Column) rotate 45*y translate <-0.18,0,-0.69>}
		object {sBlock_squ(0.35,0.32,0.5,0.5,0.48,0.32,Column) rotate -45*y translate <0.18,0,-0.69>}
		object {sBlock_squ(0.22,0.32,0.2,0.2,0.2,0.32,Column) translate <-0.42,0,-0.62>}
		object {sBlock_squ(0.22,0.32,0.2,0.2,0.2,0.32,Column) translate <0.42,0,-0.62>}
		union {
			object {nBlock_octcyl(0.22,0.04,Column) translate <0,0.28,-0.87>}
			object {nBlock_octcyl(0.16,0.02,Column) translate <0,0.38,-0.87>}
			#local i=-1;
			#while (i<2)
				object {nBlock_tor(0.1,0.02,360,Column) translate <0.23*i,0.38,-0.74>}
				object {nBlock_tor(0.08,0.02,360,Column) translate <0.42*i,0.38,-0.62>}
				union {
					#local j=0;
					#while (j<4)
						intersection {
							object {nBlock_cyl(0.04,2,Column) translate -y rotate 90*z translate <0,0.28,-0.175>}
							box {<0,0,0> <1,1,-1> texture {T_Block(Column,NoMortar)} rotate 45*y}
							rotate 90*j*y
						}				
						#local j=j+1;
					#end
					translate -0.075*z
					rotate -45*i*y
					translate <0.18*i,0,-0.69>
				}
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
					translate <0.42*i,0,-0.62>
				}
				#local i=i+2;
			#end
		}
		
		//--- Mid-lower ornament
		object {nBlock_oct(0.24,0.08,Column) translate <0,5.86,-0.87>}	
		object {nBlock_oct(0.18,0.04,Column) translate <0,5.82,-0.87>}	
		object {nBlock_cyl(0.18,0.08,Column) translate <-0.22,5.86,-0.74>}	
		object {nBlock_cyl(0.12,0.04,Column) translate <-0.22,5.82,-0.74>}	
		object {nBlock_cyl(0.18,0.08,Column) translate <0.22,5.86,-0.74>}	
		object {nBlock_cyl(0.12,0.04,Column) translate <0.22,5.82,-0.74>}	
		object {nBlock_cyl(0.16,0.08,Column) translate <-0.42,5.86,-0.62>}	
		object {nBlock_cyl(0.1,0.04,Column) translate <-0.42,5.82,-0.62>}	
		object {nBlock_cyl(0.16,0.08,Column) translate <0.42,5.86,-0.62>}	
		object {nBlock_cyl(0.1,0.04,Column) translate <0.42,5.82,-0.62>}	

		object {nBlock_octcyl(0.24,0.04,Column) translate <0,5.9,-0.87>}	
		object {nBlock_octcyl(0.18,0.02,Column) translate <0,5.84,-0.87>}	
		object {nBlock_tor(0.18,0.04,360,Column) translate <-0.22,5.9,-0.74>}	
		object {nBlock_tor(0.12,0.02,360,Column) translate <-0.22,5.84,-0.74>}	
		object {nBlock_tor(0.18,0.04,360,Column) translate <0.22,5.9,-0.74>}	
		object {nBlock_tor(0.12,0.02,360,Column) translate <0.22,5.84,-0.74>}	
		object {nBlock_tor(0.16,0.04,360,Column) translate <-0.42,5.9,-0.62>}	
		object {nBlock_tor(0.1,0.02,360,Column) translate <-0.42,5.84,-0.62>}	
		object {nBlock_tor(0.16,0.04,360,Column) translate <0.42,5.9,-0.62>}	
		object {nBlock_tor(0.1,0.02,360,Column) translate <0.42,5.84,-0.62>}	
	
		//--- Mid-upper ornament		
		object {nBlock_oct(0.24,0.08,Column) translate <0,10.45,-0.87>}	
		object {nBlock_oct(0.18,0.04,Column) translate <0,10.41,-0.87>}	
		object {nBlock_cyl(0.18,0.08,Column) translate <-0.22,10.45,-0.74>}	
		object {nBlock_cyl(0.12,0.04,Column) translate <-0.22,10.41,-0.74>}	
		object {nBlock_cyl(0.18,0.08,Column) translate <0.22,10.45,-0.74>}	
		object {nBlock_cyl(0.12,0.04,Column) translate <0.22,10.41,-0.74>}	
		object {nBlock_cyl(0.16,0.08,Column) translate <-0.42,10.45,-0.62>}	
		object {nBlock_cyl(0.1,0.04,Column) translate <-0.42,10.41,-0.62>}	
		object {nBlock_cyl(0.16,0.08,Column) translate <0.42,10.45,-0.62>}	
		object {nBlock_cyl(0.1,0.04,Column) translate <0.42,10.41,-0.62>}	
		
		object {nBlock_octcyl(0.24,0.04,Column) translate <0,10.49,-0.87>}	
		object {nBlock_octcyl(0.18,0.02,Column) translate <0,10.43,-0.87>}	
		object {nBlock_tor(0.18,0.04,360,Column) translate <-0.22,10.49,-0.74>}	
		object {nBlock_tor(0.12,0.02,360,Column) translate <-0.22,10.43,-0.74>}	
		object {nBlock_tor(0.18,0.04,360,Column) translate <0.22,10.49,-0.74>}	
		object {nBlock_tor(0.12,0.02,360,Column) translate <0.22,10.43,-0.74>}	
		object {nBlock_tor(0.16,0.04,360,Column) translate <-0.42,10.49,-0.62>}	
		object {nBlock_tor(0.1,0.02,360,Column) translate <-0.42,10.43,-0.62>}	
		object {nBlock_tor(0.16,0.04,360,Column) translate <0.42,10.49,-0.62>}	
		object {nBlock_tor(0.1,0.02,360,Column) translate <0.42,10.43,-0.62>}	
		
		//--- Upper ornament
		object {nBlock_squ(0.6,0.05,0.6,Column) translate <0,14.43,-0.87>}
		object {nBlock_squ(0.55,0.08,0.55,Column) translate <0,14.35,-0.87>}
		object {nBlock_squ(0.5,0.05,0.5,Column) translate <0,14.3,-0.87>}
		object {nBlock_squ(0.5,0.05,0.72,Column) rotate -45*y translate <0.22,14.43,-0.74>}
		object {nBlock_squ(0.5,0.08,0.65,Column) rotate -45*y translate <0.22,14.35,-0.74>}
		object {nBlock_squ(0.43,0.05,0.6,Column) rotate -45*y translate <0.22,14.3,-0.74>}
		object {nBlock_squ(0.5,0.05,0.72,Column) rotate 45*y translate <-0.22,14.43,-0.74>}
		object {nBlock_squ(0.5,0.08,0.65,Column) rotate 45*y translate <-0.22,14.35,-0.74>}
		object {nBlock_squ(0.43,0.05,0.5,Column) rotate 45*y translate <-0.22,14.3,-0.74>}
		object {nBlock_octcyl(0.16,0.02,Column) translate <0,13.92,-0.87>}
		#local i=-1;
		#while (i<2)
			object {nBlock_tor(0.1,0.02,360,Column) translate <0.22*i,14.1,-0.74>}
			#local i=i+2;
		#end 
		
		//--- Leaves
		#if (show_ornaments)
			#local i=0;
			#while (i<2)
				object {leaf_curve2 scale <0.75,1,0.75> translate <0.16,13.92,0> rotate (45+90*i)*y translate -0.87*z}
				object {leaf_curve2 scale 0.5 translate <0.1,14.1,0> rotate 90*i*y translate <0.22,0,-0.74>}
				object {leaf_curve2 scale 0.5 translate <0.1,14.1,0> rotate (90+90*i)*y translate <-0.22,0,-0.74>}
				#local i=i+1;
			#end
		#end
	}
#end