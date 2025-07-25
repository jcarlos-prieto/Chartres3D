//----- TRIFORIUM BETWEEN TWO ADJACENT COLUMNS
//		  n: Number of archs
//		  L: Length

#ifndef (triforium_column)
	#include "triforium_column.inc"
#end


#macro triforium_step(n,L)

	#local n1 = (pow(2.0,2)/pow((L-1.6)/n,2)+1)/2;
		 
	union {
		//--- Columns
		#local i=0;
		#while (i<n+1)
			object {triforium_column translate (-(L/2-0.8)+(L-1.6)/n*i)*x}
			#local i=i+1;
		#end
		
		//--- Wall behind the triforium columns
		object {sBlock_squ(0.59,2.4,0.4,0.8,0.8,0.4,Wall) translate <-(L/2-0.295),-0.22,0>}
		object {sBlock_squ(0.59,2.4,0.4,0.8,0.8,0.4,Wall) translate <(L/2-0.295),-0.22,0>}
		
		//--- Wall and archs above the columns
		difference {
			object {sBlock_squ(L,2,0.4,0.8,0.8,0.4,Wall) translate 2.15*y}
			union {
				#local i=0;
				#while (i<n)
					object {gothic_arch((L/2-0.8)/n+0.08,n1,1) texture {T_Block(Wall,NoMortar)} translate <(L/2-0.8)*(1/n-1)+(L-1.6)/n*i,2.15-2*dd,0>}
					#local i=i+1;
				#end
			}
		}

		#local i=0;
		#while (i<n)
			union {
				object {gothic_rin((L/2-0.8)/n+0.08,(L/2-0.8)/n-0.06,0.065,n1,0.16,0,0.6,Column)}
				object {gothic_tor((L/2-0.8)/n+0.08,(L/2-0.8)/n-0.06,0.08,n1,0,0.6,Column) translate 0.1*z}
				object {gothic_tor((L/2-0.8)/n+0.08,(L/2-0.8)/n-0.06,0.08,n1,0,0.6,Column) translate -0.1*z}
				difference {
					object {gothic_rin((L/2-0.8)/n+0.08,(L/2-0.8)/n+0.08,0.1,n1,0.4,0,0.6,Column)}
					#if (i!=0)
						box {<-(L-1.6)/2/n,0,-0.3> <-(L-1.6)/2/n-0.2,1,0.3> texture {T_Block(Column,NoMortar)}}
					#end
					#if (i!=n-1)
						box {<(L-1.6)/2/n,0,-0.3> <(L-1.6)/2/n+0.2,1,0.3> texture {T_Block(Column,NoMortar)}}
					#end
				}
				translate <(L/2-0.8)*(1/n-1)+(L-1.6)/n*i,2.15,0>
			}
			#local i=i+1;
		#end
		
		//--- Wall ornament
		object {sBlock_squ(L,0.08,0.08,0.8,0.8,0.08,Column) translate -0.04*y rotate -90*x translate <0,4.09,-0.255>}
		object {sBlock_squ(L,0.04,0.04,0.8,0.8,0.04,Column) translate -0.02*y rotate -90*x translate <0,4.03,-0.235>}
		object {sBlock_cyl(0.04,L,0.8,Column) rotate 90*z translate <L/2,4.09,-0.295>}
		object {sBlock_cyl(0.02,L,0.8,Column) rotate 90*z translate <L/2,4.03,-0.255>}
		
		//--- Rear side
		object {sBlock_squ(L,0.4,0.6,0.8,0.8,0.4,Floor) translate <0,-0.8,0.5>}
		object {sBlock_squ(L,5.2,0.4,0.8,0.8,0.4,Wall) translate <0,-0.8,1>}
		object {sBlock_squ(L,0.6,0.4,0.8,0.8,0.4,Wall) rotate 90*x translate <0,4.2,0.2>} 
	}
#end
