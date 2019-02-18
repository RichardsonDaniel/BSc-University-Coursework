public abstract interface MergedADT extends SortedADT{
	// returns result of merging the MergedADT object on which
	// the method is called with the parameter MergedADT object
	public abstract MergedADT merge(MergedADT additionalObjects);
}
