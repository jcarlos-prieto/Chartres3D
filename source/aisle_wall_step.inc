//----- ONE PIECE OF WALL FROM THE AISLE
//      L: Length of the step
//	vit: vitress name

#macro aisle_wall_step(L,vit)
	#local n=1.33;
	#local L0=3;	// Length of one window
	#local h1=14.28-(L/2-0.7);
	union {
	
		//--- Lower wall
		object {sBlock_squ(L,3.32,1,0.8,0.8,0.4,Wall) translate 0.5*z}		
		object {sBlock_squ2(0.08,L,0.32,0.8,Wall) rotate 90*z translate <L/2,3.24,0>}		
		object {sBlock_squ2(0.08,L,0.16,0.8,Wall) rotate 90*z translate <L/2,3.16,0>}					
		
		//--- Windows borders
		object {sBlock_squ(L0,1.68,0.46,0.8,0.8,0.4,Wall) translate 0.23*z rotate 4.37*x translate 3.32*y}
		object {sBlock_squ(L0,0.1,0.44,0.8,0.8,0.4,Wall) translate <0,5,0.38>}
		object {sBlock_ir2(0.32,0.16,0.6,0.44,h1-3.32,-1,1,0.8,Wall) translate <L0/2,3.32,0.6>}
		object {sBlock_ir2(0.32,0.16,0.6,0.44,h1-3.32,1,1,0.8,Wall) translate <-L0/2,3.32,0.6>}
		object {gothic_ir3(L0/2,L0/2,0.32,0.16,0.6,0.44,n,0,0.8,Wall) translate <0,h1,0.6>}
		
		//--- Upper wall
		difference {
			object {sBlock_squ(L,11.56,0.4,0.8,0.8,0.4,Wall) translate <0,3.32,0.2>}
			union {
				object {gothic_arch(L0/2,n,2) translate <0,h1-dd,-dd>}
				box {<-L0/2,0,-1> <L0/2,h1,1>}
				texture {T_Block(Wall,NoMortar)}
			}
		}
		
		//--- Upper curvature of the column surrounding the window
		#local i=-1;
		#while (i<2)
			union {
				object {sBlock_cyl(0.12,h1-9.12,0.8,Column)}
				object {nBlock_tor(0.12,0.02,360,Column) translate (h1-9.45)*y}				
				object {nBlock_squ(0.35,0.05,0.35,Column) translate (h1-9.17)*y}				
				object {nBlock_squ(0.3,0.05,0.3,Column) translate (h1-9.22)*y}				
				object {nBlock_squ(0.25,0.05,0.25,Column) translate (h1-9.27)*y}								                        
				translate <(L/2-0.7)*i,9.12,-0.1>
			}
			#local i=i+2;
		#end
		object {sBlock_tor(L/2-0.7,0.12,180,0.8,Column) rotate -90*x translate <0,h1,-0.1>}						

		//--- Vitress
		#if (show_vitress)
			object {Vitress(L0-0.64,h1-3.5,vit) translate <0,5.1,0.38>}
		#end
		
		//--- Leaves
		#if (show_ornaments)
			#local i=0;
			#while (i<2)
				object {leaf_curve2 scale 0.5 translate <0.12,h1-9.45,0> rotate (45+90*i)*y translate <L/2-0.7,9.12,-0.1>}
				object {leaf_curve2 scale 0.5 translate <0.12,h1-9.45,0> rotate (45+90*i)*y translate <-L/2+0.7,9.12,-0.1>}
				#local i=i+1;
			#end
		#end
	}
#end
