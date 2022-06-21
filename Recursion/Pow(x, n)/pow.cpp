class Solution {
public:
    double myPow(double x, int n) {
        // if(n==1) return x;
        // return x*myPow(x,n-1); // we know 2^5=2*2^4
        // // it wll give out of bound error incase of big number
        //2nd app
        // pow(x,n)=pow(x,n/2)*pow(x,n/2) i.e. 2^6=2^3 * 2^3
        if(n==0) return 1;
      double temp=myPow(x,n/2);
        if(n%2==0)
            return temp*temp;
        else{
            return n<0?1/x*temp*temp:x*temp*temp;
        }
          
       
    }
};
