import java.util.*;

public class Algorithm{
    int n;
    //State state;
    Stack<State> stackState;
    public Algorithm(int n){
        this.n = n;
        stackState = new Stack<State>();
        //state = new State();

       
    }

    public void ai(){
        initialState();
        transitionModel();
    }

    public void initialState(){
        State s = new State(this.n);
        if(s.peg == null){  s.peg = new Peg[3]; s.num = n; }
        for(int i=0; i<3; i++){
            //if(s.peg[i].stack == null){
                s.peg[i].stack = new Stack<Disk>();
            //}
        }
        for(int i=n; i>0; i--){
            try{
                s.peg[0].stack.push(new Disk(i));
            }catch(Exception x){ x.printStackTrace(); }
            
        }

        stackState.push(s);
    }

    public State action(int from , int to){
        State next = new State(stackState.peek());
        Disk top = next.peg[from].stack.pop();
        next.peg[to].stack.push(top);
        return next;
    }

    public boolean transitionModel(){
        boolean b=false;
        b = goalTest();
        if(b){  return b; }
        State curr, prev;
        curr = stackState.pop();
        prev = stackState.peek();
        stackState.push(curr);

        for(int i=0; i<3; i++){
            if(b == true){  return true; }
            for(int j=0; j<3; j++){
                if(b == true){  return true; }
                if(i!=j){
                    if(isValid(curr, i, j, prev)){
                        State next = action(i, j);
                        stackState.push(next);
                        b = transitionModel();
                    }
                }
            }
        }
        return false;
    }

    public boolean isValid(State curr, int from, int to, State prev){
        boolean b = true;
        State next;
        if(
            (curr.peg[to].stack.size() == 0) || 
            (curr.peg[from].stack.peek().radius < curr.peg[to].stack.peek().radius )
        ) {
            b = true;
            next = action(from, to);
        }else{  return false; }
        
        int count=0;
        try{
            for(int i=0; i<3; i++){
                if(
                    ( (next.peg[i].stack.size()== 0) && (prev.peg[i].stack.peek().radius==0) ) ||  
                (next.peg[i].stack.peek().radius== prev.peg[i].stack.peek().radius)
                )
                {
                    count++;
                }
            }
            
        
        }catch(Exception x){
            x.printStackTrace();
        }

        if(count == 3){
            // same! 
            b = false;
        }else{ b = true; }

        return b;
    }

    public boolean goalTest(){
        if( (stackState.peek().peg[1].stack.size() == this.n) || 
        (stackState.peek().peg[2].stack.size() == n) ){
            System.out.println("Goal state reached!"); return true;
        }return false;
    }

    public void pathCost(){   System.out.println("Path cost is = "+stackState.size());  }
}