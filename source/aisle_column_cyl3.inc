//----- AUXILIAR COLUMN IN THE CHAPELS AISLE
//     p: Base rotation: 0-0 degrees; 1-45 degrees

#macro aisle_column_cyl3(p)
	union {
	
		//- First step
		union {
			object {nBlock_squ(0.6,0.3,0.6,Column)}				
			object {nBlock_pyr(0.6,0.6,0.4,0.4,0.1,Column) translate 0.3*y}
			object {nBlock_squ(0.4,0.2,0.4,Column) translate 0.4*y}				
			rotate 45*p*y
		}
		
		//- Second step
		object {sBlock_cyl(0.15,8.12,0.8,Column) translate 0.4*y}
		object {nBlock_tor(0.15,0.05,360,Column) translate 0.65*y}
		object {nBlock_tor(0.15,0.02,360,Column) translate 0.74*y}
		object {nBlock_tor(0.15,0.02,360,Column) translate 8.11*y}
		
		//- Third step
		object {nBlock_squ(0.6,0.05,0.6,Column) translate 8.63*y}				
		object {nBlock_squ(0.5,0.1,0.5,Column) translate 8.53*y}				
		object {nBlock_squ(0.4,0.05,0.4,Column) translate 8.48*y}				
	
		//--- Leaves
		#if (show_ornaments)
			#local i=0;
			#while (i<4)
				object {leaf_curve2 scale <0.5,0.9,0.5> translate <0.14,8.11,0> rotate (45+90*i)*y}
				#local i=i+1;
			#end 
		#end
	}
#end
