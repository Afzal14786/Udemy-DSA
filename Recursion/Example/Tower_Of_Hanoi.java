package Recursion.Example;

public class Tower_Of_Hanoi {

    private static void TOH(int num, char A, char B, char C) {
        if (num > 0) {
            TOH(num-1, A,C,B);
            System.out.println("{" + A + " To " +  C + "}");
            TOH(num-1, B, A, C);
        }
    }

    private static void tower_hanoi(int n, int a, int b, int c) {
        if (n > 0) {
            tower_hanoi(n-1, a,c,b);
            System.out.println("{" + a +  " To " + c + "}");
            tower_hanoi(n-1, b,a,c);
        }
    }

    private static void hanoi(int noOfDisk, String t1, String t2, String t3) {
        if (noOfDisk > 0) {
            hanoi(noOfDisk-1, t1, t3, t2);
            System.out.println("{" + t1 + " -> " + t3 + "}");
            hanoi(noOfDisk-1,t2,t1,t3);
        }
    }

    public static void main(String[] args) {
        char a = 'A';
        char b = 'B';
        char c = 'C';

//        TOH(2, a, b, c);
//        tower_hanoi(3,1,2,3);
        hanoi(3,"Tower 1", "Tower 2", "Tower 3");
    }
}
