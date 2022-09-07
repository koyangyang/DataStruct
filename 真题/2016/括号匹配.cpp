bool MatchBrackets(string seq) {
    stack<char> s;
    for (int i = 0; i < seq.size(); i++) {
        if (seq[i] == '(' || seq[i] == '[')
            s.push(seq[i]);
        else {
            if (s.empty()) return false;
            if (seq[i] == ')' && s.top() != '(') return false;
            if (seq[i] == ']' && s.top() != '[') return false;
            s.pop();
        }
    }
    if(!s.empty()) return false;//如果栈内还有元素则未完全匹配
    return true;
}