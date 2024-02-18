package Array_ADTs;

public class BinearySearch {

    // Implementation Of Binary Search //
    private static int binarySearch(int[] array, int target) {
        int start = 0, end = array.length-1;

        while (start <= end) {
            int mid = start + (end - start)/2;

            if (array[mid] == target) {
                return mid;
            } else if (array[mid] < target) {
                start = mid + 1;
            } else {
                end = mid - 1;
            }
        }
        return -1;
    }

    // Recursive Approach for Bineary Search /
    private static int recursiveBiSearch(int[] array, int start, int end, int target) {

        if (start <= end) {
            int mid = start + (end - start)/2;
            if (target == array[mid]) {
                return mid;
            } else if (target < array[mid]) {
                return recursiveBiSearch(array, start, mid-1, target);
            } else  {
                return recursiveBiSearch(array, mid+1, end, target);
            }
        }
        return -1;
    }
    public static void main(String[] args) {
        int[] array = {1,2,3,4,5,6,7,8};
        System.out.println("The Target Element Find At Index : " + recursiveBiSearch(array, 0, array.length-1, 0));
    }
}
