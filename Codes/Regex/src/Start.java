import java.util.regex.Matcher;
import java.util.regex.Pattern;

public class Start {


  static void demo1() {
    final String REGEX = "[a-zA-Z]+";// "\\bcat\\b|\\bdog\\b";
    final String INPUT = "cat cat cat cattie cat dogd dog dog Dog";

    Pattern p = Pattern.compile(REGEX);
    Matcher m = p.matcher(INPUT);   // get a matcher object
    int count = 0;

    while (m.find()) {
      count++;
      System.out.println("Match number " + count);
      System.out.println("start(): " + m.start());
      System.out.println("end(): " + m.end());
      System.out.println("--------------------------------------");
    }
  }

  static void matchRegexPattern(String regex) {
    String input = "@The @quick @brown fox @jumped over the @lazy 1 23 4 @dog";
    matchRegexPattern(regex, input);
  }
  static void matchRegexPattern(String regex, String input) {
    Pattern p = Pattern.compile(regex);
    Matcher m = p.matcher(input);   // get a matcher object
    int count = 0;

    while (m.find()) {
      count++;
      int start = m.start();
      int end = m.end();
      String output = input.substring(start, end);
      System.out.println(""+count+" "+output+" "+start+" "+end);
      System.out.println("--------------------------------------");
    }
    System.out.println("-----End------\n\n");
  }

  static void CharacterClass() {
    String simpleMatchesABC = "[abc]";

//    matchRegexPattern(simpleMatchesABC);

//    String matchExceptABC = "[\\^abc]";  // tutorial e \ thakle java te \\ dite hoy
    String matchExceptABC = "[^abc]"; // tutorial e [\^abc] chhilo. javay [^abc] :/
//    matchRegexPattern(matchExceptABC);

    String rangedSearchCharacters = "[a-z]";
//    matchRegexPattern(rangedSearchCharacters);

    String unionMatch = "[a-cf-h]"; // "[[a-c][f-h]]" "[[a-c]|[f-h]]"
//    matchRegexPattern(unionMatch);

    String intersectoinMatch = "[[a-c]&&[b-c]]"; // "[a-c&&b-c]"
    // matchRegexPattern(intersectoinMatch);

    String substractMatch = "[[a-c]&&[^b-c]]";
    // matchRegexPattern(substractMatch);
  }

  static void predefinedCharacterClassesInJavaRegex() {
    /**
     * \d     a digit
     * \D     a non-digit
     * \s     a whitespace
     * \S     a non-WhiteSpace
     * \w     a character
     * \W     a non-character
     * */
    String digit = "\\d";
    // matchRegexPattern(digit);

    String nonDigit = "\\D";
    String space = "\\s";
    String nonSpace = "\\S";
    String alphaNumeric = "\\w";
    String nonAlphaNumeric = "\\W";

    matchRegexPattern(nonAlphaNumeric);
  }

  static void boundaryMatcher() {
    /**
     * ^    the beginning of a line
     * $    the end of line
     * \b   a word boundary
     * \B   a non word boundary
     * \A   the beginning of input
     * \G   the end of previous match
     * \Z   The end of the input but for the final terminator, if any.
     * \z   the end of input
     * */
    String theBeginningCharacter = "^\\w";
    // matchRegexPattern(theBeginningCharacter);

    String theStartWord = "^[\\w]+"; // Output = 1st word of the sentence = "The"
    // matchRegexPattern(theStartWord);

    String endingWord = "[\\w]+$"; // oytput = last word = "dog"
    // matchRegexPattern(endingWord);

    String theSentence = "^[\\w\\W]+$";
    // matchRegexPattern(theSentence);

    String detectMentions = "@[\\w]+";
    // matchRegexPattern(detectMentions);

    String lastMention = detectMentions + "$";
    matchRegexPattern(lastMention);
  }

  public static void main(String[] Args) {
    // CharacterClass();
    // predefinedCharacterClassesInJavaRegex();
    boundaryMatcher();
  }
}
