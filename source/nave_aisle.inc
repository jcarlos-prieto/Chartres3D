//----- CONSTRUCTION OF NAVE AISLE

#ifndef(aisle_column_oct)
	#include "aisle_column_oct.inc" 
#end
#ifndef(aisle_column_cyl)
	#include "aisle_column_cyl.inc" 
#end
#ifndef(aisle_column_cyl1)
	#include "aisle_column_cyl1.inc" 
#end
#ifndef(aisle_wall_step)
	#include "aisle_wall_step.inc" 
#end
#ifndef(aisle_endwall)
	#include "aisle_endwall.inc" 
#end

#macro nave_aisle()
	union {
		#local i=-1;
		#while (i<2)
			#if (i=-1) #declare q="r"; #else #declare q="l"; #end
			#local j=1;
			#while (j<7)
				object {aisle_column_oct() rotate 90*i*y translate <16.58*i,0,7.18*j>}
				#local j=j+2;
			#end
			#local j=2;
			#while (j<6)
				object {aisle_column_cyl() rotate 90*i*y translate <16.58*i,0,7.18*j>}
				#local j=j+2;
			#end
			object {aisle_column_cyl1(i) rotate 90*i*y translate <16.58*i,0,42.61>}
			#local j=0;
			#while (j<5)
				object {aisle_wall_step(7.18,concat("vNaveAisle_",q,str(j+1,1,0))) rotate 90*i*y translate <16.58*i,0,3.59+7.18*j>}
				#local j=j+1;
			#end
			object {aisle_wall_step(6.71,concat("vNaveAisle_",q,"6")) rotate 90*i*y translate <16.58*i,0,39.255>}
			object {aisle_endwall(1) translate <12.52*i,-1,42.61>}
					
			#local j=0;
			#while (j<6)
				object {arch(3.555,5,0.08,1.2,1,0.25,0.55,0,0,0.15,0.4,0,0,0,Column) translate <12.435*i,9.28,7.18*j>}
				#local j=j+1;
			#end
			object {arch(3.555,5,0.08,1,1,0.25,0.55,0,0,0.15,0.4,0,0,0,Column) translate <12.435*i,9.28,42.61>}
			
			#local j=0;
			#while (j<5)
				union {
					#local k=-1;
					#while (k<2)
						object {march1(4.9,5,1,0.08,0,0.16,0.34,0.05,0.15,0.3,Column) rotate 40*k*y}
						object {march1(5,5,1,0.08,0,0.16,0.34,0.05,0.15,0.3,Column) rotate 140*k*y}
						#local k=k+2;
					#end
					object {Crown(0.4,0.4) translate <0,5,0>}
					object {Vault(<0,5,-3.59>,3.555,0,1.2,0,<0,5,0>,5,40,1,0,5)}
					object {Vault(<0,5,-3.59>,3.555,0,1.2,0,<0,5,0>,4.9,40,1,0,5) scale <-1,1,1>}
					object {Vault2(<0,5,-4.04>,2.89,0,1,0,<0,5,0>,4.9,50,1,0,5) rotate 90*y}
					object {Vault(<0,5,-3.59>,3.555,0,1.2,0,<0,5,0>,5,40,1,0,5) scale <1,1,-1>}
					object {Vault(<0,5,-3.59>,3.555,0,1.2,0,<0,5,0>,4.9,40,1,0,5) scale <-1,1,-1>}
					object {Vault2(<0,5,-4.17>,3.14,0,1.3,0,<0,5,0>,5,50,1,0,5) rotate -90*y}
					translate <-12.435,9.28,3.59+7.18*j>
					scale <i,1,1>
				}
				#local j=j+1;
			#end
			union {
				#local k=-1;
				#while (k<2)
					object {march1(4.75,5,1,0.08,0,0.16,0.34,0.05,0.15,0.3,Column) rotate 38*k*y}
					object {march1(4.85,5,1,0.08,0,0.16,0.34,0.05,0.15,0.3,Column) rotate 140*k*y}
					#local k=k+2;
				#end
				object {Crown(0.4,0.4) translate <0,5,0>}
				object {Vault(<0,5,-3.4>,3.555,0,1.2,0,<0,5,0>,4.85,40,1,0,5)}
				object {Vault(<0,5,-3.4>,3.555,0,1.2,0,<0,5,0>,4.75,38,1,0,5) scale <-1,1,1>}
				object {Vault2(<0,5,-4.04>,2.655,0,1,0,<0,5,0>,4.75,52,1,0,5) rotate 90*y}
				object {Vault(<0,5,-3.4>,3.555,0,1,0,<0,5,0>,4.85,40,1,0,5) scale <1,1,-1>}
				object {Vault(<0,5,-3.4>,3.555,0,1,0,<0,5,0>,4.75,38,1,0,5) scale <-1,1,-1>}
				object {Vault2(<0,5,-4.16>,2.905,0,1.3,0,<0,5,0>,4.85,52,1,0,5) rotate -90*y}
				translate <-12.435,9.28,39.255>
				scale <i,1,1>
			}
			#local i=i+2;
		#end
	}
#end