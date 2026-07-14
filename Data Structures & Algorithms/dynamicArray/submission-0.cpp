class DynamicArray {
private:
    int* dynArray = NULL;
    int arrSize=0;
    int arrCapacity = 0;
public:

    DynamicArray(int capacity) 
    {
        this->dynArray = new int[capacity];
        this->arrCapacity = capacity;
    }

    int get(int i) 
    {
        return this->dynArray[i];
    }

    void set(int i, int n) 
    {
        this->dynArray[i] = n;
    }

    void pushback(int n) 
    {
        if(this->arrSize == this->arrCapacity)
        {
            this->resize();
        }
        this->dynArray[arrSize++] = n;
    }

    int popback() 
    {
        int data = this->dynArray[--arrSize];
        return data;
    }

    void resize() 
    {
        int newCapacity = this->arrCapacity *2;
        int* newArray_p = new int[newCapacity];
        
        for(unsigned i=0; i<this->arrSize;i++)
        {
            newArray_p[i] = this->dynArray[i];
        }

        delete[] this->dynArray;
        this->arrCapacity = newCapacity;
        this->dynArray = newArray_p;
        
    }

    int getSize() 
    {
        return this->arrSize;
    }

    int getCapacity() 
    {
        return this->arrCapacity;
    }
};
