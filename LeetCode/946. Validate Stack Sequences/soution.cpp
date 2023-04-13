/*Given two integer arrays pushed and popped each with distinct values, 
return true if this could have been the result of a sequence of push and pop operations on an initially empty stack, or false otherwise.
*/

stack<int> st; // Create a stack
        
        int j = 0; // Intialise one pointer pointing on popped array
        
        for(auto val : pushed){
            st.push(val); // insert the values in stack
            while(st.size() > 0 && st.top() == popped[j]){ // if st.peek() values equal to popped[j];
                st.pop(); // then pop out
                j++; // increment j
            }
        }
        return st.size() == 0; 
