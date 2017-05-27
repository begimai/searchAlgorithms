import java.util.*;
public class BinarySearchRecursive {
	public static void main(String[] args) {
		Scanner scan = new Scanner(System.in);

		int n = scan.nextInt();
		int[] a = new int[n];
		for (int i = 0; i < n; ++i) {
			a[i] = scan.nextInt();
		}
		
		int k = scan.nextInt();
		for(int i = 0; i < k; ++i) {
			int t = scan.nextInt();
			int index = binarySearch(a, t);
			System.out.println(index);
		}
	}

	static int binarySearch(int[] a, int k) {
		if(a[0] > k) {
			return a[0];
		}
		else if(a[a.length - 1] < k) {
			return a[a.length - 1];
		}
		return binarySearchAux(a, k, 0, a.length - 1);
	}

	static int binarySearchAux(int[] a, int k, int first, int last) {	
		if (first > last) {
			int r1 = Math.abs(a[last] - k);
			int r2 = Math.abs(a[first] - k);
			return (r1 <= r2)? a[last]:a[first];
		}

		int m = first + (last - first) / 2;
		if (a[m] == k) {
			return a[m];
		}
		if (a[m] < k) {
			return binarySearchAux(a, k, m + 1, last);
		}
		return binarySearchAux(a, k, first, m - 1);
	}
}
