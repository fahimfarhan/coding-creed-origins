import java.util.ArrayList;
import java.util.Deque;
import java.util.Scanner;
import sun.misc.Queue;
/**
 * Created by Fahim
 */
public class MaxFlow {

    static Scanner read;
    static int w[][];
    static int parent[];
    static boolean vis[];
    static int n,m;

    static int path(int src, int des) throws InterruptedException {
        Queue <Integer> q = new Queue<Integer>();

        vis = new boolean[n];
        q.enqueue(src);


        int minflow = 100000;
        while(!q.isEmpty()){
            int u= q.dequeue();
            if(u==des){
                while(u!=src){
                    int par = parent[u];
                    if(w[par][u] < minflow) minflow=w[par][u];
                    u = parent[u];
                }
                return minflow;
            }
            for(int v=0; v < n; v++){
                if(w[u][v]>0 && !vis[v]){
                    vis[v]=true;
                    q.enqueue(v);
                    parent[v]=u;
                }
            }
        }
        return -1;
    }


    static int maxflow(int s, int t){
        int f=0;
        int minflow= 0;
        try {
            minflow = path(s,t);
        } catch (InterruptedException e) {
            e.printStackTrace();
        }
        while(minflow>0){

            f += minflow;

            int cur=t;
            while(cur!=s){
                int par = parent[cur];
                w[par][cur] -= minflow;
                w[cur][par] +=minflow;
                cur = parent[cur];
            }

            try {
                minflow=path(s,t);
            } catch (InterruptedException e) {
                e.printStackTrace();
            }
        }

        return f;
    }

    public static void main(String args[]){

        read = new Scanner(System.in);

        n=read.nextInt();
        m=read.nextInt();

        w=new int[n][n];
        for(int i=0; i<n; i++)//
            for(int j=0; j<n; j++)//
                w[i][j] = -1;//
        parent=new int[n];

        int u,v,c;
        while(m-->0){
            u=read.nextInt();
            v=read.nextInt();
            c=read.nextInt();

            w[u][v]=c;
        }
        read.close();


        int f = maxflow(0,n-1);
        System.out.println(""+f);
        //for(int i=0; i<n; i++) {//
         //   for (int j = 0; j < n; j++){System.out.print(" "+w[i][j]);}//
        //    System.out.println();//
       // }//
        for(int i=0; i<n; i++){
            for (int j = 0; j < n; j++){

                if(w[i][j] == 0)
                    System.out.println(""+i+" "+j);
            }

        }
    }
}
