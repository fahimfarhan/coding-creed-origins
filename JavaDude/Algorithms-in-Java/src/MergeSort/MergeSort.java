package MergeSort;

/**
 * Created by Fahim on 11/17/2016.
 */
public class MergeSort {
   // int count;
    MergeSort(){       }

    int Merge(int arr[], int l, int m, int r){

        int count =0;
        int n1 = m-l+1;
        int n2 = r-m;

        int L[] = new int[n1];
        int R[] = new int[n2];

        for(int i=0;i<n1; i++){

            L[i] = arr[l+i];
        }
        for(int j=0;j<n2; j++){

            R[j] = arr[m+1+j];
        }

        int i=0, j=0;
        int k=l;
        while(i<n1 && j<n2){

            if(L[i] <= R[j]){
                arr[k] = L[i];
                i++;
            }else{
                arr[k] = R[j];
                j++;
                count++;
            }
            k++;

        }
        //copying the remaining elements of the array
        while(i<n1){
            arr[k] = L[i];
            i++;
            k++;
        }
        while(j<n2){
            arr[k] = R[j];
            j++;
            k++;
        }
        return count;
    }

    int sort(int arr[], int l, int r){
        int c=0;
        if(l<r){

            int m = (l+r)/2;

            int c1 = sort(arr, l , m);
            int c2 = sort(arr, m+1,r);
            int c3 = Merge(arr, l, m, r);

            c = c1+c2+c3;
            return c;
        }
        return 0;
    }

    void PrintArray(int arr[]){

        int len = arr.length;
        for(int i=0;i<len; i++)
            System.out.print(""+arr[i]+" ");
        //System.out.println("Num of Inversions = "+count);
    }
}
