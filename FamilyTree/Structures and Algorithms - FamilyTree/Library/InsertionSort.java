public class InsertionSort{
    public static void sort(Comparable[] values){
	 	/* algorithm
		for each element from the second element in the array loop // current element
			set insertion point to the first element
			while insertion position not yet found loop
				if current element is less than the insertion point element then
					note insertion point found
					for each element from the current down to the insertion point loop
						copy from previous position into the element position
					end loop
					insert current element at insertion point
				else
					set insertion point to the next position
					if insertion position is the same as the current position then
						// element already in correct position
						note insertion position found
					end if
				end if
			end loop
		end loop
	 	*/
        boolean insertionPositionFound;
        Comparable insertValue;
		int size=ArrayUtility.getNumberOfElements(values);
        for (int current=1; current<size; current++){
            insertionPositionFound=false;
            int insertion=0;
            while (!insertionPositionFound)
                if (values[current].compareTo(values[insertion])<0){
                    insertionPositionFound=true;
                    insertValue=values[current];
                    for (int index=current;index>insertion;index--)
                        values[index]=values[index-1];
                    values[insertion]=insertValue;
                }
                else{
                    insertion++;
                    if (insertion==current)
                        insertionPositionFound=true;
                }
        }
    }
}
