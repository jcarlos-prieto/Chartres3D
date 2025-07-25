//----- CONSTRUCTION OF THE VAULT

#macro main_facade_vault()
   union {
		object {arch(7.8,10.8,0.08,1.48,1,0.25,0.55,0,0,0.15,0.4,0,0,0,Column) translate 7.1*z}
		#local i=-1;
		#while (i<2)
			object {arch(8.5,10.8,0.08,1.22,1,0.25,0.55,0,0,0.15,0.4,0,0,0.5,Column) rotate 22.3*i*y translate 3.745*z}
			object {arch(8.25,10.8,0.08,1.22,1,0.25,0.55,0,0,0.15,0.4,0,0,0.5,Column) rotate 17.3*i*y translate 9.73*z}
			#local i=i+2;
		#end
		object {Crown(0.7,0.8) translate <0,10.8,3.745>}
		object {Crown(0.7,0.8) translate <0,10.8,9.73>}

	   //--- Vaults
		#local i=-1;
		#while (i<2)
			object {Vault2(<0,10.8,-7.7>,2.96,0,1,0,<0,10.8,0>,8.5,67.7,1.22,0.55,10.8) rotate 90*y scale <i,1,1> translate 3.745*z}
			object {Vault2(<0,10.8,-7.7>,2.2,0,1,0,<0,10.8,0>,8.25,72.7,1.22,0.55,10.8) rotate 90*y scale <i,1,1> translate 9.73*z}
			#local i=i+2;
		#end		
		object {Vault2(<0,10.8,-3.75>,7.7,0,1.48,0.95,<0,10.8,0>,8.5,22.3,1.22,0.55,10.8) translate 3.745*z}		
		object {Vault2(<0,10.8,-3.42>,7.7,0,1.48,0.55,<0,10.8,0>,8.5,22.3,1.22,0.55,10.8) scale <1,1,-1> translate 3.745*z}		
		object {Vault2(<0,10.8,-2.63>,7.7,0,1.48,0.55,<0,10.8,0>,8.25,17.3,1.22,0.55,10.8) translate 9.73*z}		
		object {Vault2(<0,10.8,-2.75>,6.87,0,1,0,<0,10.8,0>,8.25,17.3,1.22,0.55,10.8) scale <1,1,-1> translate 9.73*z}		
	}
#end