import org.junit.Test;
import org.junit.Ignore;
import static org.junit.Assert.assertEquals;

public class TestJunit3 {
    @Test
    public void myUnitTest() {
        Start s = new Start();	
        System.out.println("Inside TestJunit3.myUnitTest()");    
        assertEquals( 2, s.add(1, 1) );
        assertEquals( s.sub(3,1), 2  );
        assertEquals( s.mul(2,3), 6  );
        assertEquals( s.div(7,2), 3.5);
   }
}