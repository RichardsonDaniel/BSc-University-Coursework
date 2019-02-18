public class MergeSort{
    public static void sort(Comparable[] values){
        class Merge{
            void sort(Comparable[] values, int start, int end){
            	/* algorithm
					if can split array further
						calculate the midpoint of the array
						sort the left half of the array
						sort the right half of the array
						merge the sorted arrays
					end if
				*/
                int midpoint;
                if (start<end) {
                    midpoint=(start+end)/2;
                    sort(values,start,midpoint);
                    sort(values,midpoint+1,end);
                    merge(values,start,end);
                }
            }
            void merge(Comparable[] values,int start,int end){
            	/* algorithm
					create an array based on the left array
					create an array based on the right array
					merge the left and right arrays
					copy from the merged array to the original
				*/
				int midpoint=(start+end)/2;
 				MergedADT left=new MergedArray(midpoint-start+1);
				MergedADT right=new MergedArray(end-midpoint);
				for (int index=start;index<=midpoint;index++)
					left.insert(values[index]);
				for (int index=midpoint+1;index<=end;index++)
					right.insert(values[index]);
				MergedADT merged=left.merge(right);
				Comparable[] sortedValues=((MergedArray)merged).getObjects();
				for (int index=start,count=0;index<=end;index++,count++){
                    values[index]=sortedValues[count];
                }
            }
        }
		int size=ArrayUtility.getNumberOfElements(values);
        new Merge().sort(values,0,size-1);
    }
}
