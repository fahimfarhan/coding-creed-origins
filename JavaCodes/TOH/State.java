import java.util.*;


public class State{
    int num;
    Peg[] peg;
    public State(int n){
        this.num = n;
        this.peg = new Peg[3];
    } 

    public State( State clone){
        this.num = clone.num;
        this.peg = clone.peg;
    }
}
