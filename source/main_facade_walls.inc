//----- CONSTRUCTION OF THE LATERAL WALLS OF THE MAIN ENTRANCE HALL
//      sx: Simmetry in x axis

#ifndef(clerestory3_step)
	#include "clerestory3_step.inc" 
#end

#macro main_facade_walls(sx)
	union {
	
		//--- Lower part
		
		//- Wall
		difference {
			object {sBlock_squ(12.34,9.2,2,0.8,0.8,0.4,Wall) translate <0.1,0,0>}
			union {
				box {<-2.8,-0.4-dd,-2> <5,4.5,2>}
				difference {
					cylinder {<-1,4.5,-2> <-1,4.5,2> 2.1}
					box {<-3.1,4.5-dd,-2> <1.1,2.5,2>}
				}
				difference {
					cylinder {<3.2,4.5,-2> <3.2,4.5,2> 2.1}
					box {<1,4.5-dd,-2> <5.3,2.5,2>}
				}
				texture {T_Block(Wall,NoMortar)}
			}
		}
		
		//- Central column				
		union {
			object {nBlock_squ(0.9,0.7,0.9,Column)}
			object {nBlock_pyr(0.9,0.9,0.7,0.7,0.1,Column) translate 0.7*y}
			object {nBlock_tor(0.35,0.04,360,Column) translate 0.83*y}
			object {sBlock_cyl(0.35,5,0.5,Column)}
			object {nBlock_tor(0.35,0.04,360,Column) translate 4.2*y}
			object {nBlock_squ(0.9,0.05,0.9,Column) translate 4.8*y}
			object {nBlock_squ(1,0.05,1,Column) translate 4.85*y}
			object {nBlock_squ(1.1,0.1,1.1,Column) translate 4.9*y}
			difference {
				object {sBlock_squ2(1,10.4,0.5,0.4,Wall) translate <0,4.8,-0.25>}
				cylinder {<2.45,5.65,-1> <2.45,5.65,1> 2.3}
				box {<0.15,5-dd,-1> <1,5.65,1>}
				box {<-0.25,5-dd,-1> <-1,6.3,1>}
				box {<-0.25,5-dd,-1> <-1,6.3,1> translate <0.25,-6.3,0> rotate -70*z translate <-0.25,6.3,0>}
				texture {T_Block(Wall,NoMortar)}
			}
			translate <1.1,0,-1>
		}
		
		//- Lateral columns and behind the main column
		union {
			object {sBlock_squ(1,4.5,2,1,1,0.5,Wall)}
			object {sBlock_squ(1.7,4.5,1.4,1.7,1.7,0.5,Wall)}
			object {sBlock_squ(2.4,4.5,0.8,2.4,2.4,0.5,Wall)}
			object {nBlock_squ(1.1,0.7,2.1,Wall)}
			object {nBlock_pyr(1.1,2.1,1,2,0.05,Wall) translate 0.7*y}
			object {nBlock_squ(1+2*s[Wall],2*s[Wall],2+2*s[Wall],Wall) translate 0.75*y}
			object {nBlock_squ(1+2*s[Wall],2*s[Wall],2+2*s[Wall],Wall) translate 4*y}
			object {nBlock_squ(1.1,0.05,2.1,Wall) translate 4.3*y}
			object {nBlock_squ(1.2,0.05,2.2,Wall) translate 4.35*y}
			object {nBlock_squ(1.3,0.1,2.3,Wall) translate 4.4*y}
			object {nBlock_squ(1.8,0.7,1.5,Wall)}
			object {nBlock_pyr(1.8,1.5,1.7,1.4,0.05,Wall) translate 0.7*y}
			object {nBlock_squ(1.7+2*s[Wall],2*s[Wall],1.4+2*s[Wall],Wall) translate 0.75*y}
			object {nBlock_squ(1.7+2*s[Wall],2*s[Wall],1.4+2*s[Wall],Wall) translate 4*y}
			object {nBlock_squ(1.8,0.05,1.5,Wall) translate 4.3*y}
			object {nBlock_squ(1.9,0.05,1.6,Wall) translate 4.35*y}
			object {nBlock_squ(2,0.1,1.7,Wall) translate 4.4*y}
			object {nBlock_squ(2.5,0.7,0.9,Wall)}
			object {nBlock_pyr(2.5,0.9,2.4,0.8,0.05,Wall) translate 0.7*y}
			object {nBlock_squ(2.4+2*s[Wall],2*s[Wall],0.8+2*s[Wall],Wall) translate 0.75*y}
			object {nBlock_squ(2.4+2*s[Wall],2*s[Wall],0.8+2*s[Wall],Wall) translate 4*y}
			object {nBlock_squ(2.5,0.05,0.9,Wall) translate 4.3*y}
			object {nBlock_squ(2.6,0.05,1,Wall) translate 4.35*y}
			object {nBlock_squ(2.7,0.1,1.1,Wall) translate 4.4*y}
			
			object {sBlock_squ(0.16,4.5,1.64,0.2,0.2,0.5,Wall) translate -3.78*x}
			object {sBlock_squ(0.35,4.5,1.1,0.3,0.3,0.5,Wall) translate -3.525*x}
			object {sBlock_squ(0.35,4.5,0.5,0.3,0.3,0.5,Wall) translate -3.175*x}
			object {nBlock_squ(0.2,0.7,0.2,Wall) translate <-3.82,0,-0.92>}
			object {nBlock_pyr(0.2,0.2,0.1,0.1,0.05,Wall) translate <-3.82,0.7,-0.92>}
			object {sBlock_cyl(0.08,4.5,0.5,Column) translate <-3.82,0,-0.92>}
			object {nBlock_squ(0.4,0.7,0.4,Wall) translate <-3.55,0,-0.55>}
			object {nBlock_pyr(0.4,0.4,0.3,0.3,0.05,Wall) translate <-3.55,0.7,-0.55>}
			object {sBlock_cyl(0.15,4.5,0.5,Column) translate <-3.55,0,-0.55>}
			object {nBlock_squ(0.4,0.7,0.4,Wall) translate <-3.2,0,-0.25>}
			object {nBlock_pyr(0.4,0.4,0.3,0.3,0.05,Wall) translate <-3.2,0.7,-0.25>}
			object {sBlock_cyl(0.15,4.5,0.5,Column) translate <-3.2,0,-0.25>}
			object {nBlock_tor(0.08,s[Wall],360,Column) translate <-3.82,0.75,-0.92>}
			object {nBlock_tor(0.08,s[Wall],360,Column) translate <-3.82,4,-0.92>}
			object {nBlock_tor(0.15,s[Wall],360,Column) translate <-3.55,0.75,-0.55>}
			object {nBlock_tor(0.15,s[Wall],360,Column) translate <-3.55,4,-0.55>}
			object {nBlock_tor(0.15,s[Wall],360,Column) translate <-3.2,0.75,-0.25>}
			object {nBlock_tor(0.15,s[Wall],360,Column) translate <-3.2,4,-0.25>}
			object {nBlock_squ(0.26,0.7,1.74,Wall) translate -3.78*x}
			object {nBlock_pyr(0.26,1.74,0.16,1.64,0.05,Wall) translate <-3.78,0.7,0>}
			object {nBlock_squ(0.16+2*s[Wall],2*s[Wall],1.64+2*s[Wall],Wall) translate <-3.78,0.75,0>}
			object {nBlock_squ(0.16+2*s[Wall],2*s[Wall],1.64+2*s[Wall],Wall) translate <-3.78,4,0>}
			object {nBlock_squ(0.5,0.05,2.1,Wall) translate <-3.85,4.3,0>}
			object {nBlock_squ(0.6,0.05,2.2,Wall) translate <-3.85,4.35,0>}
			object {nBlock_squ(0.7,0.1,2.3,Wall) translate <-3.85,4.4,0>}
			object {nBlock_squ(0.45,0.7,1.2,Wall) translate -3.525*x}
			object {nBlock_pyr(0.45,1.2,0.35,1.1,0.05,Wall) translate <-3.525,0.7,0>}
			object {nBlock_squ(0.35+2*s[Wall],2*s[Wall],1.1+2*s[Wall],Wall) translate <-3.525,0.75,0>}
			object {nBlock_squ(0.35+2*s[Wall],2*s[Wall],1.1+2*s[Wall],Wall) translate <-3.525,4,0>}
			object {nBlock_squ(0.5,0.05,0.4,Wall) translate <-3.55,4.3,-0.55>}
			object {nBlock_squ(0.6,0.05,0.5,Wall) translate <-3.55,4.35,-0.55>}
			object {nBlock_squ(0.7,0.1,0.6,Wall) translate <-3.55,4.4,-0.55>}
			object {nBlock_squ(0.45,0.7,0.6,Wall) translate -3.175*x}
			object {nBlock_pyr(0.45,0.6,0.35,0.5,0.05,Wall) translate <-3.175,0.7,0>}
			object {nBlock_squ(0.35+2*s[Wall],2*s[Wall],0.5+2*s[Wall],Wall) translate <-3.175,0.75,0>}
			object {nBlock_squ(0.35+2*s[Wall],2*s[Wall],0.5+2*s[Wall],Wall) translate <-3.175,4,0>}
			object {nBlock_squ(0.45,0.05,0.9,Wall) translate <-3.175,4.3,0>}
			object {nBlock_squ(0.55,0.05,1,Wall) translate <-3.175,4.35,0>}
			object {nBlock_squ(0.65,0.1,1.1,Wall) translate <-3.175,4.4,0>}

			object {sBlock_squ(0.16,4.5,1.64,0.2,0.2,0.5,Wall) translate 3.78*x}
			object {sBlock_squ(0.35,4.5,1.1,0.3,0.3,0.5,Wall) translate 3.525*x}
			object {sBlock_squ(0.35,4.5,0.5,0.3,0.3,0.5,Wall) translate 3.175*x}
			object {nBlock_squ(0.2,0.7,0.2,Wall) translate <3.82,0,-0.92>}
			object {nBlock_pyr(0.2,0.2,0.1,0.1,0.05,Wall) translate <3.82,0.7,-0.92>}
			object {sBlock_cyl(0.08,4.5,0.5,Column) translate <3.82,0,-0.92>}
			object {nBlock_squ(0.4,0.7,0.4,Wall) translate <3.55,0,-0.55>}
			object {nBlock_pyr(0.4,0.4,0.3,0.3,0.05,Wall) translate <3.55,0.7,-0.55>}
			object {sBlock_cyl(0.15,4.5,0.5,Column) translate <3.55,0,-0.55>}
			object {nBlock_squ(0.4,0.7,0.4,Wall) translate <3.2,0,-0.25>}
			object {nBlock_pyr(0.4,0.4,0.3,0.3,0.05,Wall) translate <3.2,0.7,-0.25>}
			object {sBlock_cyl(0.15,4.5,0.5,Column) translate <3.2,0,-0.25>}
			object {nBlock_tor(0.08,s[Wall],360,Column) translate <3.82,0.75,-0.92>}
			object {nBlock_tor(0.08,s[Wall],360,Column) translate <3.82,4,-0.92>}
			object {nBlock_tor(0.15,s[Wall],360,Column) translate <3.55,0.75,-0.55>}
			object {nBlock_tor(0.15,s[Wall],360,Column) translate <3.55,4,-0.55>}
			object {nBlock_tor(0.15,s[Wall],360,Column) translate <3.2,0.75,-0.25>}
			object {nBlock_tor(0.15,s[Wall],360,Column) translate <3.2,4,-0.25>}
			object {nBlock_squ(0.26,0.7,1.74,Wall) translate 3.78*x}
			object {nBlock_pyr(0.26,1.74,0.16,1.64,0.05,Wall) translate <3.78,0.7,0>}
			object {nBlock_squ(0.16+2*s[Wall],2*s[Wall],1.64+2*s[Wall],Wall) translate <3.78,0.75,0>}
			object {nBlock_squ(0.16+2*s[Wall],2*s[Wall],1.64+2*s[Wall],Wall) translate <3.78,4,0>}
			object {nBlock_squ(0.5,0.05,2.1,Wall) translate <3.85,4.3,0>}
			object {nBlock_squ(0.6,0.05,2.2,Wall) translate <3.85,4.35,0>}
			object {nBlock_squ(0.7,0.1,2.3,Wall) translate <3.85,4.4,0>}
			object {nBlock_squ(0.45,0.7,1.2,Wall) translate 3.525*x}
			object {nBlock_pyr(0.45,1.2,0.35,1.1,0.05,Wall) translate <3.525,0.7,0>}
			object {nBlock_squ(0.35+2*s[Wall],2*s[Wall],1.1+2*s[Wall],Wall) translate <3.525,0.75,0>}
			object {nBlock_squ(0.35+2*s[Wall],2*s[Wall],1.1+2*s[Wall],Wall) translate <3.525,4,0>}
			object {nBlock_squ(0.5,0.05,0.4,Wall) translate <3.55,4.3,-0.55>}
			object {nBlock_squ(0.6,0.05,0.5,Wall) translate <3.55,4.35,-0.55>}
			object {nBlock_squ(0.7,0.1,0.6,Wall) translate <3.55,4.4,-0.55>}
			object {nBlock_squ(0.45,0.7,0.6,Wall) translate 3.175*x}
			object {nBlock_pyr(0.45,0.6,0.35,0.5,0.05,Wall) translate <3.175,0.7,0>}
			object {nBlock_squ(0.35+2*s[Wall],2*s[Wall],0.5+2*s[Wall],Wall) translate <3.175,0.75,0>}
			object {nBlock_squ(0.35+2*s[Wall],2*s[Wall],0.5+2*s[Wall],Wall) translate <3.175,4,0>}
			object {nBlock_squ(0.45,0.05,0.9,Wall) translate <3.175,4.3,0>}
			object {nBlock_squ(0.55,0.05,1,Wall) translate <3.175,4.35,0>}
			object {nBlock_squ(0.65,0.1,1.1,Wall) translate <3.175,4.4,0>}

			translate 1.1*x
		}
		
		//- Arcs
		union {
			object {sBlock_rin(2.1,1.7,2,180,0.5,Wall) rotate -90*x}
			object {sBlock_rin(1.7,1.6,1.8,180,0.5,Wall) rotate -90*x}
			object {sBlock_tor(1.65,0.05,180,0.5,Wall) rotate -90*x translate -0.95*z}
			object {sBlock_rin(1.6,1.35,1.4,180,0.5,Wall) rotate -90*x}
			object {sBlock_rin(1.35,1.25,1.2,180,0.5,Wall) rotate -90*x}
			object {sBlock_tor(1.3,0.05,180,0.5,Wall) rotate -90*x translate -0.65*z}
			object {sBlock_rin(1.25,1,0.8,180,0.5,Wall) rotate -90*x}
			object {sBlock_rin(1,0.9,0.6,180,0.5,Wall) rotate -90*x}
			object {sBlock_tor(0.95,0.05,180,0.5,Wall) rotate -90*x translate -0.35*z}
			translate <-1,4.5,0>
		}
		union {
			object {sBlock_rin(2.1,1.7,2,180,0.5,Wall) rotate -90*x}
			object {sBlock_rin(1.7,1.6,1.8,180,0.5,Wall) rotate -90*x}
			object {sBlock_tor(1.65,0.05,180,0.5,Wall) rotate -90*x translate -0.95*z}
			object {sBlock_rin(1.6,1.35,1.4,180,0.5,Wall) rotate -90*x}
			object {sBlock_rin(1.35,1.25,1.2,180,0.5,Wall) rotate -90*x}
			object {sBlock_tor(1.3,0.05,180,0.5,Wall) rotate -90*x translate -0.65*z}
			object {nBlock_squ(3,1.5,0.6,Wall)}
			translate <3.2,4.5,0>
		}
		union {
			object {nBlock_rin(2.4,2.35,0.3,180,Column) rotate -90*x translate -1.2*z}
			object {nBlock_rin(2.35,2.3,0.25,180,Column) rotate -90*x translate -1.175*z}
			object {nBlock_rin(2.3,2.25,0.2,180,Column) rotate -90*x translate -1.15*z}
			object {nBlock_rin(2.25,2.2,0.15,180,Column) rotate -90*x translate -1.125*z}
			object {nBlock_rin(2.2,2.15,0.1,180,Column) rotate -90*x translate -1.1*z}
			object {nBlock_rin(2.15,2.1,0.05,180,Column) rotate -90*x translate -1.075*z}
			object {nBlock_squ(0.05,0.65,0.3,Column) translate <-2.375,-0.65,-1.2>}
			object {nBlock_squ(0.05,0.65,0.3,Column) translate <2.375,-0.65,-1.2>}
			object {nBlock_squ(0.05,0.65,0.25,Column) translate <-2.325,-0.65,-1.175>}
			object {nBlock_squ(0.05,0.65,0.25,Column) translate <2.325,-0.65,-1.175>}
			object {nBlock_squ(0.05,0.65,0.2,Column) translate <-2.275,-0.65,-1.15>}
			object {nBlock_squ(0.05,0.65,0.2,Column) translate <2.275,-0.65,-1.15>}
			object {nBlock_squ(0.05,0.65,0.15,Column) translate <-2.225,-0.65,-1.125>}
			object {nBlock_squ(0.05,0.65,0.15,Column) translate <2.225,-0.65,-1.125>}
			object {nBlock_squ(0.05,0.65,0.1,Column) translate <-2.175,-0.65,-1.1>}
			object {nBlock_squ(0.05,0.65,0.1,Column) translate <2.175,-0.65,-1.1>}
			object {nBlock_squ(0.05,0.65,0.05,Column) translate <-2.125,-0.65,-1.075>}
			object {nBlock_squ(0.05,0.65,0.05,Column) translate <2.125,-0.65,-1.075>}
			difference {
				object {sBlock_squ(4.6,2.1,0.25,0.8,0.8,0.4,Wall) translate 0.25*y}
				cylinder {<0,0,-1> <0,0,1> 2.4}
				translate -1.175*z
				texture {T_Block(Wall,NoMortar)}
			}
			translate <3.65,5.65,0>
		}


		//--- Mid lower part
      #if (sx=1)
			object {sBlock_squ(12.34,6,2,0.8,0.8,0.4,Wall) translate <0.1,9.2,0>}
		#else
			difference {
				object {sBlock_squ(12.2,6,2,0.8,0.8,0.4,Wall) translate 0.1*x}
				box {<6,-dd,-2> <1.6,1.6,2>}
				object {gothic_arch(2.2,1.1,3) translate <3.8,1.6-dd,0>}
				box {<0.6,-dd,-2> <-3.8,1.6,2>}
				object {gothic_arch(2.2,1.1,3) translate <-1.6,1.6-dd,0>}
				translate 9.2*y
				texture {T_Block(Wall,NoMortar)}
			}
			#local coor = array[4] {5.85, 1.75, 0.45, -3.65};
			#local i=0;
			#while (i<4)
				union {
					object {sBlock_squ2(0.5,1.6,2,0.4,Wall) translate 9.2*y}
					object {nBlock_squ(1,0.05,2.3,Wall) translate 10.75*y}
					object {nBlock_squ(0.9,0.05,2.2,Wall) translate 10.7*y}
					object {nBlock_squ(0.8,0.05,2.1,Wall) translate 10.65*y}
					translate coor[i]*x
				}
				#local i=i+1;
			#end
			object {gothic_rin(2.2,2.2,0.4,1.1,2,0,0.8,Wall) translate <-1.6,10.8,0>}
			object {gothic_tor(2.2,1.74,0.08,1.1,0,0.8,Wall) translate <-1.6,10.8,-0.92>}
			object {gothic_rin(2.2,2.2,0.4,1.1,2,0,0.8,Wall) translate <3.8,10.8,0>}
			object {gothic_tor(2.2,1.74,0.08,1.1,0,0.8,Wall) translate <3.8,10.8,-0.92>}
			object {sBlock_squ(10,0.3,0.4,0.8,0.8,0.3,Wall) translate <1.1,9.2,-0.5>}
			object {sBlock_squ(10,3.6,0.4,0.8,0.8,0.4,Wall) translate <1.1,9.2,-0.2>}
		#end


		//--- Mid upper part
		object {sBlock_squ2(0.1,12,0.5,0.8,Wall) translate -6*y rotate -90*z translate <0,15.15,-1>}
		object {sBlock_squ2(0.1,12,0.4,0.8,Wall) translate -6*y rotate -90*z translate <0,15.05,-1>}
		object {sBlock_squ2(0.05,12,0.3,0.8,Wall) translate -6*y rotate -90*z translate <0,15,-1>}
		object {nBlock_squ(1.5,0.1,1,Wall) translate <1.1,15.1,-1.25>}
		object {nBlock_squ(1.4,0.1,0.9,Wall) translate <1.1,15,-1.25>}
		object {nBlock_squ(1.3,0.05,0.8,Wall) translate <1.1,14.95,-1.25>}
		
		#local coor = array[8] {-3.5, -2.5, -1.5, -0.5, 2.25, 3.25, 4.25, 5.25};
		#local i=0;
		#while (i<8)
			union {
				object {nBlock_squ(0.2,0.1,0.2,Wall) translate <0,-0.1,-0.1>}
				object {nBlock_squ(0.2,0.1,0.15,Wall) translate <0,-0.2,-0.075>}
				object {nBlock_squ(0.2,0.1,0.1,Wall) translate <0,-0.3,-0.05>}
				object {nBlock_squ(0.2,0.1,0.05,Wall) translate <0,-0.4,-0.025>}
				translate <coor[i],15,-1>
			}
			#local i=i+1;
		#end
		
		union {
			#if (sx=1)
				object {sBlock_squ(1.7,4.4,2,0.8,0.8,0.4,Wall) translate -4.15*x}
				object {sBlock_squ(1.2,4.4,2,0.8,0.8,0.4,Wall) translate 0.1*x}
				object {sBlock_squ(1.9,4.4,2,0.8,0.8,0.4,Wall) translate 5.25*x}
				object {nBlock_squ(1.4,0.1,0.25,Wall) translate <-4.3,4.3,-1.125>}
				object {nBlock_squ(1.4,0.1,0.2,Wall) translate <-4.3,4.2,-1.1>}
				object {nBlock_squ(1.4,0.1,0.15,Wall) translate <-4.3,4.1,-1.075>}
				object {nBlock_squ(1.4,0.1,0.1,Wall) translate <-4.3,4,-1.05>}
				object {nBlock_squ(1.4,0.1,0.05,Wall) translate <-4.3,3.9,-1.025>}
				object {nBlock_squ(0.9,0.1,0.25,Wall) translate <0.25,4.3,-1.125>}
				object {nBlock_squ(0.9,0.1,0.2,Wall) translate <0.25,4.2,-1.1>}
				object {nBlock_squ(0.9,0.1,0.15,Wall) translate <0.25,4.1,-1.075>}
				object {nBlock_squ(0.9,0.1,0.1,Wall) translate <0.25,4,-1.05>}
				object {nBlock_squ(0.9,0.1,0.05,Wall) translate <0.25,3.9,-1.025>}
				object {nBlock_squ(1.4,0.1,0.25,Wall) translate <5.3,4.3,-1.125>}
				object {nBlock_squ(1.4,0.1,0.2,Wall) translate <5.3,4.2,-1.1>}
				object {nBlock_squ(1.4,0.1,0.15,Wall) translate <5.3,4.1,-1.075>}
				object {nBlock_squ(1.4,0.1,0.1,Wall) translate <5.3,4,-1.05>}
				object {nBlock_squ(1.4,0.1,0.05,Wall) translate <5.3,3.9,-1.025>}
				#local coor = array[2] {2.9, -1.9};
				difference {
					object {sBlock_squ(12,2.8,2.5,0.8,0.8,0.4,Wall)}
					object {gothic_arch(2.1,1.1,3) translate <coor[0],-dd,0>}
					object {gothic_arch(2.1,1.1,3) translate <coor[1],-dd,0>}
					texture {T_Block(Wall,NoMortar)}
					translate 4.4*y
				}
				#local i=0;
				#while (i<2)
					union {
						object {sBlock_squ(2.8,0.4,0.4,0.8,0.8,0.4,Wall) translate -0.8*z}
						object {nBlock_squ(0.9,0.4,1.2,Wall) translate <0,0.2,0.4>}
						object {gothic_rin(2.1,0.7,0.25,1.1,1.2,0,0.8,Wall) translate <0,4.4,0.4>}
						object {gothic_rin(2.1,1.1,0.4,1.1,1.6,0,0.8,Wall) translate <0,4.4,0.2>}
						object {gothic_rin(2.1,1.7,0.6,1.1,2,0,0.8,Wall) translate 4.4*y}
						object {gothic_rin(2.1,2.1,0.4,1.1,2.5,0,0.8,Wall) translate 4.4*y}
						#local j=-1;
						#while (j<2)
							object {nBlock_squ(0.4,0.2,0.4,Column) translate <1.2*j,0.4,-0.8>}
							object {sBlock_cyl(0.16,4,0.5,Column) translate <1.25*j,0.4,-0.75>}
							object {nBlock_tor(0.16,0.05,360,Column) translate <1.25*j,0.64,-0.75>}  
							object {nBlock_tor(0.16,0.02,360,Column) translate <1.25*j,0.72,-0.75>}  
							object {nBlock_tor(0.16,0.02,360,Column) translate <1.25*j,3.96,-0.75>}  
							object {nBlock_squ(1.6,0.1,0.7,Column) translate <1.7*j,4.3,-0.8>}
							object {nBlock_squ(1.5,0.05,0.6,Column) translate <1.7*j,4.25,-0.8>}
							object {nBlock_squ(1.4,0.05,0.5,Column) translate <1.7*j,4.2,-0.8>}
							object {nBlock_squ(1.6,0.1,0.7,Column) translate <1.3*j,4.3,-0.4>}
							object {nBlock_squ(1.5,0.05,0.6,Column) translate <1.3*j,4.25,-0.4>}
							object {nBlock_squ(1.4,0.05,0.5,Column) translate <1.3*j,4.2,-0.4>}
							object {sBlock_squ2(0.9,4.4,0.4,0.4,Wall) translate <1.15*j,0,-0.4>}
							object {sBlock_squ2(1.15,4.4,1.2,0.4,Wall) translate <1.025*j,0,0.4>}
							#local j=j+2;
						#end
						translate coor[i]*x
					}
					#local i=i+1;
				#end
			#else
				object {sBlock_squ(2,4.4,2,0.8,0.8,0.4,Wall) translate -4*x}
				object {sBlock_squ(1,4.4,2,0.8,0.8,0.4,Wall) translate 5.7*x}
				object {nBlock_squ(0.8,0.1,0.25,Wall) translate <5.6,4.3,-1.125>}
				object {nBlock_squ(0.8,0.1,0.2,Wall) translate <5.6,4.2,-1.1>}
				object {nBlock_squ(0.8,0.1,0.15,Wall) translate <5.6,4.1,-1.075>}
				object {nBlock_squ(0.8,0.1,0.1,Wall) translate <5.6,4,-1.05>}
				object {nBlock_squ(0.8,0.1,0.05,Wall) translate <5.6,3.9,-1.025>}
				object {nBlock_squ(1.9,0.2,0.25,Wall) translate <-4.05,4.2,-1.125>}
				object {nBlock_squ(1.6,0.2,0.2,Wall) translate <-4.2,4,-1.1>}
				object {nBlock_squ(1.3,0.2,0.15,Wall) translate <-4.35,3.8,-1.075>}
				object {nBlock_squ(1,0.2,0.1,Wall) translate <-4.5,3.6,-1.05>}
				object {nBlock_squ(0.7,0.2,0.05,Wall) translate <-4.65,3.4,-1.025>}
				#local coor = array[2] {3.3, -1.1};
				difference {
					object {sBlock_squ(12,2.8,2.5,0.8,0.8,0.4,Wall)}
					object {gothic_arch(2.3,1.15,3) translate <coor[0],-dd,0>}
					object {gothic_arch(2.3,1.15,3) translate <coor[1],-dd,0>}
					texture {T_Block(Wall,NoMortar)}
					translate 4.4*y
				}
				#local i=0;
				#while (i<2)
					union {
						object {gothic_rin(2.3,1.1,0.5,1.15,1,0,0.8,Wall) translate <0,4.4,0.5>}
						object {gothic_rin(2.3,1.25,0.15,1.15,1.25,0,0.8,Wall) translate <0,4.4,0.375>}
						object {gothic_rin(2.3,1.45,0.2,1.15,1.4,0,0.8,Wall) translate <0,4.4,0.3>}
						object {gothic_rin(2.3,1.6,0.15,1.15,1.7,0,0.8,Wall) translate <0,4.4,0.15>}
						object {gothic_rin(2.3,2,0.4,1.15,1.85,0,0.8,Wall) translate <0,4.4,0.075>}
						object {gothic_rin(2.3,2.3,0.3,1.15,2.5,0,0.8,Wall) translate 4.4*y}
						object {gothic_tor(2.3,1.535,0.07,1.15,0,0.8,Wall) translate <0,4.4,-0.765>}
						object {gothic_tor(2.3,1.185,0.07,1.15,0,0.8,Wall) translate <0,4.4,-0.215>}

						#local j=-1;
						#while (j<2)
							object {nBlock_squ(0.4,0.2,0.4,Column) translate <1.7*j,0,-0.6>}
							object {sBlock_cyl(0.18,4.4,0.5,Column) translate <1.7*j,0,-0.6>}
							object {nBlock_tor(0.18,0.05,360,Column) translate <1.7*j,0.24,-0.6>}  
							object {nBlock_tor(0.18,0.02,360,Column) translate <1.7*j,0.32,-0.6>}  
							object {nBlock_tor(0.18,0.01,360,Column) translate <1.7*j,3.96,-0.6>}  
							object {nBlock_pyr(0.6,0.6,0.4,0.4,0.2,Column) scale <1,-1,1> translate <1.7*j,4.4,-0.6>}
							object {nBlock_squ(0.4,0.2,0.4,Column) translate <1.3*j,0,-0.2>}
							object {sBlock_cyl(0.16,4.4,0.5,Column) translate <1.35*j,0,-0.15>}
							object {nBlock_tor(0.16,0.05,360,Column) translate <1.35*j,0.24,-0.15>}  
							object {nBlock_tor(0.16,0.02,360,Column) translate <1.35*j,0.32,-0.15>}  
							object {nBlock_tor(0.16,0.01,360,Column) translate <1.35*j,3.96,-0.15>}  
							object {nBlock_pyr(0.6,0.6,0.4,0.4,0.2,Column) scale <1,-1,1> translate <1.35*j,4.4,-0.15>}
							object {nBlock_pyr(0.6,0.6,0.4,0.4,0.2,Column) scale <1,-1,1> translate <2.1*j,4.4,-0.8>}
							object {sBlock_squ2(0.4,4.4,1.4,0.4,Wall) translate <1.7*j,0,0.3>}
							object {sBlock_squ2(0.9,4.4,1,0.4,Wall) translate <1.05*j,0,0.5>}
							#local j=j+2;
						#end
						translate coor[i]*x
					}
					#local i=i+1;
				#end
			#end
			
			object {sBlock_squ2(1,6,0.5,0.4,Wall) translate <1.1,0,-1>}
			object {sBlock_cyl(0.2,9.56,0.5,Column) translate <1.1,0,-1.47>}
			object {nBlock_squ(0.6,0.3,0.6,Column) translate <1.1,0,-1.47>}
			object {nBlock_pyr(0.6,0.6,0.45,0.45,0.2,Column) translate <1.1,0.3,-1.47>}
			object {nBlock_tor(0.2,0.04,360,Column) translate <1.1,0.53,-1.47>}
			object {nBlock_squ(0.7,0.05,0.7,Column) translate <1.1,9.51,-1.53>}
			object {nBlock_squ(0.65,0.08,0.65,Column) translate <1.1,9.43,-1.53>}
			object {nBlock_squ(0.6,0.05,0.6,Column) translate <1.1,9.38,-1.53>}
			object {nBlock_tor(0.2,0.03,360,Column) translate <1.1,9,-1.5>}
			#local i=-1;
			#while (i<2)
				object {sBlock_cyl(0.12,9.56,0.5,Column) translate <1.1+0.3*i,0,-1.41>}
				object {nBlock_squ(0.44,0.3,0.44,Column) rotate 45*y translate <1.1+0.3*i,0,-1.41>}
				object {nBlock_pyr(0.44,0.44,0.29,0.29,0.2,Column) rotate 45*y translate <1.1+0.3*i,0.3,-1.41>}
				object {nBlock_tor(0.12,0.04,360,Column) rotate 45*y translate <1.1+0.3*i,0.53,-1.41>}
				object {nBlock_squ(0.58,0.05,0.58,Column) rotate 45*y translate <1.1+0.26*i,9.51,-1.47>}
				object {nBlock_squ(0.53,0.08,0.53,Column) rotate 45*y translate <1.1+0.26*i,9.43,-1.47>}
				object {nBlock_squ(0.48,0.05,0.48,Column) rotate 45*y translate <1.1+0.26*i,9.38,-1.47>}
				object {nBlock_tor(0.12,0.03,360,Column) rotate 45*y translate <1.1+0.3*i,9,-1.47>}
				object {sBlock_cyl(0.08,9.46,0.5,Column) translate <1.1+0.42*i,0,-1.23>}
				object {nBlock_squ(0.36,0.3,0.36,Column) translate <1.1+0.42*i,0,-1.23>}
				object {nBlock_pyr(0.36,0.36,0.21,0.21,0.2,Column) translate <1.1+0.42*i,0.3,-1.23>}
				object {nBlock_tor(0.08,0.04,360,Column) translate <1.1+0.42*i,0.53,-1.23>}
				#local i=i+2;
			#end
			
			translate 15.2*y
		}

		
		//--- Upper part
		object {clerestory3_step(6.64,2.2) translate <-2.22,22.4,-1.25>}
		object {clerestory3_step(5.1,1.43) translate <3.65,22.4,-1.25>}
		
		
		//--- Laterals (base of the towers)
		object {sBlock_squ(7.14,9.2,0.4,0.8,0.8,0.4,Wall) rotate 90*y translate <6.07,0,4.57>}
		object {sBlock_squ(12.74,8.54,0.5,0.7,0.3,0.3,Floor) rotate 90*x translate <-0.1,-0.25,0>}
		object {sBlock_squ(12.74,9.2,0.4,0.8,0.8,0.4,Wall) translate <-0.1,0,8.34>}
		object {sBlock_squ(12.74,8.54,0.4,0.8,0.8,0.4,Wall) rotate 90*x translate <-0.1,9.4,0>}

		//--- Leaves
		#if (show_ornaments)
			#local i=0;
			#while (i<2)
				object {leaf_curve2 scale <1.2,1.5,1> translate <0.35,4.2,0> rotate (45+90*i)*y translate <1.1,0,-1>} 
				object {leaf_curve2 scale <0.3,0.8,0.3> translate <0.08,4,0> rotate (45+90*i)*y translate <-2.72,0,-0.92>} 
				object {leaf_curve2 scale <0.5,0.8,0.6> translate <0.15,4,0> rotate (45+90*i)*y translate <-2.45,0,-0.55>} 
				object {leaf_curve2 scale <0.5,0.8,0.6> translate <0.15,4,0> rotate (45+90*i)*y translate <-2.1,0,-0.25>} 
				object {leaf_curve2 scale <0.3,0.8,0.3> translate <0.08,4,0> rotate (45+90*i)*y translate <4.92,0,-0.92>} 
				object {leaf_curve2 scale <0.5,0.8,0.6> translate <0.15,4,0> rotate (45+90*i)*y translate <4.65,0,-0.55>} 
				object {leaf_curve2 scale <0.5,0.8,0.6> translate <0.15,4,0> rotate (45+90*i)*y translate <4.3,0,-0.25>} 
				#local i=i+1;
			#end
			object {leaf_tree translate <0.35,4.3,0> rotate 90*y translate <1.1,0,-1>}
			object {leaf_tree rotate 30*x translate <0.35,4.5,0> rotate 85*y translate <1.1,0,-1>}
			object {leaf_tree rotate -30*x translate <0.35,4.5,0> rotate 95*y translate <1.1,0,-1>}
			object {leaf_rect scale <0.75,0.75,0.9> rotate 180*y translate <-0.08,4,0.2>}
			object {leaf_rect scale <0.75,0.75,0.9> rotate 180*y translate <-0.08,4,-0.2>}
			object {leaf_tree scale 0.75 rotate 180*y translate <-0.11,4.08,0>}
			object {leaf_rect scale <0.75,0.75,0.9> rotate 90*y translate <0.08,4,-0.38>}
			object {leaf_rect scale <0.75,0.75,0.85> rotate 180*y translate <0.27,4,-0.54>}
			object {leaf_rect scale <0.75,0.75,0.85> rotate 90*y translate <0.42,4,-0.68>}
			object {leaf_rect scale <0.75,0.75,0.85> rotate 180*y translate <0.62,4,-0.84>}
			object {leaf_rect scale <0.75,0.75,0.5> translate <-1.92,4,0.15>}
			object {leaf_rect scale <0.75,0.75,0.5> translate <-1.92,4,-0.15>}
			object {leaf_tree scale 0.75 translate <-1.89,4.08,0>}
			object {leaf_rect scale <0.75,0.75,0.9> translate <2.28,4,0.2>}
			object {leaf_rect scale <0.75,0.75,0.9> translate <2.28,4,-0.2>}
			object {leaf_tree scale 0.75 translate <2.31,4.08,0>}
			object {leaf_rect scale <0.75,0.75,0.9> rotate 90*y translate <2.12,4,-0.38>}
			object {leaf_rect scale <0.75,0.75,0.85> translate <1.93,4,-0.54>}
			object {leaf_rect scale <0.75,0.75,0.85> rotate 90*y translate <1.78,4,-0.68>}
			object {leaf_rect scale <0.75,0.75,0.85> translate <1.58,4,-0.84>}
			object {leaf_rect scale <0.75,0.75,0.5> rotate 180*y translate <4.12,4,0.15>}
			object {leaf_rect scale <0.75,0.75,0.5> rotate 180*y translate <4.12,4,-0.15>}
			object {leaf_tree scale 0.75 rotate 180*y translate <4.09,4.08,0>}
			#if (sx=1)
				#local i=0;
				#while (i<4)
					object {leaf_curve2 scale 0.6 translate 0.16*x rotate (45+90*i)*y translate <4.15,19.16,-0.75>}			
					object {leaf_curve2 scale 0.6 translate 0.16*x rotate (45+90*i)*y translate <1.65,19.16,-0.75>}			
					object {leaf_curve2 scale 0.6 translate 0.16*x rotate (45+90*i)*y translate <-0.65,19.16,-0.75>}			
					object {leaf_curve2 scale 0.6 translate 0.16*x rotate (45+90*i)*y translate <-3.15,19.16,-0.75>}			
					#local i=i+1;
				#end
			#else
				#local i=0;
				#while (i<4)
					object {leaf_curve2 scale 0.6 translate 0.18*x rotate (45+90*i)*y translate <1.6,19.16,-0.6>}			
					object {leaf_curve2 scale 0.6 translate 0.16*x rotate (45+90*i)*y translate <1.95,19.16,-0.15>}			
					object {leaf_curve2 scale 0.6 translate 0.18*x rotate (45+90*i)*y translate <5,19.16,-0.6>}			
					object {leaf_curve2 scale 0.6 translate 0.16*x rotate (45+90*i)*y translate <4.65,19.16,-0.15>}			
					object {leaf_curve2 scale 0.6 translate 0.18*x rotate (45+90*i)*y translate <-2.8,19.16,-0.6>}			
					object {leaf_curve2 scale 0.6 translate 0.16*x rotate (45+90*i)*y translate <-2.45,19.16,-0.15>}			
					object {leaf_curve2 scale 0.6 translate 0.18*x rotate (45+90*i)*y translate <0.6,19.16,-0.6>}			
					object {leaf_curve2 scale 0.6 translate 0.16*x rotate (45+90*i)*y translate <0.25,19.16,-0.15>}			
					#local i=i+1;
				#end
			#end
			#local i=0;
			#while (i<2)
				object {leaf_curve2 scale <0.85,1,0.8> translate <0.2,24.2,0> rotate (45+90*i)*y translate <1.1,0,-1.5>} 
				object {leaf_curve2 scale <0.7,1,0.45> translate <0.12,24.2,0> rotate 90*i*y translate <1.4,0,-1.47>} 
				object {leaf_curve2 scale <0.7,1,0.45> translate <0.12,24.2,0> rotate (90+90*i)*y translate <0.8,0,-1.47>} 
				#local i=i+1;
			#end
		#end

		scale <sx,1,1>
	}
#end