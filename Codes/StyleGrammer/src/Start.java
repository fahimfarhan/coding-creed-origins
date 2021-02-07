import java.util.*;
import java.util.concurrent.ConcurrentHashMap;

public class Start {
  public static void main(String[] args) {
    String input = "A `quick brown` @Anik fox ~jumped @Nafix over~ *the lazy @Tanmoy dog!* _roma_victor__ **asdf***";
    //-----------------------------------------------------------------------------------------------
    ConcurrentHashMap<String, MentionsMetaData> mp = new ConcurrentHashMap<>();
    MentionsMetaData anikmmd = new MentionsMetaData();
    anikmmd.start = 16; anikmmd.end = 16+5;
    MentionsMetaData nafismmd = new MentionsMetaData();
    nafismmd.start = 34; anikmmd.end = 34+6;

    MentionsMetaData tanmoymmd = new MentionsMetaData();
    tanmoymmd.start = 57; tanmoymmd.end = 57+7;
/*
    16  @Anik
    34  @Nafis
    57  @Tanmoy
    */
    String anik = input.substring(16, 16+5);
    String nafis = input.substring(34, 34 + 6);
    String tanmoy = input.substring(57, 57+7);

    mp.put(anik, anikmmd);
    mp.put(tanmoy, tanmoymmd);
    mp.put(nafis, nafismmd);
//-----------------------------------------------------------------------------------------------
    StyleParser styleParser = new StyleParser(input);
    String output = styleParser.applyStyle();
    styleParser.refreshActualMentions(mp, output);
    ArrayList<MentionsMetaData> metaDataArrayList = styleParser.getMetaDataArrayList();

    System.out.println("----------------------------------------------");

    System.out.println(output);

    System.out.println("----------------------------------------------");

    for(MentionsMetaData mmd: metaDataArrayList) {
      System.out.println(mmd.tag+" "+output.substring(mmd.start, mmd.end));
    }
    System.out.println("----------------------------------------------");
//    for(int i=0; i<input.length(); i++) {
//      if(input.charAt(i) == '@') {
//        System.out.println(i);
//      }
//    }
//    System.out.println(anik);
//    System.out.println(nafis);
//    System.out.println(tanmoy);


    System.out.println("----------------------------------------");

    System.out.println(output);

    String test = "\uD83D\uDD25fire your terminal and invoke some commands: $ sudo apt upgrade @mamakoko and @Vaas";
    String temp = "[{\"e\":6,\"s\":2,\"t\":\"_\"},{\"e\":20,\"s\":12,\"t\":\"*\"}," +
        "{\"e\":31,\"s\":25,\"t\":\"~\"}," +
        "{\"e\":65,\"s\":47,\"t\":\"`\"}," +
        "{\"e\":75,\"j\":\"10000493642@ejabberd.ridmik.net\",\"s\":66,\"t\":\"m\"}," +
        "{\"e\":85,\"j\":\"10000450219@ejabberd.ridmik.net\",\"s\":80,\"t\":\"m\"}]";

    System.out.println(test+"\n----------------------\n");
    System.out.println(test.substring(66, 75));
    System.out.println(test.substring(80, 85));
  }
}
