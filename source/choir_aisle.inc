//----- DOUBLE AISLE OF THE CHOIR

#ifndef(aisle_column_oct)
	#include "aisle_column_oct.inc" 
#end
#ifndef(aisle_column_cyl)
	#include "aisle_column_cyl.inc" 
#end
#ifndef(aisle_column_wall)
	#include "aisle_column_wall.inc" 
#end
#ifndef(aisle_wall2_step)
	#include "aisle_wall2_step.inc" 
#end
#ifndef(column_oct2)
	#include "column_oct2.inc" 
#end
#ifndef(column_cyl2)
	#include "column_cyl2.inc" 
#end
#ifndef(column_oct1)
	#include "column_oct1.inc" 
#end
#ifndef(column_cyl1)
	#include "column_cyl1.inc" 
#end

#macro choir_aisle()
	union {
		//- Wall
		object {aisle_wall2_step(7.18,concat("vChoirAisle_l1")) rotate -90*y translate <-24.87,0,3.59>}
		object {aisle_wall2_step(7.18,concat("vChoirAisle_l2")) rotate -90*y translate <-24.87,0,10.77>}
		object {aisle_wall2_step(7.38,concat("vChoirAisle_l3")) rotate -90*y translate <-24.87,0,18.05>}
		object {aisle_wall2_step(7.18,concat("vChoirAisle_r1")) rotate 90*y translate <24.87,0,3.59>}
		object {aisle_wall2_step(7.18,concat("vChoirAisle_r2")) rotate 90*y translate <24.87,0,10.77>}
		object {aisle_wall2_step(7.38,concat("vChoirAisle_r3")) rotate 90*y translate <24.87,0,18.05>}

		//- Columns
		object {aisle_column_oct() rotate -90*y translate <-24.87,0,7.18>}
		object {aisle_column_cyl() rotate -90*y translate <-24.87,0,14.36>}
		object {aisle_column_wall(-1) rotate -90*y translate <-24.87,0.4,21.54>}
		
		object {aisle_column_oct() rotate 90*y translate <24.87,0,7.18>}
		object {aisle_column_cyl() rotate 90*y translate <24.87,0,14.36>}
		object {aisle_column_wall(1) rotate 90*y translate <24.87,0.4,21.54>}

		object {column_cyl2(-0.38) rotate 90*y translate <16.58,0,0>}
		object {column_cyl2(-0.38) rotate 90*y translate <16.58,0,7.18>}
		object {column_oct1(-0.38) rotate 90*y translate <16.58,0,14.36>}
		object {column_cyl1(0.2) rotate 90*y translate <16.58,0,21.54>}

		object {column_cyl2(-0.38) rotate 90*y translate <-16.58,0,0>}
		object {column_cyl2(-0.38) rotate 90*y translate <-16.58,0,7.18>}
		object {column_oct1(-0.38) rotate -90*y translate <-16.58,0,14.36>}
		object {column_cyl1(0.2) rotate -90*y translate <-16.58,0,21.54>}

		//- Vault
		#local i=-1;
		#while (i<2)
			#local j=-1;
			#while (j<2)
				#local k=0;
				#while (k<2)
					object {arch(3.72,5,0.08,1.2,1,0.25,0.55,0,0,0.15,0.4,0,0,0,Column) translate <(16.58+3.98*j)*i,9.28,7.18*k>}
					#local k=k+1;
				#end
				#local k=2;
				#while (k<4)
					#if (j=1 & k=3)
						object {arch(2.735,5,0.08,1.2,1,0.25,0.55,0,0,0.15,0.4,0,0,0,Column) translate <(16.58+3.325*j)*i,9.28,7.18*k>}
					#else
						object {arch(3.555,5,0.08,1.2,1,0.25,0.55,0,0,0.15,0.4,0,0,0,Column) translate <(16.58+4.145*j)*i,9.28,7.18*k>}
					#end
					#local k=k+1;
				#end
				#local j=j+2;
			#end
			object {arch(3.3,5,0.08,1.2,1,0.25,0.55,0,0,0.15,0.4,0,0,0,Column) rotate 90*y translate <16.58*i,9.28,3.59>}
			object {arch(3.165,5,0.08,1.2,1,0.25,0.55,0,0,0.15,0.4,0,0,0,Column) rotate 90*y translate <16.58*i,9.28,10.635>}
			object {arch(3,5,0.08,1.2,1,0.25,0.55,0,0,0.15,0.4,0,0,0,Column) rotate 90*y translate <16.58*i,9.28,17.95>}
			
			union {
				union {
					object {Crown(0.4,0.4) translate 5*y}
					object {march1(4.85,5,1,0.08,0,0.16,0.34,0.05,0.15,0.3,Column) rotate -41.5*y}
					object {march1(4.85,5,1,0.08,0,0.16,0.34,0.05,0.15,0.3,Column) rotate 41.5*y}
					object {march1(4.95,5,1,0.08,0,0.16,0.34,0.05,0.15,0.3,Column) rotate -138.5*y}
					object {march1(4.95,5,1,0.08,0,0.16,0.34,0.05,0.15,0.3,Column) rotate 138.5*y}
					object {Vault2(<0,5,-3.98>,3.3,0,1.2,0,<0,5,0>,4.85,48.5,1,0,5) rotate 90*y}
					object {Vault2(<0,5,-4.34>,3.14,0,1.3,0,<0,5,0>,4.95,48.5,1,0,5) rotate -90*y}
					object {Vault(<0,5,-3.59>,3.72,0,1.2,0,<0,5,0>,4.95,41.5,1,0,5)}
					object {Vault(<0,5,-3.59>,3.72,0,1.2,0,<0,5,0>,4.85,41.5,1,0,5) scale <-1,1,1>}
					object {Vault(<0,5,-3.59>,3.72,0,1.2,0,<0,5,0>,4.85,41.5,1,0,5) rotate 180*y}
					object {Vault(<0,5,-3.59>,3.72,0,1.2,0,<0,5,0>,4.95,41.5,1,0,5) scale <-1,1,1> rotate 180*y}
					translate <-12.6,0,3.59>
					scale <i,1,1>
				}
				union {
					object {Crown(0.4,0.4) translate 5*y}
					object {march1(5.2,5,1,0.08,0,0.16,0.34,0.05,0.15,0.3,Column) rotate -39*y}
					object {march1(5,5,1,0.08,0,0.16,0.34,0.05,0.15,0.3,Column) rotate 39*y}
					object {march1(4.95,5,1,0.08,0,0.16,0.34,0.05,0.15,0.3,Column) rotate -138.5*y}
					object {march1(4.95,5,1,0.08,0,0.16,0.34,0.05,0.15,0.3,Column) rotate 138.5*y}
					object {Vault2(<0,5,-3.98>,3.3,0,1.2,0,<0,5,0>,4.95,48.5,1,0,5) rotate -90*y}
					object {Vault(<0,5,-4.25>,2.89,0,1,0,<0,5,0>,5.2,51,1,0,5) rotate 90*y}
					object {Vault(<0,5,-4.25>,2.89,0,1,0,<0,5,0>,5,51,1,0,5) scale <-1,1,1> rotate 90*y}
					object {Vault(<0,5,-3.59>,3.72,0,1.2,0,<0,5,0>,4.95,41.5,1,0,5)}
					object {Vault(<0,5,-3.59>,3.72,0,1.2,0,<0,5,0>,5.2,39,1,0,5) scale <-1,1,1>}
					object {Vault(<0,5,-3.59>,3.72,0,1.2,0,<0,5,0>,5,39,1,0,5) rotate 180*y}
					object {Vault(<0,5,-3.59>,3.72,0,1.2,0,<0,5,0>,4.95,41.5,1,0,5) scale <-1,1,1> rotate 180*y}
					translate <-20.56,0,3.59>
					scale <i,1,1>
				}
				union {
					object {Crown(0.4,0.4) translate 5*y}
					object {march1(4.85,5,1,0.08,0,0.16,0.34,0.05,0.15,0.3,Column) rotate -41.5*y}
					object {march1(4.85,5,1,0.08,0,0.16,0.34,0.05,0.15,0.3,Column) rotate 41.5*y}
					object {march1(4.95,5,1,0.08,0,0.16,0.34,0.05,0.15,0.3,Column) rotate -138.5*y}
					object {march1(4.95,5,1,0.08,0,0.16,0.34,0.05,0.15,0.3,Column) rotate 138.5*y}
					object {Vault2(<0,5,-4.34>,3.14,0,1.3,0,<0,5,0>,4.95,48.5,1,0,5) rotate -90*y}
					object {Vault(<0.135,5,-3.98>,3.165,0,1.2,0,<0,5,0>,4.85,48.5,1,0,5) rotate 90*y}
					object {Vault(<-0.135,5,-3.98>,3.165,0,1.2,0,<0,5,0>,4.85,48.5,1,0,5) scale <-1,1,1> rotate 90*y}
					object {Vault(<0,5,-3.59>,3.72,0,1.2,0,<0,5,0>,4.95,41.5,1,0,5)}
					object {Vault(<0,5,-3.59>,3.72,0,1.2,0,<0,5,0>,4.85,41.5,1,0,5) scale <-1,1,1>}
					object {Vault(<-0.165,5,-3.59>,3.555,0,1.2,0,<0,5,0>,4.85,41.5,1,0,5) rotate 180*y}
					object {Vault(<0.165,5,-3.59>,3.555,0,1.2,0,<0,5,0>,4.95,41.5,1,0,5) scale <-1,1,1> rotate 180*y}
					translate <-12.6,0,10.77>
					scale <i,1,1>
				}
				union {
					object {Crown(0.4,0.4) translate 5*y}
					object {march1(5.2,5,1,0.08,0,0.16,0.34,0.05,0.15,0.3,Column) rotate -39*y}
					object {march1(5,5,1,0.08,0,0.16,0.34,0.05,0.15,0.3,Column) rotate 39*y}
					object {march1(4.95,5,1,0.08,0,0.16,0.34,0.05,0.15,0.3,Column) rotate -138.5*y}
					object {march1(4.95,5,1,0.08,0,0.16,0.34,0.05,0.15,0.3,Column) rotate 138.5*y}
					object {Vault(<-0.135,5,-3.98>,3.165,0,1.2,0,<0,5,0>,4.95,48.5,1,0,5) rotate -90*y}
					object {Vault(<0.135,5,-3.98>,3.165,0,1.2,0,<0,5,0>,4.95,48.5,1,0,5) scale <-1,1,1> rotate -90*y}
					object {Vault(<0,5,-4.25>,2.89,0,1,0,<0,5,0>,5.2,51,1,0,5) rotate 90*y}
					object {Vault(<0,5,-4.25>,2.89,0,1,0,<0,5,0>,5,51,1,0,5) scale <-1,1,1> rotate 90*y}
					object {Vault(<0,5,-3.59>,3.72,0,1.2,0,<0,5,0>,4.95,41.5,1,0,5)}
					object {Vault(<0,5,-3.59>,3.72,0,1.2,0,<0,5,0>,5.2,39,1,0,5) scale <-1,1,1>}
					object {Vault(<0.165,5,-3.59>,3.555,0,1.2,0,<0,5,0>,5,39,1,0,5) rotate 180*y}
					object {Vault(<-0.165,5,-3.59>,3.555,0,1.2,0,<0,5,0>,4.95,41,1,0,5) scale <-1,1,1> rotate 180*y}
					translate <-20.56,0,10.77>
					scale <i,1,1>
				}
				union {
					object {Crown(0.4,0.4) translate 5*y}
					object {march1(4.9,5,1,0.08,0,0.16,0.34,0.05,0.15,0.3,Column) rotate -40.5*y}
					object {march1(4.9,5,1,0.08,0,0.16,0.34,0.05,0.15,0.3,Column) rotate 40.5*y}
					object {march1(4.85,5,1,0.08,0,0.16,0.34,0.05,0.15,0.3,Column) rotate -137*y}
					object {march1(4.85,5,1,0.08,0,0.16,0.34,0.05,0.15,0.3,Column) rotate 137*y}
					object {Vault2(<0,5,-4.17>,3.14,0,1.3,0,<0,5,0>,4.85,47,1,0,5) rotate -90*y}
					object {Vault2(<0,5,-4.17>,3,0,1.2,0,<0,5,0>,4.9,49.5,1,0,5) rotate 90*y}
					object {Vault(<0,5,-3.59>,3.555,0,1.2,0,<0,5,0>,4.85,43,1,0,5)}
					object {Vault(<0,5,-3.59>,3.555,0,1.2,0,<0,5,0>,4.9,40.5,1,0,5) scale <-1,1,1>}
					object {Vault(<0,5,-3.59>,3.555,0,1.2,0,<0,5,0>,4.9,40.5,1,0,5) rotate 180*y}
					object {Vault(<0,5,-3.59>,3.555,0,1.2,0,<0,5,0>,4.85,43,1,0,5) scale <-1,1,1> rotate 180*y}
					translate <-12.435,0,17.95>
					scale <i,1,1>
				}
				union {
					object {Crown(0.4,0.4) translate 5*y}
					object {march1(4.9,5,1,0.08,0,0.16,0.34,0.05,0.15,0.3,Column) rotate -40.5*y}
					object {march1(4.9,5,1,0.08,0,0.16,0.34,0.05,0.15,0.3,Column) rotate 40.5*y}
					object {march1(4.9,5,1,0.08,0,0.16,0.34,0.05,0.15,0.3,Column) rotate -139.5*y}
					object {march1(4.9,5,1,0.08,0,0.16,0.34,0.05,0.15,0.3,Column) rotate 139.5*y}
					object {Vault2(<0,5,-4.145>,3,0,1.2,0,<0,5,0>,4.9,49.5,1,0,5) rotate -90*y}
					object {Vault2(<0,5,-3.59>,3.555,0,1.2,0,<0,5,0>,4.9,40.5,1,0,5)}
					object {Vault(<0,5,-3.7>,2.735,-14,1.2,0,<0,5,0>,4.9,27.5,1,0,5) rotate 193*y}
					object {Vault(<0,5,-3.7>,2.735,14,1.2,0,<0,5,0>,4.9,53,1,0,5) scale <-1,1,1> rotate 193*y}
					object {Vault(<-0.1,5,-4.02>,2.99,0,1,0,<0,5,0>,4.9,49.5,1,0,5) rotate 90*y}
					object {Vault(<0.1,5,-4.02>,2.99,0,1,0,<0,5,0>,4.9,49.5,1,0,5) scale <-1,1,1> rotate 90*y}
					translate <-20.725,0,17.95>
					scale <i,1,1>
				}
				translate 9.28*y
			}
			#local i=i+2;
		#end
	}	
#end