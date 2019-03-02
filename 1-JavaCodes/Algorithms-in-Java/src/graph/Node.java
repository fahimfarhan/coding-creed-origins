package graph;

/**
 * Created by Fahim on 11/24/2016.
 */
public class Node { // previously Neighbour

    public int Vertexnum;
    public Node next;
    public int w;

    Node(int vnum, int w,  Node nbr){  //for weighted edges
        this.Vertexnum = vnum;
        this.w = w;
        this.next = nbr;
    }

    Node(int vnum,  Node nbr){  // for non-weighted edges
        this.Vertexnum = vnum;
        this.next = nbr;
    }



}
