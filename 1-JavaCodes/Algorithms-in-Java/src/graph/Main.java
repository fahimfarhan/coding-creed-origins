package graph;

import java.io.IOException;
import java.util.Scanner;

public class Main {

    public static void main(String[] args) throws IOException {
	// write your code here

        Scanner sc = new Scanner(System.in);
        System.out.println("Enter the file name: ");
        String file = sc.nextLine();

        Graph graph = new Graph(file);
        graph.print();
    }
}
