//----- COLUMN IN THE CORNER OF THE AISLES
//     sx: Simmetry in x axis
//     sz: Simmetry in z axis
//      c: Type (0 = Cylindrical  -  1 = Octogonal)

#macro aisle_column_cor(sx,sz,c)
	union {
		object {sBlock_cyl(0.12,9.12,0.8,Column) translate <0.1*sx,0,-0.7*sz>}
		object {sBlock_cyl(0.15,9.12,0.8,Column) translate <0.14*sx,0,-0.48*sz>}
		object {sBlock_cyl(0.15,9.12,0.8,Column) translate <0.4*sx,0,-0.4*sz>}
		object {sBlock_cyl(0.15,9.12,0.8,Column) translate <0.5*sx,0,-0.16*sz>}
		#if (c=0)
			object {sBlock_cyl(0.25,9.12,0.8,Column) translate <0.84*sx,0,0>}
		#else
			object {sBlock_oct(0.25,9.12,0.8,Column) translate <0.84*sx,0,0>}
		#end
		object {sBlock_cyl(0.15,9.12,0.8,Column) translate <0.5*sx,0,0.16*sz>}
		object {sBlock_cyl(0.15,9.12,0.8,Column) translate <0.4*sx,0,0.4*sz>}
		object {sBlock_cyl(0.15,9.12,0.8,Column) translate <0.14*sx,0,0.48*sz>}
		#if (c=0)
			object {sBlock_oct(0.25,9.12,0.8,Column) translate <0,0,0.84*sz>}
		#else
			object {sBlock_cyl(0.25,9.12,0.8,Column) translate <0,0,0.84*sz>}
		#end
		object {sBlock_cyl(0.15,9.12,0.8,Column) translate <-0.16*sx,0,0.5*sz>}
		object {sBlock_cyl(0.15,9.12,0.8,Column) translate <-0.4*sx,0,0.4*sz>}
		object {sBlock_cyl(0.15,9.12,0.8,Column) translate <-0.48*sx,0,0.14*sz>}
		object {sBlock_cyl(0.12,9.12,0.8,Column) translate <-0.7*sx,0,0.1*sz>}
	
		#local coor = 
			array[7][10]
			{	{0.8,0.6,0.9,0.8,0.7,0.84,0,0,0.25,1-c}
				{0.8,0.6,0.9,0.8,0.7,0,0.84,0,0.25,c}
				{0.6,0.4,0.8,0.7,0.6,0.4,0.4,45,0.15,1}
				{0.6,0.4,0.6,0.5,0.4,-0.4,0.4,45,0.15,1}
				{0.6,0.4,0.6,0.5,0.4,0.4,-0.4,45,0.15,1}
				{0.6,0.4,0.6,0.5,0.4,-0.7,0.1,0,0.12,-1}
				{0.6,0.4,0.6,0.5,0.4,0.1,-0.7,0,0.12,-1}
			}
		#local i=0;
		#while (i<7)
			union {
				object {nBlock_squ(coor[i][0],0.18,coor[i][0],Column)}				
				object {nBlock_pyr(coor[i][0],coor[i][0],coor[i][1],coor[i][1],0.1,Column) translate 0.18*y}
				object {nBlock_squ(coor[i][1],0.2,coor[i][1],Column) translate 0.28*y}
				#if (coor[i][9]>=0)				
					object {nBlock_squ(coor[i][2],0.05,coor[i][2],Column) translate 9.23*y}				
					object {nBlock_squ(coor[i][3],0.1,coor[i][3],Column) translate 9.13*y}				
					object {nBlock_squ(coor[i][4],0.05,coor[i][4],Column) translate 9.08*y}
				#end
				#if (coor[i][9]=0)				
					object {nBlock_octcyl(coor[i][8],0.05,Column) translate 0.53*y}
					object {nBlock_octcyl(coor[i][8],0.02,Column) translate 0.62*y}
					object {nBlock_octcyl(coor[i][8],0.02,Column) translate 8.71*y}
				#else
					object {nBlock_tor(coor[i][8],0.05,360,Column) translate 0.53*y}
					object {nBlock_tor(coor[i][8],0.02,360,Column) translate 0.62*y}
					#if (coor[i][9]>0)
						object {nBlock_tor(coor[i][8],0.02,360,Column) translate 8.71*y}
					#end
				#end
				rotate coor[i][7]*y
				translate <coor[i][5]*sx,0,coor[i][6]*sz>
			}
			#local i=i+1;
		#end
		
		//--- Leaves
		#if (show_ornaments)
			#local i=0;
			#while (i<2)
				object {leaf_curve2 scale <0.5,0.65,0.5> translate <0.15,8.71,0> rotate (180+90*i)*y translate <0.4*sx,0,-0.4*sz>}
				object {leaf_curve2 scale <0.5,0.65,0.5> translate <0.15,8.71,0> rotate (90+90*i)*y translate  <0.4*sx,0,0.4*sz>}
				object {leaf_curve2 scale <0.5,0.65,0.5> translate <0.15,8.71,0> rotate 90*i*y translate <-0.4*sx,0,0.4*sz>}
				#local i=i+1;
			#end
			#local i=0;
			#while (i<3)
				object {leaf_tree scale 0.8 translate <0.145,8.85,0> rotate (135+90*i)*y translate <0.4*sx,0,-0.4*sz>}
				object {leaf_tree scale 0.8 translate <0.145,8.85,0> rotate (45+90*i)*y translate  <0.4*sx,0,0.4*sz>}
				object {leaf_tree scale 0.8 translate <0.145,8.85,0> rotate (-45+90*i)*y translate <-0.4*sx,0,0.4*sz>}
				#local i=i+1;
			#end
			#local i=0;
			#while (i<4)
				#if (c=0)
					object {leaf_curve2 translate <0.24,8.71,0> rotate (45+90*i)*y translate <0.84*sx,0,0>}
					object {leaf_rect scale <0.5,0.65,0.5> translate <0.24,8.71,0> rotate (45+90*i)*y translate <0,0,0.84*sz>}
				#else
					object {leaf_rect scale <0.5,0.65,0.5> translate <0.24,8.71,0> rotate (45+90*i)*y translate <0.84*sx,0,0>}
					object {leaf_curve2 translate <0.24,8.71,0> rotate (45+90*i)*y translate <0,0,0.84*sz>}
				#end 
				#local i=i+1;
			#end
			#local i=0;
			#while (i<3)
				object {leaf_tree scale 0.8 rotate 20*x translate <0.25,8.85,0> rotate (90*i)*y translate <0.84*sx,0,0>}
				object {leaf_tree scale 0.8 rotate -20*x translate <0.25,8.85,0> rotate (90*i)*y translate <0.84*sx,0,0>}
				object {leaf_tree scale 0.8 rotate 20*x translate <0.25,8.8,0> rotate (90*i)*y translate  <0,0,0.84*sz>}
				object {leaf_tree scale 0.8 rotate -20*x translate <0.25,8.8,0> rotate (90*i)*y translate  <0,0,0.84*sz>}
				#local i=i+1;
			#end
		#end
	}
#end
