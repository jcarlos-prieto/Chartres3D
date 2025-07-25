//----- ONE PIECE OF WALL FROM THE CHAPELS AISLE
//      p: Main column type: 1-Octogonal; 2-Cylindrical
//      L1: Right length of the wall
//      L2: Left length of the wall
//      t1: Termination type at right (0: 1 column - 1: 3 columns)
//      t2: Termination type at left (0: 1 column - 1: 3 columns)

#ifndef(aisle_column_oct2)
	#include "aisle_column_oct2.inc" 
#end
#ifndef(aisle_column_cyl2)
	#include "aisle_column_cyl2.inc" 
#end
#ifndef(aisle_column_cyl3)
	#include "aisle_column_cyl3.inc" 
#end

#macro aisle_wall3_step(p,L1,L2,t1,t2)
	union {
		#if (p=1)
			object {aisle_column_oct2() translate 0.6*y}
		#else
			object {aisle_column_cyl2() translate 0.6*y}
		#end
		
		#if (L1+L2>0)
			object {sBlock_squ(L1+L2+0.2,0.3,1,0.8,0.8,0.3,Wall) translate <(L1-L2)/2,0.6,0.6>}
			object {nBlock_pyr(L1+L2+0.2,1,L1+L2,0.8,0.1,Wall) translate <(L1-L2)/2,0.9,0.6>}
		#end

		#if (L1>0)
			object {sBlock_squ(L1,8.12,0.65,0.8,0.8,0.4,Wall) translate <L1/2,1,0.45>}
			#if (t1=0)
				object {aisle_column_cyl3(0) translate <L1+0.13,0.6,0.35>}				
			#else
				object {sBlock_squ2(0.25,8.12,0.3,0.8,Wall) translate <L1+0.125,1,0.6>}
				object {aisle_column_cyl3(0) translate <L1+0.38,0.6,0.6>}
				object {aisle_column_cyl3(1) translate <L1+0.13,0.6,0.35>}
				object {aisle_column_cyl3(1) translate <L1+0.13,0.6,0.85>}
			#end
			object {nBlock_squ(L1,0.05,0.25,Wall) translate <L1/2,9.23,0.2>}
			object {nBlock_squ(L1,0.1,0.15,Wall) translate <L1/2,9.13,0.2>}
			object {nBlock_squ(L1,0.05,0.05,Wall) translate <L1/2,9.08,0.2>}
		#end

		#if (L2>0)
			object {sBlock_squ(L2,8.12,0.65,0.8,0.8,0.4,Wall) translate <-L2/2,1,0.45>}
			#if (t2=0)
				object {aisle_column_cyl3(0) translate <-L2-0.13,0.6,0.35>}
			#else
				object {sBlock_squ2(0.25,8.12,0.3,0.8,Wall) translate <-L2-0.125,1,0.6>}
				object {aisle_column_cyl3(0) translate <-L2-0.38,0.6,0.6>}
				object {aisle_column_cyl3(1) translate <-L2-0.13,0.6,0.35>}
				object {aisle_column_cyl3(1) translate <-L2-0.13,0.6,0.85>}
			#end
			object {nBlock_squ(L2,0.05,0.25,Wall) translate <-L2/2,9.23,0.2>}
			object {nBlock_squ(L2,0.1,0.15,Wall) translate <-L2/2,9.13,0.2>}
			object {nBlock_squ(L2,0.05,0.05,Wall) translate <-L2/2,9.08,0.2>}
		#end
	}
#end