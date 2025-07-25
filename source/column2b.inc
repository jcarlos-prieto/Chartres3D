//----- STEP 2 OF THE COLUMN (FOR FINAL PART OF THE CHOIR)

#macro column2b()
	union {
		object {nBlock_oct(1,0.05,Column) translate 0.15*y}
		object {nBlock_oct(0.9,0.1,Column) translate 0.05*y}
		object {nBlock_oct(0.8,0.05,Column)}
		#local i=0;
		#while (i<4)
			union {
				object {nBlock_squ(0.8,0.05,0.8,Column) translate 0.15*y}				
				object {nBlock_squ(0.7,0.1,0.7,Column) translate 0.05*y}				
				object {nBlock_squ(0.6,0.05,0.6,Column)}				
				#if (i=2)
					translate 0.8*x
				#else
					translate 0.87*x
				#end
				rotate 90*i*y
			}
			#local i=i+1;
		#end
	}
#end