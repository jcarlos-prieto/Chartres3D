//----- CLERESTORY BETWEEN TWO ADJACENT COLUMNS
//		L: Total length
// 	L0: Length of one window
//		vit: Vitress name

#macro clerestory_step(L,L0,vit)

	#local n=1.33;
	#local h=14.75;	
	#local h1=16-L-0.9*L0;

	union {
	
		//--- Lower wall
		object {sBlock_squ(L,1.2,0.32,0.8,0.8,0.4,Wall) translate 0.16*z rotate 9.6*x}
		object {sBlock_squ(L,0.1,0.32,0.8,0.8,0.4,Wall) translate <0,1.18,0.36>}

		//--- Windows borders
		object {sBlock_ir1(0.6,0.3,0.52,0.32,h1,0.4,Wall) translate 0.52*z}
		object {sBlock_ir2(0.45,0.3,0.52,0.32,h1,1,1,0.4,Wall) translate <-L0-0.8,0,0.52>}
		object {sBlock_ir2(0.45,0.3,0.52,0.32,h1,-1,1,0.4,Wall) translate <L0+0.8,0,0.52>}
		#local i=-1;
		#while (i<2)
			object {gothic_ir3((L0/2+0.475),(L0/2+0.475),0.45,0.3,0.52,0.32,n,0,0.8,Wall) translate <(L0/2+0.325)*i,h1,0.52>}
			#local i=i+2;
		#end
		union {
			object {sBlock_ir3(0.45,0.3,0.52,0.32,180,L/2-0.6,0.8,Wall)}		
			object {sBlock_ir3(0.45,0.3,0.52,0.32,180,L/2-0.6,0.8,Wall) rotate 180*z}		
			translate <0,h-L/2+0.42,0.52>
		}
				
		//--- Main wall       
		object {sBlock_squ(L/2-L0-0.8,h1,0.52,0.8,0.8,h1/18,Wall) translate <L/4+L0/2+0.4,0,0.26>}
		object {sBlock_squ(L/2-L0-0.8,h1,0.52,0.8,0.8,h1/18,Wall) translate <-L/4-L0/2-0.4,0,0.26>}
		difference {
			object {sBlock_squ(L,h-h1,0.52,0.8,0.8,(h-h1)/18,Wall) translate <0,h1,0.26>}
			union {
				cylinder {<0,h-L/2+0.42,-1> <0,h-L/2+0.42,1> L/2-0.6}
				object {gothic_arch(L0/2+0.475,n,2) translate <L0/2+0.325,h1-2*dd,-dd>}
				object {gothic_arch(L0/2+0.475,n,2) translate <-L0/2-0.325,h1-2*dd,-dd>}
				texture {T_Block(Wall,NoMortar)}
			}
		}
	
		//--- Upper curvature of the column surrounding the rounded window
		#local i=-1;
		#while (i<2)
			union {
				object {sBlock_cyl(0.08,h-L/2-3.43,0.8,Column) translate <(L/2-0.42)*i,3.85,-0.03>}
				object {nBlock_squ(0.3,0.05,0.4,Column) translate <(L/2-0.42)*i,0.37+h-L/2,-0.03>}
				object {nBlock_squ(0.25,0.05,0.35,Column) translate <(L/2-0.42)*i,0.32+h-L/2,-0.03>}
				object {nBlock_squ(0.2,0.05,0.3,Column) translate <(L/2-0.42)*i,0.27+h-L/2,-0.03>}
				object {nBlock_tor(0.08,0.02,360,Column) translate <(L/2-0.42)*i,0.1+h-L/2,-0.03>}
			}
			#local i=i+2;
		#end
		object {sBlock_tor(L/2-0.42,0.08,180,0.5,Column) rotate -90*x translate <0,h-L/2+0.42,-0.03>}
				
		//--- Rose
		#if (show_ornaments)
			object {Rose4(L/2-0.6) translate <0,(h-L/2+0.42),0.52>}
		#end
		
		//--- Vitress
		#if (show_vitress)
			object {Vitress(L0+0.05,h1+(L0/2+0.5)*sqrt(2*n-1)-1.78,concat(vit,"_r")) translate <L0/2+0.325,1.28,0.36>}
			object {Vitress(L0+0.05,h1+(L0/2+0.5)*sqrt(2*n-1)-1.78,concat(vit,"_l")) translate <-L0/2-0.325,1.28,0.36>}
			object {Vitress(L-1.2,L-1.2,concat(vit,"_u")) translate <0,h-L+1.02,0.36>}
		#end
		
		//--- Leaves
		#if (show_ornaments)
			#local i=0;
			#while (i<2)
				object {leaf_curve2 scale <0.4,0.45,0.4> translate 0.08*x rotate (45+90*i)*y translate <L/2-0.42,0.1+h-L/2,-0.03>}
				object {leaf_curve2 scale <0.4,0.45,0.4> translate 0.12*x rotate (45+90*i)*y translate <-L/2+0.42,0.1+h-L/2,-0.03>}
				#local i=i+1;
			#end
		#end
	}
#end