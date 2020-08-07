import java.util.*;

public class BTree{
    Node root;

    public BTree(){}

    private void printer(Node node){
        if(node == null){   return; }
        printer(node.left);
        System.out.println(node.value);
        printer(node.right);
    }

    public void printAll(){
        printer(root);
    }

    public void add(int i){
        if(root == null){
            root = new Node(i);
            return;
        }

        Node ptr = root;
        while(true){
            if(ptr.value == i){ return; }
            else if( (i < ptr.value) && (ptr.left != null) ){
                // go left
                ptr = ptr.left;
            }else if( (i < ptr.value) && (ptr.left == null) ){
                // assign left
                ptr.left = new Node(i);
                return;
            }else if( (i > ptr.value) && (ptr.right != null) ){
                // go right
                ptr = ptr.right;
            }else if( (i > ptr.value) && (ptr.right == null) ){
                // assign right
                ptr.right = new Node(i);
                return;
            }
        }
    }

}