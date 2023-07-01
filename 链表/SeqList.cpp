#include<iostream>
using namespace std;
template<class T>
class SeqList
{
private:
    int MaxSize;
    int length;  //最后一个元素所在位置
    T *data;
public:
    SeqList(int MaxSize = 10); //构造
    ~SeqList();
    int ListLength();
    T Get(int pos);    // 获取第 pos个元素的值
    int Locate(T item);  // 查找item位置
    void Insert(int i, T item);
    void PrintList();
    T Delete(int i);
};

template<class T>
SeqList<T>::SeqList(int Size)
{
    data = new T[Size];
    MaxSize = Size;
    length = 0; //表示顺序表为空
}

template<class T>
SeqList<T>::~SeqList()
{}

template<class T>
void SeqList<T>:: Insert(int i,T x)
{
    if(i < 0 || i > length + 1)
        cerr << "插入非法" << endl;
    for(int j = length - 1; j >= i; j--)
        data[j + 1] = data[j];
    data[i] = x;
    length++;
}

template<class T>
void SeqList<T>:: PrintList()
{
    for(int i = 0; i < length; i++)
        cout << data[i] << endl;
}

template<class T>
int SeqList<T>:: ListLength()
{
    return length;
}

template<class T>
T SeqList<T>:: Get(int pos)
{
    return data[pos];
    
}

template<class T>
int SeqList<T>:: Locate(T item)
{
    for(int i = 0; i < length; i++)
    {
        if(data[i] == item)
            return i + 1;
    }
}

template<class T>
T SeqList<T>:: Delete(int i)
{
    for(int j = i - 1; j < length; j++)
        data[j] = data[j + 1];
    length--;
}

int main()
{
    SeqList<int> L1(5);
    L1.Insert(0,1);
    L1.Insert(1,2);
    L1.Insert(2,3);
    L1.Insert(3,4);
    L1.Insert(4,5);
    cout << "输出顺序表" << endl;
    L1.PrintList();
    cout << "长度为：" << L1.ListLength() << endl;
    cout << "查找第3个数字的值：" << L1.Get(2) << endl;
    cout << "查找值为3的数字的位置：" << L1.Locate(3) << endl;
    cout << "删除第3个数字并输出顺序表：" << endl;
    L1.Delete(3);
    L1.PrintList();
    system("pause");
    return 0;
}
