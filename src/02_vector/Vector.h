 typedef int Rank; //秩
 #define DEFAULT_CAPACITY  3 //默认的初始容量（实际应用中可设置为更大）

 //向量模板类
 template <typename T> class Vector {
 protected:
    Rank _size; //规模、
    int _capacity;  //容量、
    T* _elem; //数据区
    //复制数组区间A[lo, hi)
    void copyFrom ( T const* A, Rank lo, Rank hi );
    //空间不足时扩容
    void expand();
    //装填因子过小时压缩
    void shrink();
    //扫描交换
    bool bubble ( Rank lo, Rank hi );
    //起泡排序算法
    void bubbleSort ( Rank lo, Rank hi );
    //选取最大元素
    Rank max ( Rank lo, Rank hi );
    //选择排序算法
    void selectionSort ( Rank lo, Rank hi );
    //归并算法
    void merge ( Rank lo, Rank mi, Rank hi );
    //归并排序算法
    void mergeSort ( Rank lo, Rank hi );
    //轴点构造算法
    Rank partition ( Rank lo, Rank hi );
    //快速排序算法
    void quickSort ( Rank lo, Rank hi );
    //堆排序（稍后结合完全堆讲解）
    void heapSort ( Rank lo, Rank hi );
 public:
 // 构造函数
    //容量为c、规模为s、所有元素初始为v
    Vector ( int c = DEFAULT_CAPACITY, int s = 0, T v = 0 )
    { _elem = new T[_capacity = c]; for ( _size = 0; _size < s; _elem[_size++] = v ); } //s<=c
    //数组整体复制
    Vector ( T const* A, Rank n ) { copyFrom ( A, 0, n ); }
    //区间
    Vector ( T const* A, Rank lo, Rank hi ) { copyFrom ( A, lo, hi ); }
    //向量整体复制
    Vector ( Vector<T> const& V ) { copyFrom ( V._elem, 0, V._size ); }
    //区间
    Vector ( Vector<T> const& V, Rank lo, Rank hi ) { copyFrom ( V._elem, lo, hi ); }
 // 析构函数
    ~Vector() { delete [] _elem; } //释放内部空间
 // 只读访问接口
    //规模
    Rank size() const { return _size; }
    //判空
    bool empty() const { return !_size; }
    //判断向量是否已排序
    int disordered() const;
    //无序向量整体查找
    Rank find ( T const& e ) const { return find ( e, 0, _size ); }
    //无序向量区间查找
    Rank find ( T const& e, Rank lo, Rank hi ) const;
    //有序向量整体查找
    Rank search ( T const& e ) const
    { return ( 0 >= _size ) ? -1 : search ( e, 0, _size ); }
    //有序向量区间查找
    Rank search ( T const& e, Rank lo, Rank hi ) const;
 // 可写访问接口
    //重载下标操作符，可以类似于数组形式引用各元素
    T& operator[] ( Rank r ) const;
    //重载赋值操作符，以便直接克隆向量
    Vector<T> & operator= ( Vector<T> const& );
    //删除秩为r的元素
    T remove ( Rank r );
    //删除秩在区间[lo, hi)之内的元素
    int remove ( Rank lo, Rank hi );
    //插入元素
    Rank insert ( Rank r, T const& e );
    //默认作为末元素插入
    Rank insert ( T const& e ) { return insert ( _size, e ); }
    //对[lo, hi)排序
    void sort ( Rank lo, Rank hi );
    //整体排序
    void sort() { sort ( 0, _size ); }
    //对[lo, hi)置乱
    void unsort ( Rank lo, Rank hi );
    //整体置乱
    void unsort() { unsort ( 0, _size ); }
    //无序去重
    int deduplicate();
    //有序去重
    int uniquify();
 // 遍历
    //遍历（使用函数指针，只读或局部性修改）
    void traverse ( void (* ) ( T& ) );
    //遍历（使用函数对象，可全局性修改）
    template <typename VST> void traverse ( VST& );
 }; //Vector
