public class SortedArray implements SortedADT{
	 // implement collection using an array
    protected Comparable[] objects;
    protected int objectCount;
    public SortedArray(){
		int size;
     	size= Input.getInteger("input array size: ");
        this.objects=new Comparable[size];
    }
    public SortedArray(int size){
        this.objects=new Comparable[size];
    }

    public boolean insert(Comparable object){
	 	/* algorithm
	 	if no space available then
			display array full error message
		else
			if array empty then
				add new entry at the start of the array
			else
				set current position to start of array
				while insertion position not yet found loop
					if new entry is less than entry at current position then
						for each entry from last entry in array to the insertion position
							copy from entry position to next position in the array
						end loop
						add new entry at insertion position
					else
						if new entry matches entry at the current position then
							display duplicate entry error message
						else
							move to next position in the array
							if no more entries to check then
								add new entry after the last occupied entry
							end if
						end if
					end if
				end loop
			end if
		end if
		*/
	 	boolean inserted=false;
		// check space available
        if(this.objectCount==this.objects.length)
            System.out.println("no space available");
        else{
            int currentPosition=0;
            boolean insertionPositionFound=false;
            int insertionPosition;
            if (this.objectCount==0){
			    // insert into an empty array
                this.objects[currentPosition]=object;
                this.objectCount++;
					 inserted=true;
            }
            else
                while (!insertionPositionFound)
                    if (object.compareTo(this.objects[currentPosition])<0) {
						// insert before current position
						insertionPosition=currentPosition;
                        insertionPositionFound = true;
                        // shuffle remaining objects up one place
						for (currentPosition=objectCount-1;currentPosition>=insertionPosition;currentPosition--)
                            this.objects[currentPosition+1]= this.objects[currentPosition];
                        this.objects[insertionPosition]=object;
                        this.objectCount++;
						inserted=true;
                    }
                    else
                        if (object.compareTo(this.objects[currentPosition])==0){
                            // attempt to add duplicate
							insertionPositionFound = true;
                            System.out.println(this.objects[currentPosition]+" already exists");
                        }
                        else{
                            currentPosition++;
                            if (currentPosition==this.objectCount){
								// insert after last object
								insertionPositionFound = true;
                                this.objects[currentPosition]=object;
                                this.objectCount++;
					            inserted=true;
                            }
                        }
        }
		return inserted;
    }

    public Comparable remove(Comparable object){
	 	/* algorithm
		set current position to start of array
		while entries to be checked loop
			if required entry matches entry at the current position then
				for each entry from the next position to the end of the array loop
					copy from entry position to the previous position in the array
				end loop
			else
				if required entry is less than entry at current position then
					required entry not in the array
				else
					move to next position in the array
					if no more entries to check then
						required entry not in the array
					end if
				end if
			end if
		end loop
		*/
        int currentPosition=0;
        Comparable removedObject=null;
		// only start check if array is occupied
        boolean entriesToBeChecked=this.objectCount!=0;
        while (entriesToBeChecked)
            if (object.compareTo(this.objects[currentPosition])==0){
				// object found
                entriesToBeChecked=false;
                removedObject=this.objects[currentPosition];
                // shuffle remaining objects down one place
				for (;currentPosition<this.objectCount-1;currentPosition++)
                    this.objects[currentPosition]= this.objects[currentPosition+1];
                this.objects[currentPosition]=null;
                this.objectCount--;
            }
            else
                if (object.compareTo(this.objects[currentPosition])<0)
					// object can't be in the array
                    entriesToBeChecked=false;
                else{
                    currentPosition++;
                    if (currentPosition==this.objectCount)
					    // all objects checked so object can't be in the array
                        entriesToBeChecked=false;
                }
        return removedObject;
    }
    public Comparable find(Comparable object){
	 	/* algorithm
		while entries to be checked loop
			set current position to the midpoint of the array
			if required entry matches entry at the current position then
				match found
			else
				if required entry is less than entry at current position then
					set the end point to the point immediately before the current position
				else
					set the start point to the point immediately after the current position
				end if
				if no more entries to check then
					required entry not in the array
				end if
			end if
		end loop
		*/
		  // only start check if array is occupied
        boolean entriesToBeChecked=this.objectCount!=0;
        Comparable foundObject=null;
        int startPosition=0;
        int endPosition=this.objectCount-1;
        int midPosition;
        while (entriesToBeChecked){
            midPosition=(endPosition+startPosition)/2;
            if (object.compareTo(this.objects[midPosition])==0){
				// object found
                entriesToBeChecked=false;
                foundObject=this.objects[midPosition];
            }
            else{
                if (object.compareTo(this.objects[midPosition])<0)
					// discard upper half of array
                    endPosition=midPosition-1;
                else
					// discard lower half of array
                    startPosition=midPosition+1;
                if (startPosition>endPosition)
					// object can't be in the array
                    entriesToBeChecked=false;
            }
        }
        return foundObject;
    }
	 

    public void display(){
        for(int index=0; index<this.objectCount; index++)
           System.out.println(objects[index]);
    }
}
