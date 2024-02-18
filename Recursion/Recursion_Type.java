package Recursion;
// 4. Indirect Recursion
class IndirectRecursion {
    public void funA(int x) {
        if (x > 0) {
            System.out.print(x + " ");
            funB(x-1);
        }
    }

    public void funB(int x) {
        if (x > 1) {
            System.out.print(x + " ");
            funA(x/2);
        }
    }
}
// 5 . Nested Recursion //
class Nested_Recursion {
    protected int fun(int x) {
        if (x > 100) {
            return x-10;
        } else {
            return fun(fun(x + 11));
        }
    }
}
public class Recursion_Type {
    public static void main(String[] args) {


        /*
            * Type Of Recursion *
            1. Tail Recursion
            *   -> The Recursive Call Is The Last Recursive Call Of The Statement
            * Example :
            *   void fun(int x) {
            *       if(x>0) {
            *           System.out.println(x);
            *           fun(x-1);   <-   Known As Tail Recursion
            *       }
            *   }


            2. Head Recursion :
               -> The Recursion Call In The Start Before The Returning Anything .
               Example
               *    private static void fun(int x) {
                        if (x > 0) {
                            fun(x-1);
                            System.out.println(x);
                        }
                    }

              3. Tree Recursion : The Recursive Call Which Call Itself More Than One Time, Then It Is Known As Tree Recursion .

              Example :
                    void fun(int a) {
                    *   if(a>0) {
                    *       System.out.println(a);
                    *       fun(a-1);
                    *       fun(a-1);
                    *   }
                    }
         */

        // Tree Recursion Function Calling //

        int x = 20;
        /* treeRecursion(x); */

        // Indirect Recursive Function Call
        IndirectRecursion in = new IndirectRecursion();
        in.funA(x);

        // Nested Recursive Function Call
        Nested_Recursion nes = new Nested_Recursion();
        System.out.println("The Nested Recusrion Is : " + nes.fun(95));

    }

/*
    private static void treeRecursion(int x) {
        if (x > 0) {
            System.out.print(x + " ");
            treeRecursion(x-1);
            treeRecursion(x-1);
        }
    }
*/


}
