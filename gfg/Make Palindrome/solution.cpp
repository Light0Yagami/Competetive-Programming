/*
You are given an array of strings arr of size n. You have to find out if it is possible to make a palindromic string by concatenating the strings in any order. Provided that all the strings given in the array are of equal length.
*/

bool checkPalindrome(string str){
        int i = 0, j = str.size() -1 ;
        while(i <= j){
            if(str[i] != str[j]){
                return false;
            }
            i++;
            j--;
        }
        
        return true;
    }
    bool makePalindrome(int n,vector<string> &arr){
        // Code here
        map<string,int> map;
        int oddcount = 0;
        for(int i = 0; i < n; i++){
            string temp = arr[i];
            reverse(temp.begin(),temp.end());
            if(map.find(temp) == map.end()){
                map[arr[i]]++;
            }else{
                map[temp]++;
            }
        }
        
        for(auto it: map){
            if(it.second % 2 != 0){
                oddcount++;
                if(oddcount > 1 || !checkPalindrome(it.first))
                    return false;
            }   
        }
        
        return true;
    }
