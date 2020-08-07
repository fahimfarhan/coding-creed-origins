package QuickSort;

/**
 * Created by Fahim on 11/19/2016.
 */
public class QuickSort {

    QuickSort(){}
    public int partition(int []a, int low, int high){

        int pivot = a[high];
        int i = low-1;
        for(int j = low; j<high; j++) {

            if(a[j]<=pivot){

                i++;
                //swap a[i] and a[j]
                a[i] = a[i]^a[j];
                a[j] = a[i]^a[j];
                a[i] = a[i]^a[j];
            }
        }
        //swap a[i+1] with a[high] also the pivot
        a[i+1] = a[i+1]^a[high];
        a[high] = a[i+1]^a[high];
        a[i+1] = a[i+1]^a[high];

        return i+1;
    }

    public void Sort(int a[], int low, int high){

        if(low<high){

            int pi = partition(a, low, high);
            Sort(a, low , pi-1);
            Sort(a, pi+1, high);
        }
    }

    public void PrintArray(int []a){

        for(int i=0; i<a.length; i++)
            System.out.print(""+a[i]+" ");
        System.out.print("\n");
    }
}
