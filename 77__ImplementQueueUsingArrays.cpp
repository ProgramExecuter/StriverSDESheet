class Queue {
    int fr;
    int ba;
    int *arr;
    int size = 0;
public:
    Queue() {
        // Implement the Constructor
        arr = new int[50001];
        fr = ba = -1;
        size = 0;
    }

    /*----------------- Public Functions of Queue -----------------*/

    bool isEmpty() {
        // Implement the isEmpty() function
        return size == 0;
    }

    void enqueue(int data) {
        // Implement the enqueue() function
        if(fr == -1) {
            fr = ba = 0;
            arr[ba] = data;
        }
        else {
            arr[++ba] = data;
        }
        ++size;
    }

    int dequeue() {
        // Implement the dequeue() function
        if(size == 0)
            return -1;
        int ele = arr[fr];
        if(fr == ba) {
            fr = ba = -1;
        }
        else {
            ++fr;
        }
        --size;
        return ele;
    }

    int front() {
        // Implement the front() function
        if(size == 0)
            return -1;
        return arr[fr];
    }
};