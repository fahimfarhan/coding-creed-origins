import java.util.*;  
class ArrayListDemo{  
public static void main(String args[]){
    ArrayList<String> arrayList = new ArrayList<>();

    arrayList.add("xunu");
    arrayList.add("niloy");

    Iterator it = arrayList.iterator();

    while(it.hasNext()){
        System.out.println(it.next());
    }
    

    ArrayList<String> list=new ArrayList<String>();//Creating arraylist  
    list.add("Ravi");//Adding object in arraylist  
    list.add("Vijay");  
    list.add("Ravi");  
    list.add("Ajay");  
    //Traversing list through Iterator  
    Iterator itr=list.iterator();  
    while(itr.hasNext()){  
            System.out.println(itr.next());  
        }  
    }  
}  