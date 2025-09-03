template <typename T>
ArrayList<T>::ArrayList(int i) {
    maxSize = i;
    this->length = 0;
    buffer = new T[maxSize];
}

template <typename T>
ArrayList<T>::ArrayList(const ArrayList<T>& copyObj) {
    copy(copyObj);
}

template <typename T>
ArrayList<T>& ArrayList<T>::operator=(const ArrayList<T>& rightObj) {
    if (this != &rightObj) {
        clear();
        copy(rightObj);
    }
    return *this;
}

template <typename T>
ArrayList<T>::~ArrayList() {
    clear();
}

template <typename T>
void ArrayList<T>::append(const T& elem) {
    if (isFull()) throw std::overflow_error("List full!");
    buffer[this->length++] = elem;
}

template <typename T>
void ArrayList<T>::clear() {
    delete[] buffer;
    buffer = nullptr;
    this->length = 0;
    maxSize = 0;
}

template <typename T>
void ArrayList<T>::copy(const ArrayList<T>& copyObj) {
    maxSize = copyObj.maxSize;
    this->length = copyObj.length;
    buffer = new T[maxSize];
    for (int i = 0; i < this->length; i++) {
        buffer[i] = copyObj.buffer[i];
    }
}

template <typename T>
T ArrayList<T>::getElement(int position) const {
    return buffer[position];
}

template <typename T>
int ArrayList<T>::getLength() const {
    return this->length;
}

template <typename T>
int ArrayList<T>::getMaxSize() const {
    return maxSize;
}

template <typename T>
void ArrayList<T>::insert(int position, const T& elem) {
    if(position < 0 || position >= this->length){
        throw std::out_of_range("Invalid Position!");
    }
    for(int i = this->length; i > position; i--){
        buffer[i] = buffer[i - 1];
    }
    buffer[position] = elem;
    this->length++;
}

template <typename T>
bool ArrayList<T>::isEmpty() const {
    return this->length == 0;
}

template <typename T>
bool ArrayList<T>::isFull() const {
    return this->length == maxSize;
}

template <typename T>
void ArrayList<T>::remove(int position) {
    if(position < 0 || position >= this->length){
        throw std::out_of_range("Invalid Position!");
    }
    for (int i = position; i < this->length; i++){
        buffer[i] = buffer[i+1];
    }
    this->length--;
}

template <typename T>
void ArrayList<T>::replace(int position, const T& elem) {
    if(position < 0 || position >= this->length){
        throw std::out_of_range("Invalid Position!");
    }
    buffer[position] = elem;
}

template <typename T>
ostream& operator<<(ostream& outStream, const ArrayList<T>& myObj) {
    if (myObj.isEmpty()) {
        outStream << "List is empty, no elements to display.\n";
    }
    else {
        for (int i = 0; i < myObj.length; i++) {
            outStream << myObj.buffer[i] << ' ';
        }
        outStream << endl;
    }

    return outStream;
}
