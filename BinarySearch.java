import java.util.*;

public class BinarySearch {
	public static void main(String[] args) {
		Scanner scan = new Scanner(System.in);
		int n = scan.nextInt();
		int[] array = new int[n];
		for(int i = 0; i < n; ++i) {
			array[i] = scan.nextInt();
		}
		
		int k = scan.nextInt();
		for(int i = 0; i < k; ++i) {
			int t = scan.nextInt();
			int index = binarySearch(array, t);
			System.out.println(index);
		}
	}
	
	static int binarySearch(int[] a, int k) {
		int first = 0;
		int last = a.length - 1;
		if(k > a[last]) {
			return a[last];
		}
		else if(k < a[first]) {
			return a[first];
		}
		while(first <= last ) {
			int n = first + (last - first) / 2;
			if(a[n] == k) {
				return n;
			} 
			else if(a[n] < k) {
				first = n + 1;
			}
			else {
				last = n - 1;
			}
		}
		int r1 = Math.abs(a[last] - k);
		int r2 = Math.abs(a[first] - k);
		return (r1 <= r2)? a[last]:a[first];
	}
}
