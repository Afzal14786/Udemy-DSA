package Arrays_Representation;

public class Array2D {
    public static void main(String[] args) {
        int row = 3, cols = 3;

        // first way
        int arr[][] = new int[row][cols];

        // second way //
        int arr2[][] = {
                {1,2,3,4},
                {4,5},
                {7,8,9,10,11}
        };
        // Printing The Elements using for loop
//        for (int i=0; i<arr2.length; i++) {
//            for (int j = 0; j < arr2[i].length; j++) {
//                System.out.print(arr2[i][j]+ " ");
//            }
//            System.out.println();
//        }

        // Printing The Elements using for-each loop
        for (int x[] : arr2) {
            for (int y : x) {
                System.out.print(y +" ");
            }
            System.out.println();
        }


    }
}