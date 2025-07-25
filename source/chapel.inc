//----- CONSTRUCTION OF ONE SINGLE CHAPEL
//		  q: Chapel number
//      p: Type: 1-Small (2 sides)
//               2-Medium (3 sides)
//               3-Big (5 sides)

#ifndef(chapel_wall_step)
	#include "chapel_wall_step.inc"
#end
#ifndef(aisle_column_cyl3)
	#include "aisle_column_cyl3.inc" 
#end

#macro chapel(q,p)
	union {
		#switch (p)
		#case (1)
			#local i=0;
			#while (i<2)
				object {chapel_wall_step(concat("vChapel",str(q,1,0),"_",str(i+1,1,0))) translate 3.9*z rotate (45*i-22.5)*y}
				#local i=i+1;
			#end
			object {aisle_column_cyl3(0) translate 3.75*z}
			#local i=0;
			#while (i<3)
				object {sBlock_squ2(0.45,8.52,0.6,0.8,Wall) translate 4.2*z rotate (45*i-45)*y}
				#local i=i+1;
			#end
			#break
		#case (2)
			#local i=0;
			#while (i<3)
				object {chapel_wall_step(concat("vChapel",str(q,1,0),"_",str(i+1,1,0))) translate 3.9*z rotate (45*i-45)*y}
				#local i=i+1;
			#end
			#local i=0;
			#while (i<2)
				object {aisle_column_cyl3(0) translate 3.75*z rotate (45*i-22.5)*y}
				#local i=i+1;
			#end
			#local i=0;
			#while (i<4)
				object {sBlock_squ2(0.45,8.52,0.6,0.8,Wall) translate 4.2*z rotate (45*i-67.5)*y}
				#local i=i+1;
			#end
			#break
		#case (3)
			#local i=0;
			#while (i<5)
				object {chapel_wall_step(concat("vChapel",str(q,1,0),"_",str(i+1,1,0))) translate 3.9*z rotate (45*i-90)*y}
				#local i=i+1;
			#end
			#local i=0;
			#while (i<4)
				object {aisle_column_cyl3(0) translate 3.75*z rotate (45*i-67.5)*y}
				#local i=i+1;
			#end
			#local i=0;
			#while (i<6)
				object {sBlock_squ2(0.45,8.52,0.6,0.8,Wall) translate 4.2*z rotate (45*i-112.5)*y}
				#local i=i+1;
			#end
			union {
			   object {Crown(0.4,0.4) translate 5*y}
   			#local i=0;
   			#while (i<6)
  			      object {march1(3.8,5,1,0.08,0,0.16,0.34,0.05,0.15,0.3,Column) rotate (45*i-22.5)*y}
   				#local i=i+1;
   			#end
   			#local i=0;
   			#while (i<5)
  			      object {Vault2(<0,5,-3.8>,1.24,0,1.33,0,<0,5,0>,3.8,67.5,1,0,5) rotate (45*i+90)*y}
   				#local i=i+1;
   			#end
   			object {Vault2(<0,5,-1.6>,3.65,0,1.13,0,<0,5,0>,3.8,22.5,1,0,5)}
			   translate 8.68*y
			}
			#break
		#end			 
	}	
#end
