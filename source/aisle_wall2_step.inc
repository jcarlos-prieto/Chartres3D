//----- ONE PIECE OF WALL FROM THE CHOIR AISLE
//      L: Length of the step
//	vit: Vitress name

#macro aisle_wall2_step(L,vit)
	#local n=1.33;
	#local L0=2.8;	// Length of one window
	#local h1=14.28-(L/2-0.7);
	#local dh=0.5;
	union {
	
		//--- Lower wall
		object {sBlock_squ(L,3.32,1,0.8,0.8,0.4,Wall) translate 0.5*z}		
		object {sBlock_squ2(0.08,L,0.32,0.8,Wall) rotate 90*z translate <L/2,3.24,0>}		
		object {sBlock_squ2(0.08,L,0.16,0.8,Wall) rotate 90*z translate <L/2,3.16,0>}					

		//--- Windows borders
		object {sBlock_squ(L,1.68,0.46,0.8,0.8,0.4,Wall) translate 0.23*z rotate 4.37*x translate 3.32*y}
		object {sBlock_squ(L,0.1,0.44,0.8,0.8,0.4,Wall) translate <0,5,0.38>}

		object {sBlock_ir1(0.48,0.16,0.6,0.44,h1-3.32-dh,0.8,Wall) translate <0,3.32,0.6>}
		object {sBlock_ir2(0.32,0.16,0.6,0.44,h1-3.32-dh,1,1,0.8,Wall) translate <-L0+0.08,3.32,0.6>}
		object {sBlock_ir2(0.32,0.16,0.6,0.44,h1-3.32-dh,-1,1,0.8,Wall) translate <L0-0.08,3.32,0.6>}
		#local i=-1;
		#while (i<2)
			object {gothic_ir3(L0/2,L0/2,0.32,0.16,0.6,0.44,n,0,0.8,Wall) translate <(L0/2-0.08)*i,h1-dh,0.6>}
			#local i=i+2;
		#end
		union {
			object {sBlock_ir3(0.32,0.16,0.6,0.44,180,0.85,0.8,Wall)}		
			object {sBlock_ir3(0.32,0.16,0.6,0.44,180,0.85,0.8,Wall) rotate 180*z}		
			translate <0,h1+2.1-dh,0.6>
		}
		
		//--- Upper wall       
		object {sBlock_squ(L/2-L0+0.08,h1-dh-4,0.6,0.8,0.8,(h1-dh-4)/18,Wall) translate <L/4+L0/2-0.04,4,0.3>}
		object {sBlock_squ(L/2-L0+0.08,h1-dh-4,0.6,0.8,0.8,(h1-dh-4)/18,Wall) translate <-L/4-L0/2+0.04,4,0.3>}
		difference {
			object {sBlock_squ(L,14.7-h1+dh,0.6,0.8,0.8,0.6,Wall) translate <0,h1-dh,0.3>}
			union {
				cylinder {<0,h1+2.1-dh,-1> <0,h1+2.1-dh,1> 0.85}
				object {gothic_arch(L0/2,n,2) translate <L0/2-0.08,h1-dh-dd,-dd>}
				object {gothic_arch(L0/2,n,2) translate <-L0/2+0.08,h1-dh-dd,-dd>}
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
			object {Vitress(L0-0.64,h1-4.1,concat(vit,"_r")) translate <L0/2-0.08,5.1,0.38>}
			object {Vitress(L0-0.64,h1-4.1,concat(vit,"_l")) translate <-L0/2+0.08,5.1,0.38>}
			object {Vitress(1.06,1.06,concat(vit,"_u")) translate <0,h1+1.08,0.38>}
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