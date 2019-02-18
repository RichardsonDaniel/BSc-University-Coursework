
public class FamilyTree {
	
	private class FamilyTreeNode{
		private FamilyTreeNode treetop;
		private String name;
		private FamilyTreeNode partner;
		private FamilyTreeNode sibling;
		private FamilyTreeNode child;
	}
	
	private FamilyTreeNode ancestor;
	private FamilyTreeNode current;
	
	public FamilyTree(String ancestorName){
		this.ancestor=new FamilyTreeNode();
		this.ancestor.name=ancestorName;
		this.current=this.ancestor;
	}
	
	//
	// Addition to the tree structure
	//
	
	public void addChild(String name){
		FamilyTreeNode child=new FamilyTreeNode();
		child.name=name;
		child.treetop=current;
			if(current.child==null)
				current.child=child;
			else{
				FamilyTreeNode next=current.child;
				while(next.sibling!=null)
					next=next.sibling;
					next.sibling=child;
			}
		}
	
	public void addPartner(String name){
		FamilyTreeNode partner=new FamilyTreeNode();
		partner.name=name;
		partner.treetop=current;
		current.partner=partner;
	}
	
	//
	// Searching the tree for identifiers/names
	//
	
	public boolean findFamMember(String name){
		boolean found=false;
		FamilyTreeNode member=this.ancestor;
		if(name.equalsIgnoreCase(member.name))
			found=true;
		else{
			FamilyTreeNode saved=member;
			member=this.checkChild(saved,name);
			if(member!=null)
				found=true;
			}
		if(found){
			this.current=member;
			this.displayFamily();
		}
		return found;
	}
		
	private FamilyTreeNode checkChild(FamilyTreeNode check,String name){
		FamilyTreeNode Child=check.child;
		boolean searching=true;
		while(searching)
			if(Child==null)
				searching=false;
			else
				if(Child.name.equalsIgnoreCase(name))
					searching=false;
				else
					Child=Child.sibling;
		return Child;
	}
	
	//displays full tree from the beginning
	public void displayFamily(){
		FamilyTreeNode partner=ancestor.partner;
		FamilyTreeNode member;
		member=ancestor.child;
		System.out.print(ancestor.name);
		
		System.out.println(" partner: "+partner.name);
		partner=partner.partner; 
			
		while(member!=null){
			System.out.print("  "+member.name);
			this.displayChild(member);
			System.out.println("    ");
			member=member.sibling;
		}
	}
	
	//used to display family down the tree
	private void displayChild(FamilyTreeNode current){
		FamilyTreeNode child=current.child;
		while(child!=null){
			System.out.print("    "+child.name);
			System.out.println("    ");
			child=child.sibling;
		}
	}
}
