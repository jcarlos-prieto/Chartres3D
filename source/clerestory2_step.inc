//----- CLERESTORY BETWEEN TWO ADJACENT COLUMNS OF THE CHOIR
//	L: Total length
//	vit: Vitress name

#macro clerestory2_step(L,vit)
	#local n=1.33;
	#local L0=3.1;	// Length of one window
	#local h1=12.8;

	union {
	
		//--- Lower wall
		object {sBlock_squ(L0,1.2,0.46,0.8,0.8,0.4,Wall) translate 0.23*z rotate 9.6*x}
		object {sBlock_squ(L0,0.1,0.32,0.8,0.8,0.4,Wall) translate <0,1.18,0.36>}
		
		//--- Window borders
		object {sBlock_ir2(0.45,0.3,0.52,0.32,h1,-1,1,0.8,Wall) translate <L0/2,0,0.52>}
		object {sBlock_ir2(0.45,0.3,0.52,0.32,h1,1,1,0.8,Wall) translate <-L0/2,0,0.52>}
		object {gothic_ir3(L0/2,L0/2,0.45,0.3,0.52,0.32,n,0,0.8,Wall) translate <0,h1,0.52>}
		
		//--- Main wall
		difference {
			object {sBlock_squ(L,14.88,0.52,0.8,0.8,0.4,Wall) translate 0.26*z}
			union {
				object {gothic_arch(L0/2,n,2) translate <0,h1-dd,-dd>}
				box {<-L0/2,0,-1> <L0/2,h1,1>}
				texture {T_Block(Wall,NoMortar)}
			}
		}
		
		//--- Upper curvature of the column surrounding the window
		#local i=-1;
		#while (i<2)
			object {sBlock_cyl(0.08,h1-3.85,0.8,Column) translate <(L/2-0.34)*i,3.85,-0.03>}
			object {nBlock_squ(0.3,0.05,0.4,Column) translate <(L/2-0.34)*i,h1-0.05,-0.03>}
			object {nBlock_squ(0.25,0.05,0.35,Column) translate <(L/2-0.34)*i,h1-0.1,-0.03>}
			object {nBlock_squ(0.2,0.05,0.3,Column) translate <(L/2-0.34)*i,h1-0.15,-0.03>}
			object {nBlock_tor(0.08,0.02,360,Column) translate <(L/2-0.34)*i,h1-0.4,-0.03>}			
			#local i=i+2;
		#end
		object {gothic_tor(L/2-0.34,L/2-0.34,0.08,n,0,0.8,Column) translate <0,h1,-0.03>}
		
		//--- Vitress
		#if (show_vitress)
			object {Vitress(L0,h1+0.25,vit) translate <0,1.28,0.36>}
		#end
	}
#end
