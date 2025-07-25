//------------------------------------------------------
// Chartres Cathedral (as built in 1260)
//
// (c) Juan Carlos Prieto - 2004 - 2023
//------------------------------------------------------
            
#version 3.8;

//----- SWITCHES
#declare show_transept		= on;
#declare show_nave			= on;
#declare show_choir			= on;
#declare show_ambulatory	= on;
#declare show_chapels		= on;
#declare show_main_facade	= on;
#declare show_north_porch	= on;
#declare show_south_porch	= on;

#declare show_ornaments		= on;
#declare show_vitress		= on;
#declare show_bricks			= on;
#declare show_details		= on; 
#declare show_textures		= on;
#declare show_normals		= on;

#declare show_ambient		= on;
#declare show_media			= on;
#declare sun_light			= on;      

#declare img = 0;
#switch (img)
#case (0) // Random
	#include "random_camera.inc"
	#break
#case (1)
	#declare r_camera = <0,0,0>;
	#declare t_camera = <0,18,-70>;
	#declare r_light = <90,0,0>; 
	#break
#case (2)
	#declare r_camera = <0,180,0>;
	#declare t_camera = <0,18,43>;
	#declare r_light = <90,0,0>; 
	#break
#case (3)
	#declare r_camera = <-90,0,0>;
	#declare t_camera = <0,0,0>;
	#declare r_light = <90,0,0>; 
	#break
#case (4)
	#declare r_camera = <90,0,0>;
	#declare t_camera = <0,33,-36>;
	#declare r_light = <90,0,0>;
	#break
#case (5)
	#declare r_camera = <-10,90,0>;
	#declare t_camera = <-33,2,0>;
	#declare r_light = <90,0,0>;
	#break
#case (6)
	#declare r_camera = <-10,-90,0>;
	#declare t_camera = <33,2,0>;
	#declare r_light = <90,0,0>;
	#break
#case (7)
	#declare r_camera = <0,0,0>;
	#declare t_camera = <-12,5,-56>;
	#declare r_light = <90,0,0>;
	#break
#case (8)
	#declare r_camera = <0,0,0>;
	#declare t_camera = <8.5,17.5,-56>;
	#declare r_light = <90,0,0>;
	#break
#case (9)
	#declare r_camera = <90,0,0>;
	#declare t_camera = <0,33,38>;
	#declare r_light = <90,0,0>;
	#break
#case (10)
	#declare r_camera = <-30,0,0>;
	#declare t_camera = <0,2,50>;
	#declare r_light = <90,0,0>;
	#break
#end   

//----- INCLUSSIONS
#include "definitions.inc"
#include "textures.inc"
#include "basic_objects.inc"
#include "environment.inc"
#include "main_object.inc"

object {Cathedral()}
