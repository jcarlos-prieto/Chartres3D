//----- COLUMN WITH SQUARED BASE AT THE FOUR CORNERS OF THE INTERSECTION
//      BETWEEN MAIN NAVE AND THE TRANSEPT
//		  sx: Symmetry on x axis
//      sz: symmetry on z axis

#macro column_squ1(sx,sz)
	union {
	
		//--- Body
		union {                  
			object {sBlock_squ2(2.3,23.5,2.3,0.8,Column) rotate 45*y}
			object {nBlock_squ(2.3,11.0,2.3,Column) rotate 45*y translate 23.5*y}

			object {sBlock_cyl(0.22,9,0.8,Column) translate -1.55*sz*z}	
			object {sBlock_oct(0.22,9,0.8,Column) translate -1.55*sx*x}	
			object {sBlock_cyl(0.22,23.42,0.8,Column) translate 1.55*sz*z}	
			object {sBlock_oct(0.22,23.42,0.8,Column) translate 1.55*sx*x}

			object {sBlock_squ2(0.08,9,0.08,0.8,Column) translate <-0.255*sx,0,-1.365*sz>}	
			object {sBlock_cyl(0.08,9,0.8,Column) translate <-0.41*sx,0,-1.31*sz>}
			object {sBlock_squ2(0.06,9,0.06,0.8,Column) translate <-0.465*sx,0,-1.155*sz>}	
			object {sBlock_cyl(0.08,9,0.8,Column) translate <-0.62*sx,0,-1.1*sz>}	
			object {sBlock_squ2(0.06,9,0.06,0.8,Column) translate <-0.69*sx,0,-0.93*sz>}	
			object {sBlock_cyl(0.1,9,0.8,Column) translate <-0.86*sx,0,-0.86*sz>}	
			object {sBlock_squ2(0.06,9,0.06,0.8,Column) translate <-0.93*sx,0,-0.69*sz>}
			object {sBlock_cyl(0.08,9,0.8,Column) translate <-1.1*sx,0,-0.62*sz>}	
			object {sBlock_squ2(0.06,9,0.06,0.8,Column) translate <-1.155*sx,0,-0.465*sz>}	
			object {sBlock_cyl(0.08,9,0.8,Column) translate <-1.31*sx,0,-0.41*sz>}	
			object {sBlock_squ2(0.08,9,0.08,0.8,Column) translate <-1.365*sx,0,-0.255*sz>}	

			object {sBlock_squ2(0.08,9,0.08,0.8,Column) translate <0.255*sx,0,-1.365*sz>}	
			object {sBlock_cyl(0.08,9,0.8,Column) translate <0.41*sx,0,-1.31*sz>}
			object {sBlock_squ2(0.06,9,0.06,0.8,Column) translate <0.465*sx,0,-1.155*sz>}	
			object {sBlock_cyl(0.08,23.42,0.8,Column) translate <0.62*sx,0,-1.1*sz>}	
			object {sBlock_squ2(0.06,23.42,0.06,0.8,Column) translate <0.69*sx,0,-0.93*sz>}	
			object {sBlock_cyl(0.1,23.42,0.8,Column) translate <0.86*sx,0,-0.86*sz>}	
			object {sBlock_squ2(0.06,23.42,0.06,0.8,Column) translate <0.93*sx,0,-0.69*sz>}
			object {sBlock_cyl(0.08,23.42,0.8,Column) translate <1.1*sx,0,-0.62*sz>}	
			object {sBlock_squ2(0.06,23.42,0.06,0.8,Column) translate <1.155*sx,0,-0.465*sz>}	
			object {sBlock_cyl(0.08,23.42,0.8,Column) translate <1.31*sx,0,-0.41*sz>}	
			object {sBlock_squ2(0.08,23.42,0.08,0.8,Column) translate <1.365*sx,0,-0.255*sz>}	

			object {sBlock_squ2(0.08,23.42,0.08,0.8,Column) translate <-0.255*sx,0,1.365*sz>}	
			object {sBlock_cyl(0.08,23.42,0.8,Column) translate <-0.41*sx,0,1.31*sz>}
			object {sBlock_squ2(0.06,23.42,0.06,0.8,Column) translate <-0.465*sx,0,1.155*sz>}	
			object {sBlock_cyl(0.08,23.42,0.8,Column) translate <-0.62*sx,0,1.1*sz>}	
			object {sBlock_squ2(0.06,23.42,0.06,0.8,Column) translate <-0.69*sx,0,0.93*sz>}	
			object {sBlock_cyl(0.1,23.42,0.8,Column) translate <-0.86*sx,0,0.86*sz>}	
			object {sBlock_squ2(0.06,23.42,0.06,0.8,Column) translate <-0.93*sx,0,0.69*sz>}
			object {sBlock_cyl(0.08,23.46,0.8,Column) translate <-1.1*sx,0,0.62*sz>}	
			object {sBlock_squ2(0.06,9,0.06,0.8,Column) translate <-1.155*sx,0,0.465*sz>}	
			object {sBlock_cyl(0.08,9,0.8,Column) translate <-1.31*sx,0,0.41*sz>}	
			object {sBlock_squ2(0.08,9,0.08,0.8,Column) translate <-1.365*sx,0,0.255*sz>}	

			object {sBlock_squ2(0.08,23.42,0.08,0.8,Column) translate <0.255*sx,0,1.365*sz>}	
			object {sBlock_cyl(0.08,23.42,0.8,Column) translate <0.41*sx,0,1.31*sz>}
			object {sBlock_squ2(0.06,23.42,0.06,0.8,Column) translate <0.465*sx,0,1.155*sz>}	
			object {sBlock_cyl(0.08,23.42,0.8,Column) translate <0.62*sx,0,1.1*sz>}	
			object {sBlock_squ2(0.06,23.42,0.06,0.8,Column) translate <0.69*sx,0,0.93*sz>}	
			object {sBlock_cyl(0.1,23.42,0.8,Column) translate <0.86*sx,0,0.86*sz>}	
			object {sBlock_squ2(0.06,23.42,0.06,0.8,Column) translate <0.93*sx,0,0.69*sz>}
			object {sBlock_cyl(0.08,23.42,0.8,Column) translate <1.1*sx,0,0.62*sz>}	
			object {sBlock_squ2(0.06,23.42,0.06,0.8,Column) translate <1.155*sx,0,0.465*sz>}	
			object {sBlock_cyl(0.08,23.42,0.8,Column) translate <1.31*sx,0,0.41*sz>}	
			object {sBlock_squ2(0.08,23.42,0.08,0.8,Column) translate <1.365*sx,0,0.255*sz>}	

			translate 0.2*y
		}
		
		//--- Lower ornament
		union {
			#local i=0;
			#while (i<4)      
				union {
					object {sBlock_squ(0.8,0.5,0.8,0.5,0.8,0.8,Column) translate <0,-0.3,1.55>}
					object {sBlock_squ(2.192,0.5,0.8,0.2,0.6,0.5,Column) translate <0,-0.3,1.262> rotate 45*y}
					object {nBlock_squ(0.8,0.18,0.8,Column) translate <0,0.2,1.55>}
					object {nBlock_pyr(0.8,0.8,0.6,0.6,0.1,Column) translate <0,0.38,1.55>}
					object {nBlock_squ(0.6,0.2,0.6,Column) translate <0,0.48,1.55>}
					rotate 90*i*y
				}
				#local i=i+1;
			#end     
			object {nBlock_octcyl(0.22,0.05,Column) translate <-1.55,0.73,0>}
			object {nBlock_octcyl(0.22,0.02,Column) translate <-1.55,0.82,0>}
			object {nBlock_octcyl(0.22,0.05,Column) translate <1.55,0.73,0>}
			object {nBlock_octcyl(0.22,0.02,Column) translate <1.55,0.82,0>}
			object {nBlock_tor(0.22,0.05,360,Column) translate <0,0.73,1.55>}
			object {nBlock_tor(0.22,0.02,360,Column) translate <0,0.82,1.55>}
			object {nBlock_tor(0.22,0.05,360,Column) translate <0,0.73,-1.55>}
			object {nBlock_tor(0.22,0.02,360,Column) translate <0,0.82,-1.55>}
			
			#local coor = 
				array[4]
				{	<0.86*sx,0,-0.86*sz>
					<-0.86*sx,0,0.86*sz>
					<0.86*sx,0,0.86*sz>
					<-0.86*sx,0,-0.86*sz>
				}
			#local i=0;
			#while (i<4)               
				union {   
					object {nBlock_squ(0.4,0.18,0.4,Column) translate 0.2*y rotate 45*y}
					object {nBlock_pyr(0.4,0.4,0.3,0.3,0.1,Column) translate 0.38*y rotate 45*y}
					object {nBlock_squ(0.3,0.2,0.3,Column) translate 0.48*y rotate 45*y}
					#if (show_details)
						object {Block_pyr(0.4-2*d[Column],0.4-2*d[Column],0.3-2*d[Column],0.3-2*d[Column],0.1,Column,Mortar) translate 0.38*y rotate 45*y}	
					#end
					object {nBlock_tor(0.1,0.05,360,Column) translate 0.73*y}
					object {nBlock_tor(0.1,0.02,360,Column) translate 0.82*y}
					translate coor[i]
				}
				#local i=i+1;
			#end
			
			#local coor = 
				array[16]
				{	<0.41*sx,0,-1.31*sz>
					<0.62*sx,0,-1.1*sz>	
					<1.1*sx,0,-0.62*sz>	
					<1.31*sx,0,-0.41*sz>	
					<-0.41*sx,0,1.31*sz>
					<-0.62*sx,0,1.1*sz>	
					<-1.1*sx,0,0.62*sz>	
					<-1.31*sx,0,0.41*sz>	
					<0.41*sx,0,1.31*sz>
					<0.62*sx,0,1.1*sz>	
					<1.1*sx,0,0.62*sz>	
					<1.31*sx,0,0.41*sz>	
					<-0.41*sx,0,-1.31*sz>
					<-0.62*sx,0,-1.1*sz>	
					<-1.1*sx,0,-0.62*sz>	
					<-1.31*sx,0,-0.41*sz>	
				}
			#local i=0;
			#while (i<16)
				union {
					object {nBlock_squ(0.2,0.18,0.2,Column) translate 0.2*y}
					object {nBlock_pyr(0.2,0.2,0.18,0.18,0.1,Column) translate 0.38*y}
					object {nBlock_squ(0.18,0.2,0.18,Column) translate 0.48*y}
					#if (show_details)
						object {Block_pyr(0.2-2*d[Column],0.2-2*d[Column],0.18-2*d[Column],0.18-2*d[Column],0.1,Column,Mortar) translate 0.38*y}	
					#end
					object {nBlock_tor(0.08,0.05,360,Column) translate 0.73*y}
					object {nBlock_tor(0.08,0.02,360,Column) translate 0.82*y}
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
				object {nBlock_tor(0.22,0.02,360,Column) translate -0.37*y}
				translate -1.55*sz*z
			}
			union {
				object {nBlock_squ(0.8,0.05,0.8,Column) translate 0.15*y}				
				object {nBlock_squ(0.7,0.1,0.7,Column) translate 0.05*y}				
				object {nBlock_squ(0.6,0.05,0.6,Column)}
				object {nBlock_octcyl(0.22,0.02,Column) translate -0.37*y}
				translate -1.55*sx*x
			}
			union {
				object {nBlock_squ(0.4,0.05,0.4,Column) translate 0.15*y}
				object {nBlock_squ(0.35,0.1,0.35,Column) translate 0.05*y}
				object {nBlock_squ(0.3,0.05,0.3,Column)}
				object {nBlock_tor(0.08,0.02,360,Column) translate -0.24*y}				
				translate <0.41*sx,0,-1.31*sz>
			}
			union {
				object {nBlock_squ(0.4,0.05,0.4,Column) translate 0.15*y}
				object {nBlock_squ(0.35,0.1,0.35,Column) translate 0.05*y}
				object {nBlock_squ(0.3,0.05,0.3,Column)}
				object {nBlock_tor(0.08,0.02,360,Column) translate -0.37*y}				
				translate <-1.31*sx,0,0.41*sz>
			}
			union {
				object {nBlock_squ(2,0.05,0.4,Column) translate 0.15*y}				
				object {nBlock_squ(1.9,0.1,0.3,Column) translate 0.05*y}				
				object {nBlock_squ(1.8,0.05,0.2,Column)}
				translate -1.3*sz*z
				rotate 45*sx*sz*y
			}
			translate 9.08*y
		}
		
		//--- Upper ornament
		#local i=0;
		#while (i<2)
			union {
				object {nBlock_squ(0.7,0.05,0.7,Column) translate 23.71*y}
				object {nBlock_squ(0.65,0.08,0.55,Column) translate 23.63*y}
				object {nBlock_squ(0.6,0.05,0.5,Column) translate 23.58*y}
				translate 1.55*sx*x
				rotate -90*i*sx*sz*y
			}
			#local i=i+1;
		#end
		object {nBlock_octcyl(0.22,0.02,Column) translate <1.55*sx,23.2,0>}
		object {nBlock_tor(0.22,0.02,360,Column) translate <0,23.2,1.55*sz>}
		
		#local i=0;
		#while (i<3)
			union {
				object {nBlock_squ(0.5,0.05,0.5,Column) translate 23.71*y}
				object {nBlock_squ(0.45,0.08,0.45,Column) translate 23.63*y}
				object {nBlock_squ(0.4,0.05,0.4,Column) translate 23.58*y}
				object {nBlock_tor(0.1,0.02,360,Column) translate 23.36*y}
				rotate 45*sx*sz*y
				translate <0.86*sx,0,-0.86*sz>
				rotate -90*i*sx*sz*y
			}
			#local i=i+1;
		#end
			
		#local coor =
			array[8]
			{	<1.1*sx,0,-0.62*sz>
				<1.31*sx,0,-0.41*sz>
				<0.41*sx,0,1.31*sz>
				<0.62*sx,0,1.1*sz>
				<1.1*sx,0,0.62*sz>
				<1.31*sx,0,0.41*sz>
				<-0.41*sx,0,1.31*sz>
				<-0.62*sx,0,1.1*sz>
			}			
		#local i=0;
		#while (i<8)
			union {
				object {nBlock_squ(0.3,0.05,0.3,Column) translate 23.71*y}
				object {nBlock_squ(0.25,0.08,0.25,Column) translate 23.63*y}
				object {nBlock_squ(0.2,0.05,0.2,Column) translate 23.58*y}
				object {nBlock_tor(0.08,0.02,360,Column) translate 23.36*y}
				translate coor[i]
			}
			#local i=i+1;
		#end  
		
		//--- Leaves
		#if (show_ornaments)
			#local i=0;
			#while (i<4)
				object {leaf_curve2 translate <0.22,8.75,0> rotate (45+90*i)*y translate -1.55*sz*z}
				object {leaf_curve2 translate <0.22,8.75,0> rotate (45+90*i)*y translate -1.55*sx*x}
				object {leaf_curve2 scale <0.3,0.5,0.3> translate <0.08,8.88,0> rotate (45+90*i)*y translate <0.41*sx,0,-1.31*sz>}
				object {leaf_curve2 scale <0.65,0.95,0.9> translate <0.22,23.22,0> rotate (45+90*i)*y translate 1.55*sx*x}
				object {leaf_curve2 scale <0.65,0.95,0.9> translate <0.22,23.22,0> rotate (45+90*i)*y translate 1.55*sz*z}
				#local j=0;
				#while (j<3)
					object {leaf_curve2 scale <0.7,0.5,0.45> translate <0.1,23.38,0> rotate 90*i*y translate <0.86*sx,0,-0.86*sz> rotate -90*j*sx*sz*y}
					#local j=j+1;
				#end
				#local j=0;
				#while (j<8)
					object {leaf_curve2 scale <0.3,0.5,0.3> translate <0.08,23.38,0> rotate (45+90*i)*y translate coor[j]}
					#local j=j+1;
				#end
				#local i=i+1;
			#end
		#end
	}
#end