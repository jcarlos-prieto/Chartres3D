//----- COLUMN (OCTOGONAL TYPE) - SMALL
//      h0: Lower ornament elevation

#macro column_oct2(h0)

	union {
	
		//--- Body
		object {sBlock_oct(0.72,9.44,0.8,Column) translate -0.36*y}
		
		//--- Lower ornament
		object {nBlock_octcyl(0.72,0.05,Column) translate (0.73+h0)*y}
		object {nBlock_octcyl(0.72,0.02,Column) translate (0.82+h0)*y}
		object {nBlock_oct(0.76,0.1,Column) translate (0.58+h0)*y}
		object {nBlock_pyr(1.72,1.72/(1+sqrt(2)),1.52,1.52/(1+sqrt(2)),0.1,Column) translate (0.48+h0)*y}
		object {nBlock_pyr(1.72,1.72/(1+sqrt(2)),1.52,1.52/(1+sqrt(2)),0.1,Column) translate (0.48+h0)*y rotate 45*y}
		object {nBlock_pyr(1.72,1.72/(1+sqrt(2)),1.52,1.52/(1+sqrt(2)),0.1,Column) translate (0.48+h0)*y rotate 90*y}
		object {nBlock_pyr(1.72,1.72/(1+sqrt(2)),1.52,1.52/(1+sqrt(2)),0.1,Column) translate (0.48+h0)*y rotate 135*y}
		object {nBlock_oct(0.86,0.5,Column) translate (-0.02+h0)*y}

		//--- Upper ornament
		union {
			object {nBlock_octcyl(0.72,0.02,Column) translate 8.2*y}
			object {nBlock_octcyl(0.72,0.02,Column) translate 8.7*y}
			object {nBlock_oct(0.9,0.05,Column) translate 9.23*y}
			object {nBlock_oct(0.8,0.1,Column) translate 9.13*y}
			object {nBlock_oct(0.7,0.05,Column) translate 9.08*y}
		}     
		
		//--- Leaves
		#if (show_ornaments)
			#local i=0;
			#while (i<4)
				object {leaf_curve1 translate <0.71,8.2,0> rotate (45+90*i)*y}
				object {leaf_curve1 scale <0.3,0.5,1> translate <0.72,8.2,0> rotate 90*i*y}
				object {leaf_curve1 translate <0.71,8.7,0> rotate 90*i*y}
				object {leaf_curve1 scale <0.3,0.5,1> translate <0.72,8.7,0> rotate (45+90*i)*y}
				#local i=i+1;
			#end
			#local i=0;
			#while (i<4)
				object {leaf_tree rotate 15*x translate <0.72,8.41,0> rotate (90*i)*y}
				object {leaf_tree rotate -15*x translate <0.72,8.41,0> rotate (90*i)*y}
				object {leaf_tree rotate 15*x translate <0.72,8.83,0> rotate (45+90*i)*y}
				object {leaf_tree rotate -15*x translate <0.72,8.83,0> rotate (45+90*i)*y}
				#local i=i+1;
			#end
		#end
	}
#end