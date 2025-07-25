//----- MISCELANEOUS BASIC OBJECTS ------------------------------------------------------
#include "glass.inc"  
#include "meshes.inc"
#declare ddd=0.05;

#macro null()
	box {
		0 dd
		pigment {color rgbt<1,1,1,1>}
		no_radiosity
		no_reflection
		no_shadow
	}
#end

//--- Solid block with gothic arch shape (to make holes)
//     r: radio
//     n: order
//     l: length
#macro gothic_arch(r,n,l)
	union {
		intersection {
			cylinder {
				<0,0,-l/2>
				<0,0,l/2>
				n*r
			}		
			box {
				<-(n-1)*r+dd,0,l>
				<-100,100,-2*l>
			}
			translate (n-1)*r*x
		}
		intersection {
			cylinder {
				<0,0,-l/2>
				<0,0,l/2>
				n*r
			}		
			box {
				<(n-1)*r-dd,0,l>
				<100,100,-2*l>
			}
			translate -(n-1)*r*x
		}
		box {<-r,dd,-l/2> <r,-5,l/2>}
	}
#end


//--- Flat square object
//		 a,b,c,d: Vertices
#macro Square(a,b,c,d)
	mesh {
		triangle {a b c}
		triangle {a d c}
	}
#end


//----- SIMPLE BLOCKS -------------------------------------------------------------------

//--- Squared block
//		 l: Length (x)
//		 h: Height (y)
//		 w: Width (z)
//		 p: Type
//		 m: Is mortar
#macro Block_squ(l,h,w,p,m)
	#if (show_details)
		#if (m)
			#local sp=s[p]-d[p];
		#else
			#local sp=s[p];
		#end

		isosurface {
			function {
				f_rounded_box(x,y,z,sp,l/2,h/2,w/2)
			}
			contained_by {
				box {
					<-l/2-dd,-h/2-dd,-w/2-dd>
					<l/2+dd,h/2+dd,w/2+dd>
				}
			} 
			translate h/2*y
			texture {T_Block(p,m)}       
		}
/*
		union {
			sphere {<-l/2+sp,sp,-w/2+sp> sp}
			sphere {<-l/2+sp,sp,w/2-sp> sp}
			sphere {<l/2-sp,sp,-w/2+sp> sp}
			sphere {<l/2-sp,sp,w/2-sp> sp}
			sphere {<-l/2+sp,h-sp,-w/2+sp> sp}
			sphere {<-l/2+sp,h-sp,w/2-sp> sp}
			sphere {<l/2-sp,h-sp,-w/2+sp> sp}
			sphere {<l/2-sp,h-sp,w/2-sp> sp}
			#if (w>2*sp)
				cylinder {<-l/2+sp,sp,-w/2+sp> <-l/2+sp,sp,w/2-sp> sp}
				cylinder {<l/2-sp,sp,-w/2+sp> <l/2-sp,sp,w/2-sp> sp}
				cylinder {<-l/2+sp,h-sp,-w/2+sp> <-l/2+sp,h-sp,w/2-sp> sp}
				cylinder {<l/2-sp,h-sp,-w/2+sp> <l/2-sp,h-sp,w/2-sp> sp}
			#end
			#if (l>2*sp)
				cylinder {<-l/2+sp,sp,-w/2+sp> <l/2-sp,sp,-w/2+sp> sp}
				cylinder {<-l/2+sp,sp,w/2-sp> <l/2-sp,sp,w/2-sp> sp}
				cylinder {<-l/2+sp,h-sp,-w/2+sp> <l/2-sp,h-sp,-w/2+sp> sp}
				cylinder {<-l/2+sp,h-sp,w/2-sp> <l/2-sp,h-sp,w/2-sp> sp}
			#end
			#if (h>2*sp)
				cylinder {<-l/2+sp,sp,-w/2+sp> <-l/2+sp,h-sp,-w/2+sp> sp}
				cylinder {<-l/2+sp,sp,w/2-sp> <-l/2+sp,h-sp,w/2-sp> sp}
				cylinder {<l/2-sp,sp,-w/2+sp> <l/2-sp,h-sp,-w/2+sp> sp}
				cylinder {<l/2-sp,sp,w/2-sp> <l/2-sp,h-sp,w/2-sp> sp}
			#end
			box {<-l/2,sp,-w/2+sp> <l/2,h-sp,w/2-sp>}
			box {<-l/2+sp,0,-w/2+sp> <l/2-sp,h,w/2-sp>}
			box {<-l/2+sp,sp,-w/2> <l/2-sp,h-sp,w/2>}
			texture {T_Block(p,m)}			
		}
*/
	#else
		box {
			<0,0,0>
			<l,h,w>
			translate <-l/2,0,-w/2>
			texture {T_Block(p,m)}
		}
	#end
	#declare n_bricks = n_bricks+1;
#end


//--- Cylindrical block
//		 r: Radius (x-z)
//		 h: Height (y)
//		 p: Type
//		 m: Is mortar
#macro Block_cyl(r,h,p,m)
	#if (show_details)
		#if (m)
			#local sp=s[p]-d[p];
		#else
			#local sp=s[p];
		#end
		union {
			torus {r-sp sp translate sp*y}
			torus {r-sp sp translate (h-sp)*y}
			cylinder {<0,sp,0> <0,h-sp,0> r}
			cylinder {<0,0,0> <0,h,0> r-sp}
			texture {T_Block(p,m)}
		}
	#else
		cylinder {
			<0,0,0>
			<0,h,0>
			r
			texture {T_Block(p,m)}
		}
	#end
	#declare n_bricks = n_bricks+1;
#end


//--- Octogonal block
//		 r: Radius (x-z) (from the center to the mid point of one side)
//		 h: Height (y)
//		 p: Type
//		 m: Is mortar
#macro Block_oct(r,h,p,m)
	#if (show_details)
		#if (m)
			#local sp=s[p]-d[p];
		#else
			#local sp=s[p];
		#end
		#local t8 = tan(pi/8);
		union {
			#local i=0;
			#while (i<8)
				union {
					sphere {<(r-sp)*t8,sp,r-sp> sp}
					sphere {<(r-sp)*t8,h-sp,r-sp> sp}
					cylinder {<(r-sp)*t8,sp,r-sp> <(r-sp)*t8,h-sp,r-sp> sp}
					cylinder {<(r-sp)*t8,sp,r-sp> <-(r-sp)*t8,sp,r-sp> sp}
					cylinder {<(r-sp)*t8,h-sp,r-sp> <-(r-sp)*t8,h-sp,r-sp> sp}
					object {Square(<(r-sp)*t8,sp,r>,<(r-sp)*t8,h-sp,r>,<-(r-sp)*t8,h-sp,r>,<-(r-sp)*t8,sp,r>)}
					mesh {
						triangle {<0,0,0> <(r-sp)*t8,0,r-sp> <-(r-sp)*t8,0,r-sp>}
						triangle {<0,h,0> <(r-sp)*t8,h,r-sp> <-(r-sp)*t8,h,r-sp>}
					}
					rotate 45*i*y
				}
				#local i=i+1;
			#end
			texture {T_Block(p,m)}
		}
	#else
		intersection {
			box {<-r,0,-r> <r,h,r>}
			box {<-r,-dd,-r> <r,h+dd,r> rotate 45*y}
			texture {T_Block(p,m)}
		}
	#end
	#declare n_bricks = n_bricks+1;
#end


