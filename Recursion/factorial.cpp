long long int factorial(int n){
        //code 
        if(n==0) return 1;// since factorial 0 is 1// termination condition
        long long help=factorial(n-1); // we will trust this function that it will return partial ans of fact(n-1)
        return n*help;
    }
