//--- RADIOSITY
global_settings {
	assumed_gamma 1
	#if (show_ambient) 
		radiosity {  
			error_bound 0.15
			count 1200
			normal on  
			media on
		}
	#end	
}
                  
//----- SKY
#if (sun_light)
	sphere {
		<0,0,0> 210
		hollow
		texture {
			pigment {rgb <0.7,0.7,1>}
		}
	}
#else
	sky_sphere {
		pigment {rgb <0.3,0.3,1>}
	}
#end

//----- GROUND
plane {
	y, -1
	pigment {rgb 1}
	finish {ambient v_ambient diffuse v_diffuse}
}

//----- MEDIA
#if (show_media)
	box {
		<-34,-0.99,-71> <34,35,71>
		pigment {rgbt 1} hollow
		interior {
			media {    
				scattering {1 0.015}
			}
		}
	}
#end

//----- LIGHT
light_source {
	#if (sun_light)
		<0,0,-200>
		rgb 2*<1,0.8,0.7>
		area_light <10,0,0> <0,10,0> 3 3  
		jitter
		circular
		orient
		rotate r_light
	#else
		#if (show_ambient)
			0
			rgb 0.5*<1,0.9,0.8>
			fade_power 2
			fade_distance 20
			area_light <1,0,0> <0,1,0> 3 3
		#else
			0
			rgb <1,0.9,0.8>
		#end
		rotate r_camera
		translate t_camera
	#end
}       

//----- CAMERA
camera {
	location 0
	look_at z
	rotate r_camera
	translate t_camera
}
