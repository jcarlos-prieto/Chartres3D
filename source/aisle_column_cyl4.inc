//----- AUXILIAR COLUMN IN THE CHAPELS
//      h: Height

#macro aisle_column_cyl4(h)
	union {
	
		//- First step
		object {nBlock_squ(0.5,0.3,0.5,Column)}				
		object {nBlock_pyr(0.5,0.5,0.3,0.3,0.1,Column) translate 0.3*y}
		object {nBlock_squ(0.3,0.2,0.3,Column) translate 0.4*y}				
		
		//- Second step
		object {sBlock_cyl(0.1,h-0.4,0.8,Column) translate 0.4*y}
		object {nBlock_tor(0.1,0.05,360,Column) translate 0.65*y}
		object {nBlock_tor(0.1,0.02,360,Column) translate 0.74*y}
		object {nBlock_tor(0.1,0.02,360,Column) translate (h-0.4)*y}
		
		//- Third step
		object {nBlock_squ(0.4,0.05,0.4,Column) translate (h-0.05)*y}				
		object {nBlock_squ(0.3,0.1,0.3,Column) translate (h-0.15)*y}				
		object {nBlock_squ(0.2,0.05,0.2,Column) translate (h-0.2)*y}				
	
		//--- Leaves
		#if (show_ornaments)
			#local i=0;
			#while (i<4)
				object {leaf_curve2 scale <0.5,0.7,0.5> translate <0.1,h-0.4,0> rotate (45+90*i)*y}
				#local i=i+1;
			#end 
		#end
	}
#end
