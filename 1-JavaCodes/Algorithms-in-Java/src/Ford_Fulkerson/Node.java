package Ford_Fulkerson;

/**
 * Created by Fahim on 12/4/2016.
 */
public class Node {

    public int vnum;
    public int w; //edge weight == max capacity
    public Node next;

    Node(int vnum, Node nbr, int w){  //for weighted edges
        this.vnum = vnum;
        this.w = w;
        this.next = nbr;
    }
}
