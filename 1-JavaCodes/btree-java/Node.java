import java.util.*;

public class Node {
    public int value;
    public Node left;
    public Node right;
    

    public Node(int value){
        System.out.println("created node: "+value);
        this.value = value;
        this.left = null;
        this.right = null;
    }
    @Override
    public String toString() {
        return ""+value;
    }    
}