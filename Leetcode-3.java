class Solution {
    public int[] smallestTrimmedNumbers(String[] nums, int[][] queries) {
        int n = nums.length;
        int [] ans = new int [queries.length];
        int j=0;
        
        for(int [] query : queries){
            int k=query[0];
            int trim=query[1];
            
            String [][] arr = new String [n][2];
            int len = nums[0].length();
            for(int i=0;i<n;i++){
                String num = nums[i];
                String sub = num.substring(len-trim);
                arr[i][0]=sub;
                arr[i][1]=i+"";
            }
            
            Arrays.sort(arr,(a,b)->{
                if(a[0].equals(b[0])==false) return a[0].compareTo(b[0]);
                else  return Integer.parseInt(a[1])-Integer.parseInt(b[1]);
            });
            
            ans[j]=Integer.parseInt(arr[k-1][1]);
            j++;
        }
        return ans;
    }
}


/*Query Kth Smallest Trimmed Number
*/
