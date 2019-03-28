//
// Created by qudong on 2019/3/27.
//

#ifndef BASIC_SKILLS_SELECTSORT_H
#define BASIC_SKILLS_SELECTSORT_H

#include <iostream>
#include <vector>
#include <random>

/**
 * 简单选择排序:
 *  在简单选择排序过程中，所需移动记录的次数比较少。
 *  最好情况下，即待排序记录初始状态就已经是正序排列了，则不需要移动记录。方法是
 *  设所排序序列的记录个数为n。i取1,2,…,n-1,从所有n-i+1个记录（Ri,Ri+1,…,Rn）
 *  中找出排序码最小的记录，与第i个记录交换。
 *
 * 时间复杂度：
 *      最好O(n), 最差O(n^2), 平均O(n^2)
 * 空间复杂度：
 *      O(1)
 * 特性：
 *      稳定、原地排序
 * */

using namespace std;

class SelectSort{
public:

    template <typename T> static void swap(T &a,T &b){
        T t = a;
        a = b;
        b = t;
    }

    /**
     * 功  能: 对数据按照从小到大排序
     * 参  数: array待排序的数据
     * 返回值: void
     * 说  明:
     * */
    template <typename T> static void selectSort(vector<T> & array){

        if(array.size() <= 1){
            return;
        }

        for(int i = 0; i < array.size();i++){

            int min = i;

            for(int j = i + 1;j < array.size();j++){
                 if(array[min] > array[j]){
                    min = j;
                 }
            }
            if(min != i){
                swap(array[i],array[min]);
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
        cout << "****************SelectSort Test Start*****************" << endl;
        vector<int> testArray = {1,2,3,4,4,5,6,7,8,9};
        auto seed = std::chrono::system_clock::now().time_since_epoch().count();
        shuffle(testArray.begin(),testArray.end(),default_random_engine(seed));
        cout << "排序前:";printVector(testArray);
        SelectSort::selectSort(testArray);
        cout << "排序后:";printVector(testArray);
        cout << "****************SelectSort Test End*****************" << endl;
        return true;
    }
};
#endif //BASIC_SKILLS_SELECTSORT_H
