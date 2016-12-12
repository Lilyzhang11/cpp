#include "stdafx.h" 

#include <iostream>

#include "FigureManager.h"

#include "Circle.h"
#include "Line.h"
#include "Rectangle.h"
#include "Triangle.h"

using std::cout; 

void FigureManager::input(std::istream &is)
{
    while (1)
    {
        // Factory Pattern
        // �ô��ǽ����п������ӵ����͵Ĺ���ŵ�����
        // ʹ��������չʱ�������ʹ�������κ��޸�
        // FigureManager��Ϊ�ͻ��������������ڸ������͵Ĺ���
        // ������ = ��֪��
        // ��֪�� = ��չ�������
        cout << "intput type("; 
        for (Factories::iterator iter = factories.begin(); 
            iter != factories.end(); ++iter)
        {
            cout << (*iter)->id(); 
            cout << " : "; 
            cout << (*iter)->name();
            cout << ", "; 
        }
        cout << "0 : quit)" << std::endl; 

        int type; 
        is >> type; 

        if (type == 0){
            return; 
        }

        for (Factories::iterator iter = factories.begin(); 
            iter != factories.end(); ++iter)
        {
            if (type == (*iter)->id())
            {
                // ���еĹ��̶���FigureFactory
                // ����֪����ʲô����
                // �ٴΣ���֪�� = ��չ������� = ����չ��
                Figure *figure = (*iter)->createFigure(); 

                // ��FigureManager��˵�����еĻ�ͼ���Ͷ���Figure
                // �����ע�������;������input
                // ��ˣ��������͵�Draw��������չ������Ӱ��FigureManager
                figure->input(is); 
                _figures.push_back(figure); 
            }
        }
    }
}

void FigureManager::display(BlackBoard &board)
{
    // ��FigureManager��˵�����еĻ�ͼ���Ͷ���Figure
    // �����ע�������;������Draw
    // ��ˣ��������͵�Draw��������չ������Ӱ��FigureManager
    for (Figures::iterator iter = _figures.begin(); 
        iter != _figures.end(); ++iter)
    {
        (*iter)->draw(board); 
    }
}


void InitiateFigureManager()
{
	FigureManager::handle().installFactory(new Factory<Circle>("Circle", FigureManager::handle().assignID())); 
	FigureManager::handle().installFactory(new Factory<Line>("Line", FigureManager::handle().assignID())); 
	FigureManager::handle().installFactory(new Factory<Rectangle>("Rectangle", FigureManager::handle().assignID())); 
	FigureManager::handle().installFactory(new Factory<Triangle>("Triangle", FigureManager::handle().assignID())); 
}


