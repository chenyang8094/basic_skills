//
// Created by qudong on 2019/3/27.
//

#ifndef BASIC_SKILLS_INSERTSORT_H
#define BASIC_SKILLS_INSERTSORT_H

#include <iostream>
#include <vector>
#include <random>
#include <algorithm>


/**
 * 简单插入排序:
 *  插入排序的基本操作就是将一个数据插入到已经排好序的有序数据中，从而得到一个新的、
 *  个数加一的有序数据，算法适用于少量数据的排序。
 *
 * 时间复杂度：
 *      最好O(n), 最差O(n^2),平均O(n^2)
 * 空间复杂度：
 *      O(1)
 * 特性：
 *      稳定、原地排序
 * */

using namespace std;

class InsertSort {

public:

    /**
     * 功  能: 对数据按照从小到大排序
     * 参  数: array待排序的数据
     * 返回值: void
     * 说  明:
     * */
    template <typename T> static void insertSort(vector<T> & array){

        if(array.size() <= 1){
            return;
        }

        for(int i = 1; i < array.size();i++){
            T temp = array[i];

            int j = i - 1;
            for(;j >= 0;j--){
                if(array[j] > temp){
                    array[j + 1] = array[j];
                } else{
                    break;
                }
            }
            array[j + 1] = temp;
        }
    }

    template <typename T> static void printVector(vector<T> & vec){
        for(int i = 0; i < vec.size();i++){
            cout << vec[i] ;
        }
        cout << endl;
    }

    static bool Test(){
        vector<int> testArray = {1,2,3,4,4,5,6,7,8,9};
        auto seed = std::chrono::system_clock::now().time_since_epoch().count();
        shuffle(testArray.begin(),testArray.end(),default_random_engine(seed));
        InsertSort::insertSort(testArray);
        printVector<int>(testArray);

        return true;
    }

};


#endif //BASIC_SKILLS_INSERTSORT_H
