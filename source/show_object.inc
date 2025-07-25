//----- CHECKS IF AN OBJECT IS VISIBLE AND RENDERS IT
//      IN HIGH OR LOW QUALITY DEPENDING ON VISIBILITY
//      AND DISTANCE

#macro sel_object(obj_name)
	#include concat(obj_name,".inc")

	#if (strcmp(obj_name,"transept_floor")=0)
		transept_floor()
	#end
	#if (strcmp(obj_name,"transept_columns")=0)
		transept_columns()
	#end
	#if (strcmp(obj_name,"transept_arcade")=0)
		transept_arcade()
	#end
	#if (strcmp(obj_name,"transept_triforium")=0)
		transept_triforium()
	#end
	#if (strcmp(obj_name,"transept_clerestory")=0)
		transept_clerestory()
	#end
	#if (strcmp(obj_name,"transept_aisle")=0)
		transept_aisle()
	#end
	#if (strcmp(obj_name,"transept_vault")=0)
		transept_vault()
	#end
	#if (strcmp(obj_name,"nave_floor")=0)
		nave_floor()
	#end
	#if (strcmp(obj_name,"nave_columns")=0)
		nave_columns()
	#end
	#if (strcmp(obj_name,"nave_arcade")=0)
		nave_arcade()
	#end
	#if (strcmp(obj_name,"nave_triforium")=0)
		nave_triforium()
	#end
	#if (strcmp(obj_name,"nave_clerestory")=0)
		nave_clerestory()
	#end
	#if (strcmp(obj_name,"nave_aisle")=0)
		nave_aisle()
	#end
	#if (strcmp(obj_name,"nave_vault")=0)
		nave_vault()
	#end
	#if (strcmp(obj_name,"choir_floor")=0)
		choir_floor()
	#end
	#if (strcmp(obj_name,"choir_columns")=0)
		choir_columns()
	#end
	#if (strcmp(obj_name,"choir_arcade")=0)
		choir_arcade()
	#end
	#if (strcmp(obj_name,"choir_triforium")=0)
		choir_triforium()
	#end
	#if (strcmp(obj_name,"choir_clerestory")=0)
		choir_clerestory()
	#end
	#if (strcmp(obj_name,"choir_aisle")=0)
		choir_aisle()
	#end
	#if (strcmp(obj_name,"choir_vault")=0)
		choir_vault()
	#end
	#if (strcmp(obj_name,"ambulatory_floor")=0)
		ambulatory_floor()
	#end
	#if (strcmp(obj_name,"ambulatory_columns")=0)
		ambulatory_columns()
	#end
	#if (strcmp(obj_name,"ambulatory_vault")=0)
		ambulatory_vault()
	#end
	#if (strcmp(obj_name,"chapels_floor")=0)
		chapels_floor()
	#end
	#if (strcmp(obj_name,"chapels_aisle")=0)
		chapels_aisle()
	#end
	#if (strcmp(obj_name,"chapels_units")=0)
		chapels_units()
	#end
	#if (strcmp(obj_name,"main_facade_floor")=0)
		main_facade_floor()
	#end
	#if (strcmp(obj_name,"main_facade_front")=0)
		main_facade_front()
	#end
	#if (strcmp(obj_name,"main_facade_north")=0)
		main_facade_north()
	#end
	#if (strcmp(obj_name,"main_facade_south")=0)
		main_facade_south()
	#end
	#if (strcmp(obj_name,"main_facade_vault")=0)
		main_facade_vault()
	#end
	#if (strcmp(obj_name,"north_porch")=0)
		north_porch()
	#end
	#if (strcmp(obj_name,"south_porch")=0)
		south_porch()
	#end
#end

#macro show_object(obj_name,r1,t1,r2,t2)
	#debug obj_name

	#local obj = sel_object(obj_name)
	#local obj0 = box {min_extent(obj) max_extent(obj) rotate r1 translate t1 rotate r2 translate t2};
	#local dist=1000;
	#local i=0;
	#while (i<1000)
		#local v0=vrotate(z,<r_camera.x+45.2*rand(rr)-22.6,r_camera.y+67.2*rand(rr)-33.6,r_camera.z>);
		#local d0=trace(obj0,t_camera,v0);
		#local dist=min(dist,vlength(t_camera-d0));
		#local i=i+1;
	#end

	#local asb = show_bricks;
	#local asd = show_details;
	#if ((!show_bricks & !show_details & !show_ornaments & !show_normals) | dist=1000) // if not visible
		#declare show_bricks = off;
		#declare show_details = off;
		#debug " (low detail)\n"
	#else
		#if (dist>20) // if far
			#declare show_details = off;
			#debug " (medium detail)\n"
		#else
			#debug " (high detail)\n"
		#end
	#end
	object {sel_object(obj_name) rotate r1 translate t1 rotate r2 translate t2}
	#declare show_bricks = asb;
	#declare show_details = asd;
#end
