public class Application {   // Introduces a new class (called Application)
    static float convertFtoC(float F) {   // Introduces a new method (called
                                                        // convertFtoC) that returns a result
	return (F-32) * 5 / 9;  // This does the job and returns a result
    }  // This curly bracket ends the convertFtoC method	

    public static void main(String[] args )  {  // Every Java application has
				               // this method – defines start
        float tempF;	   // This declares a variable (tempF) of type float
        TextIO.put("Enter temperature in °F: ");   // This prints a message
        tempF = TextIO.getlnFloat();		    // This gets keyboard input
        TextIO.putln("Temperature in °C is " + convertFtoC(tempF)); 
    }	// The line above prints out a message containing the result.
}     // This curly bracket ends the Application class
