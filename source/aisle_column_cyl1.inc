//----- COLUMN ATTACHED TO THE AISLE FINAL CORNER
//     sx: Simmetry in x axis

#macro aisle_column_cyl1(sx)
	union {
	
		//--- Main column
		union {
		
			//- First step
			object {nBlock_squ(0.8,0.18,0.8,Column)}				
			object {nBlock_pyr(0.8,0.8,0.6,0.6,0.1,Column) translate 0.18*y}
			object {nBlock_squ(0.6,0.2,0.6,Column) translate 0.28*y}				
			
			//- Second step
			object {sBlock_cyl(0.25,9.12,0.8,Column)}
			object {nBlock_tor(0.25,0.05,360,Column) translate 0.53*y}
			object {nBlock_tor(0.25,0.02,360,Column) translate 0.62*y}
			object {nBlock_tor(0.25,0.02,360,Column) translate 8.71*y}
			
			//- Third step
			object {nBlock_squ(0.9,0.05,0.9,Column) translate 9.23*y}				
			object {nBlock_squ(0.8,0.1,0.8,Column) translate 9.13*y}				
			object {nBlock_squ(0.7,0.05,0.7,Column) translate 9.08*y}				
			
			translate -0.87*z
		}
		
		//--- Second column
		union {
		
			//- First step
			union {
				object {nBlock_squ(0.6,0.18,0.6,Column)}				
				object {nBlock_pyr(0.6,0.6,0.4,0.4,0.1,Column) translate 0.18*y}
				object {nBlock_squ(0.4,0.2,0.4,Column) translate 0.28*y}				
				rotate 45*y
			}
			
			//- Second step
			object {sBlock_cyl(0.15,9.12,0.8,Column)}
			object {nBlock_tor(0.15,0.05,360,Column) translate 0.53*y}
			object {nBlock_tor(0.15,0.02,360,Column) translate 0.62*y}
			object {nBlock_tor(0.15,0.02,360,Column) translate 8.85*y}
			
			//- Third step
			object {nBlock_squ(0.6,0.05,0.7,Column) translate 9.23*y}				
			object {nBlock_squ(0.5,0.1,0.6,Column) translate 9.13*y}				
			object {nBlock_squ(0.4,0.05,0.5,Column) translate 9.08*y}				
			                        
			translate <0.4*sx,0,-0.43>
		}

		//--- Third column
		union {
		
			//- First step
			object {nBlock_squ(0.6,0.18,0.7,Column)}				
			object {nBlock_pyr(0.6,0.7,0.4,0.4,0.1,Column) translate 0.18*y}
			object {nBlock_squ(0.4,0.2,0.4,Column) translate 0.28*y}				
			
			//- Second step
			object {sBlock_cyl(0.12,9.12,0.8,Column)}
			object {nBlock_tor(0.12,0.05,360,Column) translate 0.53*y}
			object {nBlock_tor(0.12,0.02,360,Column) translate 0.62*y}
			                        
			translate <0.7*sx,0,-0.1>
		}

		//--- Internal columns
		object {sBlock_cyl(0.15,9.12,0.8,Column) translate <0.16*sx,0,-0.53>}
		object {sBlock_cyl(0.15,9.12,0.8,Column) translate <0.48*sx,0,-0.17>}
	
		//--- Leaves
		#if (show_ornaments)
			#local i=0;
			#while (i<4)
				object {leaf_curve2 translate <0.24,8.71,0> rotate (45+90*i)*y translate -0.87*z}
				#local i=i+1;
			#end 
			#local i=0;
			#while (i<3)
				object {leaf_curve2 scale <0.5,0.6,0.5> translate <0.15,8.85,0> rotate (-45+90*i)*y translate <0.4*sx,0,-0.43>}				
				#local i=i+1;
			#end
		#end
	}
#end
