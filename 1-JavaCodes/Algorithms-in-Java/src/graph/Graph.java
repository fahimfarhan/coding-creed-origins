package graph;

import java.io.File;
import java.io.FileNotFoundException;
import java.util.Scanner;

/**
 * Created by Fahim on 11/24/2016.
 */
public class Graph {

    Vertex [] adjLists;
    Graph(String file) throws FileNotFoundException{

        File f = new File(file);
        Scanner sc = new Scanner(f);

        String GraphType = sc.next();
        boolean undirected = true;
        if(GraphType.equals("directed")){   undirected = false; }

        adjLists = new Vertex[sc.nextInt()];//enter the num of nodes

        //read the vertices
        for(int i=0; i<adjLists.length; i++){

            adjLists[i]= new Vertex(sc.next(), null);
        }
        //read edges
        while(sc.hasNext()){
            int v1 = IndexForName(sc.next());
            int v2 = IndexForName(sc.next());
            if((v1 != -1) || (v2 != -1)){
                adjLists[v1].AdjList = new Node(v2, adjLists[v1].AdjList);
                if(undirected) {    adjLists[v2].AdjList = new Node(v1, adjLists[v2].AdjList);     }
            }else{System.out.println("Invalid input! :o"); }
        }
    }

    public int IndexForName(String name){

        for(int i=0; i<adjLists.length; i++){

            if(adjLists[i].name.equals(name))
                return i;
        }
        return -1;
    }

    public void print(){

        System.out.println();
        for(int i=0; i<adjLists.length; i++){

            System.out.print(adjLists[i].name);
            for(Node nbr = adjLists[i].AdjList; nbr != null; nbr = nbr.next){

                System.out.print(" --> "+ adjLists[nbr.Vertexnum].name);
            }
            System.out.println();
        }
    }
}
