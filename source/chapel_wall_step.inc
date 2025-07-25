//----- ONE PIECE OF WALL FROM THE CHAPEL
//	vit: Vitress name

#ifndef(aisle_column_cyl4)
	#include "aisle_column_cyl4.inc" 
#end

#macro chapel_wall_step(vit)
	#local n=1.33;
	#local L=3.28;		// Total length
	#local L0=2.73;	// Length of one window
	#local h1=8.7;

	union {

		//--- Lower wall
		object {sBlock_squ(L,0.3,1.2,0.8,0.8,0.3,Wall) translate 0.5*z}		
		object {nBlock_pyr(L,1.2,L-0.2,1,0.1,Wall) translate <0,0.3,0.5>}
		object {sBlock_squ(L-0.2,3.2,1,0.8,0.8,0.4,Wall) translate <0,0.2,0.5>}		
		object {sBlock_squ2(0.08,L,0.32,0.8,Wall) rotate 90*z translate <L/2,3.32,0>}		
		object {sBlock_squ2(0.08,L,0.16,0.8,Wall) rotate 90*z translate <L/2,3.24,0>}					
		object {sBlock_squ(L0,1.2,0.46,0.8,0.8,0.4,Wall) translate 0.23*z rotate 9.6*x translate 3.4*y}
		object {sBlock_squ(L0,0.1,0.32,0.8,0.8,0.4,Wall) translate <0,4.58,0.36>}
		
		//--- Window borders
		object {sBlock_ir2(0.45,0.3,0.52,0.32,h1,-1,1,0.8,Wall) translate <L0/2,3.4,0.52>}
		object {sBlock_ir2(0.45,0.3,0.52,0.32,h1,1,1,0.8,Wall) translate <-L0/2,3.4,0.52>}
		object {gothic_ir3(L0/2,L0/2,0.45,0.3,0.52,0.32,n,0,0.8,Wall) translate <0,h1+3.4,0.52>}
		
		//--- Main wall
		difference {
			object {sBlock_squ(L,h1+2,0.52,0.8,0.8,0.4,Wall) translate 0.26*z}
			union {
				object {gothic_arch(L0/2,n,2) translate <0,h1-dd,-dd>}
				box {<-L0/2,0,-1> <L0/2,h1,1>}
				texture {T_Block(Wall,NoMortar)}
			}
			translate 3.4*y
		}
		
		//--- Upper curvature of the column surrounding the window
		object {gothic_tor(L/2-0.4,L/2-0.4,0.1,n,0,0.8,Wall) translate <0,h1+3.4,-0.09>}
		
		//--- Lateral columns
		object {aisle_column_cyl4(h1+3.4) translate <-L/2+0.4,0,-0.09>}
		object {aisle_column_cyl4(h1+3.4) translate <L/2-0.4,0,-0.09>}
		
		//--- Vitress
		#if (show_vitress)
			object {Vitress(L0-0.9,h1+0.2,vit) translate <0,4.68,0.36>}
		#end

	}
#end
