#{ 
 # Driver Code Starts
#Initial Template for Python 3

# } Driver Code Ends
#User function Template for python3

from collections import defaultdict
class Solution:
    def helper(self, arr, k):
        mp = defaultdict(int)
        left, right = 0,0
        count = 0
        dist_count = 0
        
        for right in range(len(arr)):
            curr = arr[right]
            
            if curr in mp:
                mp[curr]+=1
            else:
                mp[curr]+=1
                dist_count+=1

            while dist_count > k:
                lcurr = arr[left]
                left+=1
                mp[lcurr]-=1
                if mp[lcurr] == 0:
                    del mp[lcurr]
                    dist_count-=1
                    
            count += right-left
            
        return count
    def subarrayCount(self, arr, N, k):
        return self.helper(arr,k) - self.helper(arr,k-1)
        # Code here

#{ 
 # Driver Code Starts.
if __name__ == '__main__': 
    t = int(input ())
    for _ in range (t):
        N, k = list(map(int, input().split()))
        arr = list(map(int, input().split()))
        ob = Solution()
        res = ob.subarrayCount(arr, N, k)
        print(res)
# } Driver Code Ends