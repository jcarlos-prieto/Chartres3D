//----- CONSTANTS

//--- Block types
#declare Wall		= 0;
#declare Floor		= 1;
#declare Floor2	= 2;
#declare Column	= 3;
#declare Tracery	= 4;
#declare Bricks	= 5;
#declare Door		= 6;

#declare Mortar	= on;
#declare NoMortar = off;

#declare dd			= 0.000001;		// Infinitesimal value

//----- EXTERNAL FUNCTIONS
#declare f_rounded_box = function {internal(60)}
#declare f_noise3d = function {internal(76)}


//----- GENERIC VARIABLES
#declare rr = seed(0);				// Random seed

#declare s   = array[7];			// Roundness
#declare d   = array[7];			// Mortar depth

#declare s[Wall] = 0.02;
#declare d[Wall] = 0.004;

#declare s[Floor] = 0.02;
#declare d[Floor] = 0.005;

#declare s[Floor2] = 0.02;
#declare d[Floor2] = 0.005;

#declare s[Column] = 0.015;
#declare d[Column] = 0.004;

#declare s[Tracery] = 0.004;
#declare d[Tracery] = 0.001;

#declare s[Bricks] = 0;
#declare d[Bricks] = 0;

#declare s[Door] = 0.01;
#declare d[Door] = 0; // = No mortar                             
