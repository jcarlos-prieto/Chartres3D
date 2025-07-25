//----- TRIFORIUM COLUMN

#declare triforium_column =
	union {
		object {nBlock_squ(0.4,0.22,0.4,Column)}
		object {nBlock_cyl(0.19,0.06,Column) translate 0.22*y}
		object {nBlock_tor(0.19,0.03,360,Column) translate 0.25*y}
		object {nBlock_tor(0.12,0.03,360,Column) translate 0.34*y}
		object {nBlock_tor(0.12,0.03,360,Column) translate 1.8*y}
		object {nBlock_pyr(0.38,0.38,0.33,0.33,0.08,Column) rotate 180*x translate 2.12*y}
		object {nBlock_squ(0.4,0.04,0.4,Column) translate 2.08*y}
		object {nBlock_squ(0.44,0.06,0.44,Column) translate 2.12*y}
		object {sBlock_cyl(0.12,1.82,0.5,Column) translate 0.22*y}

		//--- Leaves
		#if (show_ornaments) 
			#local i=0;
			#while (i<4)
				object {leaf_curve2 scale <0.55,0.7,0.55> translate <0.12,1.8,0> rotate (45+90*i)*y}
				#local i=i+1;
			#end
		#end
	}