//--- Toroidal block
//		r1: Major radius
//		r2: Minor radius
//		 a: Angle of sector (0-180 degrees)
//		 p: Type
//		 m: Is mortar
#macro Block_tor(r1,r2,a,p,m)
	#if (show_details)
		#if (m)
			#local sp=s[p]-d[p];
		#else
			#local sp=s[p];
		#end
		#local a1 = degrees(atan(sp/r1));
		#if (a=360)
			torus {r1,r2 texture {T_Block(p,m)}}
		#else
			union {
				intersection {
					torus {r1 r2}
					box {<-r1-r2,-r2,0> <r1+r2,r2,r1+r2> rotate a1*y}
					box {<-r1-r2,-r2,0> <r1+r2,r2,-r1-r2> rotate (a-a1)*y}
					bounded_by {box {<-(r1+r2),-r2,0> <-(r1+r2)*cos(radians(max(90,a)))-(r1-r2)*cos(radians(min(90,a))),r2,(r1+r2)*sin(radians(min(90,a)))>}}
				}
				torus {r2-sp sp rotate -90*x translate <-r1,0,sp>}
				torus {r2-sp sp rotate -90*x translate <-r1,0,-sp> rotate a*y}
				texture {T_Block(p,m)}
			}
		#end
	#else
		#if (a=360)
			torus {r1,r2 texture {T_Block(p,m)}}
		#else
			difference {
				torus {r1 r2}
				box {<-r1-r2,-r2,0> <r1+r2,r2,-r1-r2>}
				box {<-r1-r2,-r2,0> <r1+r2,r2,r1+r2> rotate a*y}
				texture {T_Block(p,m)}
				bounded_by {box {<-(r1+r2),-r2,0> <-(r1+r2)*cos(radians(max(90,a)))-(r1-r2)*cos(radians(min(90,a))),r2,(r1+r2)*sin(radians(min(90,a)))>}}
			}
		#end
	#end
	#declare n_bricks = n_bricks+1;
#end


//--- Ring block
//		r1: External radius
//		r2: Internal radius
//     h: Height
//		 a: Angle of sector (0-180 degrees)
//		 p: Type
//		 m: Is mortar
#macro Block_rin(r1,r2,h,a,p,m)
	#if (show_details)
		#if (m)
			#local sp=s[p]-d[p];
		#else
			#local sp=s[p];
		#end
		#local a1 = degrees(atan(sp/r1));
		union {
			#local i=0;
			#while (i<2)
				union {
					sphere {<-r1+sp,-h/2+sp,sp> sp}
					sphere {<-r1+sp,h/2-sp,sp> sp}
					sphere {<-r2-sp,-h/2+sp,sp> sp}
					sphere {<-r2-sp,h/2-sp,sp> sp}
					cylinder {<-r1+sp,-h/2+sp,sp> <-r1+sp,h/2-sp,sp> sp}
					cylinder {<-r1+sp,-h/2+sp,sp> <-r2-sp,-h/2+sp,sp> sp}
					cylinder {<-r2-sp,h/2-sp,sp> <-r1+sp,h/2-sp,sp> sp}
					cylinder {<-r2-sp,h/2-sp,sp> <-r2-sp,-h/2+sp,sp> sp}
					rotate (a-2*a1)*i*y
				}
				#local i=i+1;
			#end
			intersection {
				union {
					torus {r1-sp sp translate (h/2-sp)*y}
					torus {r2+sp sp translate (h/2-sp)*y}
					torus {r1-sp sp translate (-h/2+sp)*y}
					torus {r2+sp sp translate (-h/2+sp)*y}
					difference {
						cylinder {<0,-h/2,0> <0,h/2,0> r1-sp}
						cylinder {<0,-dd-h/2,0> <0,dd+h/2,0> r2+sp}
					}
					difference {
						cylinder {<0,-h/2+sp,0> <0,h/2-sp,0> r1}
						cylinder {<0,-dd-h/2+sp,0> <0,dd+h/2-sp,0> r2}
					}
				}
				box {<-r1-r2,-r2,0> <r1+r2,r2,r1+r2> rotate a1*y}
				box {<-r1-r2,-r2,0> <r1+r2,r2,-r1-r2> rotate (a-a1)*y}
				bounded_by {box {<-r1,-h/2,0> <-r1*cos(radians(max(90,a)))-r2*cos(radians(min(90,a))),h/2,r1*sin(radians(min(90,a)))>}}
			}			
			texture {T_Block(p,m)}
		}
	#else
		difference {
			cylinder {<0,-h/2,0> <0,h/2,0> r1}
			cylinder {<0,-dd-h/2,0> <0,dd+h/2,0> r2}
			box {<-r1,-dd-h/2,0> <r1,dd+h/2,-r1>}
			box {<-r1,-2*dd-h/2,0> <r1,2*dd+h/2,r1> rotate a*y}
			bounded_by {box {<-r1,-h/2,0> <-r1*cos(radians(max(90,a)))-r2*cos(radians(min(90,a))),h/2,r1*sin(radians(min(90,a)))>}}
			texture {T_Block(p,m)}
		}
	#end
	#declare n_bricks = n_bricks+1;
#end


//--- "Octogonal torus" like block 
//		r1: Major radius
//		r2: Minor radius
//		 p: Type
//		 m: Is mortar
#macro Block_octcyl(r1,r2,p,m)
	union {
		#local i=0;
		#while (i<8)
			intersection {
				cylinder {<-r1,0,-r1> <r1,0,-r1> r2}
				box {<0,-r2,0> <2*r1,r2,-2*r1> rotate 22.5*y}
				box {<0,-r2,0> <-2*r1,r2,-2*r1> rotate -22.5*y}
				rotate 45*i*y
			}				
			#local i=i+1;
		#end
		texture {T_Block(p,m)}
	}
	#declare n_bricks = n_bricks+1;
#end


//--- Pyramidal block
//		l1: Lower length (x)
//		w1: Lower width (z)
//		l2: Upper length (x)
//		w2: Upper width (z)
//		 h: Height
//		 p: Type
//		 m: Is mortar
#macro Block_pyr(l1,w1,l2,w2,h,p,m)
	#if (show_details)
		#if (m)
			#local sp=s[p]-d[p];
		#else
			#local sp=s[p];
		#end
		#local dl1 = sp/tan(atan(2*h/(l1-l2))/2);
		#local dw1 = sp/tan(atan(2*h/(w1-w2))/2);
		#local dl2 = sp/tan((pi-atan(2*h/(l1-l2)))/2);
		#local dw2 = sp/tan((pi-atan(2*h/(w1-w2)))/2);
		#local hl = sqrt((h-2*sp)*(h-2*sp)+((l1-l2)/2-dl1+dl2)*((l1-l2)/2-dl1+dl2));
		#local hw = sqrt((h-2*sp)*(h-2*sp)+((w1-w2)/2-dw1+dw2)*((w1-w2)/2-dw1+dw2));
		#local al = 90-degrees(atan((h-2*sp)/((l1-l2)/2-dl1+dl2)));
		#local aw = 90-degrees(atan((h-2*sp)/((w1-w2)/2-dw1+dw2)));
		union {  
			#local i=0;
			#while (i<2) 
				union {
					sphere {<l1/2-dl1,sp,w1/2-dw1> sp}
					sphere {<l1/2-dl1,sp,-w1/2+dw1> sp}
					cylinder {<l1/2-dl1,sp,w1/2-dw1> <l1/2-dl1,sp,-w1/2+dw1> sp}
					cylinder {<l1/2-dl1,sp,-w1/2+dw1> <-l1/2+dl1,sp,-w1/2+dw1> sp}
					cylinder {<l2/2-dl2,h-sp,w2/2-dw2> <l2/2-dl2,h-sp,-w2/2+dw2> sp}
					cylinder {<l2/2-dl2,h-sp,-w2/2+dw2> <-l2/2+dl2,h-sp,-w2/2+dw2> sp}
					object {Square(<l1/2-dl1,0,w1/2-dw1>,<l1/2-dl1,0,-w1/2+dw1>,<-l1/2+dl1,0,-w1/2+dw1>,<-l1/2+dl1,0,w1/2-dw1>)}
					object {Square(<l2/2-dl2,h,w2/2-dw2>,<l2/2-dl2,h,-w2/2+dw2>,<-l2/2+dl2,h,-w2/2+dw2>,<-l2/2+dl2,h,w2/2-dw2>)}
					union {
						sphere {<0,hl,w2/2-dw2> sp}
						sphere {<0,hl,-w2/2+dw2> sp}
						cylinder {<0,0,w1/2-dw1> <0,hl,w2/2-dw2> sp} 
						cylinder {<0,0,-w1/2+dw1> <0,hl,-w2/2+dw2> sp} 
						object {Square(<sp,0,w1/2-dw1>,<sp,0,-w1/2+dw1>,<sp,hl,-w2/2+dw2>,<sp,hl,w2/2-dw2>)}
						rotate al*z translate <(l1/2-dl1),sp,0>
					}
					object {Square(<l1/2-dl1,0,sp>,<-l1/2+dl1,0,sp>,<-l2/2+dl2,hw,sp>,<l2/2-dl2,hw,sp>) rotate -aw*x translate <0,sp,(w1/2-dw1)>}
					rotate 180*i*y
				}
				#local i=i+1;
			#end
			texture {T_Block(p,m)}
		}
	#else
		union {
			object {Square(<-l1/2,0,-w1/2>,<-l2/2,h,-w2/2>,<l2/2,h,-w2/2>,<l1/2,0,-w1/2>)}
			object {Square(<-l1/2,0,w1/2>,<-l2/2,h,w2/2>,<l2/2,h,w2/2>,<l1/2,0,w1/2>)}
			object {Square(<-l1/2,0,-w1/2>,<-l2/2,h,-w2/2>,<-l2/2,h,w2/2>,<-l1/2,0,w1/2>)}
			object {Square(<l1/2,0,-w1/2>,<l2/2,h,-w2/2>,<l2/2,h,w2/2>,<l1/2,0,w1/2>)}
			object {Square(<-l2/2,h,-w2/2>,<-l2/2,h,w2/2>,<l2/2,h,w2/2>,<l2/2,h,-w2/2>)}
			texture {T_Block(p,m)}
		}
	#end
	#declare n_bricks = n_bricks+1;
