class Solution {
public:
    string removeOuterParentheses(string s) {
        // Initialize result string
        string result= "";
        int level=0;
        for(char ch : s){
             // If we encounter '(', increase the level
            if(ch == '('){
                // If we're inside a primitive, add '(' to result
                if(level > 0)   result+=ch;
                // Increase the nesting level for '('
                level++;
            }        
            else{
                // If we encounter ')', decrease the level
                // Decrease the nesting level for ')'
                level--;
                // If we're inside a primitive, add ')' to result
                if(level > 0)   result+=ch;
            }
        }
        return result;
    }
};