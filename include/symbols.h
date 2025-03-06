

enum symbols {
    PAREN_OPEN,  // (
    PAREN_CLOSE, // )
    PLUS,        // +
    MINUS,       // -
    MULTIPLY,    // *
    DIVIDE,      // /
    OPERAND,     // 0-9
};

symbols charToSymbol(char c) {
    switch (c) {
        case '(': return PAREN_OPEN;
        case ')': return PAREN_CLOSE;
        case '+': return PLUS;
        case '-': return MINUS;
        case '*': return MULTIPLY;
        case '/': return DIVIDE;
        default: return OPERAND;
    }
}