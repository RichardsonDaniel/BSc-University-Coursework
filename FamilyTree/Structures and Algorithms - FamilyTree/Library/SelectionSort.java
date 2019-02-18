public class SelectionSort{
    public static void sort(Comparable[] values){
	 	/* algorithm
		 for each element in the array excluding the last element loop // first element
			for each remaining element in the array loop // current element
				if the current element is less than the first element then
					swap elements
				end if
			end loop
		 end loop
		*/
        Comparable temp;
		int size=ArrayUtility.getNumberOfElements(values);
        for (int first=0; first<size-1; first++){
            for (int current=first+1;current<size;current++)
                if (values[current].compareTo(values[first])<0){
                    temp=values[first];
                    values[first]=values[current];
                    values[current]=temp;
                }
        }
    }
}

