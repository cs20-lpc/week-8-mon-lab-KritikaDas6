template <typename T>
ArrayStack<T>::ArrayStack(int i) {
    // TODO
    if (i<0) {
        throw string("error, negative size  for array entered");
    }
    maxSize= i;
    buffer= new T[maxSize];
    this->length=0;
}

template <typename T>
ArrayStack<T>::ArrayStack(const ArrayStack<T>& copyObj) {
    copy(copyObj);
}

template <typename T>
ArrayStack<T>& ArrayStack<T>::operator=(const ArrayStack<T>& rightObj) {
    if (this != &rightObj) {
        clear();
        copy(rightObj);
    }
    return *this;
}

template <typename T>
ArrayStack<T>::~ArrayStack() {
    clear();
}

template <typename T>
void ArrayStack<T>::clear() {
    // for(int i=0; i<maxSize; i++){
    //     buffer[i]=NULL;
    //     ; 
    // }

    delete[] buffer;
    buffer= nullptr;
    this->length=0; 
    
}

template <typename T>
void ArrayStack<T>::copy(const ArrayStack<T>& copyObj) {
    // TODO

    maxSize= copyObj.maxSize;
    this-> length= copyObj.length; 
    buffer= new T[copyObj.maxSize];
    for(int i=0;i<=maxSize;i++){
        this-> buffer[i]=copyObj.buffer[i];
    }
}

template <typename T>
int ArrayStack<T>::getLength() const {
    return this->length;
}

template <typename T>
int ArrayStack<T>::getMaxSize() const {
    return maxSize;
}

template <typename T>
bool ArrayStack<T>::isEmpty() const {
    return this->length == 0;
}

template <typename T>
bool ArrayStack<T>::isFull() const {
    return this->length == maxSize;
}

template <typename T>
T ArrayStack<T>::peek() const {
    // TODO

    if (this->length == 0) {
        throw string("error, stack is empty");
    }
    return buffer[this->length-1];
}

template <typename T>
void ArrayStack<T>::pop() {
    if(this->length==0){
        throw string("pop. Stack is empty, cannot pop element.\n");
    }
    this->length--;


  
}

template <typename T>
void ArrayStack<T>::push(const T& elem) {
    if(this->length == maxSize){
        throw string("push: error, stack is full, avoiding overflow \n");
    }
    buffer[this->length++]= elem;
}

template <typename T>
void ArrayStack<T>::rotate(typename Stack<T>::Direction dir) {
  if (this->length <= 1) {
        throw string("rotate: error, one or less elements in stack");
    }

    T temp;

    if (dir == Stack<T>::RIGHT) {
        temp = buffer[this->length - 1];
        for (int i = this->length - 1; i > 0; i--) {
            buffer[i] = buffer[i - 1];
        }

        buffer[0] = temp;
    }


    temp = buffer[0];
    for (int i = 0; i < this->length - 1; i++) {
            buffer[i] = buffer[i + 1];
        }
        buffer[this->length - 1] = temp;


}

template <typename T>
ostream& operator<<(ostream& outStream, const ArrayStack<T>& myObj) {
    if (myObj.isEmpty()) {
        outStream << "Stack is empty, no elements to display.\n";
    }
    else {
        for (int i = myObj.length - 1; i >= 0; i--) {
            outStream << (i == myObj.length - 1 ? "top\t" : "\t")
                      << myObj.buffer[i] << endl;
        }
    }

    return outStream;
}

