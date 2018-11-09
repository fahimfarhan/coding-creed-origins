package MergeSort;

/**
 * Created by Fahim on 11/17/2016.
 */
public class MainMergeSort {
    public static void main(String args[]){
        MergeSort obj = new MergeSort();

        int a[] = {2,4,1,3,5};
        System.out.println("Given Array: ");
        obj.PrintArray(a);

        int inversion = obj.sort(a, 0, a.length-1);
        System.out.println("Sorted Array: ");
        obj.PrintArray(a);
        System.out.println("\n"+inversion );

    }
}
