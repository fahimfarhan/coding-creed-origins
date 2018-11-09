package Ford_Fulkerson;

import java.io.File;
import java.io.FileNotFoundException;
import java.util.Scanner;

/**
 * Created by Fahim on 12/4/2016.
 */
public class GraphFF {

    final int White = 0;
    final int Gray  = 1;
    final int Black = 2;

    Vertex []adjLists;
    GraphFF(String file) throws FileNotFoundException{

        File f = new File(file);
        Scanner sc = new Scanner(f);
        adjLists = new Vertex[sc.nextInt()];
        //read the vertices
        for(int i=0; i<adjLists.length; i++){

            adjLists[i] = new Vertex(sc.next(), null);
        }
        //new read the edges
        while(sc.hasNext()){
            int v1 = IndexForName(sc.next());
            int v2 = IndexForName(sc.next());
            int w = sc.nextInt();
            if((v1 != -1) || (v2 != -1)){
                adjLists[v1].AdjList = new Node(v2, adjLists[v1].AdjList, w);
                //if(undirected) {    adjLists[v2].AdjList = new Node(v1, adjLists[v2].AdjList);     }
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

    boolean Bfs(){

        return true;/*pore ei line muchhe dite hobe*/
    }


}
