
class BinarySearch{
	public static void main(String[] args) {
		int n = 1000;
		int[] table = new int[n];
		for(int i = 0; i < n; i++){
			table[i] = i;
		}

		for(int i = 0; i < n; i++){
			int index = find(i,table);
			if(index != i){
				System.out.printf("NG key(%d) index(%d)",i,index);
			}
		}
	}

	static int find(int key, int[] table){
		int left = 0;
		int right = table.length;

		while(true){
			int mid = ( left + right ) /2;

			if(table[mid] > key){
				right  = mid - 1;
			}else if(table[mid] < key){
				left = mid + 1;
			}else{
				return mid;
			}
		}
	}
}