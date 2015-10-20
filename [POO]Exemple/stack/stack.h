#define MAX_STACK 10

class Stack {
 public:
  Stack(int = MAX_STACK);
  ~Stack();
  void push(char);
  void pop();
  char top();
  bool is_empty(); 
  void display();
 private:
  char *arr;
  int top_index, nMax;
};
