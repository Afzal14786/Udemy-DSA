package Arrays_Representation;

public class Memory_Allocation {
    private int x = 30;  // <- This Will Be Created Inside The Heap Memory;
    public static void main(String[] args) {
        int x = 5;   // <- This Will Be Created Inside The Stack
        int[] arr = new int[x];
        printArray(arr,x);
    }

    private static void printArray(int arr[], int x) {
        //   code here
        for(int y : arr) {
            System.out.println(y);
        }
    }
}
