import java.util.*;

public class ShantanuReverseString{
  public static void main(String[] args) {
    String input = "i like this program very much";
    String[] words = input.split(" ");
  
    String output = words[words.length-1];
    int N = words.length;
    for(int i=N-2; i>=0; i--) {
      output = output + " " + words[i];
    }

    System.out.println(output);
  }
}