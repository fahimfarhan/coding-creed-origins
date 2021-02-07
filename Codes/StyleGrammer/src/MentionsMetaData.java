public class MentionsMetaData {
  int start;
  int end;
  String jid;
  String tag;

  @Override
  public String toString() {
    return "MentionsMetaData{" +
        "start=" + start +
        ", end=" + end +
        ", jid='" + jid + '\'' +
        ", tag='" + tag + '\'' +
        '}';
  }
}
