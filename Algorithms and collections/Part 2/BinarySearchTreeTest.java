
public class BinarySearchTreeTest {
	
	public static void main(String[] args) {
	
		int inputAdd;
		int inputDel;
		int option;	
		
		BinarySearchTree treeLeaf=new BinarySearchTree(); // addLeaf
		System.out.println("Add at leaf tree created");
		BinarySearchTree treeRoot=new BinarySearchTree(true); // addRoot
		System.out.println("Add at root tree created");
		System.out.println("");
		
		System.out.println("0: quit");
		System.out.println("1: Add 45 to both trees");
		System.out.println("2: Check for number 45 in both trees");
		System.out.println("3: Add numbers: 31,25,47,42,50 to both trees");
		System.out.println("4: Add own number to both trees.");
		System.out.println("5: Remove own number form both trees.");
		System.out.println("6: See size and height of both trees");
		System.out.println("7: Display both trees in breadthfirst");
		System.out.println("");
		System.out.println("8: Run predefined test with adding to leaf tree (Proof af part A still working)");
		System.out.println("9: Run same predefined test with adding at root tree (Proof inserting at the root works)");
		System.out.println("10: Watch as step by step numbers are add to both trees and removed (5 numbers, creates seperate tree.)");
		System.out.println("");
		
		do{

			option=Input.getInteger("Input option: ");
			
			switch(option){
			
				case 1:	treeLeaf.add(45);
						treeRoot.add(45);
						System.out.println("Number 45 added");
						break;
						
				case 2:	System.out.println("Leaf tree: " + treeLeaf.contains(45));
						System.out.println("Root tree: " + treeRoot.contains(45));
						break;
						
				case 3:	treeLeaf.add(31); treeLeaf.add(25); treeLeaf.add(47); treeLeaf.add(42); treeLeaf.add(50);
						treeRoot.add(31); treeRoot.add(25); treeRoot.add(47); treeRoot.add(42); treeRoot.add(50);
						System.out.println("Numbers 31, 25, 47, 42 and 50 added");
						break;
	
				case 4: inputAdd=Input.getInteger("Input a number to add to both trees: ");
						treeLeaf.add(inputAdd);
						treeRoot.add(inputAdd);
						break;
						
				case 5:	inputDel=Input.getInteger("Input a number to delete from both trees: ");
						treeLeaf.remove(inputDel);
						treeRoot.remove(inputDel);
						break;
						
				case 6: System.out.println("Leaf Tree:");
						treeLeaf.size();
						treeLeaf.height();
						System.out.println("Root Tree:");
						treeRoot.size();
						treeRoot.height();
						break;
					
				case 7: System.out.println("Leaf Tree:");
						treeLeaf.displayBreadth();
						System.out.println("Root Tree:");
						treeRoot.displayBreadth();
						break;
						
				case 8: System.out.println("******************************");
						System.out.println("");
						System.out.println("# Display tree: #");
						System.out.println("");
						System.out.print(" - "); treeLeaf.displayBreadth();
						System.out.print(" - "); treeLeaf.size();
						System.out.print(" - "); treeLeaf.height();
						System.out.println("");
						treeLeaf.add(37);
						treeLeaf.add(40);
						treeLeaf.add(32);
						treeLeaf.add(50);
						treeLeaf.add(23);
						treeLeaf.add(6);						
						System.out.println("# Add: 37, 40, 32, 23 and 6 then display #");
						treeLeaf.displayBreadth();
						System.out.print(" - "); treeLeaf.size();
						System.out.print(" - "); treeLeaf.height();
						System.out.println("");
						System.out.println("# Does tree contain 32? #");
						System.out.print(" - "); System.out.println(treeLeaf.contains(32));
						System.out.println("");
						System.out.println("# Does tree contain 20? #");
						System.out.print(" - "); System.out.println(treeLeaf.contains(20));
						System.out.println("");
						treeLeaf.remove(50);
						treeLeaf.remove(37);
						System.out.println("# Remove 37 and 50 then display.#  ");
						treeLeaf.displayBreadth();
						System.out.print(" - "); treeLeaf.size();
						System.out.print(" - "); treeLeaf.height();
						System.out.println("");
						System.out.println("******************************");
						break;
				
						
				case 9: System.out.println("******************************");
						System.out.println("");
						System.out.println("# Display tree: #");
						System.out.println("");
						System.out.print(" - "); treeRoot.displayBreadth();
						System.out.print(" - "); treeRoot.size();
						System.out.print(" - "); treeRoot.height();
						System.out.println("");
						treeRoot.add(37);
						treeRoot.add(40);
						treeRoot.add(32);
						treeRoot.add(50);
						treeRoot.add(23);
						treeRoot.add(6);						
						System.out.println("# Add: 37, 40, 32, 23 and 6 then display #");
						treeRoot.displayBreadth();
						System.out.print(" - "); treeRoot.size();
						System.out.print(" - "); treeRoot.height();
						System.out.println("");
						System.out.println("# Does tree contain 32? #");
						System.out.print(" - "); System.out.println(treeRoot.contains(32));
						System.out.println("");
						System.out.println("# Does tree contain 20? #");
						System.out.print(" - "); System.out.println(treeRoot.contains(20));
						System.out.println("");
						treeRoot.remove(50);
						treeRoot.remove(37);
						System.out.println("# Remove 37 and 50 then display.#  ");
						treeRoot.displayBreadth();
						System.out.print(" - "); treeRoot.size();
						System.out.print(" - "); treeRoot.height();
						System.out.println("");
						System.out.println("******************************");
						break;
						
			   case 10: Teststages.run(); // Moved to a separate class to avoid clutter (very long)
			   			break;
						
			}
		}
		while(option!=0);
	}
}
