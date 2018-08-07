import java.util.*;

public class BinarySearch{

    public static void main(String[] Args){
        int[] a;
        a = new int[]{1,4,7,3,8,2,9};
        Arrays.sort(a);
        for(int i=0; i<a.length; i++){
            System.out.print(a[i]+" ");
        }
        System.out.println("");

        int x = Arrays.binarySearch(a, 8);
        System.out.println("Arrays.binarySearch(a, 8) = "+x);
        int u = upperBound(a, a.length, 8);
        System.out.println("upper_bound(a, a.length, 8) = "+u);
        int l = lowerBound(a, a.length, 8);
        System.out.println("lower_bound(a, a.length, 8) = "+l);
    }

    public static int upperBound(int[] array, int length, int value) {
        int low = 0;
        int high = length;
        while (low < high) {
            final int mid = (low + high) / 2;
            if (value >= array[mid]) {
                low = mid + 1;
            } else {
                high = mid;
            }
        }
        return low;
    }

   
    public static int lowerBound(int[] array, int length, int value) {
        int low = 0;
        int high = length;
        while (low < high) {
            final int mid = (low + high) / 2;
            if (value <= array[mid]) {
                high = mid;
            } else {
                low = mid + 1;
            }
        }
        return low;
    }
}