//----- STEP 1 OF THE COLUMN (CYLINDRICAL)
//      h0: Lower ornament elevation

#macro column1_cyl(h0)
	union {
	
		//--- Body
		object {sBlock_cyl(0.72,9.44,0.8,Column) translate -0.48*y}
		#local i=0;
		#while (i<4)
			object {sBlock_oct(0.22,9.44,0.8,Column) translate <0.87,-0.48,0> rotate 90*i*y}
			#local i=i+1;
		#end
	
		//--- Lower ornament
		union {
			object {nBlock_tor(0.72,0.05,360,Column) translate (0.45+h0)*y}
			object {nBlock_tor(0.72,0.02,360,Column) translate (0.54+h0)*y}
			#local i=0;
			#while (i<4)
				union {
					object {nBlock_octcyl(0.22,0.05,Column) translate <0.87,0.45+h0,0> rotate 90*i*y}
					object {nBlock_octcyl(0.22,0.02,Column) translate <0.87,0.54+h0,0> rotate 90*i*y}
				}
				#local i=i+1;
			#end
		}
			
		//--- Upper ornament
		union {
			object {nBlock_tor(0.72,0.02,360,Column) translate 8.08*y}
			object {nBlock_tor(0.72,0.02,360,Column) translate 8.44*y}
			#local i=2;
			#while (i<5)
				object {nBlock_octcyl(0.22,0.02,Column) translate <0.87,8.43,0> rotate 90*i*y}
				#local i=i+1;
			#end
			object {nBlock_oct(0.25,0.05,Column) translate <0,8.8,-0.87>}
			object {nBlock_oct(0.28,0.1,Column) translate <0,8.9,-0.87>}
			object {nBlock_oct(0.31,0.05,Column) translate <0,8.95,-0.87>}
		}
		
		//--- Leaves
		#if (show_ornaments)
			#local i=0;
			#while (i<4)
				object {leaf_curve1 translate <0.71,8.1,0> rotate (45+90*i)*y}
				object {leaf_curve1 scale <1,0.9,1> translate <0.71,8.46,0> rotate (20+90*i)*y}
				object {leaf_curve1 scale <1,0.9,1> translate <0.71,8.46,0> rotate (70+90*i)*y}
				object {leaf_tree translate <0.72,8.48,0> rotate (45+90*i)*y}
				object {leaf_tree translate <0.72,8.18,0> rotate (22+90*i)*y}
				object {leaf_tree translate <0.72,8.18,0> rotate (68+90*i)*y}
				#local i=i+1;
			#end
			#local i=0;
			#while (i<3)
				#local j=0;
				#while (j<3)
					object {leaf_rect scale <0.5,0.75,0.5> translate <0.21,8.46,0> rotate (-90+90*j)*y translate 0.87*x rotate (180+90*i)*y}
					object {leaf_tree scale 0.75 translate <0.22,8.52,0> rotate (-45+90*j)*y translate 0.87*x rotate (180+90*i)*y}
					#local j=j+1;
				#end
				#local i=i+1;
			#end
		#end
	}
#end