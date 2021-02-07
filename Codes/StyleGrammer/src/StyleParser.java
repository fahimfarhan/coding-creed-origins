import java.util.ArrayList;
import java.util.Arrays;
import java.util.List;
import java.util.Map;
import java.util.concurrent.ConcurrentHashMap;

public class StyleParser {
  private String input;
  private int inputStringLength;
  private final static List<Character> KEYWORDS = Arrays.asList('*', '_', '~', '`');

  private ArrayList<MentionsMetaData> metaDataArrayList = new ArrayList<>();

  ArrayList<MentionsMetaData> getMetaDataArrayList() {
    return metaDataArrayList;
  }

  StyleParser(String input) {
    this.input = input;
    this.inputStringLength = input.length();
  }
  boolean findFirst(char ch) {
    return KEYWORDS.contains(ch);
  }

  FollowOutput followRule(int indexAfterFirst, char tagCharacter) {
    int j = indexAfterFirst;
    FollowOutput followOutput = new FollowOutput();
    followOutput.isMatchFound = false;

    while (j < inputStringLength) {
      if(input.charAt(j) == tagCharacter) {
        if(
            ((j + 1) < inputStringLength && Character.isWhitespace(input.charAt(j+1)) )
            ||
                ((j + 1) == inputStringLength)
        ) {
          // match found I guess
          followOutput = new FollowOutput();
          followOutput.isMatchFound = true;
          followOutput.matchedSubString = input.substring(indexAfterFirst, j);
          followOutput.endIndex = j+1;
          // return followOutput;
          break;
        }
      }
      j++;
    }
    return followOutput;
  }

  String applyStyle() {
    StringBuilder output = new StringBuilder();
    int i=0;
    while(i<inputStringLength) {
//      System.out.printf("debug "+i+" ");
      char tag = input.charAt(i);
      /*if(tag == '@') {
        System.out.println("tag = @ found");
        if( (i == 0) || Character.isWhitespace(input.charAt(i - 1)) ) {
          // find the mention
          int j=i;
          String candidateMention = null;
          while (j < inputStringLength-1) {
            if(Character.isWhitespace(input.charAt(j+1))) {
              break;
            }
            j++;  // todo: watch out!
          }
          candidateMention = input.substring(i,j+1);
          System.out.println("candidateMention = "+candidateMention);
          output = output.append(candidateMention);
          i = j+1;
        }else{
          i++; // todo: watch out!
        }
      } else */
      if(findFirst(tag)) {
        int nextIndex = i + 1;
        FollowOutput followOutput = followRule(nextIndex, tag);
        if(followOutput.isMatchFound) {
          MentionsMetaData mmd = new MentionsMetaData();
          mmd.start = output.length();
          output.append(followOutput.matchedSubString);
          mmd.end = output.length();
          mmd.tag = ""+tag;
          metaDataArrayList.add(mmd);

          i = followOutput.endIndex;
        }
      }else{
        output.append(input.charAt(i));
        i++;
      }
    }
    return output.toString();
  }

  void refreshActualMentions(ConcurrentHashMap<String, MentionsMetaData> mp, String output) {
    int dx = input.length() - output.length();
    for(Map.Entry<String, MentionsMetaData> ithPair: mp.entrySet()) {
      MentionsMetaData currMmd = ithPair.getValue();
      int s = Math.max(0, currMmd.start - dx);
      int e = currMmd.end;
      int d = currMmd.end - currMmd.start;

//      System.out.println("-------------- Potential candidates --------------------------");

      for(int i=s; i < s + dx; i++) {
//        System.out.println("Potential candidates 2");
//        System.out.println(output.charAt(i));
        if(output.charAt(i) == '@' ) {
          String candidate = output.substring(i, i+ithPair.getKey().length());
          if(candidate.equals(ithPair.getKey())) {
            System.out.println("ithCandidate = "+candidate);
            MentionsMetaData mmd = new MentionsMetaData();
            mmd.start = i;
            mmd.end = i+ithPair.getKey().length();
            mmd.tag = "m";
            mmd.jid = currMmd.jid;

            metaDataArrayList.add(mmd);
          }
        }
      }
    }
  }
}
