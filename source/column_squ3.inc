//----- COLUMN WITH TRIANGULAR BASE AT THE END OF THE NAVE
//		  sx: Symmetry on x axis
//      sz: symmetry on z axis

#macro column_squ3(sx,sz)
	union {
	
		//--- Body
		union {
			object {sBlock_squ2(2,23.5,2,0.8,Column) rotate 45*y}
			
			object {sBlock_oct(0.22,9,0.8,Column) translate 1.34*sx*x}	
				
			object {sBlock_squ2(0.06,9,0.06,0.8,Column) translate <1.155*sx,0,0.255*sz>}	
			object {sBlock_cyl(0.08,9,0.8,Column) translate <1.1*sx,0,0.41*sz>}	
			object {sBlock_squ2(0.06,9,0.06,0.8,Column) translate <0.93*sx,0,0.48*sz>}	
			object {sBlock_cyl(0.08,23.46,0.8,Column) translate <0.89*sx,0,0.62*sz>}	
			object {sBlock_squ2(0.06,23.46,0.06,0.8,Column) translate <0.72*sx,0,0.69*sz>}	
			object {sBlock_cyl(0.1,23.46,0.8,Column) translate <0.62*sx,0,0.89*sz>}	
			object {sBlock_squ2(0.06,23.46,0.06,0.8,Column) translate <0.465*sx,0,0.995*sz>}	
			
			object {sBlock_cyl(0.08,9,0.8,Column) translate <0.62*sx,0,-0.89*sz>}	
			object {sBlock_squ2(0.06,9,0.06,0.8,Column) translate <0.72*sx,0,-0.69*sz>}	
			object {sBlock_cyl(0.1,9,0.8,Column) translate <0.86*sx,0,-0.65*sz>}	
			object {sBlock_squ2(0.06,9,0.06,0.8,Column) translate <0.93*sx,0,-0.48*sz>}	
			object {sBlock_cyl(0.08,9,0.8,Column) translate <1.1*sx,0,-0.41*sz>}	
			object {sBlock_squ2(0.06,9,0.06,0.8,Column) translate <1.155*sx,0,-0.255*sz>}

			translate 0.2*y
		}

		//--- Lower ornament
		union {
			object {nBlock_squ(0.8,0.2,0.8,Column) translate <1.34*sx,0,0>}
			object {nBlock_pyr(0.8,0.8,0.6,0.6,0.1,Column) translate <1.34*sx,0.2,0>}
			object {nBlock_squ(0.6,0.2,0.6,Column) translate <1.34*sx,0.3,0>}

			object {nBlock_octcyl(0.22,0.05,Column) translate <1.34*sx,0.55,0>}
			object {nBlock_octcyl(0.22,0.02,Column) translate <1.34*sx,0.64,0>}
			
		#local coor = 
			array[2]
			{	<0.62*sx,0,0.89*sz>
				<0.86*sx,0,-0.65*sz>
			}
		#local i=0;
		#while (i<2)
				union {
					object {nBlock_squ(0.5,0.2,0.5,Column) rotate 45*y}
					object {nBlock_pyr(0.5,0.5,0.4,0.4,0.1,Column) translate 0.2*y rotate 45*y}
					object {nBlock_squ(0.4,0.2,0.4,Column) translate 0.3*y rotate 45*y}
					#if (show_details)
						object {Block_pyr(0.4-2*d[Column],0.4-2*d[Column],0.3-2*d[Column],0.3-2*d[Column],0.1,Column,Mortar) translate 0.38*y rotate 45*y}	
					#end
					object {nBlock_tor(0.1,0.05,360,Column) translate 0.55*y}
					object {nBlock_tor(0.1,0.02,360,Column) translate 0.64*y}
					translate coor[i]
				}
				#local i=i+1;
			#end

			#local coor = 
				array[4]
				{	<0.89*sx,0,0.62*sz>	
					<1.1*sx,0,0.41*sz>	
					<0.62*sx,0,-0.89*sz>	
					<1.1*sx,0,-0.41*sz>	
				}
			#local i=0;
			#while (i<4)
				union {
					object {nBlock_squ(0.3,0.2,0.3,Column)}
					object {nBlock_pyr(0.3,0.3,0.25,0.25,0.1,Column) translate 0.2*y}
					object {nBlock_squ(0.25,0.2,0.25,Column) translate 0.3*y}
					#if (show_details)
						object {Block_pyr(0.2-2*d[Column],0.2-2*d[Column],0.18-2*d[Column],0.18-2*d[Column],0.1,Column,Mortar) translate 0.38*y}	
					#end
					object {nBlock_tor(0.08,0.05,360,Column) translate 0.55*y}
					object {nBlock_tor(0.08,0.02,360,Column) translate 0.64*y}
					translate coor[i]
				}
				#local i=i+1;
			#end
		}
			
		//--- Mid ornament
		union {		
			union {
				object {nBlock_squ(0.8,0.05,0.8,Column) translate 0.15*y}				
				object {nBlock_squ(0.7,0.1,0.7,Column) translate 0.05*y}				
				object {nBlock_squ(0.6,0.05,0.6,Column)}
				object {nBlock_octcyl(0.22,0.02,Column) translate -0.37*y}
				translate 1.34*sx*x
			}
			union {
				object {nBlock_squ(0.4,0.05,0.4,Column) translate 0.15*y}
				object {nBlock_squ(0.35,0.1,0.35,Column) translate 0.05*y}
				object {nBlock_squ(0.3,0.05,0.3,Column)}
				object {nBlock_tor(0.08,0.02,360,Column) translate -0.22*y}				
				translate <1.1*sx,0,0.41*sz>
			}
			union {
				object {nBlock_squ(0.8,0.05,0.8,Column) translate 0.15*y}				
				object {nBlock_squ(0.7,0.1,0.7,Column) translate 0.05*y}				
				object {nBlock_squ(0.6,0.05,0.6,Column)}
				translate <0.47*sx,0,-0.87*sz>
			}
			union {
				object {nBlock_squ(1.23,0.05,0.6,Column) translate 0.15*y}				
				object {nBlock_squ(1.13,0.1,0.5,Column) translate 0.05*y}				
				object {nBlock_squ(1.03,0.05,0.4,Column)}
				rotate -45*sx*sz*y
				translate <0.97*sx,0,-0.47*sz>
			}
			translate 9.08*y
		}
		
		//--- Upper ornament
		union {
			object {nBlock_squ(0.72,0.05,0.5,Column) translate 23.71*y}
			object {nBlock_squ(0.65,0.08,0.5,Column) translate 23.63*y}
			object {nBlock_squ(0.6,0.05,0.43,Column) translate 23.58*y}
			object {nBlock_tor(0.1,0.02,360,Column) translate 23.2*y}
			rotate 45*y
			translate <0.62*sx,0,0.89*sz>
		}
		
		//--- Leaves
		#if (show_ornaments)
			#local i=0;
			#while (i<4)
				object {leaf_curve2 translate <0.22,8.73,0> rotate (45+90*i)*y translate 1.34*sx*x}
				object {leaf_curve2 scale <0.5,0.5,0.35> translate <0.08,8.88,0> rotate (45+90*i)*y translate <1.1*sx,0,0.41*sz>}
				object {leaf_curve2 scale <1,1,0.5> translate <0.1,23.2,0> rotate 90*i*y translate <0.62*sx,0,0.89*sz>}
				#local i=i+1;
			#end
		#end
	}
#end