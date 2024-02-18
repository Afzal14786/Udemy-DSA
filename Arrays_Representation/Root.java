package Arrays_Representation;

import java.util.Scanner;

public class Root {
    public static void main(String[] args) {
        System.out.println("Let's Find The Root : " );
        int a,b,c;
        Scanner scn = new Scanner(System.in);
        System.out.println("Enter The Number Of A, B And C : ");
        a = scn.nextInt();
        b = scn.nextInt();
        c = scn.nextInt();

        double root1 = (-b + Math.sqrt(b*b - 4 * a * c)/(2*a));
        double root2 = (-b - Math.sqrt(b*b - 4 * a * c)/(2*a));

        System.out.println("The Roots Are : \n" + "Root 1 : " + root1 +"\n Root 2 : " + root2);
    }
}
