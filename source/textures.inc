//----- TEXTURE DEFINITIONS   
#include "colors.inc"        
#include "stones.inc"

#declare v_ambient = 0;
#declare v_diffuse = 1;
#declare v_emission = 0;

//--- Textures for blocks
//     q: type (Wall, Floor, Floor2, Column, Tracery, Bricks, Door, StainedGlass)
//     m: Is mortar   
#macro T_Block(q,m)
	#if (m)
		#switch (q)
		#case (Wall)
			pigment {rgb 0.7*<0.9,0.8,0.7>}
			#break
		#case (Floor)
			pigment {rgb 0.4*<1,0.9,0.8>}
			#break
		#case (Floor2)
			pigment {rgb 0.4*<1,0.9,0.8>}
			#break
		#case (Column)
			pigment {rgb 0.7*<0.9,0.8,0.7>}
			#break
		#case (Tracery)
			pigment {rgb <0.9,0.8,0.7>}
			#break
		#end
		#if (show_textures)
			finish {
				crand 0.15
				ambient v_ambient
				diffuse v_diffuse
				emission v_emission
			}
		#end
	#else
		#switch (q)
		#case (Wall)
			#if (show_textures) 
				pigment {
					average
					pigment_map {
						[1 bumps
							color_map {
								[0.5 rgb 1.0*<0.85+0.1*rand(rr),0.65,0.58>]
								[0.7 rgb 0.8*<0.85+0.1*rand(rr),0.65,0.58>]
								[1.0 rgb 0.6*<0.85+0.1*rand(rr),0.65,0.58>]
							}
							scale 0.05
							translate <10*rand(rr),10*rand(rr),10*rand(rr)>
						]
						[1 bumps
							color_map {
								[0.5 rgb 1.0*<0.85+0.1*rand(rr),0.65,0.58>]
								[0.7 rgb 0.8*<0.85+0.1*rand(rr),0.65,0.58>]
								[1.0 rgb 0.6*<0.85+0.1*rand(rr),0.65,0.58>]
							}
							scale 0.5*<1,0.3,1>
							translate <10*rand(rr),10*rand(rr),10*rand(rr)>
						]
						[2 color (0.8+0.5*rand(rr))*<0.6+0.05*rand(rr),0.55,0.35>] 
					}
				}
				#if (show_normals)
					normal {
						granite 0.2
						scale 0.04
						translate <10*rand(rr),10*rand(rr),10*rand(rr)>
					}
				#end
			#else
				pigment {rgb 0.8*<0.85+0.1*rand(rr),0.65,0.58>}
			#end
			finish {
				ambient v_ambient
				diffuse v_diffuse  
				emission v_emission
			}
			#break
		#case (Column)
			#if (show_textures) 
				pigment {
					average
					pigment_map {
						[1 bumps
							color_map {
								[0.5 rgb 1.0*<0.85+0.1*rand(rr),0.65,0.58>]
								[0.7 rgb 0.8*<0.85+0.1*rand(rr),0.65,0.58>]
								[1.0 rgb 0.6*<0.85+0.1*rand(rr),0.65,0.58>]
							}
							scale 0.05
							translate <10*rand(rr),10*rand(rr),10*rand(rr)>
						]
						[1 bumps
							color_map {
								[0.5 rgb 1.0*<0.85+0.1*rand(rr),0.65,0.58>]
								[0.7 rgb 0.8*<0.85+0.1*rand(rr),0.65,0.58>]
								[1.0 rgb 0.6*<0.85+0.1*rand(rr),0.65,0.58>]
							}
							scale 0.5*<1,0.3,1>
							translate <10*rand(rr),10*rand(rr),10*rand(rr)>
						]
						[2 color (0.9+0.2*rand(rr))*<0.6+0.05*rand(rr),0.55,0.35>] 
					}
				}
				#if (show_normals)    
					normal {
						granite 0.1
						scale 0.02
						translate <10*rand(rr),10*rand(rr),10*rand(rr)>
					}
				#end
			#else
				pigment {rgb 0.8*<0.85+0.1*rand(rr),0.65,0.58>}
			#end
			finish {
				ambient v_ambient
				diffuse v_diffuse 
				emission v_emission
			}
			#break
		#case (Tracery)
			#if (show_textures)
				pigment {
					average
					pigment_map {
						[1 bumps
							color_map {
								[0.5 rgb 1.0*<0.85+0.1*rand(rr),0.65,0.58>]
								[0.7 rgb 0.8*<0.85+0.1*rand(rr),0.65,0.58>]
								[1.0 rgb 0.6*<0.85+0.1*rand(rr),0.65,0.58>]
							}
							scale 0.05
							translate <10*rand(rr),10*rand(rr),10*rand(rr)>
						]
						[1 bumps
							color_map {
								[0.5 rgb 1.0*<0.85+0.1*rand(rr),0.65,0.58>]
								[0.7 rgb 0.8*<0.85+0.1*rand(rr),0.65,0.58>]
								[1.0 rgb 0.6*<0.85+0.1*rand(rr),0.65,0.58>]
							}
							scale 0.5*<1,0.1,1>
							translate <10*rand(rr),10*rand(rr),10*rand(rr)>
						]
						[2 color (1.0+0.4*rand(rr))*<0.6+0.05*rand(rr),0.55,0.35>] 
					}
				}
				#if (show_normals)
					normal {
						granite 0.2
						scale 0.04
					}          
				#end
				finish {
					ambient v_ambient
					diffuse v_diffuse  
					emission v_emission
				}
			#else
				pigment {rgb 0.8*<0.85+0.1*rand(rr),0.65,0.58>}
			#end
			#break
		#case (Floor)
			#if (show_textures)
				pigment {
					average
					pigment_map {
						[1 bumps
							color_map {
								[0.5 rgb 1.0*<0.85+0.02*rand(rr),0.55,0.35>]
								[0.7 rgb 0.8*<0.85+0.02*rand(rr),0.55,0.35>]
								[1.0 rgb 0.6*<0.85+0.02*rand(rr),0.55,0.35>]
							}
							scale 0.15
							translate <10*rand(rr),10*rand(rr),10*rand(rr)>
						]
						[1 color (0.8+0.4*rand(rr))*<0.8+0.05*rand(rr),0.55,0.35>] 
					}
				}
				#if (show_normals)
					normal {
						granite 0.1
						scale 1
						translate <10*rand(rr),10*rand(rr),10*rand(rr)>
					}
				#end
				finish {
					ambient v_ambient
					diffuse v_diffuse  
					emission v_emission
				}
			#else
				pigment {rgb 0.8*<0.85+0.02*rand(rr),0.55,0.35>}
			#end			
			#break
		#case (Floor2)
			#if (show_textures)
				pigment {
					average
					pigment_map {
						[1 bumps
							color_map {
								[0.5 rgb 1.0*<0.85+0.02*rand(rr),0.55,0.35>]
								[0.7 rgb 0.8*<0.85+0.02*rand(rr),0.55,0.35>]
								[1.0 rgb 0.6*<0.85+0.02*rand(rr),0.55,0.35>]
							}
							scale 0.15
							translate <10*rand(rr),10*rand(rr),10*rand(rr)>
						]
						[1 color (0.8+0.4*rand(rr))*<0.8+0.05*rand(rr),0.55,0.35>] 
					}
				}
				finish {
					ambient v_ambient
					diffuse v_diffuse  
					emission v_emission
				}
			#else
				pigment {rgb 0.8*<0.85+0.02*rand(rr),0.55,0.35>}
			#end			
			#break
		#case (Bricks)
			#if (show_textures)
				pigment {
					uv_mapping
					brick 
						pigment {rgb 0.7*<0.9,0.8,0.7>}
						pigment {
							granite
							color_map {
								[0.4 rgb 0.9*<0.7,0.5,0.4>]
								[1.0 rgb 0.6*<0.7,0.5,0.4>]
							}
							scale 0.3
						}
					scale 0.08
					rotate 90*z
				}
				#if (show_normals)
					normal {
						granite 0.3
						scale 0.04
					}
				#end
				finish {
					ambient v_ambient
					diffuse v_diffuse  
					emission v_emission
				}
			#else
				pigment {rgb 0.8*<0.7,0.5,0.4>}
			#end
			#break
		#case (Door)
			#if (show_textures)
				pigment {
					average
					pigment_map {
						[2	wood
							color_map {
								[0.26 rgb <0.25, 0.14, 0.09>/4]
								[0.39 rgb <0.29, 0.15, 0.11>/4]
								[0.58 rgb <0.30, 0.16, 0.11>/4]
								[0.73 rgb <0.25, 0.14, 0.09>/5]
								[0.98 rgb <0.31, 0.15, 0.13>/6]
								[1.00 rgb <0.29, 0.15, 0.10>/7]
							}						
							turbulence 0.4
							octaves 3
							scale <1,0.05,2>
							translate <10*rand(rr),10*rand(rr),10*rand(rr)>
						]
						[1	wood
							color_map {
								[0.14 rgb <0.55, 0.35, 0.25>/4]
								[0.15 rgb <0.45, 0.35, 0.32>/4]
								[0.29 rgb <0.45, 0.35, 0.32>/4]
								[0.44 rgb <0.55, 0.35, 0.25>/4]
								[0.63 rgb <0.55, 0.35, 0.25>/4]
								[0.64 rgb <0.45, 0.35, 0.32>/4]
								[0.84 rgb <0.45, 0.35, 0.32>/4]
								[1.00 rgb <0.55, 0.35, 0.25>/4]
							}						
							turbulence <0.1,0.5,1>
							octaves 5
							lambda 3.25
							scale <1,0.5,1>
							rotate <5,10,5>
							translate <10*rand(rr),10*rand(rr),10*rand(rr)>
						]
					}
				}
				finish {
					ambient v_ambient
					diffuse v_diffuse           
					emission v_emission
				}
			#else
				pigment {rgb <0.55, 0.35, 0.25>/4}
			#end
			#break
		#end
	#end
#end
               