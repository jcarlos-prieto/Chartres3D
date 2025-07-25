//----- COLUMN ATTACHED TO THE AISLE FINAL CORNER (CHOIR)
//     sx: Simmetry in x axis

#macro aisle_column_wall(sx)
	union {
	
		//--- First column
		union {
		
			//- First step
			union {
				object {nBlock_squ(0.6,0.2,0.6,Column)}				
				object {nBlock_squ(0.6,0.3,0.6,Column) translate 0.2*y}				
				object {nBlock_pyr(0.6,0.6,0.4,0.4,0.1,Column) translate 0.5*y}
				object {nBlock_squ(0.4,0.2,0.4,Column) translate 0.6*y}				
				rotate 45*y
			}
			
			//- Second step
			object {sBlock_cyl(0.15,8.12,0.8,Column) translate 0.6*y}
			object {nBlock_tor(0.15,0.05,360,Column) translate 0.85*y}
			object {nBlock_tor(0.15,0.02,360,Column) translate 0.94*y}
			object {nBlock_tor(0.15,0.02,360,Column) translate 8.4*y}
			
			//- Third step
			object {nBlock_squ(0.6,0.05,0.7,Column) translate 8.83*y}				
			object {nBlock_squ(0.5,0.1,0.6,Column) translate 8.73*y}				
			object {nBlock_squ(0.4,0.05,0.5,Column) translate 8.68*y}				
			                        
			translate <0.4*sx,0,-0.43>
		}

		//--- Second column
		union {
		
			//- First step
			object {nBlock_squ(0.6,0.2,0.7,Column)}				
			object {nBlock_squ(0.6,0.3,0.7,Column) translate 0.2*y}				
			object {nBlock_pyr(0.6,0.7,0.4,0.4,0.1,Column) translate 0.5*y}
			object {nBlock_squ(0.4,0.2,0.4,Column) translate 0.6*y}				
			
			//- Second step
			object {sBlock_cyl(0.12,8.52,0.8,Column) translate 0.6*y}
			object {nBlock_tor(0.12,0.05,360,Column) translate 0.85*y}
			object {nBlock_tor(0.12,0.02,360,Column) translate 0.94*y}
			                        
			translate <0.5*sx,0,-0.1>
		}

		//--- Wall
		union {

			//- First step
			object {nBlock_squ(2.91,0.2,0.62,Floor) rotate 90*y translate <0.09*sx,0,-1.455>}
			object {nBlock_squ(2.91,0.3,0.8,Column) rotate 90*y translate <0,0.2,-1.455>}
			object {nBlock_pyr(2.91,0.8,2.71,0.6,0.1,Column) rotate 90*y translate <0,0.5,-1.455>}

			//- Second step
			object {sBlock_squ(2.26,8.2,0.3,0.8,0.8,0.4,Wall) rotate 90*y translate <0.15*sx,0.6,-1.13>}

			//- Third step
			object {nBlock_squ(0.25,0.05,2.5,Column) translate <0.275*sx,8.83,-1.25>}				
			object {nBlock_squ(0.15,0.1,2.5,Column) translate <0.275*sx,8.73,-1.25>}				
			object {nBlock_squ(0.05,0.05,2.5,Column) translate <0.275*sx,8.68,-1.25>}
		}
	
		//--- Leaves
		#if (show_ornaments)
			#local i=0;
			#while (i<2)
				object {leaf_curve2 scale <0.65,0.85,0.65> translate <0.14,8.4,0> rotate (45-90*sx+90*i)*y translate <0.4*sx,0,-0.43>}
				#local i=i+1;
			#end
		#end
	}
#end
