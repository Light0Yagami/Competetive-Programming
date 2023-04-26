/*
Given an integer num, repeatedly add all its digits until the result has only one digit, and return it.
*/

class Solution {
public:
    int addDigits(int num) {
      long int sum = 0,rem;
      while(true){
          while(num != 0){
            rem = num % 10;
            sum += rem;
            num = num/10;
          }
          if(sum >= 10){
            num = sum;
            sum = 0;
          }else{
            break;
          }

        }  

        return sum;
    }
};
