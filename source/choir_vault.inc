//----- CONSTRUCTION OF THE CHOIR VAULTS

#macro choir_vault()
	union {
	   //--- Ribs
		#local i=0;
		#while (i<4)
			object {arch(7.7,10.8,0.08,1.48,1,0.25,0.55,0,0,0.15,0.4,0,0,0,Column) translate 7.18*i*z}
			#local i=i+1;
		#end		

		#local i=-1;
		#while (i<2)
			#local j=0;
			#while (j<3)
				object {arch(8.6,10.8,0.08,1.22,1,0.25,0.55,0,0,0.15,0.4,0,0,0.5,Column) rotate 23.8*i*y translate (3.59+7.18*j)*z}
				#local j=j+1;
			#end
			object {arch(8.5,10.8,0.08,1.22,1,0.25,0.55,0,0,0.15,0.4,0,0,0.5,Column) rotate 22*i*y translate -3.25*z}
			#local i=i+2;
		#end

		#local i=0;
		#while (i<3)
			object {Crown(0.7,0.8) translate <0,10.8,3.59+7.18*i>}
			#local i=i+1;
		#end
		object {Crown(0.7,0.8) translate <0,10.8,-3.3>}
      
      union {
			#local i=-1;
			#while (i<2)				
				object {march1(6.0,10.8,1.2,0.1,0.05,0.16,0.34,0.1,0.25,0.5,Column) rotate (90+17.4*i)*y}
				object {march1(6.5,10.8,1.2,0.1,0.05,0.16,0.34,0.1,0.25,0.5,Column) rotate (90+50.4*i)*y}
				object {march1(7.3,10.8,1.2,0.1,0.05,0.16,0.34,0.1,0.25,0.5,Column) rotate (90+79.4*i)*y}
				object {march1(8.2,10.8,1.2,0.1,0.05,0.16,0.34,0.1,0.25,0.5,Column) rotate (90+103.5*i)*y}
				#local i=i+2;
			#end
			object {Crown(0.7,0.8) translate 10.8*y}
			translate 23.76*z		
		}

	   //--- Vaults
		object {Vault2(<0,10.8,-3.95>,7.7,0,1.48,1.4,<0,10.8,0>,8.5,22,1.22,0.55,10.8) scale <1,1,1> translate -3.25*z}		
		object {Vault2(<0,10.8,-3.3>,7.7,0,1.48,0.55,<0,10.8,0>,8.5,22,1.22,0.55,10.8) scale <1,1,-1> translate -3.25*z}		
		#local i=-1;
		#while (i<2)
			object {Vault2(<0,10.8,-7.7>,2.83,0,1,0,<0,10.8,0>,8.5,68,1.22,0.55,10.8) rotate 90*y scale <i,1,1> translate -3.25*z}
			#local j=0;
			#while (j<3)
				object {Vault2(<0,10.8,-3.59>,7.7,0,1.48,0.55,<0,10.8,0>,8.6,23.8,1.22,0.55,10.8) scale <1,1,i> translate (3.59+7.18*j)*z}		
				object {Vault2(<0,10.8,-7.7>,3.17,0,1,0,<0,10.8,0>,8.6,66.2,1.22,0.55,10.8) rotate 90*y scale <i,1,1> translate (3.59+7.18*j)*z}
				#local j=j+1;
			#end
			#local i=i+2;
		#end
				
      union {
      	object {Vault2(<0,10.8,-5.55>,1.51,0,1.33,0,<0,10.8,0>,5.9,72.6,1.2,0.34,10.8) rotate 180*y translate 2*z}
			object {Vault2(<0,10.8,-2.22>,7.7,0,1.48,0.55,<0,10.8,0>,8.1,13.5,1.2,0.34,10.8) translate 2*z}		
			#local i=-1;
			#while (i<2)
				object {Vault(<0,10.8,-5.77>,1.51,0,1.33,0,<0.87,10.8,0>,5.9,81.8,1.2,0.34,10.8) scale <-1,1,1> translate -1.78*z rotate 180*(1-1/7)*y scale <i,1,1>}
				object {Vault(<0,10.8,-5.77>,1.51,0,1.33,0,<-0.87,10.8,0>,6.4,65.2,1.2,0.34,10.8) translate -1.78*z rotate 180*(1-1/7)*y scale <i,1,1>}
				object {Vault(<0,10.8,-6.28>,1.51,0,1.33,0,<1.58,10.8,0>,6.4,89,1.2,0.34,10.8) scale <-1,1,1> translate -1.27*z rotate 180*(1-2/7)*y scale <i,1,1>}
				object {Vault(<0,10.8,-6.28>,1.51,0,1.33,0,<-1.58,10.8,0>,7.2,61,1.2,0.34,10.8) translate -1.27*z rotate 180*(1-2/7)*y scale <i,1,1>}
				object {Vault(<0,10.8,-7.1>,1.51,0,1.33,0,<1.9,10.8,0>,7.2,92.3,1.2,0.34,10.8) scale <-1,1,1> translate -0.45*z rotate 180*(1-3/7)*y scale <i,1,1>}
				object {Vault(<0,10.8,-7.1>,1.51,0,1.33,0,<-1.9,10.8,0>,8.1,63.5,1.2,0.34,10.8) translate -0.45*z rotate 180*(1-3/7)*y scale <i,1,1>}
				#local i=i+2;
			#end
			translate 21.76*z
		}
	}
#end