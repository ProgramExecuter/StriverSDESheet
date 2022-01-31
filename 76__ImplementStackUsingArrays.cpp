class Stack {
	int arr[6];
	int top;
public:
	Stack() {
		top = -1;
	}

	bool push(int ele) {
		// OVERFLOW
		// We cannot 'push' more elements
		if(top == 5) {
			return false;
		}

		arr[++top] = ele;
		return true;
	}

	bool pop() {
		// UNDERFLOW
		// No element to pop
		if(top == -1) {
			return false;
		}

		arr[top--] = 0;
		return true;
	}

	int topEle() {
		if(top > -1) {
			return top;
		}
		return -1;
	}

	int size() {
		return top+1;
	}

	void printStack() {
		cout << endl;
		cout << "Stack is :" << endl;
		for(int i = top; i >= 0; i--) {
			cout << arr[i] << " ";
		}
		cout << endl << endl;
	}
};