//----- CONSTRUCTION OF THE VAULT

#macro transept_vault()
	union {       
	   //--- Ribs
		#local i=-1;
		#while (i<2)
			object {arch(7.7,10.8,0.08,1.48,3,0.25,0.55,0.95,1.4,0.15,0.45,0.2,0.45,0,Column) translate 7.18*i*z}		
			object {arch(6.59,10.8,0.08,1.48,3,0.25,0.55,0.95,1.4,0.15,0.45,0.2,0.45,0,Column) rotate 90*y translate 8.29*i*x}		
			object {arch1(10.1,10.8,1,0.1,0.05,0.2,0.38,0.1,0.25,1,Column) rotate 40.25*i*y}
			#local j=0;
			#while (j<2)
				object {arch(6.59,10.8,0.08,1.48,1,0.25,0.55,0,0,0.15,0.4,0,0,0,Column) rotate 90*i*y translate (16.58+8.29*j)*i*x}
				#local j=j+1;
			#end
			#local j=-1;
			#while (j<2)
				object {arch(7.7,10.8,0.08,1.22,1,0.25,0.55,0,0,0.15,0.4,0,0,0.5,Column) rotate 61*j*y translate 12.775*i*x}
				object {arch(7.8,10.8,0.08,1.22,1,0.25,0.55,0,0,0.15,0.4,0,0,0.5,Column) rotate 58.8*j*y translate 20.725*i*x}
				object {arch(7.86,10.8,0.08,1.22,1,0.25,0.55,0,0,0.15,0.4,0,0,0.5,Column) rotate 58.5*j*y translate 29.015*i*x}
				#local j=j+2;
			#end
			object {Crown(0.7,0.8) translate <12.775*i,10.8,0>}
			object {Crown(0.7,0.8) translate <20.725*i,10.8,0>}
			object {Crown(0.7,0.8) translate <29.015*i,10.8,0>}
			object {Crown(1,0.8) translate <0,10.8,0>}
			#local i=i+2;
		#end

	   //--- Vaults
		#local i=-1;
		#while (i<2)
			object {Vault2(<0,10.8,-7.18>,7.7,0,1.48,1.4,<0,10.8,0>,10.1,40.25,1,0.38,10.8) scale <1,1,i>}
			object {Vault2(<0,10.8,-8.29>,6.59,0,1.48,1.0,<0,10.8,0>,10.1,49.75,1,0.38,10.8) rotate 90*y scale <i,1,1>}
		
			object {Vault2(<0,10.8,-4.48>,6.59,0,1.48,1.4,<0,10.8,0>,7.7,29,1.22,0.55,10.8) rotate 90*y scale <i,1,1> translate 12.775*i*x}
			object {Vault2(<0,10.8,-3.82>,6.59,0,1.48,0.55,<0,10.8,0>,7.7,29,1.22,0.55,10.8) rotate 90*y scale <-i,1,1> translate 12.775*i*x}
			object {Vault2(<0,10.8,-4.15>,6.59,0,1.48,0.55,<0,10.8,0>,7.86,31.5,1.22,0.55,10.8) rotate 90*y scale <i,1,1> translate 29.015*i*x}
			object {Vault2(<0,10.8,-4.2>,5.95,0,1,0,<0,10.8,0>,7.86,31.5,1.22,0.55,10.8) rotate 90*y scale <-i,1,1> translate 29.015*i*x}
			#local j=-1;
			#while (j<2)
				object {Vault2(<0,10.8,-6.59>,3.385,0,1,0,<0,10.8,0>,7.7,61,1.22,0.55,10.8) scale <1,1,j> translate 12.775*i*x}
				object {Vault2(<0,10.8,-4.145>,6.59,0,1.48,0.55,<0,10.8,0>,7.8,31.2,1.22,0.55,10.8) rotate 90*y scale <j,1,1> translate 20.725*i*x}
				object {Vault2(<0,10.8,-6.59>,3.725,0,1,0,<0,10.8,0>,7.8,58.8,1.22,0.55,10.8) scale <1,1,j> translate 20.725*i*x}
				object {Vault2(<0,10.8,-6.59>,3.725,0,1,0,<0,10.8,0>,7.86,58.5,1.22,0.55,10.8) scale <1,1,j> translate 29.015*i*x}
				#local j=j+2;
			#end
			#local i=i+2;
		#end		
	}
#end