//----- CONSTRUCTION OF THE VAULT

#macro nave_vault()
	union {
	   //--- Ribs
		#local i=0;
		#while (i<6)
			object {arch(7.7,10.8,0.08,1.48,1,0.25,0.55,0,0,0.15,0.4,0,0,0,Column) translate 7.18*i*z}
			#local i=i+1;
		#end
		object {arch(7.7,10.8,0.08,1.48,2,0.25,0.55,0.95,0,0.15,0.45,0.45,0,0,Column) translate 43.08*z}

		#local i=-1;
		#while (i<2)
			#local j=0;
			#while (j<5)
				object {arch(8.6,10.8,0.08,1.22,1,0.25,0.55,0,0,0.15,0.4,0,0,0.5,Column) rotate 23.8*i*y translate (3.59+7.18*j)*z}
				#local j=j+1;
			#end
			object {arch(8.5,10.8,0.08,1.22,1,0.25,0.55,0,0,0.15,0.4,0,0,0.5,Column) rotate 22*i*y translate -3.25*z}
			object {arch(8.5,10.8,0.08,1.22,1,0.25,0.55,0,0,0.15,0.4,0,0,0.5,Column) rotate 23*i*y translate 39.225*z}
			#local i=i+2;
		#end

		#local i=0;
		#while (i<5)
			object {Crown(0.7,0.8) translate <0,10.8,3.59+7.18*i>}
			#local i=i+1;
		#end
		object {Crown(0.7,0.8) translate <0,10.8,-3.3>}
		object {Crown(0.7,0.8) translate <0,10.8,39.3>}

	   //--- Vaults
		object {Vault2(<0,10.8,-3.93>,7.7,0,1.48,1.4,<0,10.8,0>,8.5,22,1.22,0.55,10.8) scale <1,1,1> translate -3.25*z}		
		object {Vault2(<0,10.8,-3.28>,7.7,0,1.48,0.55,<0,10.8,0>,8.5,22,1.22,0.55,10.8) scale <1,1,-1> translate -3.25*z}		
		object {Vault2(<0,10.8,-3.35>,7.7,0,1.48,0.55,<0,10.8,0>,8.5,23,1.22,0.55,10.8) scale <1,1,1> translate 39.225*z}		
		object {Vault2(<0,10.8,-3.85>,7.7,0,1.48,0.95,<0,10.8,0>,8.5,23,1.22,0.55,10.8) scale <1,1,-1> translate 39.225*z}		
		#local i=-1;
		#while (i<2)
			object {Vault2(<0,10.8,-7.7>,2.83,0,1,0,<0,10.8,0>,8.5,68,1.22,0.55,10.8) rotate 90*y scale <i,1,1> translate -3.25*z}
			object {Vault2(<0,10.8,-7.7>,2.934,0,1,0,<0,10.8,0>,8.5,67,1.22,0.55,10.8) rotate 90*y scale <i,1,1> translate 39.225*z}
			#local j=0;
			#while (j<5)
				object {Vault2(<0,10.8,-3.59>,7.7,0,1.48,0.55,<0,10.8,0>,8.6,23.8,1.22,0.55,10.8) scale <1,1,i> translate (3.59+7.18*j)*z}		
				object {Vault2(<0,10.8,-7.7>,3.17,0,1,0,<0,10.8,0>,8.6,66.2,1.22,0.55,10.8) rotate 90*y scale <i,1,1> translate (3.59+7.18*j)*z}
				#local j=j+1;
			#end
			#local i=i+2;
		#end		
	}
#end