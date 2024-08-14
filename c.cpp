Missing Digit
Have the function MissingDigit(str) take the str parameter,
 which will be a simple mathematical formula with three 
numbers, a single operator (+, -, *, or /) and an equal 
sign (=) and return the digit that completes the equation.
 In one of the numbers in the equation, there will be an x
  character, and your program should determine what digit
 is missing. For example, if str is "3x + 12 = 46" then 
 your program should output 4. The x character can appear
  in any of the three numbers and all three numbers will
   be greater than or equal to 0 and less than or equal 
   to 1000000.

//code
 stringstream ss(exp);
    string token;
    string expArr[5];
    int i = 0;
    while (getline(ss, token, ' ')) {
        expArr[i++] = token;
    }
 
    string firstOperand = expArr[0];
    string operatorStr = expArr[1];
    string secondOperand = expArr[2];
    string resultant = expArr[4];
 
    int res = 0;
    string x = "";
 
    if (resultant.find("x") != string::npos) {
        x = resultant;
        firstOperand = expArr[0];
        secondOperand = expArr[2];
 
        int first = stoi(firstOperand);
        int second = stoi(secondOperand);
 
        if (operatorStr == "+") {
            res = first + second;
        }
        else if (operatorStr == "-") {
            res = first - second;
        }
        else if (operatorStr == "*") {
            res = first * second;
        }
        else {
            res = first / second;
        }
    }
    else {
        resultant = expArr[4];
        int result = stoi(resultant);
 
        if (firstOperand.find("x") != string::npos) {
            x = firstOperand;
            secondOperand = expArr[2];
            int second = stoi(secondOperand);
 
            if (operatorStr == "+") {
                res = result - second;
            }
            else if (operatorStr == "-") {
                res = result + second;
            }
            else if (operatorStr == "*") {
                res = result / second;
            }
            else {
                res = result * second;
            }
        }
        else {
            x = secondOperand;
            firstOperand = expArr[0];
            int first = stoi(firstOperand);
 
            if (operatorStr == "+") {
                res = result - first;
            }
            else if (operatorStr == "-") {
                res = first - result;
            }
            else if (operatorStr == "*") {
                res = result / first;
            }
            else {
                res = first / result;
            }
        }
    }
 
    string resStr = to_string(res);
    int k = 0;
    for (int i = 0; i < x.length(); i++) {
        if (x[i] == 'x') {
            return resStr[k] - '0';
        }
        else {
            k++;
        }
    }
 
    return 0;