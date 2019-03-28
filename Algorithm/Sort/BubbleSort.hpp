//
// Created by qudong on 2019/3/27.
//

#ifndef BASIC_SKILLS_BUBBLESORT_H
#define BASIC_SKILLS_BUBBLESORT_H

#include <vector>
#include <iostream>
#include <algorithm>
#include <random>

using namespace std;

/**
 * 冒泡排序算法:
 * 重复地走访过要排序的元素列，依次比较两个相邻的元素，如果他们的顺序（如从大到小、首字母从A到Z）
 * 错误就把他们交换过来。走访元素的工作是重复地进行直到没有相邻元素需要交换，也就是说该元素已经排序完成。
 *
 * 时间复杂度：
 *      最好O(n), 最差O(n^2),平均O(n^2)
 * 空间复杂度：
 *      O(1)
 * 特性：
 *      稳定、原地排序
 * */

class BubbleSort {
public:

    /**
     * 功  能: 交换两个数的值
     * 参  数: a,b待交换的两个值的引用
     * 返回值: void
     * 说  明: 通用函数，被其它的排序算法调用
     * */
    template <typename T> static void swap(T &a,T &b){
        T temp = a;
        a = b;
        b = temp;
    }

    /**
     * 功  能: 将array中的数据按照从小到大跑徐
     * 参  数: array待排序的数据
     * 返回值: void
     * 说  明: 这并不是严格意义上的冒泡排序，因为它并不是对相邻的元素进行比较
     * */
    template <typename T> static void bubbleSort0(vector<T> & array){
        bool swap_flag;

        if(array.size() <= 1){
            return;
        }

        for (int i = 0; i <  array.size() - 1;i++){
            swap_flag = false;
            for (int j = i + 1; j <  array.size(); j++){
                if( array[i] > array[j]){
                    swap<T>(array[i],array[j]);
                    swap_flag = true;
                }
            }
            if(!swap_flag){
                break;
            }
        }
    }

    /**
     * 功  能: 将array中的数据按照从小到大跑徐
     * 参  数: array待排序的数据
     * 返回值: void
     * 说  明: 严格意义上的冒泡排序，是对相邻的元素进行比较
     * */
    template <typename T> static void bubbleSort1(vector<T> & array){
        bool swap_flag;

        if(array.size() <= 1){
            return;
        }

        for(int i = 0; i < array.size() ;i++){
            swap_flag = false;
            for(int j = 0 ; j < array.size() - i - 1;j++){
                if(array[j] > array[j + 1]){
                    swap(array[j + 1],array[j]);
                    swap_flag = true;
                }
            }
            if(!swap_flag){
                break;
            }
        }
    }

    /**
     * 功  能: 将array中的数据按照从小到大排序
     * 参  数: array待排序的数据
     * 返回值: void
     * 说  明: 严格意义上的冒泡排序，是对相邻的元素进行比较，和bubbleSort1的区别是从后向前遍历
     * */
    template <typename T> static void bubbleSort2(vector<T> & array){
        bool swap_flag;
        if(array.size() <= 1){
            return;
        }

        for(int i = 0;i < array.size();i++){
            swap_flag = false;
            for(int j = static_cast<int>(array.size()) - 1;j > i;j--){
                 if(array[j] < array[j - 1]){
                     swap<T>(array[j],array[j - 1]);
                     swap_flag = true;
                 }
            }

            if(!swap_flag){
                break;
            }
        }
    }

    template <typename T> static void printVector(vector<T> & vec){
       for(int i = 0; i < vec.size();i++){
           cout << vec[i] ;
       }
        cout << endl;
    }

    static bool Test(){
        cout << "****************BubbleSort Test Start*****************" << endl;

        auto seed = std::chrono::system_clock::now().time_since_epoch().count();
        vector<int> testArray = {1,2,3,4,4,5,6,7,8,9};
        shuffle(testArray.begin(),testArray.end(),default_random_engine(seed));
        cout << "排序前:";printVector<int>(testArray);
        BubbleSort::bubbleSort0<int>(testArray);
        cout << "排序后:";printVector<int>(testArray);
        seed = std::chrono::system_clock::now().time_since_epoch().count();
        shuffle(testArray.begin(),testArray.end(),default_random_engine(seed));
        cout << "排序前:";printVector<int>(testArray);
        BubbleSort::bubbleSort1<int>(testArray);
        cout << "排序后:";printVector<int>(testArray);
        seed = std::chrono::system_clock::now().time_since_epoch().count();
        shuffle(testArray.begin(),testArray.end(),default_random_engine(seed));
        cout << "排序前:";printVector<int>(testArray);
        BubbleSort::bubbleSort2<int>(testArray);
        cout << "排序后:";printVector<int>(testArray);
        cout << "****************BubbleSort Test End*****************" << endl;
        return true;
    }
};


#endif //BASIC_SKILLS_BUBBLESORT_H
