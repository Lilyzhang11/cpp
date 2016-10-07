// LibArray.cpp : �������̨Ӧ�ó������ڵ㡣
//

// ʵ�����ݣ�
// 1����C���԰汾LibArray��C++��װ��ע�⣬ԭC�汾����һ������

// ʵ��Ŀ�ģ�
// 1��C++�ඨ��Ļ�������

// ֻ�ύCLibArray.cpp��CLibArray.h

#include "stdafx.h"

#include <assert.h>

#include "CLibArray.h"

int _tmain(int argc, _TCHAR* argv[])
{
    CArray array;
	// ������Ҫinitial����Ӧ������ȷ�ĳ�ʼ��
    // array_initial(array); 

    //array.recap(10); 
    //assert(array.capacity() == 10); 

    //////////////////////////////////////////////////////////////////////////
    for (int i = 0; i < 20; ++i)
    {
        array.append(i); 
    }
    assert(array.size() == 20); 
    
    for (int i = 0; i < array.size(); ++i)
    {
        assert(array.at(i) == i); 
    }

    //////////////////////////////////////////////////////////////////////////
    CArray array2, array3; 
    // array_initial(array2); 
    // array_initial(array3); 

    array2.copy(array); 
    assert(array.compare(array2) == true); 

    array3.copy(array); 
    assert(array.compare(array3) == true); 

    //////////////////////////////////////////////////////////////////////////
    array2.insert(2, 3); 
    assert(array.compare(array2) == false); 

    //////////////////////////////////////////////////////////////////////////
    array3.at(2) = 5; 
    assert(array.compare(array3) == false); 

    //////////////////////////////////////////////////////////////////////////
	// ������Ҫdestroy����Ӧ������ȷ���ڴ��ͷ�
    // array_destroy(array); 
    // array_destroy(array2); 
    // array_destroy(array3); 

	return 0;
}