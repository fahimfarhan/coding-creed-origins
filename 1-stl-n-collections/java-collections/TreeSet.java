import java.util.*;  
public class TreeSet{  
    public static void main(String args[]){  
        //Creating and adding elements  
        TreeSet<String> set=new TreeSet<String>();  
        set.add("Ravi");  
        set.add("Vijay");  
        set.add("Ravi");  
        set.add("Ajay");  
        //traversing elements  
        Iterator<String> itr=set.iterator();  
        while(itr.hasNext()){  
            System.out.println(itr.next());  
        }  
    }  
}  