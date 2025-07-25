//----- COLUMN ATTACHED TO THE CHAPELS WALL

#macro aisle_column_oct2()
	union {
	
		//- First step
		object {nBlock_squ(0.8,0.3,0.8,Column)}				
		object {nBlock_pyr(0.8,0.8,0.6,0.6,0.1,Column) translate 0.3*y}
		object {nBlock_squ(0.6,0.2,0.6,Column) translate 0.4*y}				
		
		//- Second step
		object {sBlock_oct(0.25,8.12,0.8,Column) translate 0.4*y}
		object {nBlock_octcyl(0.25,0.05,Column) translate 0.65*y}
		object {nBlock_octcyl(0.25,0.02,Column) translate 0.74*y}
		object {nBlock_octcyl(0.25,0.02,Column) translate 8.11*y}
		
		//- Third step
		object {nBlock_squ(0.9,0.05,0.9,Column) translate 8.63*y}				
		object {nBlock_squ(0.8,0.1,0.8,Column) translate 8.53*y}				
		object {nBlock_squ(0.7,0.05,0.7,Column) translate 8.48*y}				
	
		//--- Leaves
		#if (show_ornaments)
			#local i=0;
			#while (i<4)
				object {leaf_rect scale <1,0.9,0.5> translate <0.23,8.11,0> rotate (45+90*i)*y}
				#local i=i+1;
			#end
			#local i=0;
			#while (i<3)
				object {leaf_tree translate <0.25,8.15,0> rotate (90*i)*y}
				#local i=i+1;
			#end 
		#end 
	}
#end
