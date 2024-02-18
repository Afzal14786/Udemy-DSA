package Recursion;

class Rec {
    static int n = 0;
    int value(int x) {
        if (x > 0) {
            n++;
            return value(x-1) + n;
        }
        return 0;
    }
}
public class Static_Global_Variable {

    public static void main(String[] args) {
        int x = 5;
        Rec r = new Rec();
        System.out.println(r.value(x));
        System.out.println(r.value(x));
    }
}
