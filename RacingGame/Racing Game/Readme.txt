This project was created in and runs on visaul studios 2010 edition.

When testing our project in the labs, we found that for some unknown reason the car
would accelerate and turn at a rate many times faster than when we had tried it on our home PCs.
We believe this may be due to a difference in processor brand or some hardware difference.

The value for the acceleration and others can be rather easily changed from the carInfo.h 
header file. The values we tested and found to be reasonable follow in this file.

#define CX -135.0					//center x coordinate	
#define CY -138.0					//center y coordinate	
#define HL 5.0						//half long length	
#define AN PI/2						//angle				
#define SP 0.0						//initial speed		
#define AC 0.002					//acceleration		
#define DC 0.004					//break deceleration				
#define TS 1.5						//top speed		
#define HB -0.01					//hand break						
#define deceleration_ground -0.0005;			//ground deceleration value			 
#define STEERING 0.025					//steering wheel sensitivity		
#define tarSTEERING 0					//tared steering wheel sensitivity

The values here can be changed easily without effecting the remainder of the code.

The video included in the main project directory shows the speeds and turning we epxerienced on all three of our machines.
(athough there is some frame drops in demo one from recording at the same time.)