function checkPalindrome(str){
  if(str.length < 2) return 1;
    if(str.length === 2) if (str[0] === str[1]) return 1;
    if(str[0] === str.slice(-1)) return checkPalindrome(str.slice(1,-1));
    return 0;
}
class Solution {
    isPalindrome(str){
        //code here
      return checkPalindrome(str);
    }
}
