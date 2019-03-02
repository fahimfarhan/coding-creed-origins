package Ford_Fulkerson;

/**
 * Created by Fahim on 12/4/2016.
 */
public class Vertex {

    public int color;
    public Node pi; //pi = parent
    public int d;
    String name;
    Node AdjList;
    //int w; // weight of a vertex

    Vertex(String s,  Node nbrs ){   //for weighted vertices

        this.name = s;
        //this.w = w;
        this.AdjList = nbrs;

        this.pi = null;
        this.d = 99999;//infinity
    }
}
