const int mod1=1e9+9, mod2=1e9+7;
const int p1=37,p2=31; 
const int N=1e5+7;
int pw1[N],pw2[N];

void precalculate(){
    pw1[0]=1;
    pw2[0]=1;

    for(int i=1;i<=N;i++){
        pw1[i]=1LL * pw1[i-1] * p1 % mod1 ;
        pw2[i]=1ll * pw2[i-1]  * p2 % mod2;

    }
}


pair<int,int> get_hash(string s){
    
    int n=s.size();
    
    int hash1=0,hash2=0;

    for(int i=0;i<n;i++){
     
     hash1+= 1ll * s[i] * pw1[i] % mod1;
     hash1%=mod1;

     hash2+= 1ll * s[i] * pw2[i] % mod2;
     hash2%=mod2;
    
    }
    
    return {hash1,hash2};
}


