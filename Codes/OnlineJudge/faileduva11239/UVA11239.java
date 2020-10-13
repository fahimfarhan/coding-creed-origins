package faileduva11239;

import java.util.*;

class Main{
  public static void main(String[] args) {
    
  }
}

final class Pair{
  public Integer key;
  public String value;

  Pair(Integer key, String value)  {
    this.key = key;
    this.value = value;
  }

  public Integer getKey() {  return key; }
  public void setKey(Integer key) {  this.key = key; }
  public String getValue() {  return value;  }
  public void setValue(String value) {  this.value = value; }
}

class UVA11239{
  /** Konsts/Statics */ 
  private static final String BLACKLIST = "_"; 
  /** Variables */
  private Scanner sc;

  /** Konstructors */
  UVA11239() {
    sc = new Scanner(System.in);
    while(true) {
      start();
    }
  }

  /** Private methods */
  private boolean isUpperCase(char ch){
    return (('A' <= ch) && (ch<='Z'));
  }
 
  private void start() {
    TreeMap<String, Integer> summary = new TreeMap<>();
    TreeMap<String, String> isEnrolled = new TreeMap<>();
    String line = "";
    String lastProjectName = "";

    while(sc.hasNext()) {
      line = sc.nextLine();
      if(line.equals("0")) {
        System.exit(0);
      }
      if(line.equals("1")) {
        // todo: calc results
        ArrayList<Pair> results = new ArrayList<>();
        for(Map.Entry<String,Integer> entry : summary.entrySet()) {
          String key = entry.getKey();
          Integer value = entry.getValue();
        
          results.add(new Pair(value, key));
        }

        Comparator comparator = new Comparator<Pair>(){
          @Override
          public int compare(Pair a, Pair b) {
            if( a.getKey() > b.getKey()) return 1;
            else if(a.getKey() == b.getKey()) {
                return a.getValue().compareTo(b.getValue());
              }
              return 0;
            }
        };

        Collections.sort(results, comparator);

        for(int i=0; i < results.size(); i++) {
          System.out.println(results.get(i).getValue() +" "+results.get(i).getKey());
        }

        break;
      }else if( isUpperCase(line.charAt(0)) ) {
        // this is a Project name
        lastProjectName = line;
        summary.put(lastProjectName, 0);
      }else{
        // this is a username
        if(isEnrolled.get(line) == null) {
          isEnrolled.put(line, lastProjectName);
          int num = summary.get(lastProjectName);
          num++;
          summary.put(lastProjectName, num);
        }else if(isEnrolled.get(line) != lastProjectName) {
          String key = isEnrolled.get(line);
          if(!key.equals(BLACKLIST)) {
            Integer num = summary.get(key);
            if(num == null) { num = 0; }
            num--;
            summary.put(key, num);
            isEnrolled.put(line, BLACKLIST);
          }
        }
      }
    }
  }
}