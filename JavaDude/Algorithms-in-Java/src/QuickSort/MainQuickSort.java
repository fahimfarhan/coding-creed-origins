package QuickSort;

/**
 * Created by Fahim on 11/19/2016.
 */
public class MainQuickSort {

    public static void main(String [] args){

        int a[] = {10, 7, 8, 9, 1, 5};
        int len = a.length;
        QuickSort qs = new QuickSort();
        qs.PrintArray(a);
        qs.Sort(a, 0, len-1);
        System.out.println("The sorted array is : ");
        qs.PrintArray(a);

    }

}
