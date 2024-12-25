int index= lower_bound(v.begin(),v.end()) - v.begin(); //return same value's  or lower's index
int index = upper_bound(v.begin(),v.end()) - v.begin(); //return upper values's index all time 

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
