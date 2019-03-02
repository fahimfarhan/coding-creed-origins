package GraphGFSPrototype1;

import java.util.Iterator;
import java.util.LinkedList;

/**
 * Created by Fahim on 11/14/2016.
 */
public class Graph {

    private int V;
    private LinkedList<Integer> adj[];
    private boolean unDir;
    private static int time;
    enum Color {white, gray, black};
    private Color color[];

    //constructor
    public Graph(int v, boolean b){
        time = 0;
        unDir = b;
        V = v;
        adj = new LinkedList[v];
        color = new Color[v];
        for(int i=0;i<v;i++)  {

            adj[i] = new LinkedList();
            //color[i];
        }
    }
    public void AddEdge(int v, int w){

        adj[v].add(w);
        if(unDir==true)
            adj[w].add(v);
    }

    void DFSUtil(int v, boolean visited[]){

        visited[v] = true;          //mark the current node as visited
        System.out.println(v);      // and print it
        time = time+1;
        int dt = time;
        System.out.println(v+"-->dt = "+dt);
        Iterator<Integer> i = adj[v].listIterator();
        while(i.hasNext()){

            int n = i.next();
            if(!visited[n]){

                DFSUtil(n, visited);
            }
        }
        time = time+1;
        int ft = time;
        System.out.println(v+"-->ft = "+ft);
    }

    public void DFS(){

        boolean visited[] = new boolean[V];
        //char color[] = new char[V];
        //for(int i=0; i<V; i++)


        for(int i=0;i<V; i++){

            if(visited[i] == false)
                DFSUtil(i, visited);
        }
    }
}