#end


//--- Irregular block number 1
//		l1: Major length (x)
//		l2: Minor length (x)
//		w1: Major width (z)
//		w2: Minor width (z)
//		 h: Height
//		 p: Type
//		 m: Is mortar
#macro Block_ir1(l1,l2,w1,w2,h,p,m)
	#if (show_details)
		#if (m)
			#local sp=s[p]-d[p];
		#else
			#local sp=s[p];
		#end
		#local a1 = atan((l1-l2)/(w1-w2)/2);
		#local dl1 = sp/tan((pi-a1)/2);
		#local dl2 = sp/tan((pi/2+a1)/2);
		#local a2 = degrees(atan((dl2-sp+(l1-l2)/2)/(dl1-sp+w1-w2)));
		#local l3 = sqrt((dl2-sp+(l1-l2)/2)*(dl2-sp+(l1-l2)/2)+(dl1-sp+w1-w2)*(dl1-sp+w1-w2));
		union {
			sphere {<-l1/2+sp,sp,-sp> sp}
			sphere {<l1/2-sp,sp,-sp> sp}
			sphere {<l1/2-sp,sp,-w2+dl1> sp}
			sphere {<l2/2-dl2,sp,-w1+sp> sp}
			sphere {<-l2/2+dl2,sp,-w1+sp> sp}
			sphere {<-l1/2+sp,sp,-w2+dl1> sp}			
			
			sphere {<-l1/2+sp,h-sp,-sp> sp}
			sphere {<l1/2-sp,h-sp,-sp> sp}
			sphere {<l1/2-sp,h-sp,-w2+dl1> sp}
			sphere {<l2/2-dl2,h-sp,-w1+sp> sp}			
			sphere {<-l2/2+dl2,h-sp,-w1+sp> sp}
			sphere {<-l1/2+sp,h-sp,-w2+dl1> sp}			
			
			cylinder {<-l1/2+sp,sp,-sp> <l1/2-sp,sp,-sp> sp}
			cylinder {<l1/2-sp,sp,-sp> <l1/2-sp,sp,-w2+dl1> sp}
			cylinder {<l1/2-sp,sp,-w2+dl1> <l2/2-dl2,sp,-w1+sp> sp}
			cylinder {<l2/2-dl2,sp,-w1+sp> <-l2/2+dl2,sp,-w1+sp> sp}
			cylinder {<-l2/2+dl2,sp,-w1+sp> <-l1/2+sp,sp,-w2+dl1> sp}
			cylinder {<-l1/2+sp,sp,-w2+dl1> <-l1/2+sp,sp,-sp> sp}			
			
			cylinder {<-l1/2+sp,h-sp,-sp> <l1/2-sp,h-sp,-sp> sp}
			cylinder {<l1/2-sp,h-sp,-sp> <l1/2-sp,h-sp,-w2+dl1> sp}
			cylinder {<l1/2-sp,h-sp,-w2+dl1> <l2/2-dl2,h-sp,-w1+sp> sp}
			cylinder {<l2/2-dl2,h-sp,-w1+sp> <-l2/2+dl2,h-sp,-w1+sp> sp}
			cylinder {<-l2/2+dl2,h-sp,-w1+sp> <-l1/2+sp,h-sp,-w2+dl1> sp}
			cylinder {<-l1/2+sp,h-sp,-w2+dl1> <-l1/2+sp,h-sp,-sp> sp}			
			
			cylinder {<-l1/2+sp,sp,-sp> <-l1/2+sp,h-sp,-sp> sp}
			cylinder {<l1/2-sp,sp,-sp> <l1/2-sp,h-sp,-sp> sp}
			cylinder {<l1/2-sp,sp,-w2+dl1> <l1/2-sp,h-sp,-w2+dl1> sp}
			cylinder {<l2/2-dl2,sp,-w1+sp> <l2/2-dl2,h-sp,-w1+sp> sp}
			cylinder {<-l2/2+dl2,sp,-w1+sp> <-l2/2+dl2,h-sp,-w1+sp> sp}
			cylinder {<-l1/2+sp,sp,-w2+dl1> <-l1/2+sp,h-sp,-w2+dl1> sp}			
			
			object {Square(<-l1/2+sp,sp,0>,<l1/2-sp,sp,0>,<l1/2-sp,h-sp,0>,<-l1/2+sp,h-sp,0>)}			
			object {Square(<-l1/2,sp,-sp>,<-l1/2,sp,-w2+dl1>,<-l1/2,h-sp,-w2+dl1>,<-l1/2,h-sp,-sp>)}
			object {Square(<l1/2,sp,-sp>,<l1/2,sp,-w2+dl1>,<l1/2,h-sp,-w2+dl1>,<l1/2,h-sp,-sp>)}
			object {Square(<-sp,sp,0>,<-sp,sp,-l3>,<-sp,h-sp,-l3>,<-sp,h-sp,0>) rotate -a2*y translate <-l1/2+sp,0,-w2+dl1>}
			object {Square(<sp,sp,0>,<sp,sp,-l3>,<sp,h-sp,-l3>,<sp,h-sp,0>) rotate a2*y translate <l1/2-sp,0,-w2+dl1>}
			object {Square(<-l2/2+dl2,sp,-w1>, <l2/2-dl2,sp,-w1>,<l2/2-dl2,h-sp,-w1>,<-l2/2+dl2,h-sp,-w1>)}
			texture {T_Block(p,m)}
		}
	#else
		prism {
			0, h, 7,
			<l1/2,0> <l1/2,-w2> <l2/2,-w1>
			<-l2/2,-w1> <-l1/2,-w2> <-l1/2,0>
			<l1/2,0>
			texture {T_Block(p,m)}
		}
	#end
	#declare n_bricks = n_bricks+1;
#end


