//----- MAIN OBJECT
             
#include "show_object.inc"

#macro Cathedral()

	#declare n_bricks = 0;

	union {
		
		#if (show_transept)
			union {
				object {show_object("transept_floor",0,0,0,0)}
				object {show_object("transept_columns",0,0,0,0)}
				object {show_object("transept_arcade",0,9.28*y,0,0)}
				object {show_object("transept_triforium",0,15.68*y,0,0)}
				object {show_object("transept_clerestory",0,19.81*y,0,0)}
				object {show_object("transept_aisle",0,0,0,0)}
				object {show_object("transept_vault",0,23.76*y,0,0)}
			}
		#end
		#if (show_nave)
			union {
				object {show_object("nave_floor",0,0,180*y,-14.36*z)}
				object {show_object("nave_columns",0,0,180*y,-14.36*z)}
				object {show_object("nave_arcade",0,9.28*y,180*y,-14.36*z)}
				object {show_object("nave_triforium",0,15.68*y,180*y,-14.36*z)}
				object {show_object("nave_clerestory",0,19.81*y,180*y,-14.36*z)}
				object {show_object("nave_aisle",0,14.36*z,180*y,0)}
				object {show_object("nave_vault",0,23.76*y,180*y,-14.36*z)}
			}
		#end
		#if (show_choir)
			union {
				object {show_object("choir_floor",0,0,0,14.36*z)}
				object {show_object("choir_columns",0,0,0,14.36*z)}
				object {show_object("choir_arcade",0,9.28*y,0,14.36*z)}
				object {show_object("choir_triforium",0,15.68*y,0,14.36*z)}
				object {show_object("choir_clerestory",0,19.81*y,0,14.36*z)}
				object {show_object("choir_aisle",0,0,0,14.36*z)}
				object {show_object("choir_vault",0,23.76*y,0,14.36*z)}
			}
		#end
		#if (show_ambulatory)
			union {
				object {show_object("ambulatory_floor",0,0,0,14.58*z)}
				object {show_object("ambulatory_columns",0,21.54*z,0,14.58*z)}
				object {show_object("ambulatory_vault",0,<0,9.28,21.54>,0,14.58*z)}
			}
		#end
		#if (show_chapels)
			union {
				object {show_object("chapels_floor",0,0,0,36.12*z)}
				object {show_object("chapels_aisle",0,0,0,36.12*z)}
				object {show_object("chapels_units",0,0.6*y,0,36.12*z)}
			}
		#end
		#if (show_main_facade)
			union {
				object {show_object("main_facade_floor",0,0,180*y,-57.44*z)}
				object {show_object("main_facade_north",-90*y,<-8.9,-1,6>,180*y,-57.44*z)}
				object {show_object("main_facade_south"90*y,<8.9,-1,6>,180*y,-57.44*z)}
				object {show_object("main_facade_front",0,<0,-1,12.2>,180*y,-57.44*z)}
				object {show_object("main_facade_vault",0,23.76*y,180*y,-57.44*z)}
			}
		#end
		#if (show_north_porch)
			object {show_object("north_porch",-90*y,-33.3*x,0,0)}
		#end
		#if (show_south_porch)
			object {show_object("south_porch",90*y,33.3*x,0,0)}
		#end

		union {
			box {<-8,34.6,-70> <8,34.7,36>} 
			box {<-34,34.6,-8> <34,34.7,7>}   
			box {<-9,14.8,-57.5> <-17,14.9,-15>}
			box {<9,14.8,-57.5> <17,14.9,-15>}
			box {<-34,14.8,-15> <-9,14.9,-8>}
			box {<34,14.8,-15> <9,14.9,-8>}      
			box {<-34,14.8,7> <-9,14.9,14>}
			box {<34,14.8,7> <9,14.9,14>}
			box {<-9,14.8,14> <-25.5,14.9,36>}
			box {<9,14.8,14> <25.5,14.9,36>}
			cylinder {<0,34.6,36> <0,34.7,36> 8} 
			difference {
				cylinder {<0,14.8,36> <0,14.9,36> 25.5}
				cylinder {<0,14.7,36> <0,15,36> 9}
				box {<-37,14.7,36> <37,15,10>}
			}
			cylinder {<0,14.8,60.6> <0,14.9,60.6> 4.4}
			cylinder {<0,14.8,24.6> <0,14.9,24.6> 4.4 rotate 45.48*y translate 36*z}
			cylinder {<0,14.8,24.6> <0,14.9,24.6> 4.4 rotate -45.48*y translate 36*z}
			pigment {rgb 1}
			finish {ambient v_ambient diffuse v_diffuse}
		}

		#debug "----------------------------------\n"
		#debug concat(str(n_bricks,0,0)," BRICKS!\n")
		#debug "----------------------------------\n"
	}
#end
