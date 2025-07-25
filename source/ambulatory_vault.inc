//----- CONSTRUCTION OF THE VAULT

#macro ambulatory_vault()
	union {                    
      object {arch(3.4,5,0.08,1.13,1,0.25,0.55,0,0,0.15,0.4,0,0,0,Column) translate 16.3*z rotate 0*y}
      object {arch(2.6,5,0.08,1.13,1,0.25,0.55,0,0,0.15,0.4,0,0,0,Column) translate 16.4*z rotate 22.62*y}
      object {arch(3.8,5,0.08,1.13,1,0.25,0.55,0,0,0.15,0.4,0,0,0,Column) translate 16.2*z rotate 46.61*y}
		object {arch(4,5,0.08,1.13,1,0.25,0.55,0,0,0.15,0.4,0,0,0,Column) translate 16.26*z rotate 75.1*y}
      object {arch(2.6,5,0.08,1.13,1,0.25,0.55,0,0,0.15,0.4,0,0,0,Column) translate 16.4*z rotate -22.62*y}
      object {arch(3.8,5,0.08,1.13,1,0.25,0.55,0,0,0.15,0.4,0,0,0,Column) translate 16.2*z rotate -46.61*y}
      object {arch(4,5,0.08,1.13,1,0.25,0.55,0,0,0.15,0.4,0,0,0,Column) translate 16.26*z rotate -75.1*y}

		object {arch(3.85,5,0.08,1.2,1,0.25,0.55,0,0,0.15,0.4,0,0,0,Column) rotate 90*y translate 3.85*z rotate -0.5*y translate 8.6*z rotate 12.86*y}
		object {arch(3.89,5,0.08,1.2,1,0.25,0.55,0,0,0.15,0.4,0,0,0,Column) rotate 90*y translate 3.89*z rotate -13*y translate 8.6*z rotate 38.57*y}
		object {arch(3.87,5,0.08,1.2,1,0.25,0.55,0,0,0.15,0.4,0,0,0,Column) rotate 90*y translate 3.87*z rotate -8*y translate 8.6*z rotate 64.29*y}
		object {arch(3.85,5,0.08,1.2,1,0.25,0.55,0,0,0.15,0.4,0,0,0,Column) rotate 90*y translate 3.85*z rotate 0.5*y translate 8.6*z rotate -12.86*y}
		object {arch(3.89,5,0.08,1.2,1,0.25,0.55,0,0,0.15,0.4,0,0,0,Column) rotate 90*y translate 3.89*z rotate 13*y translate 8.6*z rotate -38.57*y}
		object {arch(3.87,5,0.08,1.2,1,0.25,0.55,0,0,0.15,0.4,0,0,0,Column) rotate 90*y translate 3.87*z rotate 8*y translate 8.6*z rotate -64.29*y}

		object {arch(2.9,5,0.08,1.2,1,0.25,0.55,0,0,0.15,0.4,0,0,0,Column) rotate 90*y translate 19.76*z rotate 12.59*y}
		object {arch(2.9,5,0.08,1.2,1,0.25,0.55,0,0,0.15,0.4,0,0,0,Column) rotate 90*y translate 19.76*z rotate 32.65*y}
		object {arch(2.9,5,0.08,1.2,1,0.25,0.55,0,0,0.15,0.4,0,0,0,Column) rotate 90*y translate 19.76*z rotate 60.56*y}
		object {arch(2.9,5,0.08,1.2,1,0.25,0.55,0,0,0.15,0.4,0,0,0,Column) rotate 90*y translate 19.76*z rotate -12.59*y}
		object {arch(2.9,5,0.08,1.2,1,0.25,0.55,0,0,0.15,0.4,0,0,0,Column) rotate 90*y translate 19.76*z rotate -32.65*y}
		object {arch(2.9,5,0.08,1.2,1,0.25,0.55,0,0,0.15,0.4,0,0,0,Column) rotate 90*y translate 19.76*z rotate -60.56*y}

		object {arch(3.65,5,0.08,1.2,1,0.25,0.55,0,0,0.15,0.4,0,0,0,Column) translate 22.83*z}
		object {arch(3.65,5,0.08,1.2,1,0.25,0.55,0,0,0.15,0.4,0,0,0,Column) translate 22.83*z rotate 45.48*y}
		object {arch(3.65,5,0.08,1.2,1,0.25,0.55,0,0,0.15,0.4,0,0,0,Column) translate 22.83*z rotate -45.48*y}

		union {
			object {Crown(0.4,0.4) translate 5*y}
			object {march1(4.6,5,1,0.08,0,0.16,0.34,0.05,0.15,0.3,Column) rotate -69.5*y}
			object {march1(4.2,5,1,0.08,0,0.16,0.34,0.05,0.15,0.3,Column) rotate 42*y}
			object {march1(4.6,5,1,0.08,0,0.16,0.34,0.05,0.15,0.3,Column) rotate -110.5*y}
			object {march1(4.2,5,1,0.08,0,0.16,0.34,0.05,0.15,0.3,Column) rotate 138*y}
			object {Vault2(<0,5,-4.85>,1.625,0,1.3,1.18,<0,5,0>,4.6,69.5,1,0.3,5)}
			object {Vault2(<0,5,-3.3>,3.4,0,1.13,0.51,<0,5,0>,4.2,42,1,0.3,5) rotate 180*y}
			object {Vault(<0,5,-2.868>,3.85,5,1.2,0.51,<0,5,0>,4.6,38,1,0.3,5) rotate 72.6*y}
			object {Vault(<0,5,-2.868>,3.85,-5,1.2,0.51,<0,5,0>,4.2,30.5,1,0.3,5) scale <-1,1,1> rotate 72.6*y}
			object {Vault(<0,5,-2.868>,3.85,-5,1.2,0.51,<0,5,0>,4.2,30.5,1,0.3,5) rotate -72.6*y}
			object {Vault(<0,5,-2.868>,3.85,5,1.2,0.51,<0,5,0>,4.6,38,1,0.3,5) scale <-1,1,1> rotate -72.6*y}
			translate 13*z
		}
		union {
			object {Crown(0.4,0.4) translate 5*y}
			object {march1(4.5,5,1,0.08,0,0.16,0.34,0.05,0.15,0.3,Column) rotate -43*y}
			object {march1(4.4,5,1,0.08,0,0.16,0.34,0.05,0.15,0.3,Column) rotate 39*y}
			object {march1(4.5,5,1,0.08,0,0.16,0.34,0.05,0.15,0.3,Column) rotate -137*y}
			object {march1(4.4,5,1,0.08,0,0.16,0.34,0.05,0.15,0.3,Column) rotate 141*y}
			object {Vault2(<0,5,-3.46>,3.4,0,1.13,0.51,<0,5,0>,4.5,43,1,0.3,5)}
			object {Vault2(<0,5,-3.07>,3.6,0,1.2,0.51,<0,5,0>,4.4,39,1,0.3,5) rotate 180*y}
			object {Vault(<0,5,-4.33>,2.9,-6.5,1.2,0.51,<0,5,0>,4.5,53,1,0.3,5) rotate 84*y}
			object {Vault(<0,5,-4.33>,2.9,7,1.2,0.51,<0,5,0>,4.4,45,1,0.3,5) scale <-1,1,1> rotate 84*y}
			object {Vault(<0,5,-4.33>,2.9,7,1.2,0.51,<0,5,0>,4.4,45,1,0.3,5) rotate -84*y}
			object {Vault(<0,5,-4.33>,2.9,-6.5,1.2,0.51,<0,5,0>,4.5,53,1,0.3,5) scale <-1,1,1> rotate -84*y}
			translate 19.76*z
		}

		#local i=-1;
		#while (i<2)
			union {
				object {Crown(0.4,0.4) translate 5*y}
				object {march1(4.4,5,1,0.08,0,0.16,0.34,0.05,0.15,0.3,Column) rotate -75*y}
            object {march1(3.8,5,1,0.08,0,0.16,0.34,0.05,0.15,0.3,Column) rotate 51*y}
            object {march1(4.9,5,1,0.08,0,0.16,0.34,0.05,0.15,0.3,Column) rotate -113*y}
            object {march1(3.8,5,1,0.08,0,0.16,0.34,0.05,0.15,0.3,Column) rotate 129*y}
            object {Vault2(<0,5,-3.4>,2.6,0,1.13,0.51,<0,5,0>,3.8,51,1,0.3,5) rotate 180*y}
            object {Vault(<0,5,-4.9>,1.625,7,1.3,1.18,<0,5,0>,4.9,72,1,0.3,5) rotate -5*y}
            object {Vault(<0,5,-4.9>,1.625,-7,1.3,1.18,<0,5,0>,4.4,70,1,0.3,5) scale <-1,1,1> rotate -5*y}
            object {Vault(<0,5,-2.3>,3.85,8,1.2,0.51,<0,5,0>,4.4,34,1,0.3,5) rotate 71.3*y}
            object {Vault(<0,5,-2.3>,3.85,-8,1.2,0.51,<0,5,0>,3.8,20,1,0.3,5) scale <-1,1,1> rotate 71.3*y}
            object {Vault(<0,5,-2.7>,3.89,-16,1.2,0.51,<0,5,0>,3.8,20,1,0.3,5) rotate -71.3*y}
            object {Vault(<0,5,-2.7>,3.89,16,1.2,0.51,<0,5,0>,4.9,42,1,0.3,5) scale <-1,1,1> rotate -71.3*y}
				translate 13*z
				rotate 22.62*y
				scale <i,1,1>
			}
			union {
				object {Crown(0.4,0.4) translate 5*y}
			   object {march1(4.3,5,1,0.08,0,0.16,0.34,0.05,0.15,0.3,Column) rotate -78*y}
				object {march1(4.5,5,1,0.08,0,0.16,0.34,0.05,0.15,0.3,Column) rotate 38*y}
				object {march1(5.02,5,1,0.08,0,0.16,0.34,0.05,0.15,0.3,Column) translate -0.03*x rotate -115.5*y}
				object {march1(4.5,5,1,0.08,0,0.16,0.34,0.05,0.15,0.3,Column) rotate 142*y}
				object {Vault2(<0,5,-3.2>,3.8,0,1.13,0.51,<0,5,0>,4.5,38,1,0.3,5) rotate 180*y}
   			object {Vault(<0,5,-4.93>,1.625,13,1.3,1.18,<0,5,0>,5.05,72.5,1,0.3,5) rotate -8*y}
   			object {Vault(<0,5,-4.93>,1.625,-13,1.3,1.18,<0,5,0>,4.3,70,1,0.3,5) scale <-1,1,1> rotate -8*y}
   			object {Vault(<0,5,-2.75>,3.89,-2,1.2,0.51,<0,5,0>,4.3,30,1,0.3,5) rotate 71.3*y}
   			object {Vault(<0,5,-2.75>,3.89,2,1.2,0.51,<0,5,0>,4.5,33,1,0.3,5) scale <-1,1,1> rotate 71.3*y}
   			object {Vault(<0,5,-3.4>,3.87,-7,1.2,0.51,<0,5,0>,4.5,35,1,0.3,5) rotate -72.7*y}
   			object {Vault(<0,5,-3.4>,3.87,9,1.2,0.51,<0,5,0>,5.05,42,1,0.3,5) scale <-1,1,1> rotate -72.7*y}
				translate 13*z
				rotate 46.61*y
				scale <i,1,1>
			}
			union {
				object {Crown(0.4,0.4) translate 5*y}
				object {march1(4.5,5,1,0.08,0,0.16,0.34,0.05,0.15,0.3,Column) rotate -74*y}
				object {march1(4.6,5,1,0.08,0,0.16,0.34,0.05,0.15,0.3,Column) rotate 37*y}
				object {march1(4.9,5,1,0.08,0,0.16,0.34,0.05,0.15,0.3,Column) rotate -116*y}
				object {march1(4.8,5,1,0.08,0,0.16,0.34,0.05,0.15,0.3,Column) rotate 146*y}
				object {Vault(<0,5,-3.3>,4,0,1.13,0.51,<0,5,0>,4.6,36.5,1,0.3,5) rotate 180*y}
				object {Vault(<0,5,-3.3>,4,0,1.13,0.51,<0,5,0>,4.8,33.5,1,0.3,5) scale <-1,1,1> rotate 180*y}
   			object {Vault(<0,5,-4.9>,1.625,4,1.3,1.18,<0,5,0>,4.9,67,1,0.3,5) rotate -3.3*y}
   			object {Vault(<0,5,-4.9>,1.625,-6,1.3,1.18,<0,5,0>,4.5,70.5,1,0.3,5) scale <-1,1,1> rotate -3.3*y}
   			object {Vault(<0,5,-3>,3.87,-2,1.2,0.51,<0,5,0>,4.5,33,1,0.3,5) rotate 73*y}
   			object {Vault(<0,5,-3>,3.87,2,1.2,0.51,<0,5,0>,4.6,36,1,0.3,5) scale <-1,1,1> rotate 73*y}
   			object {Vault(<0,5,-3.55>,3.555,-2,1.2,0.51,<0,5,0>,4.8,39,1,0.3,5) rotate -72.7*y}
   			object {Vault(<0,5,-3.55>,3.555,3,1.2,0.51,<0,5,0>,4.9,43,1,0.3,5) scale <-1,1,1> rotate -72.7*y}
				translate 13*z
				rotate 75.1*y
				scale <i,1,1>
			}
   		union {
   			object {Crown(0.4,0.4) translate 5*y}
   			object {march1(3.9,5,1,0.08,0,0.16,0.34,0.05,0.15,0.3,Column) rotate -49*y}
   			object {march1(4,5,1,0.08,0,0.16,0.34,0.05,0.15,0.3,Column) rotate 46*y}
   			object {march1(3.9,5,1,0.08,0,0.16,0.34,0.05,0.15,0.3,Column) rotate -131*y}
   			object {march1(4,5,1,0.08,0,0.16,0.34,0.05,0.15,0.3,Column) rotate 131*y}
   			object {march1(4,5,1,0.08,0,0.16,0.34,0.05,0.15,0.3,Column) rotate 88.75*y}
   			object {Vault2(<0,5,-3.36>,2.6,0,1.13,0.51,<0,5,0>,3.9,49,1,0.3,5)}
   			object {Vault2(<0,5,-4>,1.24,0,1.33,0,<0,5,0>,4,68.7,1,0.3,5) rotate 157.3*y}
   			object {Vault(<0,5,-3.95>,1.24,1,1.33,0,<0,5,0>,4,68.7,1,0.3,5) rotate -159.7*y}
   			object {Vault(<0,5,-3.95>,1.24,-1,1.33,0,<0,5,0>,4,69.5,1,0.3,5) scale <-1,1,1> rotate -159.7*y}
   			object {Vault(<0,5,-3.5>,2.9,-5,1.2,0.51,<0,5,0>,3.9,46,1,0.3,5) rotate 85*y}
   			object {Vault(<0,5,-3.5>,2.9,4,1.2,0.51,<0,5,0>,4,39,1,0.3,5) scale <-1,1,1> rotate 85*y}
   			object {Vault(<0,5,-3.5>,2.9,4,1.2,0.51,<0,5,0>,4,35.5,1,0.3,5) rotate -85*y}
   			object {Vault(<0,5,-3.5>,2.9,-6,1.2,0.51,<0,5,0>,3.9,46,1,0.3,5) scale <-1,1,1> rotate -85*y}
   			translate 19.76*z
   			rotate 22.62*y
				scale <i,1,1>
   		}
   		union {
   			object {Crown(0.4,0.4) translate 5*y}
   			object {march1(4.8,5,1,0.08,0,0.16,0.34,0.05,0.15,0.3,Column) rotate -41*y}
   			object {march1(4.7,5,1,0.08,0,0.16,0.34,0.05,0.15,0.3,Column) rotate 35*y}
   			object {march1(4.8,5,1,0.08,0,0.16,0.34,0.05,0.15,0.3,Column) rotate -139*y}
   			object {march1(4.3,5,1,0.08,0,0.16,0.34,0.05,0.15,0.3,Column) rotate 137*y}
   			object {Vault2(<0,5,-3.56>,3.8,0,1.13,0.51,<0,5,0>,4.8,41,1,0.3,5)}
   			object {Vault(<0,5,-3.1>,3.65,7,1.2,0.51,<0,5,0>,4.7,43,1,0.3,5) rotate 172*y}
				object {Vault(<0,5,-3.1>,3.65,-7,1.2,0.51,<0,5,0>,4.3,35,1,0.3,5) scale <-1,1,1> rotate 172*y}
   			object {Vault(<0,5,-4.8>,2.9,-7.5,1.2,0.51,<0,5,0>,4.8,55,1,0.3,5) rotate 83.5*y}
   			object {Vault(<0,5,-4.8>,2.9,8.5,1.2,0.51,<0,5,0>,4.7,48,1,0.3,5) scale <-1,1,1> rotate 83.5*y}
   			object {Vault(<0,5,-4.8>,2.9,8.5,1.2,0.51,<0,5,0>,4.4,40,1,0.3,5) rotate -83.5*y}
   			object {Vault(<0,5,-4.8>,2.9,-8,1.2,0.51,<0,5,0>,4.8,55,1,0.3,5) scale <-1,1,1> rotate -83.5*y}
   			translate 19.76*z
   			rotate 46.61*y
				scale <i,1,1>
   		}
   		union {
   			object {Crown(0.4,0.4) translate 5*y}
   			object {march1(5,5,1,0.08,0,0.16,0.34,0.05,0.15,0.3,Column) rotate -39*y}
   			object {march1(4.7,5,1,0.08,0,0.16,0.34,0.05,0.15,0.3,Column) rotate 37*y}
   			object {march1(5.6,5,1,0.08,0,0.16,0.34,0.05,0.15,0.3,Column) rotate -143*y}
   			object {march1(4.2,5,1,0.08,0,0.16,0.34,0.05,0.15,0.3,Column) rotate 133*y}
   			object {march1(5.4,5,1,0.08,0,0.16,0.34,0.05,0.15,0.3,Column) rotate 69*y}
   			object {march1(5,5,1,0.08,0,0.16,0.34,0.05,0.15,0.3,Column) rotate 102*y}
   			object {Vault(<0,5,-3.5>,4,0,1.13,0.51,<0,5,0>,5.6,37,1,0.3,5)}
				object {Vault(<0,5,-3.5>,4,0,1.13,0.51,<0,5,0>,5,39,1,0.3,5) scale <-1,1,1>}
   			object {Vault(<0,5,-5.15>,1.24,5,1.33,0,<0,5,0>,5.4,74,1,0.3,5) rotate 175*y}
	 			object {Vault(<0,5,-5.15>,1.24,-3,1.33,0,<0,5,0>,5,73,1,0.3,5) scale <-1,1,1> rotate 175*y}
	 			object {Vault(<0,5,-5.05>,1.24,-7.5,1.33,0,<0,5,0>,4.7,75,1,0.3,5) rotate 142*y}
   			object {Vault(<0,5,-5.05>,1.24,8,1.33,0,<0,5,0>,5.4,73,1,0.3,5) scale <-1,1,1> rotate 142*y}
   			object {Vault(<0,5,-4.7>,1.24,14,1.33,0,<0,5,0>,5,73,1,0.3,5) rotate -151*y}
   			object {Vault(<0,5,-4.65>,1.24,-14,1.33,0,<0,5,0>,4.2,76,1,0.3,5) scale <-1,1,1> rotate -151*y}
   			object {Vault(<0,5,-5>,2.9,-7,1.2,0.51,<0,5,0>,5,58,1,0.3,5) rotate 83*y}
   			object {Vault(<0,5,-5>,2.9,8,1.2,0.51,<0,5,0>,4.7,46,1,0.3,5) scale <-1,1,1> rotate 83*y}
				object {Vault(<0,5,-5.4>,2.735,9,1.2,0.51,<0,5,0>,4.2,37,1,0.3,5) rotate -84*y}
				object {Vault(<0,5,-5.35>,2.735,-9,1.2,0.51,<0,5,0>,5.6,59,1,0.3,5) scale <-1,1,1> rotate -84*y}
   			translate 19.76*z
   			rotate 75.1*y
				scale <i,1,1>
   		}
			#local i=i+2;
		#end
	}
#end