//----- CONSTRUCTION OF THE NORTH PORCH

#ifndef(aisle_endwall)
	#include "aisle_endwall.inc" 
#end

#macro north_porch()
	#local n=1.2;
	#local n1=1.3;
	#local h1=5.58;
	#local h2=10.4;
	#local h3=12;
	#local r=5.9;
	
	union {

		//--- Central - lower
		
		//- Main wall
		difference {
			object {sBlock_squ(14.36,15.2,1,0.8,0.8,0.4,Wall) translate 0.5*z}
			union {
				box {<-2.85,-1,-2> <2.85,6,2>}
				object {gothic_arch(2.85,n1,3) translate (6-dd)*y}
				box {<-3.65,-1,-2> <-5.15,2.4,2>}
				box {<3.65,-1,-2> <5.15,2.4,2>}
				cylinder {<-4.75,2.4,-2> <-4.75,2.4,2> 0.4}
				cylinder {<-4.05,2.4,-2> <-4.05,2.4,2> 0.4}
				cylinder {<-4.4,2.75,-2> <-4.4,2.75,2> 0.4}
				cylinder {<4.75,2.4,-2> <4.75,2.4,2> 0.4}
				cylinder {<4.05,2.4,-2> <4.05,2.4,2> 0.4}
				cylinder {<4.4,2.75,-2> <4.4,2.75,2> 0.4}
				texture {T_Block(Wall,NoMortar)}
			}
		}

		//- Front ornaments
		object {gothic_rin(2.85,2.85,0.65,n1,1,0,0.8,Wall) translate <0,6,0.5>}
		object {gothic_rin(2.85,2.85,0.65,n1,0.72,0,0.8,Wall) translate <0,5.4,0.64>}
		#local i=-1;
		#while (i<2)
			object {nBlock_pyr(2.23,1.1,2.13,1,0.1,Wall) translate <6.115*i,0.2,0.5>}
			object {nBlock_pyr(1.7,1.1,1.6,1,0.1,Wall) translate <2.95*i,0.2,0.5>}
			object {sBlock_squ(2.23,0.2,1.1,0.8,0.8,0.2,Wall) translate <6.115*i,0,0.5>}
			object {sBlock_squ(1.7,0.2,1.1,0.8,0.8,0.2,Wall) translate <2.95*i,0,0.5>}
			object {sBlock_ir2(0.1,0.05,1,0.9,2.4,-i,1,0.4,Wall) translate <5.15*i,0,1>}
			object {sBlock_ir2(0.1,0.05,1,0.9,2.4,i,1,0.4,Wall) translate <3.65*i,0,1>}
			object {sBlock_ir3(0.1,0.05,1,0.9,90,0.4,2,Wall) rotate -(1+i)*45*z translate <4.75*i,2.4,1>}
			object {sBlock_ir3(0.1,0.05,1,0.9,90,0.4,2,Wall) rotate -(1-i)*45*z translate <4.05*i,2.4,1>}
			object {sBlock_ir3(0.1,0.05,1,0.9,180,0.4,2,Wall) translate <4.4*i,2.75,1>}
			difference {
				box {<-1,0,-0.37> <1,2,0.37>}
				box {<-0.5,-dd,-1> <0.5,0.4,1>}
				cylinder {<0,0,-1> <0,0,1> 0.2 scale <0.5,1,1> translate -0.5*x}
				cylinder {<0,0,-1> <0,0,1> 0.2 scale <0.5,1,1> translate 0.5*x}
				texture {T_Block(Wall,NoMortar)}
				translate <4.4*i,2,0.47>
			}
			union {
				object {sBlock_cyl(0.1,h2,0.8,Column)}
				object {nBlock_squ(0.4,0.2,0.4,Column)}
				object {nBlock_pyr(0.4,0.4,0.3,0.3,0.1,Column) translate 0.2*y}
				object {nBlock_squ(0.3,0.2,0.3,Column) translate 0.3*y}
				object {nBlock_tor(0.1,0.05,360,Column) translate 0.55*y}
				object {nBlock_tor(0.1,0.02,360,Column) translate 0.64*y}
				object {nBlock_tor(0.1,0.02,360,Column) translate (h2-0.4)*y}
				object {nBlock_squ(0.3,0.05,0.3,Column) translate (h2-0.15)*y}
				object {nBlock_squ(0.35,0.05,0.35,Column) translate (h2-0.1)*y}
				object {nBlock_squ(0.4,0.05,0.4,Column) translate (h2-0.05)*y}				
				translate <2.85*i,0,-0.1>
			}
			union {
				object {sBlock_cyl(0.1,h2,0.8,Column)}
				object {nBlock_squ(0.4,0.2,0.4,Column)}
				object {nBlock_pyr(0.4,0.4,0.3,0.3,0.1,Column) translate 0.2*y}
				object {nBlock_squ(0.3,0.2,0.3,Column) translate 0.3*y}
				object {nBlock_tor(0.1,0.05,360,Column) translate 0.55*y}
				object {nBlock_tor(0.1,0.02,360,Column) translate 0.64*y}
				object {nBlock_tor(0.1,0.02,360,Column) translate (h2-0.4)*y}
				object {nBlock_squ(0.3,0.05,0.3,Column) translate (h2-0.15)*y}
				object {nBlock_squ(0.35,0.05,0.35,Column) translate (h2-0.1)*y}
				object {nBlock_squ(0.4,0.05,0.4,Column) translate (h2-0.05)*y}
				translate <5.95*i,0,-0.1>
			}
			object {sBlock_squ(0.7,6,1,0.6,0.6,0.4,Wall) translate <2.55*i,0,0.5>}
			#local i=i+2;
		#end
		object {sBlock_squ(4.3,2.4,0.26,0.8,0.8,0.4,Wall) translate <0,6,0.7>}
		difference {
			object {sBlock_squ(14.36,15.2-h2,0.28,0.8,0.8,0.4,Wall) translate <0,h2,-0.14>}
			union {
				object {gothic_arch(2.85,n1,3) translate (h2-dd)*y}
				#local i=-1;
				#while (i<2)
					box {<5.95*i,h2-dd,-1> <2.85*i,h3,1>}
					object {gothic_arch(1.55,n1,3) translate <4.4*i,h3-dd,0>}
					#local i=i+2;
				#end
				texture {T_Block(Wall,NoMortar)}
			}
		}   
		
		object {gothic_tor(2.85,2.72,0.06,n1,0,0.8,Column) translate <0,h2,-0.23>}
		object {gothic_rin(2.85,2.85,0.09,n1,0.28,0,0.8,Column) translate <0,h2,-0.14>}
		#local i=-1;
		#while (i<2)
			object {gothic_tor(1.55,1.42,0.06,n1,0,0.8,Column) translate <4.4*i,h3,-0.23>}
			object {gothic_rin(1.55,1.55,0.09,n1,0.28,0,0.8,Column) translate <4.4*i,h3,-0.14>}
			
			#local j=-1;
			#while (j<2)
				union {
					object {sBlock_cyl(0.06,h3-h2,0.8,Column) translate <1.42*i+4.4*j,0,-0.23>}
					object {sBlock_squ2(0.09,h3-h2,0.28,0.8,Column) translate <1.505*i+4.4*j,0,-0.14>}
					translate h2*y
				}
				#local j=j+2;
			#end
			#local i=i+2;
		#end		

		
		//--- Central - upper
		object {sBlock_squ2(0.05,14.36,0.2,0.8,Wall) translate -7.18*y rotate 90*z translate <0,15.175,-0.28>}
		object {sBlock_squ2(0.05,14.36,0.1,0.8,Wall) translate -7.18*y rotate 90*z translate <0,15.125,-0.28>}
		object {sBlock_ir2(0.6,0.4,1.28,0.52,14.36,1,1,0.4,Wall) translate -7.18*y rotate 90*z translate <0,15.2,1>}
		difference {
			object {sBlock_squ(14.36,18.81-h1,0.52,0.8,0.8,0.4,Wall) translate <0,15.8+h1,0.74>}
			union {
				#local i=0;
				#while (i<5)
					object {gothic_arch(1.32,n,3) translate <-4.68+2.34*i,15.8+h1-dd,0>}
					#local i=i+1;
				#end
				cylinder {<0,34.51-r,-2> <0,34.51-r,2> r}
				#local coor_x = array[4] {5.4,4.56,3.68,2.82};
				#local coor_y = array[4] {2.5,1.4,0.6,0.1};
				#local i=-1;
				#while (i<2)
					#local j=0;
					#while (j<4)
						union {
							difference {
								union {
									cylinder {<-0.18,coor_y[j],-2> <-0.18,coor_y[j],2> 0.18}
									cylinder {<0.18,coor_y[j],-2> <0.18,coor_y[j],2> 0.18}
								}
								box {<-0.4,coor_y[j]-dd,-3> <0.4,coor_y[j]-0.2,3>}
							}
							cylinder {<0,coor_y[j]+0.18,-2> <0,coor_y[j]+0.18,2> 0.18}
							box {<-0.36,0,-2> <0.36,coor_y[j],2>}
							translate <coor_x[j]*i,22.93,0>
						}
						#local j=j+1;
					#end
					#local i=i+2;
				#end
				#local i=0;
				#while (i<6)
					cylinder {<0,0,-2> <0,0,2> 0.25 translate <-5.85+2.34*i,22.53,0>}
					#local i=i+1;
				#end
				texture {T_Block(Wall,NoMortar)}
			}
		}
		
		union {
			#local i=-1;
			#while (i<2)
				object {sBlock_ir2(0.45,0.3,0.52,0.32,h1,-i,1,0.8,Wall) translate <6*i,15.8,1>}
				object {sBlock_ir2(1,0.92,1,0.92,19.31-r,-i,1,0.8,Wall) translate <6.75*i,15.2,1>}            
            object {nBlock_squ(1,0.4,1,Column) translate <6.25*i,15.6,0.22>}
            object {nBlock_squ(0.3,0.2,0.3,Column) translate <5.95*i,16,-0.1>}
            object {nBlock_tor(0.1,0.04,360,Column) translate <5.95*i,16.23,-0.1>}
            object {nBlock_tor(0.1,0.02,360,Column) translate <5.95*i,16.29,-0.1>}
				object {sBlock_cyl(0.1,13.41,0.8,Column) translate <5.95*i,15.2,-0.1>}
				object {nBlock_squ(0.35,0.05,0.35,Column) translate <5.95*i,28.56,-0.1>}
				object {nBlock_squ(0.3,0.05,0.3,Column) translate <5.95*i,28.51,-0.1>}
				object {nBlock_squ(0.25,0.05,0.25,Column) translate <5.95*i,28.46,-0.1>}
				object {nBlock_tor(0.1,0.02,360,Column) translate <5.95*i,28.21,-0.1>}
				#local i=i+2;
			#end
			#local i=0;
			#while (i<4)
				object {sBlock_ir1(0.6,0.3,0.52,0.32,h1,0.8,Wall) translate <-5.85+2.34*(i+1),15.8,1>}
				object {nBlock_squ(0.2,0.4,0.2,Column) translate <-5.85+2.34*(i+1),15.7,0.43>}
				object {nBlock_tor(0.07,0.04,360,Column) translate <-5.85+2.34*(i+1),16.11,0.43>} 
				object {nBlock_tor(0.07,0.02,360,Column) translate <-5.85+2.34*(i+1),16.14,0.43>} 
				object {sBlock_cyl(0.07,h1,0.8,Column) translate <-5.85+2.34*(i+1),15.8,0.43>}
				object {nBlock_squ(0.3,0.05,0.2,Column) translate <-5.85+2.34*(i+1),h1+15.75,0.43>}
				object {nBlock_squ(0.25,0.05,0.22,Column) translate <-5.85+2.34*(i+1),h1+15.7,0.43>}
				object {nBlock_squ(0.2,0.05,0.2,Column) translate <-5.85+2.34*(i+1),h1+15.65,0.43>}
				object {nBlock_tor(0.07,0.02,360,Column) translate <-5.85+2.34*(i+1),h1+15.5,0.43>}
				#local i=i+1;
			#end
			#local i=0;
			#while (i<5)				
				union {
					#if (i=2)
						difference {
							object {gothic_ir3(1.32,1.32,0.45,0.3,0.52,0.32,n,0,0.8,Wall)}
							cylinder {<0,19.28-r-h1,-1> <0,19.28-r-h1,1> r texture {T_Block(Wall,NoMortar)}}
						}
					#else
						object {gothic_ir3(1.32,1.32,0.45,0.3,0.52,0.32,n,0,0.8,Wall)}
					#end
					object {gothic_tor(1.32,1.17,0.07,n,0,0.4,Column) translate -0.57*z}
					translate <-4.68+2.34*i,15.8+h1,1>			
				}
				#local i=i+1;
			#end
			union {
				object {sBlock_ir3(0.45,0.3,0.52,0.32,180,r,0.8,Wall)}		
				object {sBlock_ir3(0.45,0.3,0.52,0.32,180,r,0.8,Wall) rotate 180*z}		
				object {sBlock_ir3(1,0.92,1,0.92,180,6.75,0.8,Wall)}
				object {sBlock_tor(5.95,0.1,180,0.8,Wall) rotate -90*x translate -1.1*z}
				translate <0,34.51-r,1>
			}
		}

		//--- Laterals
		#local i=-1;
		#while (i<2)
			object {aisle_endwall(2) translate 10.77*i*x}		 
			#local i=i+2;
		#end

		//--- Doors
		object {nBlock_squ(6,0.2,0.26,Door) translate -0.1 rotate 90*z translate <0,3,0.7>}
		object {sBlock_squ2(6,4.4,0.2,0.2,Door) translate -2.2*y rotate 90*z translate <0,3,0.73>}
		object {sBlock_squ2(3,1.5,0.05,0.1,Door) translate -0.75*y rotate 90*z translate <4.4,1.5,0.2>}
		object {sBlock_squ2(3,1.5,0.05,0.1,Door) translate -0.75*y rotate 90*z translate <-4.4,1.5,0.2>}
		
		//--- Vitress
		#if (show_vitress)
			#local i=0;
			#while (i<5)
				object {Vitress(1.74,6.95,concat("vNorthPorch_d",str(i+1,1,0))) translate <-4.68+2.34*i,15.5,0.9>}
				#local i=i+1;
			#end
			#local i=0;
			#while (i<6)
				object {Vitress(0.5,0.5,concat("vNorthPorch_c",str(i+1,1,0))) translate <-5.85+2.34*i,22.28,0.9>}
				#local i=i+1;
			#end
			object {Vitress(11.52,(11.58-r)*2,"vNorthPorch_u") translate <0,22.93,0.9>}
		#end

		//--- Leaves
		#if (show_ornaments)
			#local i=0;
			#while (i<4)
				object {leaf_curve2 scale <0.5,0.6,0.5> translate <0.1,h2-0.4,0> rotate (45+90*i)*y translate <2.85,0,-0.1>}
				object {leaf_curve2 scale <0.5,0.6,0.5> translate <0.1,h2-0.4,0> rotate (45+90*i)*y translate <-2.85,0,-0.1>}
				object {leaf_curve2 scale <0.5,0.6,0.5> translate <0.1,h2-0.4,0> rotate (45+90*i)*y translate <5.95,0,-0.1>}
				object {leaf_curve2 scale <0.5,0.6,0.5> translate <0.1,h2-0.4,0> rotate (45+90*i)*y translate <-5.95,0,-0.1>}
				object {leaf_curve2 scale <0.5,0.6,0.5> translate <0.1,28.21,0> rotate (45+90*i)*y translate <5.95,0,-0.1>}
				object {leaf_curve2 scale <0.5,0.6,0.5> translate <0.1,28.21,0> rotate (45+90*i)*y translate <-5.95,0,-0.1>}
				#local j=0;
				#while (j<4)
					object {leaf_curve2 scale <0.3,0.4,0.3> translate <0.07,h1+15,0> rotate (45+90*i)*y translate <-5.85+2.34*(j+1),0.5,0.43>}
					#local j=j+1;
				#end
				#local i=i+1;
			#end
		#end
	}	
#end