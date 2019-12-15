#ifndef __Singleton_h__
#define __Singleton_h__

template < typename T  >
class Singleton
{
    protected:
        Singleton(void) {}
        ~Singleton(void) {}
    protected:
        static T* m_pInst;
    public:
        static T* GetInst(void)
        {
            if( ! m_pInst)
                m_pInst = new T;
       
            return m_pInst;
        }
        static void DestroyInst(void)
        {
            printf("DestroyInst");
            if(m_pInst)
            {
                printf("m_pInst");
                delete m_pInst;
                m_pInst = NULL;
            }
        }
    };

    template <typename T>
    T* Singleton<T>::m_pInst = NULL;

/*
template <class T>
class Singleton
{
public:
	static T& getInstance(void)
	{
		static T object;
		return object;
	}
	static T* getPointer(void)
	{
		return &getInstance();
	}
	static const T& getConst(void)
	{
		return getInstance();
	}
    
    
    
    static void destroyer()
    {
        delete &getInstance();
    }
    static T& CreateInstance()
    {
        if(&getInstance() == 0)
        {
            static T object;
            return object;
        }
        return getInstance();
    }
    
    
	Singleton()  {}
	//~Singleton() {}
    
 
	Singleton(const Singleton&);
	Singleton& operator=(const Singleton&);
}; 
*/
#endif // __Singleton_h__
