

// greedy or any operaion  ( when found monotonic beaheahiner
 auto ok=[&](long long mid)
    {
        int total=0;
        for (int i = 0;i < n;i++) {
            total += (mid / v[i]);
            if (total >= t) {
                return true;
            }
        }
        return false;
        };


   int l=0,r=1e18,ans,mid;

   while(l<=r){

      mid=l+(r-l)/2;

      if(ok(mid)){

         r=mid-1;

         ans=mid;

      }
      else{

         l=mid+1;
      }
   }

