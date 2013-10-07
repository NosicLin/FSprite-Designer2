#ifndef _SD_CIRCLE_QUEUE_
#define _SD_CIRCLE_QUEUE_
#define SD_DEFAULT_CIRCLE_QUEUE_SIZE 512
template <typename T>
class SdCircleQueue
{
	public:
        SdCircleQueue()
        {
            init();
        }
        ~SdCircleQueue()
        {
            destroy();
        }
	public:
		int size()
		{
			return m_used;
		}

        int capacity()
		{
			return m_size;
		}
		bool full()
		{
			return m_size==m_used;
		}
		bool empty()
		{
			return m_used==0;
		}

        void push(T* item)
		{
			if(m_used==m_size)
			{
				delete m_queue[m_begin];
				m_queue[m_begin]=item;
				m_begin=(m_begin+1)%m_size;
			}
			else 
			{
                int pos=(m_begin+m_used)%m_size;
				m_queue[pos]=item;
				m_used++;
			}
		}

        T* getItem(int i)
		{
            int pos=(m_begin+i)%m_size;
			return m_queue[pos];
		}
		void dropTail(int nu)
		{
			while(nu--)
			{
				int pos=(m_begin+m_used-1)%m_size;
				delete m_queue[pos];
				m_used--;
			}
		}
		void clear() 
		{
			for(int i=0;i<m_used;i++)
			{
				int pos=(i+m_begin)%m_size;
				delete m_queue[pos];
			}
			m_used=0;
			m_begin=0;
		}

	protected:
		void init()
		{
			m_queue=new T*[SD_DEFAULT_CIRCLE_QUEUE_SIZE];
			m_size=SD_DEFAULT_CIRCLE_QUEUE_SIZE;
			m_used=0;
			m_begin=0;
		}
		void destroy()
		{
			clear();
			delete[] m_queue;
		}

	private:
        T** m_queue;
		int m_size;
		int m_used;
		int m_begin;
};

#endif /*_SD_CIRCLE_QUEUE_*/
















