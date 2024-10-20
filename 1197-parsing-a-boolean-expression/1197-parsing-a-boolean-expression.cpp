class Solution {
public:
    bool parseBoolExpr(string expression) {
        // Start parsing the full expression
        return parse(expression, 0, expression.size() - 1);
    }
    
private:
    // Helper function to parse the expression
    bool parse(const string& expr, int left, int right) {
        // Base case: single boolean value
        if (left == right) {
            return expr[left] == 't';
        }

        // Handling based on the first character
        if (expr[left] == '!') {
            // Logical NOT operation, parse the subexpression inside the brackets
            return !parse(expr, left + 2, right - 1);
        } else if (expr[left] == '&') {
            // Logical AND operation
            bool result = true;
            int start = left + 2;  // Start of the first sub-expression
            for (int i = left + 2, level = 0; i < right; ++i) {
                if (expr[i] == '(') ++level;
                else if (expr[i] == ')') --level;
                else if (expr[i] == ',' && level == 0) {
                    result = result && parse(expr, start, i - 1);
                    start = i + 1;
                }
            }
            // Process the last subexpression after the final comma
            return result && parse(expr, start, right - 1);
        } else if (expr[left] == '|') {
            // Logical OR operation
            bool result = false;
            int start = left + 2;  // Start of the first sub-expression
            for (int i = left + 2, level = 0; i < right; ++i) {
                if (expr[i] == '(') ++level;
                else if (expr[i] == ')') --level;
                else if (expr[i] == ',' && level == 0) {
                    result = result || parse(expr, start, i - 1);
                    start = i + 1;
                }
            }
            // Process the last subexpression after the final comma
            return result || parse(expr, start, right - 1);
        }
        
        return false;
    }
};