//--- Irregular block number 2
//		l1: Major length (x)
//		l2: Minor length (x)
//		w1: Major width (z)
//		w2: Minor width (z)
//		 h: Height
//    sx: Orientation x
//    sz: Orientation z
//		 p: Type
//		 m: Is mortar
#macro Block_ir2(l1,l2,w1,w2,h,sx,sz,p,m)
	#if (show_details)
		#if (m)
			#local sp=s[p]-d[p];
		#else
			#local sp=s[p];
		#end
		#local a1 = atan((l1-l2)/(w1-w2));
		#local dl1 = sp/tan((pi-a1)/2);
		#local dl2 = sp/tan((pi/2+a1)/2);
		#local a2 = degrees(atan((dl2-sp+l1-l2)/(dl1-sp+w1-w2)));
		#local l3 = sqrt((dl2-sp+l1-l2)*(dl2-sp+l1-l2)+(dl1-sp+w1-w2)*(dl1-sp+w1-w2));
		union {
			sphere {<sp,sp,-sp> sp}
			sphere {<l1-sp,sp,-sp> sp}
			sphere {<l1-sp,sp,-w2+dl1> sp}
			sphere {<l2-dl2,sp,-w1+sp> sp}
			sphere {<sp,sp,-w1+sp> sp}
			
			sphere {<sp,h-sp,-sp> sp}
			sphere {<l1-sp,h-sp,-sp> sp}
			sphere {<l1-sp,h-sp,-w2+dl1> sp}
			sphere {<l2-dl2,h-sp,-w1+sp> sp}
			sphere {<sp,h-sp,-w1+sp> sp}
			
			cylinder {<sp,sp,-sp> <l1-sp,sp,-sp> sp}
			cylinder {<l1-sp,sp,-sp> <l1-sp,sp,-w2+dl1> sp}
			cylinder {<l1-sp,sp,-w2+dl1> <l2-dl2,sp,-w1+sp> sp}
			cylinder {<l2-dl2,sp,-w1+sp> <sp,sp,-w1+sp> sp}
			cylinder {<sp,sp,-w1+sp> <sp,sp,-sp> sp}
			
			cylinder {<sp,h-sp,-sp> <l1-sp,h-sp,-sp> sp}
			cylinder {<l1-sp,h-sp,-sp> <l1-sp,h-sp,-w2+dl1> sp}
			cylinder {<l1-sp,h-sp,-w2+dl1> <l2-dl2,h-sp,-w1+sp> sp}
			cylinder {<l2-dl2,h-sp,-w1+sp> <sp,h-sp,-w1+sp> sp}
			cylinder {<sp,h-sp,-w1+sp> <sp,h-sp,-sp> sp}
			
			cylinder {<sp,sp,-sp> <sp,h-sp,-sp> sp}
			cylinder {<l1-sp,sp,-sp> <l1-sp,h-sp,-sp> sp}
			cylinder {<l1-sp,sp,-w2+dl1> <l1-sp,h-sp,-w2+dl1> sp}
			cylinder {<l2-dl2,sp,-w1+sp> <l2-dl2,h-sp,-w1+sp> sp}
			cylinder {<sp,sp,-w1+sp> <sp,h-sp,-w1+sp> sp}
			
			object {Square(<sp,sp,0>,<l1-sp,sp,0>,<l1-sp,h-sp,0>,<sp,h-sp,0>)}			
			object {Square(<0,sp,-sp>,<0,sp,-w1+sp>,<0,h-sp,-w1+sp>,<0,h-sp,-sp>)}
			object {Square(<l1,sp,-sp>,<l1,sp,-w2+dl1>,<l1,h-sp,-w2+dl1>,<l1,h-sp,-sp>)}
			object {Square(<sp,sp,0>,<sp,sp,-l3>,<sp,h-sp,-l3>,<sp,h-sp,0>) rotate a2*y translate <l1-sp,0,-w2+dl1>}
			object {Square(<sp,sp,-w1>, <l2-dl2,sp,-w1>,<l2-dl2,h-sp,-w1>,<sp,h-sp,-w1>)}			
			texture {T_Block(p,m)}
			#if (sx=-1)
				rotate 180*z
				translate h*y
			#end
			#if (sz=-1)
				rotate 180*x
				translate h*y
			#end
		}
	#else
		prism {
			0, h, 6,
			<0,0> <0,-w1>
			<l2,-w1> <l1,-w2> <l1,0>
			<0,0>
			texture {T_Block(p,m)}
			#if (sx=-1)
				rotate 180*z
				translate h*y
			#end
			#if (sz=-1)
				rotate 180*x
				translate h*y
			#end
		}
	#end
	#declare n_bricks = n_bricks+1;
#end


//--- Irregular block number 3
//		l1: Major length (x)
//		l2: Minor length (x)
//		w1: Major width (z)
//		w2: Minor width (z)
//		 a: Angle of sector (0-180 degrees)
//		 r: Radius
//		 p: Type
//		 m: Is mortar
#macro Block_ir3(l1,l2,w1,w2,a,r,p,m)
	#if (show_details)
		#if (m)
			#local sp=s[p]-d[p];
		#else
			#local sp=s[p];
		#end
		#local a1 = atan((l1-l2)/(w1-w2));
		#local dl1 = sp/tan((pi-a1)/2);
		#local dl2 = sp/tan((pi/2+a1)/2);
		union {
			#local i=0;
			#while (i<2)
				union {
					sphere {<-r+sp,0,-sp> sp}
					sphere {<-r+l1-sp,0,-sp> sp}
					sphere {<-r+l1-sp,0,-w2+dl1> sp}
					sphere {<-r+l2-dl2,0,-w1+sp> sp}
					sphere {<-r+sp,0,-w1+sp> sp}
					cylinder {<-r+sp,0,-sp> <-r+l1-sp,0,-sp> sp}
					cylinder {<-r+l1-sp,0,-sp> <-r+l1-sp,0,-w2+dl1> sp}
					cylinder {<-r+l1-sp,0,-w2+dl1> <-r+l2-dl2,0,-w1+sp> sp}
					cylinder {<-r+l2-dl2,0,-w1+sp> <-r+sp,0,-w1+sp> sp}
					cylinder {<-r+sp,0,-w1+sp> <-r+sp,0,-sp> sp}
					translate (1-2*i)*sp*y
					rotate -min(a,180)*i*z
				}
				#local i=i+1;
			#end
			intersection {
				union {
					torus {r-sp sp rotate 90*x translate -sp*z}
					torus {r-l1+sp sp rotate 90*x translate -sp*z}
					torus {r-l1+sp sp rotate 90*x translate (-w2+dl1)*z}
					torus {r-l2+dl2 sp rotate 90*x translate (-w1+sp)*z}
					torus {r-sp sp rotate 90*x translate (-w1+sp)*z}
					difference {
						union {
							difference {
								cylinder {<0,0,-sp> <0,0,-w2+dl1> r}
								cylinder {<0,0,-sp+dd> <0,0,-w2+dl1-dd> r-l1}
							}
							difference {
								cylinder {<0,0,0> <0,0,-w1> r-sp}
								cylinder {<0,0,dd> <0,0,-w1-dd> r-l2+dl2}
							}
							difference {
								cylinder {<0,0,0> <0,0,-w1-dl2+sp> r-l2+dl2}
								cylinder {<0,0,dd> <0,0,-w1-dl2+sp-dd> r-l1+dl2}
							}
							difference {
								cylinder {<0,0,-w1+dl1> <0,0,-w2-dl1> r-l2}
								cylinder {<0,0,-w1+dl1-dd> <0,0,-w2-dl1+dd> r-l1}
							}
						}
						cone {<0,0,-w1-dd> r-l2 <0,0,-w2> r-l1}			
					}
				}
				box {<-r,0,dd> <r,r,-w1-dd> translate sp*y}
				box {<-r,0,dd> <r,-r,-w1-dd> translate -sp*y rotate -min(a,180)*z }
				bounded_by {box {<-r,0,0> <-r*cos(radians(max(90,min(a,180))))-(r-l1)*cos(radians(min(90,min(a,180)))),r*sin(radians(min(90,min(a,180)))),-w1>}}
			}
			texture {T_Block(p,m)}
		}
	#else
		difference {
			cylinder {<0,0,0> <0,0,-w1> r}
			cylinder {<0,0,dd> <0,0,-w1-dd> r-l1}
			cone {<0,0,-w1-dd> r-l2 <0,0,-w2> r-l1}
			box {<-r,0,dd> <r,-r,-w1-dd>}
			box {<-r,0,dd> <r,r,-w1-dd> rotate -min(a,180)*z}
			bounded_by {box {<-r,0,0> <-r*cos(radians(max(90,min(a,180))))-(r-l1)*cos(radians(min(90,min(a,180)))),r*sin(radians(min(90,min(a,180)))),-w1>}}
			texture {T_Block(p,m)}
		}
	#end
	#declare n_bricks = n_bricks+1;
#end


//----- STANDARD SIMPLE BLOCKS (NO MORTAR) --------------------------------------------------

//--- Standard squared block (wall type)
//		l: Length (x)
//		h: Height (y)
//		w: Width (z)
//		 p: Type
#macro nBlock_squ(l,h,w,p)
	Block_squ(l,h,w,p,NoMortar)
#end


//--- Standard squared block (column type)
//		l: Length (x)
//		h: Height (y)
//		w: Width (z)
//		 p: Type
#macro nBlock_squ2(l,h,w,p)
	Block_squ2(l,h,w,p,NoMortar)
#end


//--- Standard cylindrical block
//		 r: Radius (x-z) (from the center to the mid point of one side)
//		 h: Height (y)
//		 p: Type
#macro nBlock_cyl(r,h,p)
	Block_cyl(r,h,p,NoMortar)
#end


//--- Standard octogonal block
//		 r: Radius (x-z)
//		 h: Height (y)
//		 p: Type
#macro nBlock_oct(r,h,p)
	Block_oct(r,h,p,NoMortar)
