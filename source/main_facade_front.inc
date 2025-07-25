//----- CONSTRUCTION OF THE FRONT OF THE MAIN ENTRANCE HALL

#macro main_facade_front()
	union {
		//--- Lower part
		difference {
			object {sBlock_squ(15.8,5,1,0.8,0.8,0.5,Wall) translate 5*y}
			union {
				#local i=-1;
				#while (i<2)
					object {gothic_arch(1.85,1.3,2) translate <5.65*i,5,0>}
					#local i=i+2;
				#end
				object {gothic_arch(2.5,1.3,2) translate 5*y}
				texture {T_Block(Wall,NoMortar)}								
			}
			translate 0.5*z
		}
		union {
			object {sBlock_squ(0.9,5,1,0.8,0.8,0.5,Wall) translate -7.45*x}
			object {sBlock_squ(2.3,5,1,0.8,0.8,0.5,Wall) translate -3.15*x}
			object {sBlock_squ(2.3,5,1,0.8,0.8,0.5,Wall) translate 3.15*x}
			object {sBlock_squ(0.9,5,1,0.8,0.8,0.5,Wall) translate 7.45*x}
			translate 0.5*z
		}
		
		#local i=-1;
		#while (i<2)
			union {
				object {nBlock_pyr(1,1,0.9,0.9,0.2,Column) translate 0.25*y}				
				object {nBlock_squ(0.9,0.25,0.9,Column) translate 0.45*y}
				object {nBlock_pyr(0.9,0.9,0.7,0.7,0.1,Column) translate 0.7*y}
				object {nBlock_tor(0.35,0.04,360,Column) translate 0.83*y}
				object {sBlock_cyl(0.35,5,0.5,Column)}
				object {nBlock_tor(0.35,0.04,360,Column) translate 4.3*y}
				object {nBlock_squ(1,0.05,1,Column) translate 4.85*y}
				object {nBlock_squ(1.1,0.1,1.1,Column) translate 4.9*y}
				object {sBlock_squ2(1,3.2,0.3,0.4,Column) translate <0,5,-0.15>}
				object {nBlock_squ(0.6,0.2,0.6,Column) translate 8.2*y}
				object {nBlock_tor(0.2,0.03,360,Column) translate 8.42*y}
				object {sBlock_cyl(0.2,11,0.5,Column) translate 8*y} 
				object {nBlock_tor(0.2,0.05,360,Column) translate 10*y}
				object {nBlock_tor(0.2,0.05,360,Column) translate 18.4*y}
				object {nBlock_squ(0.6,0.05,0.6,Column) translate 18.8*y}
				object {nBlock_squ(0.7,0.05,0.7,Column) translate 18.85*y}
				object {nBlock_squ(0.8,0.1,0.8,Column) translate 18.9*y}
				translate 3.5*i*x
			}
			union {
				object {nBlock_pyr(1,1,0.9,0.9,0.2,Column) translate 0.25*y}				
				object {nBlock_squ(0.9,0.25,0.9,Column) translate 0.45*y}
				object {nBlock_pyr(0.9,0.9,0.7,0.7,0.1,Column) translate 0.7*y}
				object {nBlock_tor(0.35,0.04,360,Column) translate 0.83*y}
				object {sBlock_cyl(0.35,5,0.5,Column)}
				object {nBlock_tor(0.35,0.04,360,Column) translate 4.3*y}
				object {nBlock_squ(1,0.05,1,Column) translate 4.85*y}
				object {nBlock_squ(1.1,0.1,1.1,Column) translate 4.9*y}
				object {sBlock_squ2(1,3.2,0.3,0.4,Column) translate <0,5,-0.15>}
				object {nBlock_squ(0.5,0.2,0.5,Column) translate 8.2*y}
				object {nBlock_tor(0.15,0.03,360,Column) translate 8.42*y}
				object {sBlock_cyl(0.15,11,0.5,Column) translate 8*y} 
				object {nBlock_tor(0.15,0.05,360,Column) translate 10*y}
				object {nBlock_tor(0.15,0.05,360,Column) translate 18.4*y}
				object {nBlock_squ(0.6,0.05,0.6,Column) translate 18.8*y}
				object {nBlock_squ(0.7,0.05,0.7,Column) translate 18.85*y}
				object {nBlock_squ(0.8,0.1,0.8,Column) translate 18.9*y}
				translate 7.8*i*x
			}
			object {gothic_rin(1.85,1.85,0.5,1.3,1,0,0.8,Wall) translate <5.65*i,5,0.5>}
			object {sBlock_squ(3,1.8,0.5,0.8,0.8,0.4,Wall) translate <5.65*i,5,0.75>}
			#local i=i+2;
		#end
		object {gothic_rin(2.5,2.5,0.5,1.3,1,0,0.8,Wall) translate <0,5,0.5>}
		object {sBlock_cyl(0.05,15.8,0.5,Column) translate -7.9*y rotate 90*z translate 10*y}
		object {sBlock_squ(4,2.8,0.5,0.8,0.8,0.4,Wall) translate <0,5,0.75>}


		//--- Mid part
		
		difference {
			object {sBlock_squ(15.8,3.8,1,0.8,0.8,0.4,Wall) translate <0,19,0.5>}
			object {gothic_arch(1.8,1.1,3) translate <-5.5,19-dd,0>}
			object {gothic_arch(1.8,1.1,3) translate <5.5,19-dd,0>}
			object {gothic_arch(3.1,1.1,3) translate (19-dd)*y}
			texture {T_Block(Wall,NoMortar)}
		}
		difference {
			object {sBlock_squ(15.8,3.8,0.4,0.8,0.8,0.38,Wall) translate <0,19,-0.2>}
			object {gothic_arch(3.47,1.1,2) translate <0,19-dd,0>}
			object {gothic_arch(2.25,1.1,2) translate <5.65,19-dd,0>}
			object {gothic_arch(2.25,1.1,2) translate <-5.65,19-dd,0>}
			texture {T_Block(Wall,NoMortar)}
		}              
		
		object {sBlock_squ2(0.1,16,0.2,0.8,Wall) translate -8*y rotate 90*z translate <0,22.75,-0.5>}
		object {gothic_rin(3.47,3.1,0.8,1.1,1,0,0.8,Wall) translate <0,19,0.5>}
		object {gothic_rin(3.47,3.47,0.2,1.1,0.4,0,0.8,Wall) translate <0,19,-0.2>}
		object {sBlock_squ(16,1.2,0.2,0.8,0.8,0.4,Wall) translate <0,10,0.9>}
		object {sBlock_squ(16,0.6,0.2,0.8,0.8,0.6,Wall) translate <0,10,0.7>}
		object {sBlock_squ(16,0.4,0.2,0.8,0.8,0.4,Wall) translate <0,10,0.5>}
		object {sBlock_squ(16,0.2,0.2,0.8,0.8,0.2,Wall) translate <0,10,0.3>}
		
		#local i=-1;
		#while (i<2)
			object {gothic_rin(2.25,1.8,0.4,1.1,1,0,0.8,Wall) translate <5.5*i,19,0.5>}
			object {gothic_rin(2.25,2.25,0.4,1.1,0.4,0,0.8,Wall) translate <5.65*i,19,-0.2>}
			object {sBlock_squ2(1.4,9,1,0.4,Wall) translate <3.4*i,10,0.5>}
			object {sBlock_squ2(1,9,1,0.4,Wall) translate <7.4*i,10,0.5>}
			object {sBlock_squ2(0.4,9,0.6,0.4,Wall) translate <2.5*i,10,0.7>}
			object {nBlock_squ(0.4,0.2,0.4,Column) translate <2.5*i,10,0.2>}
			object {nBlock_tor(0.15,0.02,360,Column) translate <2.5*i,10.1,0.2>}
			object {sBlock_cyl(0.15,9,0.5,Column) translate <2.5*i,10,0.2>} 
			object {nBlock_tor(0.15,0.02,360,Column) translate <2.5*i,18.6,0.2>}
			object {nBlock_squ(0.4,0.1,0.4,Column) translate <2.5*i,18.9,0.2>}
			object {nBlock_squ(0.35,0.05,0.35,Column) translate <2.5*i,18.85,0.2>}
			object {nBlock_squ(0.31,0.05,0.31,Column) translate <2.5*i,18.8,0.2>}
			#local i=i+2;
		#end
		
		//--- Upper part
		difference {
			object {sBlock_squ(15.8,13.2,0.58,0.8,0.8,0.4,Wall) translate <0,22.8,1.16>}
			cylinder {<0,29.1,-2> <0,29.1,2> 6.3}
			texture {T_Block(Wall,NoMortar)}
		}
		union {
			object {sBlock_ir3(0.45,0.3,0.52,0.32,180,6.3,0.8,Wall)}		
			object {sBlock_ir3(0.45,0.3,0.52,0.32,180,6.3,0.8,Wall) rotate 180*z}		
			translate <0,29.1,1.4>
		}
		#local i=-1;
		#while (i<2)
			object {sBlock_cyl(0.08,1.86,0.5,Column) translate <7.67*i,22.8,-0.42>}
			object {nBlock_squ(0.3,0.2,0.3,Column) translate <7.67*i,22.8,-0.42>}
			object {nBlock_tor(0.08,0.05,360,Column) translate <7.67*i,23.03,-0.42>}  
			object {nBlock_tor(0.08,0.02,360,Column) translate <7.67*i,23.08,-0.42>}  
			object {sBlock_cyl(0.15,1.86,0.5,Column) translate <7.43*i,22.8,-0.1>}
			object {nBlock_squ(0.45,0.2,0.45,Column) translate <7.43*i,22.8,-0.1>}
			object {nBlock_tor(0.15,0.05,360,Column) translate <7.43*i,23.03,-0.1>}  
			object {nBlock_tor(0.15,0.02,360,Column) translate <7.43*i,23.08,-0.1>}  
			object {nBlock_squ(0.58,0.1,0.58,Column) rotate 45*y translate <7.43*i,24.66,-0.1>}
			object {nBlock_squ(0.53,0.1,0.53,Column) rotate 45*y translate <7.43*i,24.56,-0.1>}
			object {nBlock_pyr(0.5,0.5,0.3,0.3,0.3,Column) rotate 45*y scale <1,-1,1> translate <7.43*i,24.56,-0.1>}
			object {nBlock_tor(0.15,0.03,360,Column) translate <7.43*i,24.13,-0.1>}
			object {sBlock_cyl(0.08,6.3,0.5,Column) translate <6.87*i,22.8,0.38>}
			object {nBlock_squ(0.3,0.2,0.3,Column) translate <6.87*i,22.8,0.38>}
			object {nBlock_tor(0.08,0.05,360,Column) translate <6.87*i,23.03,0.38>}  
			object {nBlock_tor(0.08,0.02,360,Column) translate <6.87*i,23.08,0.38>}  
			object {nBlock_squ(0.3,0.05,0.4,Column) translate <6.87*i,29.05,0.38>}
			object {nBlock_squ(0.25,0.05,0.35,Column) translate <6.87*i,29,0.38>}
			object {nBlock_squ(0.2,0.05,0.3,Column) translate <6.87*i,28.95,0.38>}
			object {nBlock_tor(0.08,0.02,360,Column) translate <6.87*i,28.8,0.38>}
			object {sBlock_ir2(0.8,0,1.2,0.4,6.3,-i,1,0.4,Wall) translate <7.67*i,22.8,0.88>}
			#local i=i+2;
		#end
		object {sBlock_ir3(0.8,0,1.2,0.4,180,7.67,0.8,Wall) translate <0,29.1,0.88>}
		object {sBlock_tor(6.87,0.08,180,0.8,Wall) rotate -90*x translate <0,29.1,0.38>}
						
		//--- Doors
		object {nBlock_squ(5,0.2,0.26,Door) translate -0.1*y rotate 90*z translate <0,2.5,0.7>}
		object {nBlock_squ(5,0.2,0.26,Door) translate -0.1*y rotate 90*z translate <5.65,2.5,0.7>}
		object {nBlock_squ(5,0.2,0.26,Door) translate -0.1*y rotate 90*z translate <-5.65,2.5,0.7>}
		object {sBlock_squ2(5,4.2,0.2,0.2,Door) translate -2.1*y rotate 90*z translate <0,2.5,0.73>}
		object {sBlock_squ2(5,2.7,0.2,0.2,Door) translate -1.35*y rotate 90*z translate <5.65,2.5,0.73>}
		object {sBlock_squ2(5,2.7,0.2,0.2,Door) translate -1.35*y rotate 90*z translate <-5.65,2.5,0.73>}

		//--- Vitress
		#if (show_vitress)
			object {Vitress(4.6,10.4,"vMainFacadeFront_c") translate <0,11.2,0.9>}
			object {Vitress(2.8,9.4,"vMainFacadeFront_r") translate <5.5,11.2,0.9>}
			object {Vitress(2.8,9.4,"vMainFacadeFront_l") translate <-5.5,11.2,0.9>}
			object {Vitress(11.7,11.7,"vMainFacadeFront_u") translate <0,23.25,1.3>}
		#end

		//--- Leaves
		#if (show_ornaments)
			#local i=0;
			#while (i<4)
				object {leaf_curve2 scale 1.5 translate <0.35,4.3,0> rotate (45+90*i)*y translate 3.5*x}
				object {leaf_curve2 scale 1.5 translate <0.35,4.3,0> rotate (45+90*i)*y translate -3.5*x}
				object {leaf_curve2 scale 1.5 translate <0.35,4.3,0> rotate (45+90*i)*y translate 7.8*x}
				object {leaf_curve2 scale 1.5 translate <0.35,4.3,0> rotate (45+90*i)*y translate -7.8*x}
				object {leaf_curve2 scale <1,1.2,1> translate <0.2,18.4,0> rotate (45+90*i)*y translate 3.5*x}
				object {leaf_curve2 scale <1,1.2,1> translate <0.2,18.4,0> rotate (45+90*i)*y translate -3.5*x}
				object {leaf_curve2 scale <1,1.2,0.75> translate <0.15,18.4,0> rotate (45+90*i)*y translate 7.8*x}
				object {leaf_curve2 scale <1,1.2,0.75> translate <0.15,18.4,0> rotate (45+90*i)*y translate -7.8*x}
				object {leaf_curve2 scale <0.3,0.5,0.5> translate <0.15,18.6,0> rotate (45+90*i)*y translate <2.5,0,0.2>}
				object {leaf_curve2 scale <0.3,0.5,0.5> translate <0.15,18.6,0> rotate (45+90*i)*y translate <-2.5,0,0.2>}
				object {leaf_curve2 scale <0.3,0.4,0.4> translate <0.08,28.8,0> rotate (45+90*i)*y translate <6.87,0,0.38>}
				object {leaf_curve2 scale <0.3,0.4,0.4> translate <0.08,28.8,0> rotate (45+90*i)*y translate <-6.87,0,0.38>}
				#local i=i+1;
			#end
		#end
	}
#end