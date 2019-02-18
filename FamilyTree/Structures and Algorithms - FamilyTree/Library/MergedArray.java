public class MergedArray extends SortedArray implements MergedADT{
    public MergedArray(){
    }
    public MergedArray(int size){
        super(size);
    }
    public MergedADT merge(MergedADT additionalObjects){
	 	/* algorithm
		while entries in both arrays loop
	   		if entry in array1 is less than entry in array2
				copy entry from array1 into merged array
			else
				if entry in array1 is greater than entry in array2
					copy entry from array2 into merged array
				else // duplicate entries could copy from either array1 or array2
					copy entry from array1 into merged array
				end if
			end if
		end loop
		if at end of array1 then
		   for each remaining entry in array2 loop
			   copy entry from array2 into merged array
			end loop
		else
		   for each remaining entry in array1 loop
			   copy entry from array1 into merged array
			end loop
		end if 
		*/	 
        // create merged array based on the occupancy of the arrays to be merged
    	MergedArray additionalArray=(MergedArray)additionalObjects;    
		MergedArray mergedObjects=new MergedArray(this.objectCount+additionalArray.objectCount);
        int thisIndex=0;
        int additionalIndex=0;
        int mergedIndex=0;
        while((thisIndex!=this.objectCount)&&(additionalIndex!=additionalArray.objectCount))
        	if(this.objects[thisIndex].compareTo(additionalArray.objects[additionalIndex])<0){
        		// copy object from this array
                mergedObjects.objects[mergedIndex]=this.objects[thisIndex];
                mergedIndex++;
                thisIndex++;
        	}
        	else
        		if (this.objects[thisIndex].compareTo(additionalArray.objects[additionalIndex])>0){
        			// copy object from additional array
                    mergedObjects.objects[mergedIndex]=additionalArray.objects[additionalIndex];
                    mergedIndex++;
                    additionalIndex++;
        		}
                else{
                	// duplicate object, copy object from this array
                    mergedObjects.objects[mergedIndex]=this.objects[thisIndex];
                    mergedIndex++;
                    thisIndex++;
                    additionalIndex++;
                }
        if (thisIndex==this.objectCount)
        	// at end of this array
        	// copy remaining objects from additional array
        	for(;additionalIndex<additionalArray.objectCount;additionalIndex++){
        		mergedObjects.objects[mergedIndex]=additionalArray.objects[additionalIndex];
        		mergedIndex++;
        	}
        else
        	// at end of additional array 
        	// copy remaining objects from this array
        	for(;thisIndex<this.objectCount;thisIndex++){
        		mergedObjects.objects[mergedIndex]=this.objects[thisIndex];
        		mergedIndex++;
        	}
        mergedObjects.objectCount=mergedIndex;
        return mergedObjects;
    }
	 
	 public Comparable[] getObjects(){
	 	return this.objects;
	}

}