public class QuickSort{
    public static void sort(Comparable[] values){
        class Quick{
            void sort(Comparable[] values, int start, int end){
				/* algorithm
					if elements to be sorted
						partition the array about the pivot value
						sort the left subarray (values up to the new position of the pivot value)
						sort the right subarray (values from the new position of the pivot value)
					end if
				*/
                if (start<end){
                    int pivot=partition(values,start,end);
                    sort(values,start,pivot-1);
                    sort(values,pivot+1,end);
                 }
            }
            int partition(Comparable[] values, int start, int end){
				/* algorithm
					copy first element of the array to the pivot value
					for each element from the second element to the end of the array loop
						if element to be swapped with pivot value then
							copy the element to be swapped to the pivot value position
							copy the element after the pivot value position to the element position of the element just swapped
							copy the pivot value to the next position
							note the new pivot value position
						end if
					end loop
				*/
                Comparable pivotValue=values[start];
                int pivotIndex=start;
                for (int index=start+1;index<=end;index++)
                   if(values[index].compareTo(pivotValue)<0){
                       values[pivotIndex]=values[index];
                       values[index]=values[pivotIndex+1];
                       values[pivotIndex+1]=pivotValue;
                       pivotIndex++;
                   }
                return pivotIndex;
            }
        }
		int size=ArrayUtility.getNumberOfElements(values);
        new Quick().sort(values,0,size-1);
    }
}