#end


//--- Standard Toroidal block
//		r1: Major radius
//		r2: Minor radius
//		 a: Angle of sector (0-180 degrees)
//		 p: Type
#macro nBlock_tor(r1,r2,a,p)
	Block_tor(r1,r2,a,p,NoMortar)
#end


//--- Standard Ring block
//		r1: External radius
//		r2: Internal radius
//     h: Height
//		 a: Angle of sector (0-180 degrees)
//		 p: Type
#macro nBlock_rin(r1,r2,h,a,p)
	Block_rin(r1,r2,h,a,p,NoMortar)
#end


//--- Standard "Octogonal torus" like block 
//		r1: Major radius
//		r2: Minor radius
//		 p: Type
//		 m: Is mortar
#macro nBlock_octcyl(r1,r2,p)
	Block_octcyl(r1,r2,p,NoMortar)
#end


//--- Pyramidal block
//		l1: Lower length (x)
//		w1: Lower width (z)
//		l2: Upper length (x)
//		w2: Upper width (z)
//		 h: Height
//		 p: Type
//		 m: Is mortar
#macro nBlock_pyr(l1,w1,l2,w2,h,p)
	Block_pyr(l1,w1,l2,w2,h,p,NoMortar)
#end


//--- Standard irregular block number 1
//		l1: Major length (x)
//		l2: Minor length (x)
//		w1: Major width (z)
//		w2: Minor width (z)
//		 h: Height
//		 p: Type
#macro nBlock_ir1(l1,l2,w1,w2,h,p)
	Block_ir1(l1,l2,w1,w2,h,p,NoMortar)
#end


//--- Standard irregular block number 2
//		l1: Major length (x)
//		l2: Minor length (x)
//		w1: Major width (z)
//		w2: Minor width (z)
//		 h: Height
//     d: Direction
//		 p: Type
#macro nBlock_ir2(l1,l2,w1,w2,h,d,p)
	Block_ir2(l1,l2,w1,w2,h,d,p,NoMortar)
#end


//--- Standard irregular block number 3
//		l1: Major length (x)
//		l2: Minor length (x)
//		w1: Major width (z)
//		w2: Minor width (z)
//		 a: Angle of sector (0-180 degrees)
//		 r: Radius
//		 p: Type
#macro nBlock_ir3(l1,l2,w1,w2,a,r,p)
	Block_ir3(l1,l2,w1,w2,a,r,p,NoMortar)
#end


//----- COMPOSED BLOCKS (SUPER BLOCKS) --------------------------------------------------

//--- Super squared block (wall type)
//		l: Length (x)
//		h: Height (y)
//		w: Width (z)
//		l1: Maximum length of block
//		l2: Minimum length of block
//		h1: Height of one row
//		 p: Type
#macro sBlock_squ(l,h,w,l1,l2,h1,p)
	#if (show_bricks)
		union {
			#local n=ceil(h/h1);
			#local h1=h/n;
			#local init=1;
			#local i=0;
			#local num=0;
			#while (i<n)
				#local j=-l/2;
				#local init=1.5-init;
				#local dl=init*(l2+(l1-l2)*rand(rr));
				#while (j<l/2)
					object {Block_squ(min(dl,l/2-j),h1+dd,w,p,NoMortar) translate <min(dl,l/2-j)/2+j+dd,i*h1,0>}
					#local j=j+dl;
					#local dl=l2+(l1-l2)*rand(rr);
					#local num=num+1;
				#end
				#local i=i+1;
			#end
			#if (show_details & d[p]>0)
				object {Block_squ(l-2*d[p],h+s[p],w-2*d[p],p,Mortar) translate -(d[p]+s[p])*y}
				#local num=num+1;
			#end
			#if (num<2)
				object {null()}
			#end
		}
	#else
		object {Block_squ(l,h,w,p,NoMortar)}
	#end
#end


//--- Super squared block (column type)
//		l: Length (x)
//		h: Height (y)
//		w: Width (z)
//		h1: Height of one block
//		 p: Type
#macro sBlock_squ2(l,h,w,h1,p)   
	#if (show_bricks)
		union {
			#local n=ceil(h/h1);
			#local h1=h/n;
			#local i=0;
			#local num=0;  
			#while (i<n)
				object {Block_squ(l,h1+dd,w,p,NoMortar) translate i*h1*y}
				#local i=i+1;
				#local num=num+1;
			#end
			#if (show_details & d[p]>0)
				object {Block_squ(l-2*d[p],h+s[p],w-2*d[p],p,Mortar) translate -(d[p]+s[p])*y}
				#local num=num+1;
			#end
			#if (num<2)
				object {null()}
			#end
		}
	#else
		object {Block_squ(l,h,w,p,NoMortar)}
	#end
#end


//--- Super cylindrical block
//		 r: Radius (x-z) (from the center to the mid point of one side)
//		 h: Height (y)
//		h1: Height of one block
//		 p: Type
#macro sBlock_cyl(r,h,h1,p)
	#if (show_bricks)
		union {
			#local n=ceil(h/h1);
			#local h1=h/n;
			#local i=0;
			#local num=0;
			#while (i<n)
				object {Block_cyl(r,h1+dd,p,NoMortar) translate i*h1*y}
				#local i=i+1;
				#local num=num+1;
			#end
			#if (show_details & d[p]>0)
				object {Block_cyl(r-d[p],h+s[p],p,Mortar) translate -(d[p]+s[p])*y}
				#local num=num+1;
			#end
			#if (num<2)
				object {null()}
			#end
		}
	#else
		object {Block_cyl(r,h,p,NoMortar)}
	#end
#end


//--- Super octogonal block
//		 r: Radius (x-z)
//		 h: Height (y)
//		h1: Height of one block
//		 p: Type
#macro sBlock_oct(r,h,h1,p)
	#if (show_bricks)
		union {
			#local n=ceil(h/h1);
			#local h1=h/n;
			#local i=0;
			#local num=0;
			#while (i<n)
				object {Block_oct(r,h1+dd,p,NoMortar) translate i*h1*y}
				#local i=i+1;
				#local num=num+1;
			#end
			#if (show_details & d[p]>0)
				object {Block_oct(r-d[p],h+s[p],p,Mortar) translate -(d[p]+s[p])*y}
				#local num=num+1;
			#end
			#if (num<2)
				object {null()}
			#end
		}
	#else
		object {Block_oct(r,h,p,NoMortar)}
	#end
#end


//--- Super Toroidal block
//		r1: Major radius
//		r2: Minor radius
//		 a: Angle of sector (0-180 degrees)
//		l1: Length of one block
//		 p: Type
#macro sBlock_tor(r1,r2,a,l1,p)
	#if (show_bricks)
		#local a1 = 180*l1/pi/r1;
		union {
			#local n=ceil(a/a1);
			#local a1=a/n;
			#local i=0;
			#local num=0;
			#while (i<n)
				object {Block_tor(r1,r2,a1+dd,p,NoMortar) rotate i*a1*y}
				#local i=i+1;
				#local num=num+1;
			#end
			#if (show_details & d[p]>0)
				#local a2=180*s[p]/pi/r1;
				object {Block_tor(r1,r2-d[p],a+2*a2-d[p],p,Mortar) rotate -2*a2*y}
				#local num=num+1;
			#end
			#if (num<2)
				object {null()}
			#end
		}
	#else
		object {Block_tor(r1,r2,a,p,NoMortar)}
	#end
#end


//--- Super Ring block
//		r1: External radius
//		r2: Internal radius
//     h: Height
//		 a: Angle of sector (0-180 degrees)
//		l1: Length of one block
//		 p: Type
#macro sBlock_rin(r1,r2,h,a,l1,p)
	#if (show_bricks)
		#local a1 = 180*l1/pi/r1;
		union {
			#local n=ceil(a/a1);
			#local a1=a/n;
			#local i=0;
			#local num=0;
			#while (i<n)
				object {Block_rin(r1,r2,h,a1+dd,p,NoMortar) rotate i*a1*y}
				#local i=i+1;
				#local num=num+1;
			#end
			#if (show_details & d[p]>0)
				#local a2=180*s[p]/pi/r1;
				object {Block_rin(r1+d[p]+s[p],r2+d[p],h-2*d[p],a+2*a2-d[p],p,Mortar) rotate -2*a2*y}
				#local num=num+1;
			#end
			#if (num<2)
				object {null()}
			#end
		}
	#else
		object {Block_rin(r1,r2,h,a,p,NoMortar)}
	#end
