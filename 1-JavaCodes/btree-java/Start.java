import java.util.*;

public class Start{
    public static void main(String[] args) {
        BTree bTree = new BTree();
         bTree.add(5);
        
        for(int i=0; i<10; i++){
            bTree.add(i);
        }

        bTree.printAll();

    }
}