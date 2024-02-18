package Array_ADTs.SetOperations;

public class Difference {

    /*
        Difference

        -> Take All The First Array Which Is Unique and not present in another array .
     */
    public static void main(String[] args) {
        int[] arr1 = {3,4,5,6,10};
        int[] arr2 = {2,4,5,7,12};

        int[] res = difference(arr1, arr2);

        for (int i = 0; i < res.length-1; i++) {
            System.out.print(res[i] +" ");
        }

    }

    static int[] difference(int[] A, int[] B) {
        int[] diffAns = new int[10];
        int m = A.length, n = B.length;
        int i = 0, j =0, k = 0;

        while (i < m && j < n) {

            if (A[i] < B[j]) {
                diffAns[k++] = A[i++];
            } else if (A[i] == B[j]) {
                i++;
                j++;
            } else {
                j++;
            }
        }

        for (; i < m; i++) {
            diffAns[k] = A[i];
        }
        return diffAns;
    }

}
