
public class Countdown {

	/**
	 *  constanants.txt , vowels.txt and words5to8.txt (all included
	 *  in the file) need to be in the JRE System Library for it to
	 *  work
	 */
	public static void main(String[] args) {
		
		final String wordfile = "words5to8.txt";
		String[] wordList = Filereader(wordfile); //reads and returns dictionary file
		
		final String vowel = "vowels.txt";
		char[] Vowels = Vowelreader(vowel); //reads and returns vowels
		
		final String constant = "constanants.txt";
		char[] Constanant = constreader(constant); //reads and returns constanants

		//explains what is happening and what input is needed from the user
		TextIO.putln("You will now be asked to choose 8 random letters from either ");
		TextIO.putln("the constanants or vowels categories. Press your chosen number (1/2)");
		TextIO.putln("then hit enter.");
		TextIO.putln(" "); //spaceing to seperate
		
		
		char[] Combiword = new char [8]; //creating the combined letters array
		int wordcount = 0;
		int g = 0; //combined word array counter
		{
			while (wordcount < 8) { //Counts and returns letters of constanants/vowels
			TextIO.put("Please choose a constanant (1) or vowel (2): ");
			int choice = TextIO.getInt();
			switch (choice) 
			{
				case 1 :int ConstanantNumber = (int)(Math.random()*Constanant.length);
				char Contchoice = Constanant[ConstanantNumber];
				TextIO.putln(Contchoice);
				wordcount++;
				Combiword[g] = Contchoice;
				g++;
				break;
				
				case 2 :int VowelNumber = (int)(Math.random()*Vowels.length);
				char Vowchoice = Vowels[VowelNumber];
				TextIO.putln(Vowchoice);
				wordcount++;
				Combiword[g] = Vowchoice;
				g++;
				break;
				
				default : TextIO.putln("Not recognised character, please try again: ");
				break;
			}
		}	
		TextIO.putln(" "); //spacing
		TextIO.putln("Thank you, your 8 letter combination is: " );
		for (int i=0; i < Combiword.length; i++) {
			TextIO.put(Combiword[i]); } //displays the 8 letter combination
		}
		
		int correct = 0;
		int wordschecked = 0; //sets words checked so far
		
		/*
		 * will run through the eight characters in the combined word and
		 * compares each to the characters in the comparing word
		 */
		
		for (; wordschecked < 70548; wordschecked++) { //moves through all the word in dictionary
			correct = 0;
			for (int arraycount = 0; arraycount < Combiword.length; arraycount++) { //moves through the combiword
				
				for (int letters= 0; letters < wordList[wordschecked].length(); letters++) { //moves through word in dictionary
					
					if (Combiword[arraycount] == wordList[wordschecked].charAt(letters)) { //compares letter
						correct++;
						Combiword[arraycount] = 9;
						if (correct >4) {
							TextIO.putln(" ");
							TextIO.putln(wordList[wordschecked]);
						}
					}
		}
		}
		}
	}
	

	
		
	
	public static char[] constreader(String constant) { //filreader, returns Constanants
		
		TextIO.readFile(constant);
		int counter = 0;
		while (!TextIO.eof()) {
			TextIO.getln();
			counter++;
		}
		TextIO.readStandardInput();
		
		char[] Constanants = new char[counter];
		TextIO.readFile(constant);
		for (int i=0; i<counter; i++) {
			Constanants[i] = TextIO.getChar();
		}
		TextIO.readStandardInput();
		return Constanants;
	}
	
	public static char[] Vowelreader(String vowel) { //filereader, returns VowelLetters
		
		TextIO.readFile(vowel);
		int counter = 0;
		while (!TextIO.eof()) {
			TextIO.getln();
			counter++;
		}
		TextIO.readStandardInput();
		
		char[] VowelLetters = new char[counter];
		TextIO.readFile(vowel);
		for (int i=0; i<counter; i++) {
			VowelLetters[i] = TextIO.getChar();
		}
		TextIO.readStandardInput();
		return VowelLetters;
	}
	
	public static String[] Filereader(String wordfile) { //filereader, returns words
			
			TextIO.readFile(wordfile);
			int counter = 0;
			while (!TextIO.eof()) {
				TextIO.getln();
				counter++;
			}
			TextIO.readStandardInput();
			
			String[] words = new String[counter];
			TextIO.readFile(wordfile);
			for (int i=0; i<counter; i++) {
				words[i] = TextIO.getln();
			}
			TextIO.readStandardInput();
			return words;
		}

	}