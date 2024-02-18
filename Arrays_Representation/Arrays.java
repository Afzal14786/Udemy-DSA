package Arrays_Representation;

class Student {
    public String name;
    public int rollNo;

    Student(int rollNo, String name) {
        this.rollNo = rollNo;
        this.name = name;
    }
}

public class Arrays {
    public static void main(String[] args) {
        int arr[] = {1,2,3,4,5};
//        for (int i = 0; i<arr.length; i++) {
//            System.out.print(arr[i] +" ");
//
//        }

        // Decleration of array //
        int ar[];

//        Instantiating an Array
        ar = new int[5];

        // combining both statements in oneint[]
        int[] array = new int[5];
        /*
            Note: The elements in the array allocated by new will automatically be initialized to
            zero (for numeric types), false (for boolean), or null (for reference types). Do refer
            to default array values in Java.

            -> Obtaining an array is a two-step process. First, you must declare a variable of the desired
            array type.
            Second, you must allocate the memory to hold the array, using new, and assign it to the
            array variable. Thus, in Java, all arrays are dynamically allocated.
         */

        // Declaring array literal
        int[] intArray = new int[]{ 1,2,3,4,5,6,7,8,9,10 };

        // Access The Elements using for each loop //
//        for (int x : intArray) {
//            System.out.print(x + " ");
//        }

        Student[] st = new Student[5];
        st[0] = new Student(1, "Aman");
        st[1] = new Student(2, "Rahul");
        st[2] = new Student(3, "Afzal");
        st[3] = new Student(4, "Mohit");
        st[4] = new Student(5, "Mujeeb");

//        for (int i = 0; i<st.length; i++) {
//            System.out.println(st[i]);
//        }
//        for (Student s : st) {
//            System.out.println(s.rollNo + " " + s.name);
//        }
        int x = 5;
        int array2[] = new int[x];
        sum(array2,x);
    }

    private static int sum(int arr[], int n) {
        int sum = 0;

        for (int i = 0; i<n; i++) {
            sum += arr[i];
        }
        return sum;
    }
}
