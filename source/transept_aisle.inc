//----- CONSTRUCTION OF TRANSEPT AISLE

#ifndef(aisle_column_cor)
	#include "aisle_column_cor.inc" 
#end
#ifndef(aisle_column_cyl)
	#include "aisle_column_cyl.inc" 
#end
#ifndef(aisle_column_oct1)
	#include "aisle_column_oct1.inc" 
#end
#ifndef(aisle_wall_step)
	#include "aisle_wall_step.inc" 
#end

#macro transept_aisle()
	union {
		#local i=-1;
		#while (i<2)
			#if (i=-1) #declare q="l"; #else #declare q="r"; #end
			object {aisle_column_cor(-i,1,0) translate <16.58*i,0,-14.36>}
			object {aisle_column_cor(-i,-1,0) translate <24.87*i,0,14.36>}
			object {aisle_wall_step(8.29,concat("vTranseptAisle_",q,"b1")) rotate 180*y translate <20.725*i,0,-14.36>}
			object {aisle_wall_step(8.29,concat("vTranseptAisle_",q,"b2")) rotate 180*y translate <29.015*i,0,-14.36>}
			object {aisle_wall_step(8.29,concat("vTranseptAisle_",q,"f1")) translate <29.015*i,0,14.36>}
			object {aisle_column_oct1(i) rotate 180*y translate <33.16*i,0,-14.36>}
			object {aisle_column_cyl() rotate 180*y translate <24.87*i,0,-14.36>}
			object {aisle_column_oct1(-i) translate <33.16*i,0,14.36>}

			union {
				object {arch(3,5,0.08,1.2,1,0.25,0.55,0,0,0.15,0.4,0,0,0,Column) rotate 90*y translate <16.58*i,0,-10.77>}
				object {arch(3,5,0.08,1.2,1,0.25,0.55,0,0,0.15,0.4,0,0,0,Column) rotate 90*y translate <24.87*i,0,-10.77>}
				object {arch(3.165,5,0.08,1.2,1,0.25,0.55,0,0,0.15,0.4,0,0,0,Column) rotate 90*y translate <16.58*i,0,10.905>}
				object {arch(3,5,0.08,1.2,1,0.25,0.55,0,0,0.15,0.4,0,0,0,Column) rotate 90*y translate <24.87*i,0,10.77>}
				union {
					object {Crown(0.4,0.4) translate 5*y}
					object {march1(5,5,1,0.08,0,0.16,0.34,0.05,0.15,0.3,Column) rotate -40*y}
					object {march1(4.9,5,1,0.08,0,0.16,0.34,0.05,0.15,0.3,Column) rotate -137.1*y}
					object {march1(4.4,5,1,0.08,0,0.16,0.34,0.05,0.15,0.3,Column) rotate 140*y}
					object {march1(4.9,5,1,0.08,0,0.16,0.34,0.05,0.15,0.3,Column) rotate 37.5*y}
					object {Vault(<0,5,-3.59>,3.555,0,1.3,0,<0,5,0>,4.9,42.5,1,0,5)}
					object {Vault(<0,5,-3.59>,3.555,0,1.3,0,<0,5,0>,5,40,1,0,5) scale <-1,1,1>}
					object {Vault(<0,5,-4.145>,3,0,1.2,0,<0,5,0>,5,50,1,0,5) rotate 90*y}
					object {Vault(<0,5,-4.145>,3,0,1.2,0,<0,5,0>,4.9,52.5,1,0,5) scale <-1,1,1> rotate 90*y}
					object {Vault(<0.34,5,-3.59>,3.355,0,1.3,0,<0,5,0>,4.9,37.5,1,0,5) rotate 180*y}
					object {Vault(<-0.34,5,-3.59>,3.355,0,1.3,0,<0,5,0>,4.4,40,1,0,5) scale <-1,1,1> rotate 180*y}
					object {Vault(<-0.34,5,-4.145>,2.8,0,1.3,0,<0,5,0>,4.4,50,1,0,5) rotate -90*y}
					object {Vault(<0.34,5,-4.145>,2.8,0,1.3,0,<0,5,0>,4.9,47.5,1,0,5) scale <-1,1,1> rotate -90*y}
					translate <-12.435,0,-10.77>
					scale <i,1,1>
				}
				union {
					object {Crown(0.4,0.4) translate 5*y}
					object {march1(4.9,5,1,0.08,0,0.16,0.34,0.05,0.15,0.3,Column) rotate 42*y}
					object {march1(5,5,1,0.08,0,0.16,0.34,0.05,0.15,0.3,Column) rotate 138.5*y}
					object {march1(4.5,5,1,0.08,0,0.16,0.34,0.05,0.15,0.3,Column) rotate -142*y}
					object {march1(4.8,5,1,0.08,0,0.16,0.34,0.05,0.15,0.3,Column) rotate -38.5*y}
					object {Vault(<-0.175,5,-3.59>,3.355,0,1.3,0,<0,5,0>,4.5,38,1,0,5)}
					object {Vault(<0.175,5,-3.59>,3.355,0,1.3,0,<0,5,0>,4.8,38.5,1,0,5) scale <-1,1,1>}
					object {Vault(<-0.15,5,-3.98>,3.165,0,1.2,0,<0,5,0>,4.8,51.5,1,0,5) rotate 90*y}
					object {Vault(<0.15,5,-3.98>,3.165,0,1.2,0,<0,5,0>,4.9,48,1,0,5) scale <-1,1,1> rotate 90*y}
					object {Vault(<0,5,-3.59>,3.72,0,1.2,0,<0,5,0>,4.9,42,1,0,5) rotate 180*y}
					object {Vault(<0,5,-3.59>,3.72,0,1.2,0,<0,5,0>,5,41,1,0,5) scale <-1,1,1> rotate 180*y}
					object {Vault(<0.34,5,-4.31>,2.8,0,1.3,0,<0,5,0>,5,49,1,0,5) rotate -90*y}
					object {Vault(<-0.34,5,-4.31>,2.8,0,1.3,0,<0,5,0>,4.5,52,1,0,5) scale <-1,1,1> rotate -90*y}
					translate <-12.6,0,10.77>
					scale <i,1,1>
				}
				union {
					object {Crown(0.4,0.4) translate 5*y}
					object {march1(4.92,5,1,0.08,0,0.16,0.34,0.05,0.15,0.3,Column) rotate -40.5*y}
					object {march1(5,5,1,0.08,0,0.16,0.34,0.05,0.15,0.3,Column) rotate -139.5*y}
					object {march1(4.85,5,1,0.08,0,0.16,0.34,0.05,0.15,0.3,Column) rotate 142*y}
					object {march1(4.9,5,1,0.08,0,0.16,0.34,0.05,0.15,0.3,Column) rotate 37.5*y}
					object {Vault(<0,5,-3.5>,3.445,0,1,0,<0,5,0>,5,40.5,1,0,5)}
					object {Vault(<0,5,-3.5>,3.445,0,1,0,<0,5,0>,4.92,40.5,1,0,5) scale <-1,1,1>}
					object {Vault(<0,5,-4.145>,3,0,1.2,0,<0,5,0>,4.92,49.5,1,0,5) rotate 90*y}
					object {Vault(<0,5,-4.145>,3,0,1.2,0,<0,5,0>,4.9,52.5,1,0,5) scale <-1,1,1> rotate 90*y}
					object {Vault(<0,5,-3.59>,3.695,0,1.3,0,<0,5,0>,4.9,37.5,1,0,5) rotate 180*y}
					object {Vault(<0,5,-3.59>,3.695,0,1.3,0,<0,5,0>,4.85,38,1,0,5) scale <-1,1,1> rotate 180*y}
					object {Vault(<0,5,-4.145>,3,0,1.2,0,<0,5,0>,4.85,52,1,0,5) rotate -90*y}
					object {Vault(<0,5,-4.145>,3,0,1.2,0,<0,5,0>,5,49.5,1,0,5) scale <-1,1,1> rotate -90*y}
					translate <-20.725,0,-10.77>
					scale <i,1,1>
				}
				union {
					object {Crown(0.4,0.4) translate 5*y}
					object {march1(5,5,1,0.08,0,0.16,0.34,0.05,0.15,0.3,Column) rotate -37*y}
					object {march1(4.75,5,1,0.08,0,0.16,0.34,0.05,0.15,0.3,Column) rotate -141*y}
					object {march1(4.8,5,1,0.08,0,0.16,0.34,0.05,0.15,0.3,Column) rotate 138*y}
					object {march1(5,5,1,0.08,0,0.16,0.34,0.05,0.15,0.3,Column) rotate 39*y}
					object {Vault(<-0.165,5,-3.59>,3.695,0,1.3,0,<0,5,0>,4.75,39,1,0,5)}
					object {Vault(<0.165,5,-3.59>,3.695,0,1.3,0,<0,5,0>,5,37,1,0,5) scale <-1,1,1>}
					object {Vault(<0,5,-4.31>,3,0,1.2,0,<0,5,0>,5,53,1,0,5) rotate 90*y}
					object {Vault(<0,5,-4.31>,3,0,1.2,0,<0,5,0>,5,51,1,0,5) scale <-1,1,1> rotate 90*y}
					object {Vault(<0,5,-3.59>,3.72,0,1.2,0,<0,5,0>,5,39,1,0,5) rotate 180*y}
					object {Vault(<0,5,-3.59>,3.72,0,1.2,0,<0,5,0>,4.8,42,1,0,5) scale <-1,1,1> rotate 180*y}
					object {Vault(<0.1,5,-4>,3.165,0,1.2,0,<0,5,0>,4.8,48,1,0,5) rotate -90*y}
					object {Vault(<-0.1,5,-4>,3.165,0,1.2,0,<0,5,0>,4.75,51,1,0,5) scale <-1,1,1> rotate -90*y}
					translate <-20.56,0,10.77>
					scale <i,1,1>
				}
				union {
					object {Crown(0.4,0.4) translate 5*y}
					object {march1(5,5,1,0.08,0,0.16,0.34,0.05,0.15,0.3,Column) rotate -40*y}
					object {march1(5,5,1,0.08,0,0.16,0.34,0.05,0.15,0.3,Column) rotate -140*y}
					object {march1(4.9,5,1,0.08,0,0.16,0.34,0.05,0.15,0.3,Column) rotate 142*y}
					object {march1(4.9,5,1,0.08,0,0.16,0.34,0.05,0.15,0.3,Column) rotate 38*y}
					object {Vault2(<0,5,-3.5>,3.445,0,1,0,<0,5,0>,5,40,1,0,5)}
					object {Vault(<0,5,-4.145>,3,0,1.2,0,<0,5,0>,5,50,1,0,5) rotate 90*y}
					object {Vault(<0,5,-4.145>,3,0,1.2,0,<0,5,0>,5,52,1,0,5) scale <-1,1,1> rotate 90*y}
					object {Vault2(<0,5,-3.59>,3.695,0,1.3,0,<0,5,0>,4.9,38,1,0,5) rotate 180*y}
					object {Vault(<0,5,-4.145>,3,0,1.2,0,<0,5,0>,5,52,1,0,5) rotate -90*y}
					object {Vault(<0,5,-4.145>,3,0,1.2,0,<0,5,0>,5,50,1,0,5) scale <-1,1,1> rotate -90*y}
					translate <-29.015,0,-10.77>
					scale <i,1,1>
				}
				union {
					object {Crown(0.4,0.4) translate 5*y}
					object {march1(5,5,1,0.08,0,0.16,0.34,0.05,0.15,0.3,Column) rotate 40*y}
					object {march1(5,5,1,0.08,0,0.16,0.34,0.05,0.15,0.3,Column) rotate 140*y}
					object {march1(4.9,5,1,0.08,0,0.16,0.34,0.05,0.15,0.3,Column) rotate -142*y}
					object {march1(4.9,5,1,0.08,0,0.16,0.34,0.05,0.15,0.3,Column) rotate -38*y}
					object {Vault2(<0,5,-3.5>,3.445,0,1.2,0,<0,5,0>,4.9,38,1,0,5)}
					object {Vault(<0,5,-4.145>,3,0,1.2,0,<0,5,0>,5,50,1,0,5) scale <-1,1,1> rotate -90*y}
					object {Vault(<0,5,-4.145>,3,0,1.2,0,<0,5,0>,5,52,1,0,5) rotate -90*y}
					object {Vault2(<0,5,-3.62>,3.695,0,1,0,<0,5,0>,5,40,1,0,5) rotate 180*y}
					object {Vault(<0,5,-4.145>,3,0,1.2,0,<0,5,0>,5,52,1,0,5) scale <-1,1,1> rotate 90*y}
					object {Vault(<0,5,-4.145>,3,0,1.2,0,<0,5,0>,5,50,1,0,5) rotate 90*y}
					translate <-29.015,0,10.77>
					scale <i,1,1>
				}
				translate 9.28*y
			}
			#local i=i+2;
		#end		
	}
#end