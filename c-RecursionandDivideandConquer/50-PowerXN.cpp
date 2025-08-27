class Solution {
public:
    double myPow(double x, int n) {
        return pow(x,n);
    }
};


//Optimal approach using Binary Exponentiation
//TC:O(logn)
//SC:O(1)
class Solution {
public:
    double myPow(double x, int n) {
        double ans=1.0;
        long long N = n;
        if(N<0){
            N=-N;
        }
        while(N>0){
            if(N%2==1){
                ans=ans*x;
                N=N-1;
            }else{
                x*=x;
                N/=2;
            }
        }
        if(n<0) ans=(double)1.0/(double)(ans);
        return ans;
    }
};