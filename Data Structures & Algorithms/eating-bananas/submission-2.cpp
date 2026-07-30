class Solution {
private:
    int getCount(vector<int>& piles, int mid){
        int sum =0;
        for(int i=0;i<piles.size();i++){

            sum += (piles[i]/ mid);
            if(piles[i]%mid!=0) sum+=1;
        }
        return sum;
    }
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int low = 1;
        int high = INT_MIN;
        for(int i=0;i<piles.size();i++){
            high = max(high,piles[i]);
        }

        while(low<=high){
            int mid = low+(high-low)/2;

            int totalHours = getCount(piles,mid);
            if(totalHours<= h){
                high = mid-1;
            }else low = mid+1;
        }
        return low;
    }
};
