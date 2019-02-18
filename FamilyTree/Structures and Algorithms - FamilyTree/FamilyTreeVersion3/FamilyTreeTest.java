
public class FamilyTreeTest {

	public static void main(String[] args) {
		
		String name=Input.getString("input the ancestor's name: ");

		
		FamilyTree tree=new FamilyTree(name);
		int option;
		boolean uniquechild;
		boolean found;
		boolean findpartner;
		
		tree.addPartner(Input.getString("input partner's name: "));
		
		do{
			System.out.println("0: quit");
			System.out.println("1: add child to current family member (member must have a partner)");
			System.out.println("2: add partner to a family member");
			System.out.println("3: find and set current family member");
			System.out.println("4: display current family member");
			System.out.println("5: display full family tree");
			option=Input.getInteger("input option: ");
			
			switch(option){
			
				case 1:	name=Input.getString("input the child's name: ");
						uniquechild=tree.findFamMember(name); //used to check if child name is already in use
						if(!uniquechild)
							tree.addChild(name);
						else
							System.out.println("Child name already exists");
						break;
						
				case 2:	tree.displayFamily(); //display family tree
						name=Input.getString("input member to have partner added: ");
						findpartner=tree.findFamMember(name); //finds member in tree and sets as current, identifier is name
						if(!findpartner)
							System.out.println("not found"); //if name not found problem
						else{
						name=Input.getString("input partners name: ");
						tree.addPartner(name); } //checks to see if member has a partner is not adds a partner to member
						break;
						
				case 3:	name=Input.getString("input the family members name: ");
						found=tree.findFamMember(name); //used to find a family member and set that member as current
						if(!found)						//uses a name as the identifier
							System.out.println("not found");
						break;
						
				case 4:	tree.displayFamilyMember();
						break;
						
				case 5:	tree.displayFamily();
						break;
						
			}
		}while(option!=0);
	}
}
