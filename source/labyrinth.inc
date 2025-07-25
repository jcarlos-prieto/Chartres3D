//----- THE LABYRINTH

#macro labyrinth()
	union {
		//--- Floor bricks sorrounding the labyrinth  
 
		difference {
			object {sBlock_squ(16,13.8,0.5,0.7,0.3,0.3,Floor) translate -6.9*y}
			cylinder {<0,0,-1> <0,0,1> 6.6 texture {T_Block(Floor,NoMortar)}} 
		}			
		
		//--- Main object  
		cylinder {
			<0,0,-0.25> <0,0,0> 6.6
			texture {T_Block(Floor2,NoMortar)}
			#if (show_details)
				normal {
					bump_map {
						png "labyrinth_normal.png"
						bump_size 20
						once
					}
					rotate 180*z
					scale <13.2,13.2,1>
					translate <6.6,6.6,0>
				}
			#end
		}
      
		cylinder {
			<0,0,-0.251> <0,0,-0.252> 6.6
			pigment {
				image_map {
					png "labyrinth_texture.png"
				}
				rotate 180*z
				scale <13.2,13.2,0.01>
				translate <6.6,6.6,0>
			}                     
			#if (show_normals)
				normal {
					granite 0.1
					scale 1
					translate <10*rand(rr),10*rand(rr),10*rand(rr)>
				}
			#end
			finish {
				phong 0.4
				phong_size 5
				ambient v_ambient
				diffuse v_diffuse  
				emission v_emission
			}
		}

	}
#end