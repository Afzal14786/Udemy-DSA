package Recursion.Example;


class Tylor_Horner_Rule {
    // using recursion //
    static double result;
    protected double Tylor_Hons_Rule(int x, int n) {
        if (x == 0)
            return result;
        result = 1 + (double)(x/n)*result;
        return Tylor_Hons_Rule(x, n-1);
    }



}


public class Tylor_Series {
    // using for loop
    private static double tylor(int x, int n) {
        double res = 1, num = 1, den = 1;
        for (int i = 1; i<= n; i++) {
            num *= x;
            den *= i;
            res += num/den;
        }
        return res;
    }
    static int p = 1, f = 1;

    public static double tylor_series(int x, int n) { 
        double result;
        if (n == 0) {
            return 1;
        } else {
            result = tylor_series(x, n - 1);
            p *= x;
            f *= n;
            return result + (double)p/f;
        }
    }



    public static void main(String[] args) {
        int x = 1;
        int y = 10;
        System.out.println(tylor_series(x, y));

        // Tylor Using Horner's Rule //
//        Tylor_Horner_Rule tr = new Tylor_Horner_Rule();
//        double res = tr.Tylor_Hons_Rule(1,10);  // error
        System.out.println(tylor(x,y));

    }
}
