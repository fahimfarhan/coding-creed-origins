package graph;

/**
 * Created by Fahim on 11/24/2016.
 */
public class Vertex {
    String name;
    Node AdjList;
    int w; // weight of a vertex

    Vertex(String s, int w,  Node nbrs ){   //for weighted vertices

        this.name = s;
        this.w = w;
        this.AdjList = nbrs;
    }

    Vertex(String s,  Node nbrs ){  //for non-weighted vertices

        this.name = s;
        this.AdjList = nbrs;
    }
}