#end


//--- Super irregular block number 1
//		l1: Major length (x)
//		l2: Minor length (x)
//		w1: Major width (z)
//		w2: Minor width (z)
//		 h: Height
//		h1: Height of one block
//		 p: Type
#macro sBlock_ir1(l1,l2,w1,w2,h,h1,p)
	#if (show_bricks)
		union {
			#local n=ceil(h/h1);
			#local h1=h/n;
			#local i=0;
			#local num=0;
			#while (i<n)
				object {Block_ir1(l1,l2,w1,w2,h1+dd,p,NoMortar) translate i*h1*y}
				#local i=i+1;
				#local num=num+1;
			#end
			#if (show_details & d[p]>0)
				object {Block_ir1(l1-2*d[p],l2-2*d[p],w1-2*d[p],w2-2*d[p],h+s[p],p,Mortar) translate <0,-(d[p]+s[p]),-d[p]>}
				#local num=num+1;
			#end
			#if (num<2)
				object {null()}
			#end
		}
	#else
		object {Block_ir1(l1,l2,w1,w2,h,p,NoMortar)}
	#end
#end


//--- Super irregular block number 2
//		l1: Major length (x)
//		l2: Minor length (x)
//		w1: Major width (z)
//		w2: Minor width (z)
//		 h: Height
//    dx: Orientation x
//    dz: Orientation z
//		h1: Height of one block
//		 p: Type
#macro sBlock_ir2(l1,l2,w1,w2,h,dx,dz,h1,p)
	#if (show_bricks)
		union {
			#local n=ceil(h/h1);
			#local h1=h/n;
			#local i=0;
			#local num=0;
			#while (i<n)
				object {Block_ir2(l1,l2,w1,w2,h1+dd,dx,dz,p,NoMortar) translate i*h1*y}
				#local i=i+1;
				#local num=num+1;
			#end
			#if (show_details & d[p]>0)
				object {Block_ir2(l1-d[p]+2*s[p],l2-d[p]+2*s[p],w1-2*d[p],w2-2*d[p],h+s[p],dx,dz,p,Mortar) translate <-dx*2*s[p],-(d[p]+s[p]),-d[p]>}
				#local num=num+1;
			#end
			#if (num<2)
				object {null()}
			#end
		}
	#else
		object {Block_ir2(l1,l2,w1,w2,h,dx,dz,p,NoMortar)}
	#end
#end


//--- Super irregular block number 3
//		l1: Major length (x)
//		l2: Minor length (x)
//		w1: Major width (z)
//		w2: Minor width (z)
//		 a: Angle of sector (0-180 degrees)
//		 r: Radius
//	  l11: Length of oneblock
//		 p: Type
#macro sBlock_ir3(l1,l2,w1,w2,a,r,l11,p)
	#if (show_bricks)
		#local a1 = 180*l11/pi/r;
		union {
			#local n=ceil(a/a1);
			#local a1=a/n;
			#local i=0;
			#local num=0;
			#while (i<n)
				object {Block_ir3(l1,l2,w1,w2,a1+dd,r,p,NoMortar) rotate -i*a1*z}
				#local i=i+1;
				#local num=num+1;
			#end
			#if (show_details & d[p]>0)
				#local a2=180*s[p]/pi/r;
				object {Block_ir3(l1-d[p]+0.5*s[p],l2-d[p]+0.5*s[p],w1-2*d[p],w2-2*d[p],a+2*a2-d[p],r+0.5*s[p],p,Mortar) rotate 2*a2*z translate -d[p]*z}
				#local num=num+1;
				#if (a+2*a2-d[p]>180)
					object {Block_ir3(l1-d[p]+0.5*s[p],l2-d[p]+0.5*s[p],w1-2*d[p],w2-2*d[p],a+2*a2-d[p]-180,r+0.5*s[p],p,Mortar) rotate (2*a2-180)*z translate -d[p]*z}
					#local num=num+1;
				#end
			#end
			#if (num<2)
				object {null()}
			#end
		}
	#else
		object {Block_ir3(l1,l2,w1,w2,a,r,p,NoMortar)}
	#end
#end


//----- CYLINDRICAL PIECE OF FLOOR
//		 r1: Major radius
//		 r2: Minor radius
//		 h: Height (y)
//     a: Angle
//		 l1: Length of one block
//		 w1: Width of one row (r)
//		 p: Type
#macro ssBlock_rin(r1,r2,h,a,l1,w1,p)
	#if (show_bricks)
		union { 
			#local i=r2;
			#local num=0;
			#while (i<r1)
				#local a1=180*l1/pi/(i+w1);
				#local n=ceil(a/a1);
				#local a1=a/n;
				#local j=0;
				#while (j<n)
					object {Block_rin(min(i+w1,r1)+dd,i,h,a1+dd,p,NoMortar) rotate j*a1*y} 
					#local num=num+1;
					#local j=j+1;
				#end
				#local i=i+w1;
			#end
			#if (show_details & d[p]>0)
				object {Block_rin(r1-d[p],r2+d[p],h-d[p],a,p,Mortar)}
				#local num=num+1;
			#end
			#if (num<2)
				object {null()}
			#end
		}
	#else
		object {Block_rin(r1,r2,h,a,p,NoMortar)}
	#end
#end


//----- GOTHIC ARC MADE OF 2 OPOSITE RINGS (MID PART)
//		 r0: Arch radius
//		 r: External radius
//		 w1: Width (r)
//		 n: Arc order
//     w2: Width (z)
//     f: Free space on top
//		 l1: Length of one block
//		 p: Type
#macro mgothic_rin(r0,r,w1,n,w2,f,l1,p)
	#local a=0.9*degrees(acos(1-1/n));
	union {
		object {sBlock_rin(r+r0*(n-1),r+r0*(n-1)-w1,w2,a,l1,p) rotate -90*x translate r0*(n-1)*x}
		difference {
			object {sBlock_rin(r+r0*(n-1),r+r0*(n-1)-w1,w2,90-a,l1,p) rotate <-90,0,-a> translate r0*(n-1)*x}
			box {<-f,-100,-100> <100,100,100>}
			texture {T_Block(p,NoMortar)}
		}			
	}
#end


//----- GOTHIC ARC MADE OF 2 OPOSITE TORUS (MID PART)
//		 r0: Arch radius
//		 r1: Major radius
//		 r2: Minor order
//		 n: Arc order
//     f: Free space on top
//		 l1: Length of one block
//		 p: Type
#macro mgothic_tor(r0,r1,r2,n,f,l1,p)
	#local a=0.9*degrees(acos(1-1/n));
	union {
		object {sBlock_tor(r1+r0*(n-1),r2,a,l1,p) rotate -90*x translate r0*(n-1)*x}
		difference {
			object {sBlock_tor(r1+r0*(n-1),r2,90-a,l1,p) rotate <-90,0,-a> translate r0*(n-1)*x}
			box {<-f,-100,-100> <100,100,100>}
			texture {T_Block(p,NoMortar)}
		}			
	}
#end


//----- GOTHIC ARC MADE OF 2 OPOSITE IREGULAR OBJECTS 3 (MID PART)
//		 r0: Arch radius
//		  r: Radius
//		 l1: Major length (x)
//		 l2: Minor length (x)
//		 w1: Major width (z)
//		 w2: Minor width (z)
//		  n: Arc order
//      f: Free space on top
//		 l11: Length of one block
//		 p: Type
#macro mgothic_ir3(r0,r,l1,l2,w1,w2,n,f,l11,p)
	#local a=0.9*degrees(acos(1-1/n));
	union {
		object {sBlock_ir3(l1,l2,w1,w2,a,r+r0*(n-1),l11,p) translate r0*(n-1)*x}
		difference {
			object {sBlock_ir3(l1,l2,w1,w2,90-a,r+r0*(n-1),l11,p) rotate -a*z translate r0*(n-1)*x}
			box {<-f,-100,-100> <100,100,100>}
			texture {T_Block(p,NoMortar)}
		}			
	}
#end


