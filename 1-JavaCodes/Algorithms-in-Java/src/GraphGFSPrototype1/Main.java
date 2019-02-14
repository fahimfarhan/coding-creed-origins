package GraphGFSPrototype1;

public class Main {

    public static void main(String[] args) {
	// write your code here
        Graph g = new Graph(4, false);

        g.AddEdge(0,1);
        //g.AddEdge(0,2);
       // g.AddEdge(1,2);
        //g.AddEdge(2,0);
        g.AddEdge(2,3);
        g.AddEdge(3,3);

        System.out.println("The DFS traversal is : ");

        g.DFS();

    }
}
