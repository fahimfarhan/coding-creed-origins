package uva10226;

import java.util.*;

class Main{
  public static void main(String[] args) {
    new UVA10226();  
  }
}

class UVA10226 {
  public UVA10226() {
    Scanner sc = new Scanner(System.in);
    
    int T, kount;
    String s;
    TreeMap<String, Integer> mp = new TreeMap<String, Integer>();

    String testCase;
    testCase = sc.nextLine();
    T = Integer.parseInt(testCase);
    s = sc.nextLine();
    // s = sc.nextLine();
    for(int c = 0; c < T; c++) {
      mp.clear();
      kount = 0;
      while(true) {
        if(sc.hasNext()) {
          s = sc.nextLine();
        }else{
          break;
        }

        if(s.isEmpty()) {  break; }
        int value = 0;
        if(mp.get(s) !=null) {
          value = mp.get(s);
        }
        value++;
        mp.put(s, value);
        kount++;  
      }

      for(String key: mp.keySet()) {
        float percentage = (float) (mp.get(key)*100.0 / kount);
        System.out.printf("%s %.4f\n", key, percentage);
        // System.out.println(key+" "+percentage);
      }
      if(c < T-1) {
        System.out.println("");
      }
    }
    sc.close();
  } 
  
}
