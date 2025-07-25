//----- RANDOM POSITIONING OF THE CAMERA
//      (AND SUN IF IT APPLIES)

#local r1=seed(9876*(frame_number+1));
#local good = false;
#while (!good)
	#local good = true;
	#local cx = 66.32*rand(r1)-33.16;
	#local cz = 130.41*rand(r1)-69.64;
	#local cy = 23.76*rand(r1);
	#if (cx<-16.415 & cz<-14.195)
		#local good = false;
	#end
	#if (cx>16.415 & cz<-14.195)
		#local good = false;
	#end
	#if (cx<-24.87 & cz>13.81)
		#local good = false;
	#end
	#if (cx>24.87 & cz>13.81)
		#local good = false;
	#end
	#if (cx<-8.29 & cz<-7.18 & cy>9.08)
		#local good = false;
	#end
	#if (cx>8.29 & cz<-7.18 & cy>9.08)
		#local good = false;
	#end
	#if (cx<-8.29 & cz>7.18 & cy>9.08)
		#local good = false;
	#end
	#if (cx>8.29 & cz>7.18 & cy>9.08)
		#local good = false;
	#end
	#if (good)                
		#declare t_camera = <cx,cy,cz>;
		#declare r_camera = <90*rand(r1)-45,360*rand(r1),0>;
		#declare r_light  = <40*rand(r1)+30,r_camera.y+90+180*rand(r1),0>;    
		          
		#debug "\n"
		#debug concat("Camera position: <", vstr(3,t_camera,",",0,2),">\n")
		#debug concat("Camera rotation: <", vstr(3,r_camera,",",0,2),">\n")
		#debug concat("Sun rotation   : <", vstr(3,r_light,",",0,2),">\n\n")
	#end
#end
