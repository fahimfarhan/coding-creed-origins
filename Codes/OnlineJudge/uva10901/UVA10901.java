package uva10901;

import java.util.*;

class Main{
  public static void main(String[] args) {
    new UVA10901();
  }

}

class UVA10901{
  private static final Boolean LEFT = true;
  private static final Boolean RIGHT = false;
  

  public UVA10901() {
    Scanner sc = new Scanner(System.in);
    
    int T, n,t,m;

    T = sc.nextInt();
    for(int c=0; c<T; c++){
      n = sc.nextInt(); 
      t = sc.nextInt(); 
      m = sc.nextInt();
      Queue<Pair > left = new LinkedList<Pair>();
      Queue<Pair > right = new LinkedList<Pair>();
      Integer[] result = new Integer[m+1];
      
      int arrivalTime = 0; String side = "";
      for(int i=0; i<m; i++) {
        arrivalTime = sc.nextInt();
        side = sc.next();
        if(side.equals("left")) {
          left.add(new Pair(i, arrivalTime));
        }else{
          right.add(new Pair(i, arrivalTime));
        }
      }

      Integer time = 0, maximus = 0;
      Boolean toogle = LEFT;
      Queue<Integer> boat = new PriorityQueue<>();
      
      while(!( left.isEmpty() && right.isEmpty() && boat.isEmpty() ) ) {
        Integer next = 0;
        if(!left.isEmpty() && !right.isEmpty()) {
          next = Math.min(left.peek().getValue() , right.peek().getValue());
        }else if(left.isEmpty() && !right.isEmpty()) {
          next = right.peek().getValue();
        }else if(!left.isEmpty() && right.isEmpty()) {
          next = left.peek().getValue();
        }else{  break;  }

        maximus = Math.max(maximus, next);
        if(toogle == LEFT) {
          while(!left.isEmpty() && left.peek().getValue() <= maximus && boat.size() < n) {
            boat.add(left.peek().getKey());
            left.remove();
          }
        }else{
          while(!right.isEmpty() && right.peek().getValue() <= maximus && boat.size() < n) {
            boat.add(right.peek().getKey());
            right.remove();
          }
        }

        toogle = !toogle;
        maximus += t;

        while(!boat.isEmpty()) {
          result[boat.peek()] = maximus;
          boat.remove();
        }
      } 

      for(int i=0; i<m; i++) {
        System.out.println(result[i]);
      }

      if(c < T-1) {
        System.out.println("");
      }
    }

    sc.close();
  }
}

final class Pair{
  public Integer key;
  public Integer value;

  Pair(Integer key, Integer value)  {
    this.key = key;
    this.value = value;
  }

  Integer getKey() {  return key; }
  Integer getValue() {  return value;  }
}