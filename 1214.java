import java.util.*;
import java.math.*;
class Main{
    public static void main(String args[])
    {
        Scanner sc=new Scanner(System.in);
        int t;
        t=sc.nextInt();
        int casE=1;
        while(t-->0)
        {
            BigInteger x=sc.nextBigInteger();
            x=x.abs();
            BigInteger a=sc.nextBigInteger();
            a=a.abs();
            System.out.printf("Case %d: ",casE++);
            x=x.mod(a);
            if(x.equals(BigInteger.ZERO)==true)
            {
                System.out.println("divisible");
            }
            else{
                System.out.println("not divisible");
            }
        }
    }
}
