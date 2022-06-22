	int help(int l,int r,string &s){
	    if(l>=r) return 1;
	    if(s[l]!=s[r]) return 0;
	    return help(l+1,r-1,s);
	}
	int isPalindrome(string S)
	{
	    // Your code goes here
	    return help(0,S.size()-1,S);
	}