//----- GOTHIC ARC MADE OF 2 OPOSITE RINGS
//		 r0: Arch radius
//		 r: External radius
//		 w1: Width (r)
//		 n: Arc order
//     w2: Width (z)
//     f: Free space on top
//		 l1: Length of one block
//		 p: Type
#macro gothic_rin(r0,r,w1,n,w2,f,l1,p)
	#local a=0.9*degrees(acos(1-1/n));
	union {
		object {mgothic_rin(r0,r,w1,n,w2,f,l1,p)}
		object {mgothic_rin(r0,r,w1,n,w2,f,l1,p) rotate 180*y}
	}
#end


//----- GOTHIC ARC MADE OF 2 OPOSITE TORUS
//		 r0: Arch radius
//		 r1: Major radius
//		 r2: Minor radius
//		 n: Arc order
//     f: Free space on top
//		 l1: Length of one block
//		 p: Type
#macro gothic_tor(r0,r1,r2,n,f,l1,p)
	#local a=0.9*degrees(acos(1-1/n));
	union {
		object {mgothic_tor(r0,r1,r2,n,f,l1,p)}
		object {mgothic_tor(r0,r1,r2,n,f,l1,p) rotate 180*y}
	}
#end


//----- GOTHIC ARC MADE OF 2 OPOSITE IREGULAR OBJECTS 3
//		 r0: Arch radius
//		  r: Radius
//		 l1: Major length (x)
//		 l2: Minor length (x)
//		 w1: Major width (z)
//		 w2: Minor width (z)
//		  n: Arc order
//      f: Free space on top
//		 l11: Length of one block
//		 p: Type
#macro gothic_ir3(r0,r,l1,l2,w1,w2,n,f,l11,p)
	#local a=0.9*degrees(acos(1-1/n));
	union {
		object {mgothic_ir3(r0,r,l1,l2,w1,w2,n,f,l11,p)}
		object {mgothic_ir3(r0,r,l1,l2,w1,w2,n,f,l11,p) scale <-1,1,1>}
	}
#end


//----- GENERIC ARCH WITH CYLINDRICAL AND SQUARED ORNAMENTS - TYPE 0
//       r: radius
//       h: Total height
//      r1: radius of rounded ornaments
//       n: curvature order 
//		  n1: number of ornaments
//		  t1: thickness of the rect ornament 1 (internal)
//		  t2: thickness of the rect ornament 2
//		  t3: thickness of the rect ornament 3
//		  t4: thickness of the rect ornament 4 (external)
//		  w1: width of rect ornament 1 (internal)
//		  w2: width of rect ornament 2
//		  w3: width of rect ornament 3
//		  w4: width of rect ornament 4 (external)
//       f: Free space on top
//		   p: Type

#macro arch(r,h,r1,n,n1,t1,t2,t3,t4,w1,w2,w3,w4,f,p)
	union {
		#local h1=h-r*sqrt(2*n-1);

		object {gothic_rin(r,r-w2-w3-w4,w1,n,t1,f,0.8,p) translate h1*y}
		object {gothic_rin(r,r-w3-w4,w2,n,t2,f,0.8,p) translate h1*y}
		#if (n1>1.5)
			object {gothic_rin(r,r-w4,w3,n,t3,f,0.8,p) translate h1*y}
			#if (n1>2.5)
				object {gothic_rin(r,r,w4,n,t4,f,0.8,p) translate h1*y}
			#end
		#end
		#local i=-1;
		#while (i<2)
			object {gothic_tor(r,r-w2-w3-w4-r1+0.01,r1,n,f,0.8,p) translate <0,h1,i*(t2/2-r1)>}
			#if (n1>1)
				object {gothic_tor(r,r-w3-w4-r1+0.01,r1,n,f,0.8,p) translate <0,h1,i*(t3/2-r1)>}
				#if (n1>2)
					object {gothic_tor(r,r-w4-r1+0.01,r1,n,f,0.8,p) translate <0,h1,i*(t4/2-r1)>}
				#end
			#end
			#if (h1>0)
				object {sBlock_squ2(w1,h1+dd,t1,0.8,p) translate <i*(r-w1/2-w2-w3-w4),-dd,0>}
				object {sBlock_squ2(w2,h1+dd,t2,0.8,p) translate <i*(r-w2/2-w3-w4),-dd,0>}
				#if (n1>1.5)       
					object {sBlock_squ2(w3,h1+dd,t3,0.8,p) translate <i*(r-w3/2-w4),-dd,0>}
					#if (n1>2.5)
						object {sBlock_squ2(w4,h1+dd,t4,0.8,p) translate <i*(r-w4/2),-dd,0>}
					#end
				#end
				#local j=-1;
				#while (j<2)
		 			object {sBlock_cyl(r1,h1+dd,0.8,p) translate <i*(r-w2-w3-w4-r1+0.01),-dd,j*(t2/2-r1)>}
		 			#if (n1>1)
		 				object {sBlock_cyl(r1,h1+dd,0.8,p) translate <i*(r-w3-w4-r1+0.01),-dd,j*(t3/2-r1)>}
		 				#if (n1>2)
		 					object {sBlock_cyl(r1,h1+dd,0.8,p) translate <i*(r-w4-r1+0.01),-dd,j*(t4/2-r1)>}
		 				#end
		 			#end
					#local j=j+2;
				#end
			#end
			#local i=i+2;
		#end
	}
#end


//----- GENERIC ARCH WITH CYLINDRICAL AND SQUARED ORNAMENTS - TYPE 1 (simpler)
//       r: radius
//       h: Total height
//       n: curvature order 
//      r1: Radius of round ornament 1 (internal) (r=0: non-existent)
//      r2: Radius of round ornament 2 (external) (r=0: non-existent)
//		  t1: thickness of the rect ornament 1 (internal)
//		  t2: thickness of the rect ornament 2 (external)
//		  w1: width of rect ornament 1 (internal)
//		  w2: width of rect ornament 2 (external)
//       f: Free space on top
//		   p: Type

#macro arch1(r,h,n,r1,r2,t1,t2,w1,w2,f,p)
	union {
		#local h1=h-r*sqrt(2*n-1);

		object {gothic_rin(r,r-w2,w1,n,t1,f,0.8,p) translate h1*y}
		object {gothic_rin(r,r+0.2,w2+0.2,n,t2,f,0.8,p) translate h1*y}
		#if (r1>0)
			object {gothic_tor(r,r-w1-w2-r1+0.01,r1,n,f,0.8,p) translate h1*y}
		#end
		#if (r2>0)
			object {gothic_tor(r,r-w2-r2+0.01,r2,n,f,0.8,p) translate <0,h1,t1/2+r2-0.01>}
			object {gothic_tor(r,r-w2-r2+0.01,r2,n,f,0.8,p) translate <0,h1,-t1/2-r2+0.01>}
		#end
		#if (h1>0)
			#local i=-1;
			#while (i<2)
				object {sBlock_squ2(w1,h1+dd,t1,0.8,p) translate <(r-w2-w1/2)*i,-dd,0>}
				object {sBlock_squ2(w2,h1+dd,t2,0.8,p) translate <(r-w2/2)*i,-dd,0>}
				#if (r1>0)
					object {sBlock_cyl(r1,h1+dd,0.8,p) translate <(r-w1-w2-r1+0.01)*i,-dd,0>}
				#end
				#if (r2>0)
					object {sBlock_cyl(r2,h1+dd,0.8,p) translate <(r-w2-r2+0.01)*i,-dd,t1/2+r2-0.01>}
					object {sBlock_cyl(r2,h1+dd,0.8,p) translate <(r-w2-r2+0.01)*i,-dd,-t1/2-r2+0.01>}
				#end
				#local i=i+2;
			#end
		#end
	}
#end


//----- GENERIC ARCH WITH CYLINDRICAL AND SQUARED ORNAMENTS - TYPE 1 (simpler) - MID PART
//       r: radius
//       h: Total height
//       n: curvature order 
//      r1: Radius of round ornament 1 (internal) (r=0: non-existent)
//      r2: Radius of round ornament 2 (external) (r=0: non-existent)
//		  t1: thickness of the rect ornament 1 (internal)
//		  t2: thickness of the rect ornament 2 (external)
//		  w1: width of rect ornament 1 (internal)
//		  w2: width of rect ornament 2 (external)
//       f: Free space on top
//		   p: Type

