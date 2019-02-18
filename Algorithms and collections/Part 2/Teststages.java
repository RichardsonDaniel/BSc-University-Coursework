
public class Teststages {

	public static void run() {
		
			BinarySearchTree treeLeaf=new BinarySearchTree(); // addLeaf
			BinarySearchTree treeRoot=new BinarySearchTree(true); // addRoot
		
			System.out.println("******************************");
		   
			System.out.println("**TreeLeaf**");
			treeLeaf.size();
			treeLeaf.height();
			treeLeaf.displayBreadth();
			System.out.println("");

			System.out.println("**TreeRoot**");
			treeRoot.size();
			treeRoot.height();
			treeRoot.displayBreadth();
			System.out.println("");
			
			System.out.println("******************************");
			System.out.println("About to ADD 10 to both trees.");
			int i;
			i=Input.getInteger("Proceed? (1 yes, 0 no):  ");
			System.out.println("******************************");
			if (i == 0)
				return;
			
			//-------
			
			treeLeaf.add(10); treeRoot.add(10);
			
			System.out.println("**TreeLeaf**");
			treeLeaf.size();
			treeLeaf.height();
			treeLeaf.displayBreadth();
			System.out.println("");

			System.out.println("**TreeRoot**");
			treeRoot.size();
			treeRoot.height();
			treeRoot.displayBreadth();
			System.out.println("");
			
			System.out.println("******************************");
			System.out.println("About to ADD 37 to both trees.");
			int j;
			j=Input.getInteger("Proceed? (1 yes, 0 no):  ");
			System.out.println("******************************");
			if (j == 0)
				return;
			
			//-------
			
			treeLeaf.add(37); treeRoot.add(37);
			
			System.out.println("**TreeLeaf**");
			treeLeaf.size();
			treeLeaf.height();
			treeLeaf.displayBreadth();
			System.out.println("");

			System.out.println("**TreeRoot**");
			treeRoot.size();
			treeRoot.height();
			treeRoot.displayBreadth();
			System.out.println("");
			
			System.out.println("******************************");
			System.out.println("About to ADD 16 to both trees.");
			int k;
			k=Input.getInteger("Proceed? (1 yes, 0 no):  ");
			System.out.println("******************************");
			if (k == 0)
				return;
			
			//-------
			
			treeLeaf.add(16); treeRoot.add(16);
			
			System.out.println("**TreeLeaf**");
			treeLeaf.size();
			treeLeaf.height();
			treeLeaf.displayBreadth();
			System.out.println("");

			System.out.println("**TreeRoot**");
			treeRoot.size();
			treeRoot.height();
			treeRoot.displayBreadth();
			System.out.println("");
			
			System.out.println("******************************");
			System.out.println("About to ADD 50 to both trees.");
			int l;
			l=Input.getInteger("Proceed? (1 yes, 0 no):  ");
			System.out.println("******************************");
			if (l == 0)
				return;
			
			//-------
			
			treeLeaf.add(50); treeRoot.add(50);
			
			System.out.println("**TreeLeaf**");
			treeLeaf.size();
			treeLeaf.height();
			treeLeaf.displayBreadth();
			System.out.println("");

			System.out.println("**TreeRoot**");
			treeRoot.size();
			treeRoot.height();
			treeRoot.displayBreadth();
			System.out.println("");
			
			System.out.println("******************************");
			System.out.println("About to ADD 26 to both trees.");
			int m;
			m=Input.getInteger("Proceed? (1 yes, 0 no):  ");
			System.out.println("******************************");
			if (m == 0)
				return;
			
			//-------
			
			treeLeaf.add(26); treeRoot.add(26);
			
			System.out.println("**TreeLeaf**");
			treeLeaf.size();
			treeLeaf.height();
			treeLeaf.displayBreadth();
			System.out.println("");

			System.out.println("**TreeRoot**");
			treeRoot.size();
			treeRoot.height();
			treeRoot.displayBreadth();
			System.out.println("");
			
			System.out.println("******************************");
			System.out.println("******************************");
			System.out.println("About to REMOVE 50 from both trees.");
			int o;
			o=Input.getInteger("Proceed? (1 yes, 0 no):  ");
			System.out.println("******************************");
			System.out.println("******************************");
			if (o == 0)
				return;
			
			//-------

			treeLeaf.remove(50); treeRoot.remove(50);
	
			System.out.println("**TreeLeaf**");
			treeLeaf.size();
			treeLeaf.height();
			treeLeaf.displayBreadth();
			System.out.println("");

			System.out.println("**TreeRoot**");
			treeRoot.size();
			treeRoot.height();
			treeRoot.displayBreadth();
			System.out.println("");
		
			System.out.println("******************************");
			System.out.println("About to REMOVE 37 from both trees.");
			int p;
			p=Input.getInteger("Proceed? (1 yes, 0 no):  ");
			System.out.println("******************************");
			if (p == 0)
			return;
		
			//-------

			treeLeaf.remove(37); treeRoot.remove(37);
	
			System.out.println("**TreeLeaf**");
			treeLeaf.size();
			treeLeaf.height();
			treeLeaf.displayBreadth();
			System.out.println("");

			System.out.println("**TreeRoot**");
			treeRoot.size();
			treeRoot.height();
			treeRoot.displayBreadth();
			System.out.println("");
		
			System.out.println("******************************");
			System.out.println("*****RETURNING TO NORMAL MENU*****");
			System.out.println("0: quit");
			System.out.println("1: Add 45 to both trees");
			System.out.println("2: Check for number 45 in both trees");
			System.out.println("3: Add numbers: 31,25,47,42,50 to both trees");
			System.out.println("4: Add own number to both trees.");
			System.out.println("5: Remove own number form both trees.");
			System.out.println("6: See size and height of both trees");
			System.out.println("7: Display both trees in breadthfirst");
			System.out.println("");
			System.out.println("8: Run predefined test with adding to leaf tree");
			System.out.println("9: Run same predefined test with adding at root tree");
			System.out.println("10: Watch as step by step numbers are add to both trees (5 numbers)");
			System.out.println("");
			return;
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			

	}
}