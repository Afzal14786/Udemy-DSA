package Array_ADTs.SetOperations;


/*
        Set Operations An Array. . . 
        
        -> Union
        -> Intersection
        -> Difference
        -> Set Membership
 */
public class Union {

    /*
            * Union *
           -> We Just Ignore All The Duplicates Elements And Store Rest All The Elements .
     */

    public static void main(String[] args) {
        int[] arr1 = {1,3,5,6,7,8,9,12};
        int[] arr2 = {2,4,5,6,7,9,10,12};

        int[] res = union(arr1, arr2);

        for (int i = 0; i < res.length-1; i++) {
            System.out.print(res[i] +" ");
        }
    }
    
    private static int[] union(int[] arr1, int[] arr2) {
        int[] resultentArray = new int[20];
        int m = arr1.length, n = arr2.length;
        int i = 0, j = 0, k = 0;
        while (i < m && j < n) {
            // comparing the elements of the both sorted array //
            if (arr1[i] == arr2[j]) {
                resultentArray[k++] = arr1[i++];
                j++;
            }
            else if (arr1[i] < arr2[j]) {
                resultentArray[k++] = arr1[i++];
            } else {
                resultentArray[k++] = arr2[j++];
            }
        }

        // copy all the rest of the elements //

        for (; i < m; i++) {
            resultentArray[k] = arr1[i];
        }

        for (; j < n; j++) {
            resultentArray[k] = arr2[j];
        }
        
        return resultentArray;
    }
}
