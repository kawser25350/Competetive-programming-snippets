
 void prime_sieve(vector<int>&sieve){

    sieve[1]=0;
    sieve[0]=0;

    int n=sieve.size();

    for(int i=2;i<n;i++){
        if(sieve[i]){
            for(int j=i*i;j<n;j+=i){
                sieve[j]=0;
            }
        }
    }
 // in main funciotn   -> int n=1e5;
//                       vector<int>sieve(n,1);

 }