#macro march1(r,h,n,r1,r2,t1,t2,w1,w2,f,p)
	union {
		#local h1=h-r*sqrt(2*n-1);

		object {mgothic_rin(r,r-w2,w1,n,t1,f,0.8,p) translate h1*y}
		object {mgothic_rin(r,r+0.2,w2+0.2,n,t2,f,0.8,p) translate h1*y}
		#if (r1>0)
			object {mgothic_tor(r,r-w1-w2-r1+0.01,r1,n,f,0.8,p) translate h1*y}
		#end
		#if (r2>0)
			object {mgothic_tor(r,r-w2-r2+0.01,r2,n,f,0.8,p) translate <0,h1,t1/2+r2-0.01>}
			object {mgothic_tor(r,r-w2-r2+0.01,r2,n,f,0.8,p) translate <0,h1,-t1/2-r2+0.01>}
		#end
		#if (h1>0)
			object {sBlock_squ2(w1,h1+dd,t1,0.8,p) translate <-(r-w2-w1/2),-dd,0>}
			object {sBlock_squ2(w2,h1+dd,t2,0.8,p) translate <-(r-w2/2),-dd,0>}
			#if (r1>0)
				object {sBlock_cyl(r1,h1+dd,0.8,p) translate <-(r-w1-w2-r1+0.01),-dd,0>}
			#end
			#if (r2>0)
				object {sBlock_cyl(r2,h1+dd,0.8,p) translate <-(r-w2-r2+0.01),-dd,t1/2+r2-0.01>}
				object {sBlock_cyl(r2,h1+dd,0.8,p) translate <-(r-w2-r2+0.01),-dd,-t1/2-r2+0.01>}
			#end
		#end
	}
#end


//----- OBJECT TO MAKE HOLES IN THE ROSES
//		  r: Radius
#macro RoseHole(r)
	union {
		cylinder {<0,0,dd> <0,0,-0.3-dd> r}
		torus {r 0.02 rotate 90*x scale <1,1,5> translate -0.3*z}
	}
#end


//----- ROSE FOR THE CLERESTORIES
//		  r: Radius
#macro Rose4(r)
	difference {
		cylinder {<0,0,0> <0,0,-0.3> 1}
		object {RoseHole(0.32)}
		#local i=0;
		#while (i<8)
			object {RoseHole(0.13) translate 0.4*y rotate 45*i*z}
			#local i=i+1;
		#end
		#local i=0;
		#while (i<8)
			union {
				#local j=0;
				#while (j<4)
					object {RoseHole(0.05) translate 0.05*y rotate 90*j*z}
					#local j=j+1;
				#end
				translate 0.61*y
				rotate (45*i+22.5)*z
			}
			#local i=i+1;
		#end
		#local i=0;
		#while (i<8)
			union {
				#local j=0;
				#while (j<4)
					object {RoseHole(0.03) translate 0.03*y rotate 90*j*z}
					#local j=j+1;
				#end
				translate 0.67*y
				rotate 45*i*z
			}
			#local i=i+1;
		#end
		scale <r,r,1>
		texture {T_Block(Tracery,NoMortar)}
	}
	
#end


//----- CROWN (ROUND STRUCTURE ON TOP OF THE RIBS)
//      r: External radius

#macro Crown(r,h)
	union {
		difference {
			object {nBlock_cyl(r,h,Column)}
			cylinder {<0,-dd,0> <0,h-0.1,0> 0.4*r texture {T_Block(Column,NoMortar)}}
			translate -h*y
		}
		
		//--- Leaves
		#if (show_ornaments)
			#local n=10;
			#local i=0;
			#while (i<n)
				object {leaf_tree scale <4,2,2>*r rotate <30,0,-85> translate <0.45*r,-h,0> rotate 360/n*i*y texture {T_Block(Column,NoMortar)}}
				object {leaf_tree scale <4,2,2>*r rotate <-30,0,-80> translate <0.5*r,-h,0> rotate 360/n*i*y texture {T_Block(Column,NoMortar)}}
				#local i=i+1;
			#end
		#else
			object {null()}
		#end
	}
#end


//----- VAULT (triangular piece)
//      P01: Upper point 1
//      r1:  Radius 1
//      a1:  Angle 1
//      n1:  Arch order 1
//      w1:  Width of the arch that is attached to (1)
//      P02: Upper point 2
//      r2:  Radius 2
//      a2:  Angle 2
//      n2:  Arch order 2
//      w2:  Width of the arch that is attached to (2)
//      h:   Total height

#macro Vault(P01,r1,a1,n1,w1,P02,r2,a2,n2,w2,h)
	#local dl=0.05;
	#local h1=r1*sqrt(2*n1-1);
	#local h2=r2*sqrt(2*n2-1)-dd;

	#local x01=P01.x+(w1/2-s[Column])*sin(radians(a1));
	#local x02=P02.x-w2/2*sin(radians(a2));
	#local z01=P01.z+(w1/2-s[Column])*cos(radians(a1));
	#local z02=P02.z-w2/2*cos(radians(a2));

	#local fr1=function(y) {
		(y>=h-h1)*(-r1*(n1-1)+sqrt(pow(r1*n1,2)-(y>=h-h1)*pow(y-(h-h1),2)))+(y<h-h1)*r1
	}

	#local fr2=function(y) {
		(y>=h-h2)*(-r2*(n2-1)+sqrt(pow(r2*n2,2)-pow(y-(h-h2),2)))+(y<h-h2)*r2
	}
   
	#local x1=function(y) {x01+fr1(y)*cos(radians(a1))}
	#local x2=function(y) {x02+fr2(y)*cos(radians(a2))}
   #local z1=function(y) {z01-fr1(y)*sin(radians(a1))}
	#local z2=function(y) {z02-fr2(y)*sin(radians(a2))}
   
   //--- Use of U and Uinc, thanks to Kyle from news.povray.org 
   union {          
	   mesh {
			#local i=h;
			#local U=0;
			#while (i>0)
				#local a_i=i;
				#local i=i-dl/sqrt(1+pow((fr1(i)-fr1(i-dd))/dd,2));
				#local Uinc=abs(vlength(<x2(a_i),a_i,z2(a_i)>-<x2(i),i,z2(i)>));
				triangle {
					<x1(a_i),a_i,z1(a_i)> <x2(a_i),a_i,z2(a_i)> <x1(i),i,z1(i)>
					uv_vectors <U,z1(a_i)> <U,z2(a_i)> <U+Uinc,z1(i)>
				}
				triangle {
					<x2(a_i),a_i,z2(a_i)> <x1(i),i,z1(i)> <x2(i),i,z2(i)>
					uv_vectors <U,z2(a_i)> <U+Uinc,z1(i)> <U+Uinc,z2(i)>
				}
				#local U=U+Uinc;
			#end
		}
		box {
			<P01.x-0.2,P01.y,P01.z-0.2>
			<P02.x+0.2,P02.y-0.005,P02.z+0.2>
		} 
		texture {T_Block(Bricks,NoMortar)}
	}
#end


//----- VAULT2 (double-triangular piece)
//      P01: Upper point 1
//      r1:  Radius 1
//      a1:  Angle 1
//      n1:  Arch order 1
//      w1:  Width of the arch that is attached to (1)
//      P02: Upper point 2
//      r2:  Radius 2
//      a2:  Angle 2
//      n2:  Arch order 2
//      w2:  Width of the arch that is attached to (2)
//      h:   Total height

#macro Vault2(P01,r1,a1,n1,w1,P02,r2,a2,n2,w2,h)
	union {
		object {Vault(P01,r1,a1,n1,w1,P02,r2,a2,n2,w2,h)}
		object {Vault(P01,r1,a1,n1,w1,P02,r2,a2,n2,w2,h) scale <-1,1,1>}
	}
#end

#macro Vitress(w,h,file)         
	#local f=concat("stainglasses/", file,".png");   
	#if (! file_exists(f))
		#local f="vnull.png";
		#local s=2;
	#else
		#local s=<w,h,1>;
	#end

	box {
		<0,0,0> <w,h,0.01>    
		pigment {
			image_map {
				png f           
				#if (sun_light)
					#for (c, 0, 254)
						#if (c < 5)
							filter c, 0
							transmit c, 0
						#else    
							filter c, 1
							transmit c, 0.2
						#end
					#end
				#end
			}
			scale s
		}
		normal {granite 0.2 scale 1}
		interior {ior 2}
		translate -w/2*x     
		no_radiosity      
	}
#end
