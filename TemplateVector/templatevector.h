//um simples vetor de classe modelada template <class T>
#ifndef templatevector.h
#define templatevector.h

template <class T>
class TemplateVector
{
    public:
       TemplateVector(int nArraySize)
       {
           // armazena o número de elementos
           nSize = nArraySize;
           array = new T [nArraySize];
           reset();
       }
    int size() {return nWriteIndex;}
    void reset() {nWriteIndex = 0; nReadIndex = 0;}
    void add(const T& object)
    {
        if (nWriteIndex < nSize)
        {
            array [nWriteIndex++] = object;
        }
        
    }
       T& get()
       {
           return array [nReadIndex++];
       }
    protected:
       int nSize;
       int nWriteIndex;
       int nReadIndex;
       T* array;

};
#endif